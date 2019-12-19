#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace System::Threading;

struct MyCamera {
	cv::Mat cameraImage;
	int id;
};

class CameraView {

public:
	CameraView() = default;
	void SetCam1(cv::Mat image);
	cv::Mat GetCam1();
	void SetCam2(cv::Mat image);
	cv::Mat GetCam2();
	void SetCam3(cv::Mat image);
	cv::Mat GetCam3();
	void SetCam4(cv::Mat image);
	cv::Mat GetCam4();
	void SetSelectedCamera(int camera);
	int GetSelectedCamera();


private:
	MyCamera cam1;
	MyCamera cam2;
	MyCamera cam3;
	MyCamera cam4;
	int selectedCamera = 1;

};