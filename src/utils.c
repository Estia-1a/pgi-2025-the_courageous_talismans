#include <estia-image.h>
#include <stdio.h>
#include "utils.h"



pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    if (data == NULL) return NULL;
    if ( x>=width || y>=height) return NULL;

    int index = 3*(y*width+x); 

    return (pixelRGB *)&data[index];
}

void print_pixel( char *filename, int x, int y ){
    unsigned char *data = NULL;
    int width=0, height=0, n=0;

    read_image_data(filename, &data, &width, &height, &n);

    pixelRGB *pixel = get_pixel(data, width, height, n, x, y);

    if (pixel == NULL){
        printf("Les coordonnees ne sont pas valides.\n");
    }
    else{
        printf("Pixel (%d, %d) : %d, %d, %d\n",x, y, (*pixel).r, (*pixel).g, (*pixel).b );
    }
}