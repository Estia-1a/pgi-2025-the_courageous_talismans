#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"


void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) == 0) {
        int index = 9 * channels;
        int r = data[index];
        int g = data[index + 1];
        int b = data[index + 2];
        printf("tenth_pixel: %d, %d, %d\n", r, g, b);
    } 
}
void helloWorld() {
    printf("Hello World !");
}
