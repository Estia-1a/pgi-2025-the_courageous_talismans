# Daily Evaluation 18/06 - 15:34:54
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 18/23 :  78%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                           | Stdout                            |
| :---------- | :---------- | :--------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| dimension   | 4/4 :  100% |                                                                                                                        |                                   |
| first_pixel | 5/5 :  100% |                                                                                                                        |                                   |
| tenth_pixel | 5/5 :  100% |                                                                                                                        |                                   |
| second_line | 4/5 :  80%  | Second line First Pixel 21 22 23                                                                                       | second_line : 32, 32, 32          |
| print_pixel | 0/4 :  0%   | Print Pixel (0,0) : 0,0,0<br>Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0 | Pixel (0, 0) : 0, 0, 0<br>Pixel … |

# Milestone  statistiques
Score : 8/26 :  30%
## Detail by Feature
| Feature         | Score       | Missed tests                                                                          | Stdout                                                     |
| :-------------- | :---------- | :------------------------------------------------------------------------------------ | :--------------------------------------------------------- |
| max_pixel       | 4/4 :  100% |                                                                                       |                                                            |
| min_pixel       | 4/4 :  100% |                                                                                       |                                                            |
| min_component R | 0/3 :  0%   | Min Component R of black 8x8<br>Min Component R of white 8x8<br>Min Component 2 0 5   | <br><br>                                                   |
| min_component G | 0/3 :  0%   | Min Component G of black 8x8<br>Min Component G of white 8x8<br>Min Component 2 0 5   | <br><br>                                                   |
| min_component B | 0/3 :  0%   | Min Component B of black 8x8<br>Min Component B of white 8x8<br>Min Component 2 0 5   | <br><br>                                                   |
| max_component R | 0/3 :  0%   | Max Component R of black 8x8<br>Max Component R of white 8x8<br>Max Component 2 0 255 | max_component R (0, 0): 0                                  |
                                                                                                                          max_component G (0, 0): 0                                   
                                                                                                                          max_component B (0, 0): 0<br>max…                           
                                                                                                                          max_component G (0, 0): 255                                 
                                                                                                                          max_component B (0, 0): 255<br>max_component R (2, 0): 250  
                                                                                                                          max_component G (1, 0): 255                                 
                                                                                                                          max_component B (1, 0): 255                                 
| max_component G | 0/3 :  0%   | Max Component G of black 8x8<br>Max Component G of white 8x8<br>Max Component 2 0 255 | max_component R (0, 0): 0                                  |
                                                                                                                          max_component G (0, 0): 0                                   
                                                                                                                          max_component B (0, 0): 0<br>max…                           
                                                                                                                          max_component G (0, 0): 255                                 
                                                                                                                          max_component B (0, 0): 255<br>max_component R (1, 0): 255  
                                                                                                                          max_component G (2, 0): 250                                 
                                                                                                                          max_component B (1, 0): 255                                 
| max_component B | 0/3 :  0%   | Max Component B of black 8x8<br>Max Component B of white 8x8<br>Max Component 2 0 255 | max_component R (0, 0): 0                                  |
                                                                                                                          max_component G (0, 0): 0                                   
                                                                                                                          max_component B (0, 0): 0<br>max…                           
                                                                                                                          max_component G (0, 0): 255                                 
                                                                                                                          max_component B (0, 0): 255<br>max_component R (1, 0): 255  
                                                                                                                          max_component G (1, 0): 255                                 
                                                                                                                          max_component B (2, 0): 250                                 

# Milestone  colors
Score : 35/35 :  100%
## Detail by Feature
| Feature              | Score       | Missed tests | Stdout |
| :------------------- | :---------- | :----------- | :----- |
| color_red            | 5/5 :  100% |              |        |
| color_blue           | 5/5 :  100% |              |        |
| color_green          | 5/5 :  100% |              |        |
| color_gray           | 5/5 :  100% |              |        |
| color_invert         | 5/5 :  100% |              |        |
| color_gray_luminance | 5/5 :  100% |              |        |
| color_desaturate     | 5/5 :  100% |              |        |

# Milestone  transform
Score : 7/15 :  46%
## Detail by Feature
| Feature           | Score       | Missed tests                            | Stdout |
| :---------------- | :---------- | :-------------------------------------- | :----- |
| rotate_cw         | 1/3 :  33%  | rotate large image<br>rotate high image | <br>   |
| rotate_acw        | 3/3 :  100% |                                         |        |
| mirror_horizontal | 1/3 :  33%  | mirror large image<br>mirror high image | <br>   |
| mirror_vertical   | 1/3 :  33%  | mirror large image<br>mirror high image | <br>   |
| mirror_total      | 1/3 :  33%  | mirror large image<br>mirror high image | <br>   |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

