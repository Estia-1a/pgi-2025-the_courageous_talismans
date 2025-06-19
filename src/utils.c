#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


pixelRGB *get_pixel(unsigned char *data, unsigned int width, unsigned int height, unsigned int n, unsigned int x, unsigned int y) {
    if (data == NULL) return NULL;
    if (x >= width || y >= height) return NULL;
    if (n < 3) return NULL; // on s'assure d'avoir R, G, B

    pixelRGB *pixel = malloc(sizeof(pixelRGB));
    if (!pixel) return NULL;

    int index = (y * width + x) * n;
    pixel->r = data[index];
    pixel->g = data[index + 1];
    pixel->b = data[index + 2];

    return pixel;
}

