#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  
  if ( strncmp( configuration.command, "print_pixel", 12 ) == 0 ) {
    print_pixel(configuration.filenames[0], 45, 500);
  }
 
  if (strncmp(configuration.command, "tenth_pixel", 11) == 0) {
    tenth_pixel(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "first_pixel", 11) == 0) {
    first_pixel(configuration.filenames[0]); 
  }
  
  if (strncmp(configuration.command, "color_red", 10)==0){
    color_red(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "color_green", 10)==0){
    color_green(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "color_bleu", 10)==0){
    color_bleu(configuration.filenames[0]);
  }
  
  if (strncmp(configuration.command, "second_line", 8) == 0) {
    second_line(configuration.filenames[0]);
  }
  
  if (strncmp(configuration.command, "dimension", 9) == 0) {
    dimension(configuration.filenames[0]);
  }
  return 0;
}