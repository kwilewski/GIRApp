#include "CameraView.h"


void CameraView::SetCam1(cv::Mat image)
{
	cam1.cameraImage = image;
}

cv::Mat CameraView::GetCam1()
{
	return cam1.cameraImage;
}

void CameraView::SetCam2(cv::Mat image)
{
	cam2.cameraImage = image;
}

cv::Mat CameraView::GetCam2()
{
	return cam2.cameraImage;
}

void CameraView::SetCam3(cv::Mat image)
{
	cam3.cameraImage = image;
}

cv::Mat CameraView::GetCam3()
{
	return cam3.cameraImage;
}