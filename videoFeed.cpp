#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

//#include<opencv2/highgui/highgui.hpp>

#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	// Create a VideoCapture object and open the input file
	// If the input is the web camera, pass 0 instead of the video file name
	VideoCapture cap("rtmp://192.168.0.100/live");
	//glutInit(&argc, argv);                 // Initialize GLUT
	//glutCreateWindow("Frame");
	//setOpenGlDrawCallback("Frame", on_opengl);

	// Check if camera opened successfully
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	//setOpenGlDrawCallback("Frame", on_opengl);
	while (1) {

		Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		// Display the resulting frame
		imshow("Frame", frame);

		// Press  ESC on keyboard to exit
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}
	// When everything done, release the video capture object
	cap.release();
	// Closes all the frames
	destroyAllWindows();

	return 0;
}
