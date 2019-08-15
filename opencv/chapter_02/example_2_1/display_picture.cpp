// a simple OpenCV program that loads an 
// image for every supported OpenCV function

// inlucde file for every supported OpenCV function
#include <opencv2/opencv.hpp>   

int main(int argc, char **argv){
    cv::Mat img = cv::imread(argv[1], -1);
    if(argc < 2){
        fprintf(stdout, "usage: %s <picture>\n", argv[0]);
    }
    if(img.empty()){
        return -1;
    }

    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;

}
