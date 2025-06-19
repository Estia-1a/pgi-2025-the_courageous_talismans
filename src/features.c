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
        printf("dimension : %d, %d\n", width, height);

}

void max_pixel (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    
    int sum_max = -1;
    int max_x = 0;
    int max_y= 0;

    for (int y =0; y < height; y++){
        for (int x =0; x < width; x++){
            pixelRGB *current_pixel = get_pixel(data, width, height, channel, x, y);

            if (current_pixel != NULL){
                int sum = (*current_pixel).r + (*current_pixel).g + (*current_pixel).b;
                
                if (sum > sum_max){
                    sum_max = sum;
                    max_x = x;
                    max_y = y;
                }
           }
        }
    }
    pixelRGB *final_pixel = get_pixel(data, width, height, channel, max_x, max_y);

    if (final_pixel != NULL){
        printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, (*final_pixel).r, (*final_pixel).g, (*final_pixel).b);
    }
    
    
}

void min_pixel (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    
    int sum_min = 766;
    int min_x = 0;
    int min_y= 0;

    for (int y =0; y < height; y++){
        for (int x =0; x < width; x++){
            pixelRGB *current_pixel = get_pixel(data, width, height, channel, x, y);

            if (current_pixel != NULL){
                int sum = (*current_pixel).r + (*current_pixel).g + (*current_pixel).b;
                
                if (sum < sum_min){
                    sum_min = sum;
                    min_x = x;
                    min_y = y;
                }
           }
        }
    }
    pixelRGB *final_pixel = get_pixel(data, width, height, channel, min_x, min_y);

    if (final_pixel != NULL){
        printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, (*final_pixel).r, (*final_pixel).g, (*final_pixel).b);
    }
    
    
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


void color_blue(const char *filename){
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

void max_component(char *source_path, char component){
    unsigned char *data = NULL;
    int width=0, height=0, channel_count=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);
        
    int component_index;
        if (component == 'R') {
        component_index = 0;
        } 
        else if (component == 'G') {
            component_index = 1;
        } 
        else if (component == 'B') {
            component_index = 2;
    } 

    int y;
    int x;

    int max_value = -1;
    int max_x = 0;
    int max_y = 0;

    for (y = 0; y<height; y++){
        for (x = 0; x < width; x++){
            int index;
            index = (y*width + x) * channel_count + component_index;

            int value;
            value = data[index];

            if (value > max_value){
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
    
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

    write_image_data("image_out.bmp", nouvelle_image, height, width);

}

void min_component(char *source_path, char component){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int component_index;
    if (component == 'R') {
        component_index = 0;
    } 
    else if (component == 'G') {
        component_index = 1;
    } 
    else if (component == 'B') {
        component_index = 2;
    }

    int x;
    int y;

    int min_value = 256;
    int min_x = 0;
    int min_y = 0;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index;
            index = (y * width + x) * channel_count + component_index;
            
            int value;
            value = data[index];

            if (value < min_value){
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
}

void mirror_vertical(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);

    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            for(int c=0; c<n; c++){
                int index=(y*width+x)*n+c;
                int nouveau_y=height-1-y;
                int nouveau_index=(nouveau_y*width+x)*n+c;
                nouvelle_image[nouveau_index]=data[index];
            }
            
        }
    }

    write_image_data("image_out.bmp", nouvelle_image, height, width);
}

void mirror_total(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);

    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            for(int c=0; c<n; c++){
                int index=(y*width+x)*n+c;
                int nouveau_x=width-1-x;
                int nouveau_y=height-1-y;
                int nouveau_index=(nouveau_y*width+nouveau_x)*n+c;
                nouvelle_image[nouveau_index]=data[index];
            }
            
        }
    }

    write_image_data("image_out.bmp", nouvelle_image, height, width);
}

void color_desaturate(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;

        unsigned char r = data[index+0];
        unsigned char g = data[index+1];
        unsigned char b = data[index+2];

        unsigned char min = (r<g ? (r<b ? r:b):(g<b ? g:b));
        unsigned char max = (r>g ? (r>b ? r:b):(g>b ? g:b));
        unsigned char couleur = (min+max)/2;
        if (n>0) nouvelle_image[index+0]=couleur;
        if (n>1) nouvelle_image[index+1]=couleur;
        if (n>2) nouvelle_image[index+2]=couleur;
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}

void scale_nearest (const char *filename, float scale){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    int nouvelle_largeur = scale*width;
    int nouvelle_hauteur = scale*height;
    unsigned char *nouvelle_image = malloc(nouvelle_largeur*nouvelle_hauteur*n);

    for (int y=0 ; y<nouvelle_hauteur ; y++){
        for (int x=0 ; x<nouvelle_largeur ; x++){
            int xx=x/scale;
            int yy=y/scale;
            if(xx>=width) xx=width-1;
            if(yy>=height) yy=height-1;

            int index = (yy*width+xx)*n;
            int nouvelle_index = (y*nouvelle_largeur+x)*n;

            for (int c=0 ; c<n ; c++){
                nouvelle_image[nouvelle_index+c]=data[index+c];
            }
        }
    }
    write_image_data("image_out.bmp", nouvelle_image, nouvelle_largeur, nouvelle_hauteur);

}

void stat_report(char *source_path) {
    FILE *file = fopen("report.txt", "w");
    
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    int som_max = -1; //somme max R+G+B donc on part d'une valeur qui ne sera que plus petit
    int max_x = 0;
    int max_y = 0;
    int R_max = 0;
    int G_max = 0; 
    int B_max = 0;


    int som_min = 256*3+1; //somme min R+G+B donc on part d'une valeur qui ne sera que plus grande
    int min_x = 0;
    int min_y = 0;
    int R_min = 0;
    int G_min = 0;
    int B_min = 0;


    int R_min_val = 255;
    int R_max_val = 0;
    int G_min_val = 255; 
    int G_max_val = 0;
    int B_min_val = 255;
    int B_max_val = 0;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index;
            index = (y * width + x) * 3;

            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];
 
            int som = R + G + B;
 
            if (som > som_max) {
                som_max = som;
                max_x = x;
                max_y = y;
                R_max = R;
                G_max = G;
                B_max = B;
            }
            if (som < som_min) {
                som_min = som;
                min_x = x;
                min_y = y;
                R_min = R;
                G_min = G;
                B_min = B;
            }
 
            if (R < R_min_val) R_min_val = R;
            if (R > R_max_val) R_max_val = R;
            if (G < G_min_val) G_min_val = G;
            if (G > G_max_val) G_max_val = G;
            if (B < B_min_val) B_min_val = B;
            if (B > B_max_val) B_max_val = B;
        }
    }
    fprintf(file, "max_pixel (%d, %d): %d, %d, %d\n\n", max_x, max_y, R_max, G_max, B_max);
    fprintf(file, "min_pixel (%d, %d): %d, %d, %d\n\n", min_x, min_y, R_min, G_min, B_min);
    fprintf(file, "max_component R: %d\n", R_max_val);
    fprintf(file, "max_component G: %d\n", G_max_val);
    fprintf(file, "max_component B: %d\n\n", B_max_val);
    fprintf(file, "min_component R: %d\n", R_min_val);
    fprintf(file, "min_component G: %d\n", G_min_val);
    fprintf(file, "min_component B: %d\n", B_min_val);
 
    fclose(file);

void scale_crop(const char *filename, int center_x, int center_y, int crop_w, int crop_h){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    
    unsigned char *nouvelle_image = malloc(crop_w*crop_h*n);

    int source_x = center_x - crop_w /2;
    int source_y = center_y - crop_h /2;

    for (int y=0; y<crop_h; y++){
        for(int x=0; x<crop_w; x++){
            int source_index = ((source_y+y) * width + (source_x+ x)) * n;
            int index=(y * crop_w + x) * n;

            for(int c=0; c<n; c++) {                 
                nouvelle_image[index+c]=data[source_index+c];
            }
        }
    }
    write_image_data("image_out.bmp", nouvelle_image, crop_w, crop_h);

}
    }