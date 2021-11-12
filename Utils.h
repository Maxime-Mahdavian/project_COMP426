#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#include "Globals.h"

/* Utility functions */
void readKernelSourceFile(const char *filename, char *kernelSource, size_t *sourceLength);
void initGrid(grid_t grid[WIDTH * HEIGHT], int colors[WIDTH*HEIGHT], int num_of_colors, int generation);
void fillGrid(grid_t grid[WIDTH * HEIGHT]);
void showGrid(grid_t grid[WIDTH * HEIGHT]);
void showFailureMessage(const char *message);

#endif // UTILS_H
