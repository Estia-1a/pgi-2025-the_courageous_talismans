#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void second_line (char *source_path){
    unsigned char *data = NULL;
    int width=0, height=0, channel=0;

    read_image_data(source_path, &data, &width, &height, &channel);

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