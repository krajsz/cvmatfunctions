#include "cvmatfunctions.h"


cvMatFunctions::cvMatFunctions()
{
}

cvMatFunctions::~cvMatFunctions()
{
}

cv::Mat cvMatFunctions::bwlabel(const cv::Mat &image)
{

}

cv::Mat cvMatFunctions::entim(const cv::Mat &image)
{

}

cv::Mat cvMatFunctions::im2bw(const cv::Mat &image,const float_t& level)
{
    cv::Mat ret;

    cv::threshold(image, ret, level, 255, cv::THRESH_BINARY);

    return ret;
}

cv::Mat cvMatFunctions::medfilt2(const cv::Mat &image, const int &ksize)
{
    cv::Mat ret = image.clone();
    if ((ksize > 0))
    {
        cv::medianBlur(image, ret, ksize);
    }
    return ret;
}

cv::Mat cvMatFunctions::xOr(const cv::Mat &imageOne, const cv::Mat &imageTwo)
{
    cv::Mat ret;
    cv::bitwise_xor(imageOne, imageTwo, ret);
    return ret;
}

cv::Mat cvMatFunctions::adapthisteq(const cv::Mat &imgage)
{
    cv::Mat ret;
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->setClipLimit(4.0);

    clahe->apply(imgage, ret);

    return ret;
}

double_t cvMatFunctions::entropy(const cv::Mat &image)
{
    return 0;
}

double_t cvMatFunctions::graythresh(const cv::Mat &image)
{
    cv::Mat tmp;
    return cv::threshold(image, image.clone(), 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU );
}

void cvMatFunctions::size(const cv::Mat &image, Sizei size, int depth)
{
    size.setWidth(image.rows);
    size.setHeight(image.cols) ;
    depth = image.depth();
}

void cvMatFunctions::bwmorphErode(cv::Mat &image, const int times)
{
    cv::Mat ret;

    int erosion_size = 6;
    cv::Mat element = getStructuringElement(cv::MORPH_CROSS,
                                            cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                                            cv::Point(erosion_size, erosion_size) );
    cv::erode(image, ret, element, cv::Point(-1,-1), times );
}

cv::Mat cvMatFunctions::imresize(const cv::Mat &image, const Sizei &size)
{
    cv::Mat ret = cv::Mat::zeros(size.getCWidth(), size.getCHeight(), image.type());

    if (size.isValid())
    {
        cv::resize(image, ret, cv::Size(size.getCWidth(), size.getCHeight()));
    }
    else
    {
        std::cout << "Invalid size on imresize!" << std::endl;
    }
    return ret;
}

double_t cvMatFunctions::max(const cv::Mat &image)
{
    double max { 0 };

    cv::minMaxLoc(image, nullptr, &max);

    return max;
}

double_t cvMatFunctions::sum(const cv::Mat &image)
{
    return cv::sum(image)[0];
}

cv::Point cvMatFunctions::find(const cv::Mat& image, const float_t& value, bool firstOrLast)
{
    uint8_t* pixel_ptr = static_cast<uint8_t*>(image.data);
    cv::Scalar_<uint8_t> pixel;
    cv::Point ret {0 , 0};
    if (firstOrLast)
    {
        for (int i = 0; i < image.rows; ++i)
        {
            for (int j = 0; j < image.cols; ++j)
            {
                pixel.val[0] = pixel_ptr[i * image.cols * image.channels() + j * image.channels()];

                if (pixel.val[0] == value)
                {
                    ret.x = i;
                    break;
                }
            }
        }

        for (int i = 0; i < image.rows; ++i)
        {
            for (int j = 0; j < image.cols; ++j)
            {
                pixel.val[0] = pixel_ptr[i * image.cols * image.channels() + j * image.channels()];

                if (pixel.val[0] == value)
                {
                    ret.y = j;
                    break;
                }
            }
        }
    }
    else
    {

        for (int i = image.rows-1; i >=0; --i)
        {
            for (int j =  image.cols-1; j >= 0; --j)
            {
                pixel.val[0] = pixel_ptr[i * image.cols * image.channels() + j * image.channels()];

                if (pixel.val[0] == value)
                {
                    ret.x = i;
                    break;
                }
            }
        }

        for (int i = image.rows-1; i >= 0; --i)
        {
            for (int j = image.cols-1; j >= 0; --j)
            {
                pixel.val[0] = pixel_ptr[i * image.cols * image.channels() + j * image.channels()];

                if (pixel.val[0] == value)
                {
                    ret.y = j;
                    break;
                }
            }
        }
    }

    return ret;
}
