#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "opengl_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QString filepath;
  void write_settings();
  void read_settings();

 private slots:

  void on_pushButton_Load_obj_file_clicked();
  void on_pushButton_scale_clicked();
  void on_pushButton_right_x_clicked();
  void on_pushButton_up_y_clicked();
  void on_pushButton_down_y_clicked();
  void on_pushButton_forward_z_clicked();
  void on_pushButton_backward_z_clicked();
  void on_pushButton_left_x_clicked();
  void on_pushButton_rotate_x_right_clicked();
  void on_pushButton_rotate_x_left_clicked();
  void on_pushButton_rotate_y_right_clicked();
  void on_pushButton_rotate_y_left_clicked();
  void on_pushButton_rotate_z_right_clicked();
  void on_pushButton_rotate_z_left_clicked();
  void on_radioButton_ortho_clicked(bool checked);
  void on_radioButton_frustum_clicked(bool checked);
  void on_radioButton_round_points_clicked(bool checked);
  void on_radioButton_square_points_clicked(bool checked);
  void on_radioButton_without_points_clicked(bool checked);
  void on_lineEdit_point_size_returnPressed();
  void on_radioButton_solid_line_clicked(bool checked);
  void on_radioButton_dotted_line_clicked(bool checked);
  void on_lineEdit_line_width_returnPressed();
  void on_pushButton_line_color_clicked();
  void on_pushButton_point_color_clicked();
  void on_pushButton_background_color_clicked();
  void on_pushButton_screenshot_clicked();

 private:
  Ui::MainWindow *ui;
  OpenGL_Widget *openGLWidget;
  bool check_input(QLineEdit *lineEdit, QString error_message);
  void affine_transformation(QLineEdit *lineEdit, int button_id, int sign,
                             QString error_message);
};
#endif  // MAINWINDOW_H
