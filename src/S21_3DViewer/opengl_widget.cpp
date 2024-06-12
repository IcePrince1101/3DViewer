#include "opengl_widget.h"

#include "ui_opengl_widget.h"

OpenGL_Widget::OpenGL_Widget(QWidget *parent)
    : QOpenGLWidget(parent), ui(new Ui::OpenGL_Widget) {}

OpenGL_Widget::~OpenGL_Widget() { delete ui; }

void OpenGL_Widget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);  // Используем буфер глубины
}

void OpenGL_Widget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);  // Координаты углов видимой области
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void OpenGL_Widget::paintGL() {
  glClearColor(background.redF(), background.greenF(), background.blueF(),
               1);  // цвет фона

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (default_projection)
    glOrtho(-1.5, 1.5, -1.5, 1.5, -3, 1000);
  else {
    glFrustum(-1.5, 1.5, -1.5, 1.5, 1, 100000);
    glTranslatef(0, 0, -3);
  }

  glRotatef(x_rotation, 1, 0, 0);  // Поворот вокруг оси X
  glRotatef(y_rotation, 0, 1, 0);  // Поворот вокруг оси Y

  if (mem_allocated) draw_model();  // рисуем если файл прочитан корректно
}

void OpenGL_Widget::file_preprocessing() {
  destroy_model();
  model.count_of_vertexes = 0;
  model.count_of_facets = 0;
  QByteArray ba = file.toUtf8();
  char *c_str = ba.data();
  if (parseFile(c_str, &model) == 0) mem_allocated = true;
}

void OpenGL_Widget::center_model() {
  max_x = model.matrix_3d.matrix[1][0], max_y = model.matrix_3d.matrix[1][1],
  max_z = model.matrix_3d.matrix[1][2];
  min_x = max_x, min_y = max_y, min_z = max_z;

  for (unsigned int i = 1; i <= model.count_of_vertexes; i++) {
    max_x = max_x < model.matrix_3d.matrix[i][0] ? model.matrix_3d.matrix[i][0]
                                                 : max_x;
    max_y = max_y < model.matrix_3d.matrix[i][1] ? model.matrix_3d.matrix[i][1]
                                                 : max_y;
    max_z = max_z < model.matrix_3d.matrix[i][2] ? model.matrix_3d.matrix[i][2]
                                                 : max_z;
    min_x = min_x > model.matrix_3d.matrix[i][0] ? model.matrix_3d.matrix[i][0]
                                                 : min_x;
    min_y = min_y > model.matrix_3d.matrix[i][1] ? model.matrix_3d.matrix[i][1]
                                                 : min_y;
    min_z = min_z > model.matrix_3d.matrix[i][2] ? model.matrix_3d.matrix[i][2]
                                                 : min_z;
  }

  center_x = min_x + (max_x - min_x) / 2;
  center_y = min_y + (max_y - min_y) / 2;
  center_z = min_z + (max_z - min_z) / 2;

  for (unsigned int i = 1; i <= model.count_of_vertexes; i++) {
    model.matrix_3d.matrix[i][0] -= center_x;
    model.matrix_3d.matrix[i][1] -= center_y;
    model.matrix_3d.matrix[i][2] -= center_z;
  }
}

void OpenGL_Widget::draw_model() {  // основная функция для отрисовки
  if (!move)
    center_model();  // Центрирование модели только при первой отрисовке, пока
                     // не начали двигать
  // массив вершин для отрисовки точек
  double *vertex_array =
      (double *)malloc(model.count_of_vertexes * 3 * sizeof(double));
  unsigned int vertex_number = 0;
  for (unsigned int i = 1; i <= model.count_of_vertexes; i++) {
    vertex_array[vertex_number++] = model.matrix_3d.matrix[i][0];
    vertex_array[vertex_number++] = model.matrix_3d.matrix[i][1];
    vertex_array[vertex_number++] = -1 * model.matrix_3d.matrix[i][2];
  }
  // массив индексов для отрисовки линий
  int *index_array = (int *)malloc(model.count_of_facets * 6 * sizeof(int));
  unsigned int count = 0;
  for (unsigned int i = 1; i <= model.count_of_facets; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 2) {
        index_array[count++] = model.polygons[i].vertexes[2] - 1;
        index_array[count++] = model.polygons[i].vertexes[0] - 1;
      } else {
        index_array[count++] = model.polygons[i].vertexes[j] - 1;
        index_array[count++] = model.polygons[i].vertexes[j + 1] - 1;
      }
    }
  }

  glVertexPointer(3, GL_DOUBLE, 0, vertex_array);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColor3d(points_color.redF(), points_color.greenF(), points_color.blueF());
  if (round) glEnable(GL_POINT_SMOOTH);
  if (!without_points) {  // отрисовка точек
    glPointSize(point_size);
    glDrawArrays(GL_POINTS, 0, model.count_of_vertexes);
  }
  if (round) glDisable(GL_POINT_SMOOTH);
  if (!solid_line) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  }
  glColor3d(lines_color.redF(), lines_color.greenF(), lines_color.blueF());

  glLineWidth(line_width);
  glDrawElements(GL_LINES, count, GL_UNSIGNED_INT,
                 index_array);  // отрисовка линий
  if (!solid_line) glDisable(GL_LINE_STIPPLE);
  glDisableClientState(GL_VERTEX_ARRAY);

  free(vertex_array);
  free(index_array);
}

void OpenGL_Widget::mousePressEvent(QMouseEvent *event) {
  mouse_position = event->pos();
  last_x_rotation = x_rotation;
  last_y_rotation = y_rotation;
}

void OpenGL_Widget::mouseMoveEvent(QMouseEvent *event) {
  x_rotation =
      last_x_rotation +
      0.3 * (event->pos().y() -
             mouse_position.y());  // Вращение вокруг оси y при движении по x
  y_rotation = last_y_rotation + 0.3 * (event->pos().x() - mouse_position.x());
  update();
}

void OpenGL_Widget::scale_model(double scale) {
  for (unsigned int i = 1; i <= model.count_of_vertexes; i++) {
    model.matrix_3d.matrix[i][0] *= scale;
    model.matrix_3d.matrix[i][1] *= scale;
    model.matrix_3d.matrix[i][2] *= scale;
  }
  update();
}

void OpenGL_Widget::wheelEvent(QWheelEvent *event) {
  if (mem_allocated) {
    double scale = event->angleDelta().y() / 100;
    if (scale > 0) scale_model(1.1);
    if (scale < 0) scale_model(0.9);
  }
}

void OpenGL_Widget::destroy_model() {  // очищаем память
  if (mem_allocated) {
    move = false;
    if (model.matrix_3d.matrix != NULL) s21_remove_matrix(&model.matrix_3d);

    for (unsigned int i = 1; i <= model.count_of_facets; i++) {
      if (model.polygons[i].vertexes != NULL) free(model.polygons[i].vertexes);
    }

    if (model.polygons != NULL) free(model.polygons);

    mem_allocated = false;
  }
}
