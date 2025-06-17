#include <estia-image.h>
#include <stdio.h>
#include<stdlib.h>
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



void first_pixel (char *source_path){
    unsigned char *data = NULL;
    int width=0, height=0, channel_count=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

    printf("first_pixel : %d, %d, %d\n", r, g, b);
    
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


void color_red(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;
        if (n>0) nouvelle_image[index+0]=data[index+0];
        if (n>1) nouvelle_image[index+1]=0;
        if (n>2) nouvelle_image[index+2]=0;
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}


void color_green(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;
        if(n>0) nouvelle_image[index+0]=0;
        if(n>1) nouvelle_image[index+1]=data[index+1];
        if(n>2) nouvelle_image[index+2]=0;
    }

    write_image_data("image_out.bmp", nouvelle_image, width,height);
}


void color_bleu(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;
        if (n>0) nouvelle_image[index+0]=0;
        if (n>1) nouvelle_image[index+1]=0;
        if (n>2) nouvelle_image[index+2]=data[index+2];
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}

void color_gray(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;

        unsigned char gray = (data[index+0]+data[index+1]+data[index+2])/3;

        if (n>0) nouvelle_image[index+0]=gray;
        if (n>1) nouvelle_image[index+1]=gray;
        if (n>2) nouvelle_image[index+2]=gray;
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}

void color_invert(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;

        if (n>0) nouvelle_image[index+0]=255 - data[index+0];
        if (n>1) nouvelle_image[index+1]=255 - data[index+1];
        if (n>2) nouvelle_image[index+2]=255 - data[index+2];
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}

void color_gray_luminance(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;

        unsigned char gray_luminance = 0.21*data[index+0]+0.72*data[index+1]+0.07*data[index+2];

        if (n>0) nouvelle_image[index+0]=gray_luminance;
        if (n>1) nouvelle_image[index+1]=gray_luminance;
        if (n>2) nouvelle_image[index+2]=gray_luminance;
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}

void helloWorld() {
    printf("Hello World !");
}
