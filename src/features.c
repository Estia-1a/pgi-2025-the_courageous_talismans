#include <estia-image.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
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

void second_line(char *source_path){
    unsigned char *data = NULL;
    int width=0, height=0, channel_count=0;
    int x = 0;
    int y = 1;
    int index = (y * width + x) + channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char r = data[index + 0];
    unsigned char g = data[index + 1];
    unsigned char b = data[index + 2];

    printf("second_line : %d, %d, %d\n", r, g, b);
    
}


void first_pixel (char *source_path){
    unsigned char *data = NULL;
    int width=0, height=0, channel=0;

    read_image_data(source_path, &data, &width, &height, &channel);

    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

    printf("first_pixel : %d, %d, %d\n", r, g, b);
    
}



void dimension (char *source_path) {
    int width, height, channel;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel);
        printf("dimention : %d, %d\n", width, height);

}

    void min_component(char *filename, char component) {
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

void rotate_cw(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);

    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            for(int c=0; c<n; c++){
                int index=(y*width+x)*n+c;
                int nouveau_x=x;
                int nouveau_y=height-1-y;
                int index2=(nouveau_x*height+nouveau_y)*n+c;
                nouvelle_image[index2]=data[index];
            }
            
        }
    }

    write_image_data("image_out.bmp", nouvelle_image, height, width);
    free(data);
    free(nouvelle_image);
}

void rotate_acw(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);

    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            for(int c=0; c<n; c++){
                int index=(y*width+x)*n+c;
                int nouveau_x=y;
                int nouveau_y=width-1-x;
                int index2=(nouveau_y*height+nouveau_x)*n+c;
                nouvelle_image[index2]=data[index];
            }
            
        }
    }

    write_image_data("image_out.bmp", nouvelle_image, height, width);
    free(data);
    free(nouvelle_image);
}


void mirror_horizontal(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);

    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            for(int c=0; c<n; c++){
                int index=(y*width+x)*n+c;
                int nouveau_index=(y*width+(width-1-x))*n+c;
                nouvelle_image[nouveau_index]=data[index];
            }
            
        }
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);

}

    void min_component(char *filename, char component) {
        unsigned char *data = NULL;
        int width = 0, height = 0, channel_count = 0;

        read_image_data(filename, &data, &width, &height, &channel_count);
        if (data == NULL) {
            fprintf(stderr, "Erreur : impossible de lire l'image %s\n", filename);
            return;
        }

        int min_value = 256; 
        int min_x = -1, min_y = -1;

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
                if (value < min_value) {
                    min_value = value;
                    min_x = x;
                    min_y = y;
                }
            }
        }

        if (min_value < 256)
            printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
}