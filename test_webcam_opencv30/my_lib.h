#ifndef MY_LIB_H
#define MY_LIB_H
#include "opencv2/opencv.hpp"
#include <math.h>
// includes CUDA
#include <cuda_runtime.h>
using namespace cv;

Mat seuillage(Mat frame);
 Mat contours(Mat frame);
Mat NoiretBlanc(Mat frame);

Mat median(Mat frame);






#endif
