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

void max_component(char *filename, char component) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(filename, &data, &width, &height, &channel_count);


    int max_value = -1;
    int max_x = -1, max_y = -1;

    int c_index = 0;
    if (component == 'R') c_index = 0;
    else if (component == 'G') c_index = 1;
    else if (component == 'B') c_index = 2;
    else {
        fprintf(stderr, "Composante invalide : %c (utiliser R, G ou B)\n", component);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
            if (channel_count < 3) continue; 

            int value = data[index + c_index];
            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }

    if (max_value >= 0)
        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
}