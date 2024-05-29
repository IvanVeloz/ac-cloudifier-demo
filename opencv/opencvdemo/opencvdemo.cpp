#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <iostream>
#include "cv-gstreamer-pipeline.hpp"

int main()
{
    //pipeline parameters
    int capture_width = 2304;
    int capture_height = 1296;
    int framerate = 56 ;
    int display_width = 2304;
    int display_height = 1296;

    //reset frame average
    std::string pipeline = gstreamer_pipeline(capture_width, capture_height, framerate,
                                              display_width, display_height);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n\n\n";

	cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
	if(!cap.isOpened()) {
		std::cerr << "Unable to open camera!\n";
		return -1;
	}
	cv::Mat frame;
	cap.read(frame);
	//Mat save_img; cap >> save_img;
	if(frame.empty()) {
		std::cerr << "Could not get the frame" << std::endl;
	}
	else {
		cv::imwrite("test.jpg", frame);
	}
	return 0;
}
