#include "processing.hpp"

#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

void Processing::processFrame(const cv::Mat& src, cv::Mat& dst, int& framex, int& framey, int& ksize)
{
    src.copyTo(dst);

    //cv::Rect region(src.rows/4+ rand ()%100 , src.cols/4 + rand ()%100, rand()%100+50, rand()%100+50);

	framex += rand()%100; 
	framey += rand()%100; 
	ksize = (ksize + rand()%100) % 300;

	if (framex + ksize> src.rows) framex = rand()%50;
	if (framey + ksize> src.cols) framey = rand()%50;

	cv::Rect region(framex, framey, ksize, ksize);
    Mat roi = dst(region);

    const int kSize = 11;
    medianBlur(roi, roi, kSize);


    rectangle(dst, region, Scalar(255, 0, 0));
}
