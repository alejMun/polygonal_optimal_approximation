#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <iostream>
#include <cassert>

#include "utils.hpp"


cv::Mat change_bgr_to_hsv(const cv::Mat& img){
    CV_Assert(img.type() == CV_32FC3);

    cv::Mat out = img;

    cv::cvtColor(img, out, cv::COLOR_BGR2HSV);


    CV_Assert(out.type() == CV_32FC3);
    return out;
}

cv::Mat change_to_grayscale(const cv::Mat& img){
    CV_Assert(img.type() == CV_8UC3);

    cv::Mat out;

    img.convertTo(out, CV_32F, 1.0/255.0);
    out = change_bgr_to_hsv(out);

    std::vector<cv::Mat> channels;
    cv::split(out, channels);

    out = channels[2];

    CV_Assert(out.type() == CV_32F);
    return out;
}

cv::Mat create_lap_eight(){
    cv::Mat laplace = cv::Mat::ones(cv::Size(3,3), CV_32F);
    laplace.at<float>(1, 1) = -8.0f;

    return laplace;
}

void apply_border_filter(cv::Mat& img){
    cv::Mat filter = create_lap_eight();
    cv::filter2D(img, img, CV_32F, filter);

    cv::Mat mask;
    cv::threshold(img, mask, 1.0f, 255, cv::THRESH_BINARY);
    mask.convertTo(mask, CV_8U);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat contours_image = cv::Mat::zeros(mask.size(), CV_8UC3);

    cv::drawContours(contours_image, contours, -1, cv::Scalar(255, 255, 255), 1);

    img = contours_image;
}