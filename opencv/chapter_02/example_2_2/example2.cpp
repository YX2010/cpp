// A simple OpenCV program that loads an image from disk and displays it on the screen
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stdout, "usage: %s <pictrue>\n", argv[0]);
    }
    Mat img = imread(argv[1], -1);
    if(img.empty()){
        return -1;
    }
    namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    imshow("Example1", img);
    waitKey(0);

    destroyWindow("Example1");
    
}