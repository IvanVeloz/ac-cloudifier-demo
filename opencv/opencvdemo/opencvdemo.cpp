#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <iostream>
#include "cv-gstreamer-pipeline.hpp"

int main()
{
    //pipeline parameters
    int capture_width = 640; //1280 ;
    int capture_height = 480; //720 ;
    int framerate = 15 ;
    int display_width = 640; //1280 ;
    int display_height = 480; //720 ;

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
