#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

#define V4L2_CTL_CMD "v4l2-ctl --set-ctrl power_line_frequency=2,auto_exposure=1,exposure_time_absolute=400"

int main()
{
	bool r;
	//int codec = cv::VideoWriter::fourcc('M','J','P','G');
	
	assert( std::system(V4L2_CTL_CMD) == 0);
	cv::VideoCapture cap(0, cv::CAP_V4L2);
	//assert( cap.set(cv::CAP_PROP_FOURCC, codec) == true);
	assert( cap.set(cv::CAP_PROP_FPS, 15) == true );
	assert( cap.set(cv::CAP_PROP_EXPOSURE, 400) == true);
	assert( cap.set(cv::CAP_PROP_FRAME_WIDTH, 2592) == true);
	assert( cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1944) == true);
	
	if(!cap.isOpened()) {
		std::cerr << "Unable to open camera!\n";
		return -1;
	}
	
	cv::Mat frame;
	r = cap.read(frame);
	
	if(r == false) {
		std::cerr << "Could not get the frame" << std::endl;
	}
	else {
		cv::imwrite("test.jpg", frame);
	}
	
	return 0;
}
