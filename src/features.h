#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void tenth_pixel(char *source_path);
void dimension(char *source_path);
void second_line(char *source_path);
void max_pixel(char *source_path);
void min_pixel(char *source_path);
void first_pixel (char *source_path);
void color_red (const char *filename);
void color_green (const char *filename);
void color_bleu (const char *filename);
void color_gray (const char *filename);
void color_invert (const char *filename);
void color_gray_luminance (const char *filename);
void max_component(char *source_path, char component);
void rotate_cw (const char *filename);
void mirror_horizontal (const char *filename);
void min_component(char*source_path, char component);
void stat_report(char *source_path);


#endif
