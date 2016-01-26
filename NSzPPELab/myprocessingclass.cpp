#include "myprocessingclass.h"

MyProcessingClass::MyProcessingClass() : m_window_size(Sizei(800, 600))
{
    std::set_terminate(terminate_handler);
}

MyProcessingClass::~MyProcessingClass()
{
}

void MyProcessingClass::tests()
{
    Coordinate<int> c(2,3);

    std::cout <<c.toString() ;
    c.setFirst(5);
    c.setSecond(7);

    std::cout << c.toString();
    Sizei s(1,2);

    std::cout << s.toString();

    OpticDisc od(Coordinate<int> (6,7),8);

    std::cout << od.toString();

}

void MyProcessingClass::terminate_handler()
{
    std::cout << "Error, something happened. /*copyright 2015, win10 install*/" << std::endl;
    std::abort();
}

void MyProcessingClass::read(const std::string &fileName)
{
    m_window_name = "Test - " + fileName;
    m_input_image = cv::imread(fileName);
    if (m_input_image.empty())
    {
        m_is_input_empty = true;
        std::cout << "Input image is empty!" << endl;
        std::terminate();
    }
}

void MyProcessingClass::show()
{
    int key { -1 };
    if (!m_is_input_empty)
    {
        while( (key = cv::waitKey(30) & 0xFF))
        {
            if (key == 27)
            {
                cv::destroyWindow(m_window_name);
                break;
            }
            cv::imshow(m_window_name, m_input_image);
        }
    }
    else
    {
        std::cout << "Failed to show the image, it's empty!" << std::endl;
        std::terminate();
    }
}

cv::Mat& MyProcessingClass::getInput()
{
    return this->m_input_image;
}

const cv::Mat& MyProcessingClass::getCInput() const
{
    return this->m_input_image;
}

void MyProcessingClass::ResizeImage()
{
    /*
     * *
     * function [newIm,zoom]=ResizeImage(Im,oldSizeOfROI,newSizeOfROI)

    zoom = newSizeOfROI/oldSizeOfROI;
    [height,width,deep] = size(Im);

    newIm = imresize(Im,[height*zoom width*zoom]);
end
     */
    float zoom = m_new_size_of_roi / m_old_size_of_roi;

    size(m_input_image, m_image_size, m_image_depth);
    m_input_image = imresize(m_input_image,Sizei(m_input_image.size().height * zoom, m_input_image.size().width * zoom));
}


void MyProcessingClass::PreProcessingToEntropy()
{

    /*
     *
     * function [preProcessed_Im] = PreProcessingToEntropy(image,size)

    red = double(image(:,:,1));
    green = double(image(:,:,2));
    blue = double(image(:,:,3));

    I = uint8((double(red) + double(green) + double(blue))/3);

    %to use a medfilter
    medfilt_I = medfilt2(I,[size size]);

    %use a CLAHE
    preProcessed_Im = adapthisteq(medfilt_I(:,:));

     * */
    std::vector<cv::Mat> image_channels(3);

    cv::split(m_input_image, image_channels);

    m_red_channel = image_channels.at(0);
    m_green_channel = image_channels.at(1);
    m_blue_channel = image_channels.at(2);


    cv::Mat for_median_filter = (m_red_channel + m_green_channel + m_blue_channel) / 3.0;

    cv::medianBlur(for_median_filter, for_median_filter, m_median_filet_kernel_size);

    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->setClipLimit(4.0);

    clahe->apply(for_median_filter, pre_processed_image);
}


void MyProcessingClass::DiameterOfRoi()
{
    /**
    *
    * function [ROI,D]=DiameterOfROI(I)

    R = I(:,:,1);

    %ROI segmentation
    ROI = medfilt2(R,[7 7]);
    [level EM] = graythresh(ROI);
    ROI = im2bw(ROI,level/10);
    ROI = bwmorph(ROI,'erode',3);

    [x1,y1] = find(ROI,1,'first');
    [x2,y2] = find(ROI,1,'last');

    D = y2-y1;

end
    */
    cv::medianBlur(m_red_channel, m_roi, m_median_filet_kernel_size+ 2);

    double threshold_value = cv::threshold(m_roi, m_roi, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::threshold(m_roi, m_roi, threshold_value, 255, CV_THRESH_BINARY);

    m_roi = medfilt2(m_red_channel, 7);
    m_roi = im2bw(m_roi, graythresh(m_roi) / 10.0);

    bwmorphErode(m_roi, 3);

    int y1 {-1};
    int y2 {-1};

    cv::Point p{-1, -1 };
    p = find(m_roi, 255);
    y1 = p.y;

    p = find(m_roi, 255, false);
    y2 = p.y;

    if ( (y1 != -1) && (y2 != -1))
    {
        m_optic_disc.setDiameter( y2 - y1);
    }
    else
    {
        std::cout << "Diameter of roi couldn't be determined!" << std::endl;
        std::terminate();
    }
}

void MyProcessingClass::EntropyOfImage()
{
    /*
     *
     * function [entIm] = EntropyOfImage(image, windSize)

    [height, width] = size(image);
    entIm(1:height,1:width) = 0;

    for i=windSize+1:height-windSize
        for j=windSize+1:width-windSize

            window = image(i-windSize:i+windSize,j-windSize:j+windSize);
            entIm(i,j) = entropy(window);

        end
    end
     */

    cv::Mat entIm = cv::Mat::zeros(m_input_image.rows, m_input_image.cols, m_input_image.type());



}

void MyProcessingClass::LocalizeOpticDisc()
{
    /*
 *
 * function [bw] = LocalizeOpticDisc(entIm)

    MAX = max(max(entIm));
    level = graythresh(int16(entIm(entIm > 0)*10000));
    level = level * MAX;

    BW = entIm > level;

    L = bwlabel(BW, 8);

    N = max(max(L));

    Feature(1:N,1:4) = 0;
    for i=1:N

        BW = L == i;
        Feature(i,1) = sum(sum(BW));

        BW = xor(BW,bwmorph(BW,'erode'));
        Feature(i,2) = sum(sum(BW));

        Feature(i,3) = ((4 * pi * Feature(i,1)) / (Feature(i,2)^2));
        Feature(i,4) = Feature(i,1) * Feature(i,3);
    end

    [val,ind] = max(Feature(:,4));

    bw = L == ind;
 */
    double max = 0;
    cv::max(max, m_ent_im);


}

void MyProcessingClass::GetOD_Coordinates()
{
    /*
 *
 * function [X,Y,R] = GetOD_Coordinates(bw)

    R = 0;
    while sum(sum(bw)) > 0
        tmp = bw;
        bw = bwmorph(bw,'erode');
        R = R + 1;
    end

    [X,Y] = find(tmp,1);
 */


    cv::Mat tmp;
    while (cv::sum(m_bw).val[0] > 0)
    {
        tmp = m_bw;
        cv::erode(m_bw, m_bw, cv::Mat());
        m_optic_disc.setDiameter(m_optic_disc.getDiameter()+1);
        //++m_optic_disc_diameter;
    }

}

void MyProcessingClass::MainEntropy()
{
    /*
 * function [X,Y,R,BW] = MainEntropy(image)

    [ROI,D] = DiameterOfROI(image);

    [newIm,zoom]=ResizeImage(image,D,630);

    [newIm] = PreProcessingToEntropy(newIm,5);

    [entIm] = EntropyOfImage(newIm, 45);

    [bw] = LocalizeOpticDisc(entIm);

    [X,Y,R] = GetOD_Coordinates(bw);

    X = int16(X / zoom);
    Y = int16(Y / zoom);
    R = int16(R / zoom);
    [BW]=ResizeImage(bw,630,D);

 *
 * */
}

void MyProcessingClass::main_final_ENTROPY_ODC()
{
    /*
     *
     * function main_final_ENTROPY_ODC(inputIm,outputTXT)

        image = imread(inputIm);

        [ODx,ODy,R,BW]=MainEntropy(image);

%        image(ODx-3:ODx+3,ODy-3:ODy+3,:) = 0;
%        imwrite(image,[outputTXT '1.png']);

%        imwrite(BW,[outputTXT '2.png']);

        fid = fopen(outputTXT, 'w');
        fprintf(fid, '%d  %d  %d\n', int16(ODy),int16(ODx),R);
        fclose(fid);

     *
     * */
}

