#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <iostream>

int main()
{

	cv::VideoCapture cap("udp://127.0.0.1:5000",cv::CAP_FFMPEG);
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
