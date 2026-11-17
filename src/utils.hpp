#pragma once

#include <opencv2/core.hpp>

cv::Mat change_bgr_to_hsv(const cv::Mat& img);
cv::Mat change_to_grayscale(const cv::Mat& img);

cv::Mat create_lap_eight();

void apply_border_filter(cv::Mat& img);