#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include <QColorDialog>
#include <QDir>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QWheelEvent>
#include <QWidget>

extern "C" {
#include "../affine/affine.h"
#include "../lib_matrix/s21_matrix.h"
#include "../obj_files_management/obj_files_management.h"
}

namespace Ui {
class OpenGL_Widget;
}

class OpenGL_Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  OpenGL_Widget(QWidget *parent = nullptr);
  ~OpenGL_Widget();
  void draw_model();
  void file_preprocessing();
  void scale_model(double scale);
  void center_model();
  void destroy_model();
  double *vertex_array;
  int *index_array;
  bool move = false;
  bool round = true, without_points = false, solid_line = true;
  int point_size = 1, line_width = 1;
  bool mem_allocated = false;
  bool default_projection = true;
  QColor background, lines_color, points_color;
  double max_x, min_x, max_y, min_y, max_z, min_z, center_x, center_y, center_z;
  QString file;
  obj_data model;

 private:
  Ui::OpenGL_Widget *ui;

  double x_rotation = 0, y_rotation = 0, last_x_rotation, last_y_rotation;
  QPoint mouse_position;

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent *event);

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
};

#endif  // OPENGL_WIDGET_H
