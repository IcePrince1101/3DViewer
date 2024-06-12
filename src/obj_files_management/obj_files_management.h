/*!
 * \mainpage
 * \authors camillec, raffordg, pickledl
 * \version 1.0
 *
 * \section intro_sec 3d viewer
 * This application has been developed with:
 * 1. C language
 * 2. C++
 * 3. QT framework
 * 4. Doxygen
 *
 * \section brief_sec Brief
 * This application has been developed to view .obj files.
 */
/*!
 * @file obj_files_management.h
 * @brief    This file contains functions for parsing of the .obj file and
 * describes the structures used in the code
 */
#ifndef OBJ_FILES_MANAGEMENT_H
#define OBJ_FILES_MANAGEMENT_H

// #define  _POSIX_C_SOURCE 200809L // заклятие для поиска getline
#define _GNU_SOURCE

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib_matrix/s21_matrix.h"

/*!
 * @brief This struct describes polygon in .obj file
 * @param int *vertexes - list with indexes of vertexes
 * @param int numbers_of_vertexes_in_facets - count of vertexes
 */
typedef struct polygon_t {
  int *vertexes;
  int numbers_of_vertexes_in_facets;
} polygon_t;

/*! @brief This struct describes data from .obj file
 * @param unsigned int count_of_vertexes - count of vertexes
 * @param unsigned int count_of_facets - count of facets
 * @param matrix_t matrix_3d - matrix with vertexes
 * @param polygon_t *polygons - list with polygons
 */
typedef struct data {
  unsigned int count_of_vertexes;
  unsigned int count_of_facets;
  matrix_t matrix_3d;
  polygon_t *polygons;
} obj_data;

/*!
 * @brief This function parses .obj file
 * @param char *filename - name of .obj file
 * @param obj_data *data - struct for data from .obj file
 * @return 0 - success
 * @return 1 - error
 */
int parseFile(char *filename, obj_data *data);

/*! @brief This function counts vertexes and facets and writes them into data
 * structure
 * @param FILE *file - pointer to file
 * @param obj_data *data - struct for data from .obj file
 */
void countVertexesAndFacets(FILE *file, obj_data *data);

/*!
 * @brief This function allocates memory for vertex-matrix and polygons in data
 * structure
 * @param obj_data *data - struct for data from .obj file
 * @return 0 - success
 * @return 1 - error
 */
int allocateMemory(obj_data *data);

/*!
 * @brief This function parses vertexes and facets
 * @param FILE *file - pointer to file
 * @param obj_data *data - struct for data from .obj file
 * @return 0 - success
 * @return 1 - error
 */
int parseVertexesAndFacets(FILE *file, obj_data *data);

/*!
 * @brief This function parses vertexes
 * @param char *buffer - string with vertex
 * @param obj_data *data - struct for data from .obj file
 * @param int vertex_number - number of vertex
 * @return 0 - success
 * @return 1 - error
 */
int parseVertex(char *buffer, obj_data *data, int vertex_number);

/*!
 * @brief This function parses facets
 * @param char *buffer - string with facet
 * @param obj_data *data - struct for data from .obj file
 * @param int facet_number - number of facet
 * @return 0 - success
 * @return 1 - error
 */
int parseFacet(char *buffer, obj_data *data, int facet_number);

void printData(obj_data *data);
void printVertexes(obj_data *data);
void printFacets(obj_data *data);

void removeEndSpaces(char *str);
#endif