#ifndef DEVICE_KERNELS_H
#define DEVICE_KERNELS_H

const char gameOfLife2[] =
"inline int getAliveNeighbours(__global int *input, int pos, int rowUp, int rowDown){                           \n"
"    int aliveNeighbours = input[rowUp-1] + input[rowUp] + input[rowUp+1];                                      \n"
"    aliveNeighbours += input[pos-1] + input[pos+1];                                                            \n"
"    aliveNeighbours += input[rowDown-1] + input[rowDown] + input[rowDown+1];                                   \n"
"    return aliveNeighbours;                                                                                    \n"
"}                                                                                                              \n"
"                                                                                                               \n"
"inline bool outOfBounds(int pos, int width, int height){                                                       \n"
"    return (pos < width) || (pos > (width * (height-1))) || (pos % width == 0) || (pos % width == width-1);    \n"
"}                                                                                                              \n"
"                                                                                                               \n"
"inline bool willLive(__global int *input, int pos, int aliveNeighbours){                                       \n"
"    return input[pos]==1 && (aliveNeighbours==3 || aliveNeighbours==2) ||                                      \n"
"           (input[pos]==0 && aliveNeighbours==3);                                                              \n"
"}                                                                                                              \n"
"                                                                                                               \n"
"__kernel void life(                                                                                            \n"
"   __global int* input,                                                                                        \n"
"   __global int* output,                                                                                       \n"
"   const unsigned int height,                                                                                  \n"
"   const unsigned int width)                                                                                   \n"
"{                                                                                                              \n"
"   int i = get_global_id(0);                                                                                   \n"
"   int rowUp = i - width;                                                                                      \n"
"   int rowDown = i + width;                                                                                    \n"
"   if (outOfBounds(i,width, height)){                                                                          \n"
"      output[i] = 0;                                                                                           \n"
"      return;                                                                                                  \n"
"   }                                                                                                           \n"
"   int aliveNeighbours = getAliveNeighbours(input, i, rowUp, rowDown);                                         \n"
"   if (willLive(input, i, aliveNeighbours)){                                                                   \n"
"       output[i] = 1;                                                                                          \n"
"   }                                                                                                           \n"
"   else {                                                                                                      \n"
"       output[i] = 0;                                                                                          \n"
"   }                                                                                                           \n"
"}                                                                                                              \n"
;
#endif // DEVICE_KERNELS_H
