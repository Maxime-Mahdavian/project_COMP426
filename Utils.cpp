#include "Utils.h"
#include <random>

void readKernelSourceFile(const char *filename, char *kernelSource, size_t *sourceLength)
{
    size_t fileSize;
    FILE *file;

    file = fopen(filename, "rb");
    if(file == NULL){
        printf("Error: Could not load kernel source file %s.\n", filename);
        return;
    }

    printf("Opened file...\n");

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    printf("Found file size: %d bytes\n", fileSize);

    kernelSource = (char *)malloc(fileSize);

    printf("Allocated memory...\n");

    if(kernelSource == NULL){
        printf("Error: Could not allocate memory for kernel file contents.\n");
        return;
    }

    if(fread(kernelSource, 1, fileSize, file) != fileSize)
    {
        printf("Closing file...\n");
        fclose(file);
        free(kernelSource);
        return;
    }

    fclose(file);
    *sourceLength = fileSize;
    kernelSource[fileSize] = '\0';

    printf("Kernel source file successfully read.\n");
}

void initGrid(grid_t grid[WIDTH * HEIGHT],int colors[WIDTH*HEIGHT], int num_of_colors, int generation)
{
    int pos;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(1, num_of_colors);

    for(pos=0; pos<WIDTH * HEIGHT; pos++){
        grid[pos] = DEAD;
			colors[pos] = uni(rng);
    }
}

void fillGrid(grid_t grid[WIDTH * HEIGHT])
{
    int pos, randomNumber;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(1,10);

    for(pos=0; pos<WIDTH * HEIGHT; pos++){
		randomNumber = uni(rng);
        if(randomNumber >= 9) grid[pos] = ALIVE;
    }
}

void showGrid(grid_t grid[WIDTH * HEIGHT])
{
    int i,j;
    for(i=0; i<WIDTH; i++){
        for(j=0; j<HEIGHT; j++){
            printf("%5d ", grid[j * HEIGHT + i]);
        }
        printf("\n");
    }
}

void showFailureMessage(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
