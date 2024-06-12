#include "affine.h"

// * @brief this function describes motions of the object on x axis
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double x - bias
void affine_moveX(obj_data *data, double x) {
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    data->matrix_3d.matrix[i][0] += x;
  }
}

// * @brief this function describes motions of the object on y axis
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double y - bias
void affine_moveY(obj_data *data, double y) {
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    data->matrix_3d.matrix[i][1] += y;
  }
}

// * * @brief this function describes motions of the object on z axis
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double z - bias
void affine_moveZ(obj_data *data, double z) {
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    data->matrix_3d.matrix[i][2] += z;
  }
}

// * @brief this function describes rotation of the object around x axis. It
// transforms angles into radians.
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double angle - angle
void affine_rotateX(obj_data *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    double y = data->matrix_3d.matrix[i][1];
    double z = data->matrix_3d.matrix[i][2];
    data->matrix_3d.matrix[i][1] = y * cos(angle) + z * sin(angle);
    data->matrix_3d.matrix[i][2] = z * cos(angle) - y * sin(angle);
  }
}

// * @brief this function describes rotation of the object around y axis. It
// transforms angles into radians.
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double angle - angle
void affine_rotateY(obj_data *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    double x = data->matrix_3d.matrix[i][0];
    double z = data->matrix_3d.matrix[i][2];
    data->matrix_3d.matrix[i][0] = x * cos(angle) + z * sin(angle);
    data->matrix_3d.matrix[i][2] = z * cos(angle) - x * sin(angle);
  }
}

// * @brief this function describes rotation of the object around z axis. It
// transforms angles into radians.
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double angle - angle
void affine_rotateZ(obj_data *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    double x = data->matrix_3d.matrix[i][0];
    double y = data->matrix_3d.matrix[i][1];
    data->matrix_3d.matrix[i][0] = x * cos(angle) + y * sin(angle);
    data->matrix_3d.matrix[i][1] = y * cos(angle) - x * sin(angle);
  }
}

// * @brief this function describes scaling of the object and checks for
// non-zero coefficient.
// * @params: obj_data *data - struct for data from .obj file (for matrix with
// vertexes)
// *          double k - coefficient
void affine_scale(obj_data *data, double k) {
  if (k > 0) {
    for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
      data->matrix_3d.matrix[i][0] *= k;
      data->matrix_3d.matrix[i][1] *= k;
      data->matrix_3d.matrix[i][2] *= k;
    }
  } else
    printf("Error: scale to point (with zero coefficient).\n");
}
