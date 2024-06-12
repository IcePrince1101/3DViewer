#include "obj_files_management.h"

int parseFile(char *filename, obj_data *data) {
  // * Check for NULL pointers
  if (filename == NULL || data == NULL) {
    printf("Filename or data are NULL\n");
    return 1;
  }
  data->count_of_facets = 0;
  data->count_of_vertexes = 0;
  FILE *file = fopen(filename, "r");
  // * Check for existence of file
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  countVertexesAndFacets(file, data);
  if (data->count_of_facets == 0 || data->count_of_vertexes == 0) return 1;
  int status = allocateMemory(data);
  if (status != 0) return status;
  fseek(file, 0, SEEK_SET);
  status = parseVertexesAndFacets(file, data);
  fclose(file);
  if (status != 0) printf("ERROR: Invalid .obj file!\n");
  return status;
}

void countVertexesAndFacets(FILE *file, obj_data *data) {
  char *buffer = NULL;
  size_t len = 0;

  while (getline(&buffer, &len, file) != EOF) {
    if (strncmp(buffer, "v ", 2) == 0)
      data->count_of_vertexes++;
    else if (strncmp(buffer, "f ", 2) == 0)
      data->count_of_facets++;
  }
  free(buffer);
}

int allocateMemory(obj_data *data) {
  // * allocate memory for matrix
  int status =
      s21_create_matrix(data->count_of_vertexes + 1, 3, &data->matrix_3d);
  // * allocate memory for array of polygons
  if (status == 0) {
    data->polygons = (polygon_t *)malloc(sizeof(polygon_t) * (data->count_of_facets + 1));
  }
  // ? maybe set default data->polygon->numbers_of_vertexes_in_facets = -1.
  // ? we can use it for easy freeing memory in errors case
  // * check for success
  if (data->polygons == NULL || data->matrix_3d.matrix == NULL || status > 0) {
    s21_remove_matrix(&data->matrix_3d);
    status = 1;
  }
  return status;
}

int parseVertexesAndFacets(FILE *file, obj_data *data) {
  char *buffer = NULL;  // for each string in file
  size_t len = 0;       // temp variable
  int status = 0;
  int vertex_number = 1, facet_number = 1;
  while (getline(&buffer, &len, file) != EOF) {
    removeEndSpaces(buffer);
    if (strncmp(buffer, "v ", 2) == 0) {
      status = status == 1 ? 1 : parseVertex(buffer, data, vertex_number);
      vertex_number++;
    } else if (strncmp(buffer, "f ", 2) == 0) {
      status = status == 1 ? 1 : parseFacet(buffer, data, facet_number);
      facet_number++;
    }
    // ? else printf("WARNING: Unknown instruction: %s", buffer);
  }
  free(buffer);
  return status;
}

int parseVertex(char *buffer, obj_data *data, int vertex_number) {
  char *ptr_x, *ptr_y, *ptr_z;
  char *token = strtok(buffer, " ");
  token = strtok(NULL, " ");
  double x = strtod(token, &ptr_x);
  // * check for errors
  if (strlen(ptr_x) != 0) return 1;
  token = strtok(NULL, " ");
  double y = strtod(token, &ptr_y);
  // * check for errors
  if (strlen(ptr_y) != 0) return 1;
  token = strtok(NULL, " ");
  double z = strtod(token, &ptr_z);
  // * check for errors
  if (strcmp(ptr_z, "\n") != 0) return 1;
  // * add vertex to matrix
  data->matrix_3d.matrix[vertex_number][0] = x;
  data->matrix_3d.matrix[vertex_number][1] = y;
  data->matrix_3d.matrix[vertex_number][2] = z;
  return 0;
}

int parseFacet(char *buffer, obj_data *data, int facet_number) {
  int vertex = 0, count_of_vertexes = 0;
  // * create new string for counting vertexes
  char tmp_str[strlen(buffer) + 1];
  strcpy(tmp_str, buffer);
  // * count vertexes in facet
  char *token = strtok(tmp_str, " ");
  while (token != NULL) {
    count_of_vertexes++;
    token = strtok(NULL, " ");
  }
  if (--count_of_vertexes < 3) return 1;
  // * allocate memory for new facet
  data->polygons[facet_number].numbers_of_vertexes_in_facets = count_of_vertexes;
  // ? -1 because first Token is "f"
  data->polygons[facet_number].vertexes = (int *)malloc(sizeof(int) * count_of_vertexes);
  // * parse facet
  token = strtok(buffer, " ");
  token = strtok(NULL, " ");
  while (token != NULL) {
    data->polygons[facet_number].vertexes[vertex++] = atoi(token);
    token = strtok(NULL, " ");
  }
  // ! ERROR: if f-string have vertex on index 100 (when we have only 10 strings
  // ! in file, for example) we must see error. Do check this case?
  return 0;
}

// ======= viewing =======
void printData(obj_data *data) {
  printf("count of vertexes: %d\n", data->count_of_vertexes);
  printf("count of facets: %d\n", data->count_of_facets);
  printf("matrix_3d:\n");
  printVertexes(data);
  printf("polygons:\n");
  printFacets(data);
}

void printVertexes(obj_data *data) {
  printf("index x y z\n");
  for (unsigned int i = 1; i <= data->count_of_vertexes; i++) {
    printf("%d %f %f %f\n", i, data->matrix_3d.matrix[i][0],
           data->matrix_3d.matrix[i][1], data->matrix_3d.matrix[i][2]);
  }
}

void printFacets(obj_data *data) {
  for (unsigned int i = 1; i <= data->count_of_facets; i++) {
    for (int j = 0; j < data->polygons[i].numbers_of_vertexes_in_facets; j++) {
      printf("%d ", data->polygons[i].vertexes[j]);
    }
    printf("\n");
  }
}

void removeEndSpaces(char *str) {
  while (str[strlen(str) - 1] == ' ' || str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }
  str[strlen(str)] = '\n';
}
