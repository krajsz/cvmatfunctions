#ifndef CVMATFUNCTIONS_H
#define CVMATFUNCTIONS_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <omp.h>
#include <array>
#include <limits>
#include "coordinate.h"
#include "size.h"


using Pixel = cv::Point3_<uint8_t>;

class cvMatFunctions
{
public:
    cvMatFunctions();

    void bwmorphErode(cv::Mat& image, const int& times = 1);
    void size(const cv::Mat& image, Size& size, int& depth = 0);

    cv::Mat imresize(const cv::Mat& image, const Size& size);
    cv::Mat im2bw(const cv::Mat& image,const float_t& level);
    cv::Mat entim(const cv::Mat& image);
    cv::Mat medfilt2(const cv::Mat& image, const int& ksize);
    cv::Mat bwlabel(const cv::Mat& image);
    cv::Mat xOr(const cv::Mat& imageOne, const cv::Mat& imageTwo);
    cv::Mat adapthisteq(const cv::Mat& imgage);

    double_t entropy(const cv::Mat& image);
    double_t graythresh(const cv::Mat &image);

    double_t sum(const cv::Mat& image);
    double_t max(const cv::Mat& image);

    cv::Point find(const cv::Mat& image, const float_t& value, bool firstOrLast = true);

private:

};


#endif // CVMATFUNCTIONS_H
