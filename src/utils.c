#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


pixelRGB *get_pixel(unsigned char *data, unsigned int width, unsigned int height, unsigned int n, unsigned int x, unsigned int y) {
    if (data == NULL) return NULL;
    if (x >= width || y >= height) return NULL;
    if (n < 3) return NULL; 

    int index = (y * width + x) * n;
    
    return (pixelRGB *) &data[index];
}

