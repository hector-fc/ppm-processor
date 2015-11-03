// img_manip.h
void build_img(char file[], Pixel img[MAX][MAX]);
void choice(Pixel img[w][h]);
void manip_ppm(char file[]);
void skip_comments();

// visual.h
void clr_screen();
void invalid_option(int type);
void menu();

// functions.h
void img_amp(char file[], int zoom, Pixel img[MAX][MAX]);
void img_blurring(Pixel img[w][h]);
void copy_img(Pixel origin[MAX][MAX], Pixel destiny[MAX][MAX]);
void img_grayscale(Pixel img[w][h]);
void img_high_relief(Pixel img[w][h]);
void img_info(Pixel img[w][h]);
void img_invert_h(Pixel img[w][h]);
void img_invert_v(Pixel img[w][h]);
void img_negative(Pixel img[w][h]);
void img_posterize(Pixel img[w][h]);
void img_red(char file[], int zoom, Pixel img[MAX][MAX]);
void img_rot_180(Pixel img[MAX][MAX]);
void img_rot_left(Pixel img[MAX][MAX]);
void img_rot_right(Pixel img[MAX][MAX]);
void img_sharpening(Pixel img[w][h]);
void img_thresholding(Pixel img[w][h]);
