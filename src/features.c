#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"

void tenth_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width=0, height=0, channel_count=0;

    int x = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (x != 0) {
        int r = data[27];
        int g = data[28];
        int b = data[29];

        printf("tenth_pixel: %d, %d, %d\n", r, g, b);
    }
    else {
        printf("Erreur read_image_data");
    }
}

void helloWorld() {
    printf("Hello World !");
}

void second_line (char *source_path){
    unsigned char *data = NULL;
    int width=0, height=0, channel_count=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

    printf("second_line : %d, %d, %d\n", r, g, b);
    
}
void dimension (char *source_path) {
    int width, height, channel;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel);
        printf("dimention : %d, %d\n", width, height);

}

void min_component(char *source_path, char component){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int component_index;
    if (component == 'R') {
        component_index = 0;
    } else if (component == 'G') {
        component_index = 1;
    } else if (component == 'B') {
        component_index = 2;
    }

    int x;
    int y;

    int min_value = 256;
    int min_x = 0;
    int min_y = 0;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count + component_index;
            int value = data[index];