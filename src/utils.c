#include <estia-image.h>
#include <stdio.h>
#include "utils.h"



pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    if (data == NULL) return NULL;
    if ( x>=width || y>=height) return NULL;

    int index = 3*(y*width+x); 

    return (pixelRGB *)&data[index];
}

