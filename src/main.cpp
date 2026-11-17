#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>
#include <iostream>

#include "utils.hpp"

int main() {
    cv::Mat image = cv::imread("../data/dog.jpg");

    if(image.empty()){
        std::cerr << "Unable to load data/dog.jpg\n";
        return 1;
    }

    image = change_to_grayscale(image);

    apply_border_filter(image);

    cv::imshow("Poligono con OpenCV", image);
    cv::waitKey(0);

    return 0;
}
