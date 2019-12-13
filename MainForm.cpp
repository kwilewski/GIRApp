#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace cv;


vector<CameraDevice> cameraVector;
CameraView mCameraView;
SensorStorage mSensorStorage;

void Main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GIRApp::MainForm form;
	Application::Run(%form);

}


namespace GIRApp {
	void MainForm::SetImage1()
	{
		
		Mat image;
		int id = 0;
		string wantedName = "Chicony USB 2.0 Camera";
		id = GetCameraID(cameraVector, wantedName);
		VideoCapture video(id);
		int fps = 30;

		if (!video.isOpened())
		{
			printf("cannot connect to camera ");
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam1(image);
				DrawCVImage(cameraBox1, image);
				//Thread::Sleep(1 / fps);
			}
		}
		/*
		CameraView c1;
		Mat image;
		while (1)
		{
			image = c1.GetCam1();
			DrawCVImage(cameraBox1, image);
		}*/


	}
	void MainForm::SetImage2()
	{
		Mat image;
		int id = 3;
		string wantedName = "e2eSoft iVCam";
		id = GetCameraID(cameraVector, wantedName);
		VideoCapture video(id);
		int fps = 30;
		if (!video.isOpened())
		{
			printf("cannot connect to camera ");
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam2(image);
				AddText(image);
				DrawCVImage(cameraBox2, image);
				//Thread::Sleep(1 / fps);
			}
		}

	}
	void MainForm::SetImage3()
	{
		Mat image;
		int id = 2;
		VideoCapture video(id);
		int fps = 30;
		if (!video.isOpened())
		{
			printf("cannot connect to camera ");
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam3(image);
				DrawCVImage(cameraBox3, image);
				//Thread::Sleep(1 / fps);
			}
		}

	}

	cv::Mat MainForm::AddText(cv::Mat image)
	{
		SensorData mData = mSensorStorage.getSensorData();
		string text = string("First sensor: ") + to_string(mData.data1) + string("\nSecond sensor: ") + to_string(mData.data2);
		cv::putText(image, text, cv::Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255),  1.5);
		return image;
	}

	void MainForm::DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
	{
		try
		{
			System::Drawing::Graphics^ graphics = control->CreateGraphics();
			System::IntPtr ptr(colorImage.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			graphics->DrawImage(b, rect);
			delete graphics;
		}
		catch (string obj)
		{

		}
	}

	void MainForm::SetStartUp()
	{
		cameraVector = ListDevices();
		cameraVector = SortDevices(cameraVector);
		th1->Start();
		th2->Start();
		th3->Start();

	}

	


	vector<CameraDevice> MainForm::ListDevices()
	{

		DeviceEnumerator de;
		// Audio Devices
		std::vector<CameraDevice> devices = de.GetCameraDevices();
		// Print information about the devices
		return devices;
	}

	vector<CameraDevice> MainForm::SortDevices(vector<CameraDevice> deviceList)
	{
		vector<CameraDevice> rootList;
		vector<CameraDevice> nonRootList;
		vector<CameraDevice> retList;
		string findString = "root";
		string path;

		for (auto x : deviceList)
		{
			path = x.devicePath;
			size_t found = path.find(findString);
			if (found != string::npos)
			{
				rootList.push_back(x);
			}
			else
			{
				nonRootList.push_back(x);
			}
		}
		retList.insert(retList.begin(), nonRootList.begin(), nonRootList.end());
		retList.insert(retList.end(), rootList.begin(), rootList.end());

		int c = 0;
		for (auto x : retList)
		{
			x.id = c;
			c++;
		}

		return retList;
	}




	int MainForm::GetCameraID(vector<CameraDevice> cameraVector, string name)
	{
		int retID = -1;
		System::String^ wn = gcnew System::String(name.c_str());
		for (auto x : cameraVector)
		{
			System::String^ dn = gcnew System::String(x.deviceName.c_str());
			if (name.compare(x.deviceName) == 0)
			{
				retID = x.id;
				continue;
			}
		}
		return retID;
	}

	void MainForm::SaveImages()
	{
		cv::Mat img1 = mCameraView.GetCam1();
		cv::Mat img2 = mCameraView.GetCam2();
		cv::Mat img3 = mCameraView.GetCam3();
		string path = "C:/GIRApp/";
		bool bDir = CreateDirectory(L"C:/GIRApp/", NULL);
		cv::imwrite(path + "img1.jpg", img1);
		cv::imwrite(path + "img2.jpg", img2);
		cv::imwrite(path + "img3.jpg", img3);
	}




	//------------------------------------		Buttons and UI		---------------------------------------------

	void MainForm::closeButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		th1->Abort();
		th2->Abort();
		th3->Abort();
		Application::Exit();
	}

	void MainForm::forwardButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//forward function
	}

	void MainForm::leftButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//left function
	}

	void MainForm::rightButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//right function
	}

	void MainForm::backwardButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//back function
	}

	void MainForm::ssButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveImages();
	}





}//end of namespace GIRApp












