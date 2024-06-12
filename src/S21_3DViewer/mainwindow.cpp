#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3D Viewer");
  ui->lineEdit_point_size->setPlaceholderText("Enter point size");
  ui->lineEdit_line_width->setPlaceholderText("Enter line width");
  ui->lineEdit_rotate_x->setPlaceholderText("Enter angle");
  ui->lineEdit_rotate_y->setPlaceholderText("Enter angle");
  ui->lineEdit_rotate_z->setPlaceholderText("Enter angle");
  ui->lineEdit_scale->setPlaceholderText("Enter scale");
  ui->lineEdit_x->setPlaceholderText("Enter distance");
  ui->lineEdit_y->setPlaceholderText("Enter distance");
  ui->lineEdit_z->setPlaceholderText("Enter distance");

  QDoubleValidator *double_validator = new QDoubleValidator(this);
  QList<QLineEdit *> lineEdits = {
      ui->lineEdit_line_width, ui->lineEdit_point_size, ui->lineEdit_x,
      ui->lineEdit_y,          ui->lineEdit_z,          ui->lineEdit_scale,
      ui->lineEdit_rotate_x,   ui->lineEdit_rotate_y,   ui->lineEdit_rotate_z};

  for (auto lineEdit : lineEdits) lineEdit->setValidator(double_validator);

  ui->widget_opengl->lines_color = QColor("#8B8B8B");
  ui->widget_opengl->points_color = QColor("#1B484B");
  ui->widget_opengl->background = QColor("#E8E8E8");

  ui->radioButton_solid_line->setChecked(true);
  ui->radioButton_round_points->setChecked(true);
  ui->radioButton_ortho->setChecked(true);

  QString file = "settings";
  QFileInfo fileInfo(file);
  if (fileInfo.exists()) read_settings();
}

MainWindow::~MainWindow() {
  ui->widget_opengl->destroy_model();
  write_settings();
  delete ui;
}

void MainWindow::on_pushButton_Load_obj_file_clicked() {
  QString file =
      QFileDialog::getOpenFileName(this, "Open .obj file", "", "(*.obj)", 0,
                                   QFileDialog::DontUseNativeDialog);
  ui->widget_opengl->file = file;
  if (!file.isEmpty()) {
    ui->widget_opengl->file_preprocessing();  // Парсим файл в opengl_widget.cpp
    if (ui->widget_opengl->mem_allocated) {
      QStringList arr = file.split("/");
      QString filename = arr.last();
      ui->filename_label->setText(filename);
      ui->label_vertexes->setText(
          QString::number(ui->widget_opengl->model.count_of_vertexes));
      ui->label_edges->setText(
          QString::number(ui->widget_opengl->model.count_of_facets * 3));
      ui->widget_opengl->update();
    } else {
      QMessageBox::warning(this, "", "Invalid .obj file");
      ui->widget_opengl->destroy_model();
      ui->widget_opengl->update();
      ui->filename_label->setText("");
      ui->label_vertexes->setText("");
      ui->label_edges->setText("");
    }
  } else
    QMessageBox::warning(this, "", "Select .obj file");
}

void MainWindow::on_pushButton_scale_clicked() {
  affine_transformation(ui->lineEdit_scale, 4, 1, "scale");
}

void MainWindow::on_pushButton_right_x_clicked() {
  affine_transformation(ui->lineEdit_x, 2, 1, "distance");
}

void MainWindow::on_pushButton_left_x_clicked() {
  affine_transformation(ui->lineEdit_x, 2, -1, "distance");
}

void MainWindow::on_pushButton_up_y_clicked() {
  affine_transformation(ui->lineEdit_y, 1, 1, "distance");
}

void MainWindow::on_pushButton_down_y_clicked() {
  affine_transformation(ui->lineEdit_y, 1, -1, "distance");
}

void MainWindow::on_pushButton_forward_z_clicked() {
  affine_transformation(ui->lineEdit_z, 3, 1, "distance");
}

void MainWindow::on_pushButton_backward_z_clicked() {
  affine_transformation(ui->lineEdit_z, 3, -1, "distance");
}

void MainWindow::on_radioButton_ortho_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->default_projection = true;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_radioButton_frustum_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->default_projection = false;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_pushButton_rotate_x_right_clicked() {
  affine_transformation(ui->lineEdit_rotate_x, 5, 1, "angle");
}

void MainWindow::on_pushButton_rotate_x_left_clicked() {
  affine_transformation(ui->lineEdit_rotate_x, 5, -1, "angle");
}

void MainWindow::on_pushButton_rotate_y_right_clicked() {
  affine_transformation(ui->lineEdit_rotate_y, 6, 1, "angle");
}

void MainWindow::on_pushButton_rotate_y_left_clicked() {
  affine_transformation(ui->lineEdit_rotate_y, 6, -1, "angle");
}

void MainWindow::on_pushButton_rotate_z_right_clicked() {
  affine_transformation(ui->lineEdit_rotate_z, 7, 1, "angle");
}

void MainWindow::on_pushButton_rotate_z_left_clicked() {
  affine_transformation(ui->lineEdit_rotate_z, 7, -1, "angle");
}

bool MainWindow::check_input(QLineEdit *lineEdit, QString error_message) {
  if (lineEdit->text().isEmpty()) {
    QMessageBox::warning(this, "", error_message);
    return false;
  }
  return true;
}

void MainWindow::affine_transformation(QLineEdit *lineEdit, int button_id,
                                       int sign, QString error_message) {
  if (ui->widget_opengl->mem_allocated) {
    if (check_input(lineEdit, "Enter the " + error_message)) {
      double n = lineEdit->text().toDouble() * sign;
      switch (button_id) {
        case 1:
          affine_moveY(&ui->widget_opengl->model, n);
          ui->widget_opengl->move = true;
          break;
        case 2:
          affine_moveX(&ui->widget_opengl->model, n);
          ui->widget_opengl->move = true;
          break;
        case 3:
          affine_moveZ(&ui->widget_opengl->model, n);
          ui->widget_opengl->move = true;
          break;
        case 4:
          if (n > 0)
            affine_scale(&ui->widget_opengl->model, n);
          else
            QMessageBox::warning(this, "", "Scale should be positive");
          break;
        case 5:
          affine_rotateX(&ui->widget_opengl->model, n);
          break;
        case 6:
          affine_rotateY(&ui->widget_opengl->model, n);
          break;
        case 7:
          affine_rotateZ(&ui->widget_opengl->model, n);
          break;
        default:
          break;
      }
      ui->widget_opengl->update();
    }
  } else
    QMessageBox::warning(this, "", "Open the file first");
}

void MainWindow::on_radioButton_round_points_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->round = true;
    ui->widget_opengl->without_points = false;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_radioButton_square_points_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->round = false;
    ui->widget_opengl->without_points = false;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_radioButton_without_points_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->without_points = true;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_lineEdit_point_size_returnPressed() {
  ui->widget_opengl->point_size = ui->lineEdit_point_size->text().toInt();
  ui->widget_opengl->update();
}

void MainWindow::on_radioButton_solid_line_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->solid_line = true;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_radioButton_dotted_line_clicked(bool checked) {
  if (checked) {
    ui->widget_opengl->solid_line = false;
    ui->widget_opengl->update();
  }
}

void MainWindow::on_lineEdit_line_width_returnPressed() {
  ui->widget_opengl->line_width = ui->lineEdit_line_width->text().toInt();
  ui->widget_opengl->update();
}

void MainWindow::on_pushButton_line_color_clicked() {
  QColor lines_color =
      QColorDialog::getColor(Qt::green, this, "Choose lines color");
  if (lines_color.isValid()) ui->widget_opengl->lines_color = lines_color;
  ui->widget_opengl->update();
}

void MainWindow::on_pushButton_point_color_clicked() {
  QColor points_color =
      QColorDialog::getColor(Qt::blue, this, "Choose points color");
  if (points_color.isValid()) ui->widget_opengl->points_color = points_color;
  ui->widget_opengl->update();
}

void MainWindow::on_pushButton_background_color_clicked() {
  QColor background_color =
      QColorDialog::getColor(Qt::black, this, "Choose background color");
  if (background_color.isValid())
    ui->widget_opengl->background = background_color;
  ui->widget_opengl->update();
}

void MainWindow::on_pushButton_screenshot_clicked() {
  QString file = QFileDialog::getSaveFileName(0, "Save screenshot", "",
                                              tr("Images (*.jpeg *.bmp)"));
  if (!ui->widget_opengl->grab().save(file))
    QMessageBox::warning(this, "", "Enter file name and format");
}

void MainWindow::write_settings() {
  QSettings settings("settings", QSettings::IniFormat);
  settings.beginGroup("MainWindow");
  settings.setValue("geometry", saveGeometry());
  settings.endGroup();

  settings.beginGroup("Points");
  if (ui->radioButton_round_points->isChecked()) {
    ui->widget_opengl->round = true;
    ui->widget_opengl->without_points = false;
  } else if (ui->radioButton_square_points->isChecked()) {
    ui->widget_opengl->round = false;
    ui->widget_opengl->without_points = false;
  } else if (ui->radioButton_without_points->isChecked()) {
    ui->widget_opengl->without_points = true;
    ui->widget_opengl->round = false;
  }
  settings.setValue("round_points", ui->widget_opengl->round);
  settings.setValue("without_points", ui->widget_opengl->without_points);

  settings.setValue("points_color", ui->widget_opengl->points_color);
  settings.setValue("points_size", ui->widget_opengl->point_size);
  settings.endGroup();

  settings.beginGroup("Lines");

  if (ui->radioButton_solid_line->isChecked())
    ui->widget_opengl->solid_line = true;
  else if (ui->radioButton_dotted_line->isChecked())
    ui->widget_opengl->solid_line = false;
  settings.setValue("solid_line", ui->widget_opengl->solid_line);

  settings.setValue("lines_color", ui->widget_opengl->lines_color);
  settings.setValue("line_width", ui->widget_opengl->line_width);
  settings.endGroup();

  settings.beginGroup("Background");
  settings.setValue("background_color", ui->widget_opengl->background);
  settings.endGroup();

  settings.beginGroup("Projection");

  if (ui->radioButton_ortho->isChecked())
    ui->widget_opengl->default_projection = true;
  else
    ui->widget_opengl->default_projection = false;
  settings.setValue("projection", ui->widget_opengl->default_projection);
  settings.endGroup();
}

void MainWindow::read_settings() {
  QSettings settings("settings", QSettings::IniFormat);
  settings.beginGroup("MainWindow");
  restoreGeometry(settings.value("geometry").toByteArray());
  settings.endGroup();

  settings.beginGroup("Points");

  if (settings.value("round_points") == true) {
    ui->radioButton_round_points->setChecked(true);
    ui->widget_opengl->round = true;
  } else if (settings.value("without_points") == true) {
    ui->radioButton_without_points->setChecked(true);
    ui->widget_opengl->without_points = true;
  } else {
    ui->radioButton_square_points->setChecked(true);
    ui->widget_opengl->round = false;
  }

  ui->widget_opengl->points_color = settings.value("points_color").toString();
  ui->widget_opengl->point_size = settings.value("points_size").toInt();
  ui->lineEdit_point_size->setText(
      QString::number(ui->widget_opengl->point_size));
  settings.endGroup();

  settings.beginGroup("Lines");

  if (settings.value("solid_line") == true) {
    ui->radioButton_solid_line->setChecked(true);
    ui->widget_opengl->solid_line = true;
  } else {
    ui->radioButton_dotted_line->setChecked(true);
    ui->widget_opengl->solid_line = false;
  }
  ui->widget_opengl->lines_color = settings.value("lines_color").toString();
  ui->widget_opengl->line_width = settings.value("line_width").toInt();
  ui->lineEdit_line_width->setText(
      QString::number(ui->widget_opengl->line_width));
  settings.endGroup();

  settings.beginGroup("Background");
  ui->widget_opengl->background = settings.value("background_color").toString();
  settings.endGroup();

  settings.beginGroup("Projection");
  if (settings.value("projection") == true) {
    ui->radioButton_ortho->setChecked(true);
    ui->widget_opengl->default_projection = true;
  } else {
    ui->radioButton_frustum->setChecked(true);
    ui->widget_opengl->default_projection = false;
  }
  settings.endGroup();
}
