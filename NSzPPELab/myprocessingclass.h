#ifndef MYPROCESSINGCLASS_H
#define MYPROCESSINGCLASS_H

#include "opticdisc.h"
#include "cvmatfunctions.h"

#include <exception>

using std::endl;


class MyProcessingClass : public cvMatFunctions
{
public:
    MyProcessingClass();
    ~MyProcessingClass();

    void read(const std::string& fileName);
    void show();

    void tests();
private:
    void PreProcessingToEntropy();
    cv::Mat ResizeImage();
    void DiameterOfRoi();
    void EntropyOfImage();
    void LocalizeOpticDisc();
    void GetOD_Coordinates();
    void MainEntropy();
    void main_final_ENTROPY_ODC();

    static void terminate_handler();

    cv::Mat m_input_image;
    cv::Mat m_output_image;

    cv::Mat m_red_channel;
    cv::Mat m_green_channel;
    cv::Mat m_blue_channel;

    cv::Mat m_roi;
    cv::Mat m_ent_im;
    cv::Mat m_bw;

    cv::Mat pre_processed_image;

    int m_median_filet_kernel_size = 5;

    bool m_is_input_empty = false;

    std::string m_window_name = "Test";

    OpticDisc m_optic_disc;
    Sizei m_image_size;

    int m_image_depth;
    float m_old_size_of_roi;
    float m_new_size_of_roi;


};

#endif // MYPROCESSINGCLASS_H
