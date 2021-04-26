
#include <opencv2/opencv.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace cv;


int err(String message) {
	cout << message << endl;
	return (1);
}

int main() {

	VideoCapture cam(0); //Camera
	if (!cam.isOpened())
		return err("Cannot open Webcam");
	//create GUI windows
	namedWindow("Cam");
	Mat cam_frame;

	int keyboard = 0; //input from keyboard
	bool condition = true;
	int start = 0;
	int _sleep = 60;
	int _waitKey = 30;
	float _wait5sec = 5*1000 / (_sleep + _waitKey);
	while ((char)keyboard != 'q' && (char)keyboard != 27) {
		cam >> cam_frame;

		if (cam_frame.empty())
			break;

		//resize(cam_frame, cam_frame, { 747, 560 }, 0, 0, 1);
		if (condition) {
			flip(cam_frame, cam_frame, 1);
		}
		imshow("Cam", cam_frame);

		if (start >= _wait5sec) {
			condition = !condition;
		}
		start++;
		Sleep(_sleep);
		keyboard = waitKey(_waitKey);
	}
	//destroy GUI windows
	destroyAllWindows();
	return EXIT_SUCCESS;
}
