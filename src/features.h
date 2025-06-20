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
void color_blue (const char *filename);
void color_gray (const char *filename);
void color_invert (const char *filename);
void color_gray_luminance (const char *filename);
void max_component(char *source_path, char component);
void min_component(char *source_path, char component);
void rotate_cw (const char *filename);
void mirror_horizontal (const char *filename);
void mirror_vertical (const char *filename);
void rotate_acw (const char *filename);
void mirror_total (const char *filename);
void color_desaturate (const char *filename);
void scale_nearest (const char *filename, float scale);
void print_pixel( char *filename, int x, int y );
#endif
