#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
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
void color_red(const char *filename){
    unsigned char *data = NULL;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *nouvelle_image = malloc(width*height*n);

    for (int i=0; i<width*height; i++){
        int index=i*n;
        nouvelle_image[index+0]=data[index+0];
        if (n>1) nouvelle_image[index+1]=0;
        if (n>2) nouvelle_image[index+2]=0;
        
    }

    write_image_data("image_out.bmp", nouvelle_image, width, height);
}