/*!
 * @file   affine.h
 * @brief    This file contains functions which describe affine transformations
 */
#ifndef AFFINE_H
#define AFFINE_H

#include "../obj_files_management/obj_files_management.h"

/// This set of functions describes shifting of the vertexes upon x, y, z axis
/*! @brief this function describes motions of the object on x axis
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double x - bias
*/
void affine_moveX(obj_data *data, double x);
/*! @brief this function describes motions of the object on y axis
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double y - bias
*/
void affine_moveY(obj_data *data, double y);

/*! @brief this function describes motions of the object on z axis
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double z - bias
*/
void affine_moveZ(obj_data *data, double z);

/// This set of functions describes rotation of the vertexes upon x, y, z axis
/*! @brief this function describes rotation of the object around x axis. It
   transforms angles into radians.
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double angle - angle
*/
void affine_rotateX(obj_data *data, double angle);
/*! @brief this function describes rotation of the object around y axis. It
   transforms angles into radians.
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double angle - angle
*/
void affine_rotateY(obj_data *data, double angle);

/*! @brief this function describes rotation of the object around z axis. It
   transforms angles into radians.
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double angle - angle
*/
void affine_rotateZ(obj_data *data, double angle);

/// This set of functions describes scaling of x, y, z coordiantes of vertexes
/*! @brief this function describes scaling of the object and checks for non-zero
   coefficient.
    @param obj_data *data - struct for data from .obj file (for matrix with
   vertexes)
    @param double k - coefficient
*/
void affine_scale(obj_data *data, double x);

#endif