#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace cv;


vector<CameraDevice> cameraVector;
CameraView mCameraView;
SensorStorage mSensorStorage;


void Main()														//uruchomienie interfejsu graficznego
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GIRApp::MainForm form;
	Application::Run(%form);

}


namespace GIRApp {

	//ponizsze 4 metody obsluguja obraz
	void MainForm::SetImage1()
	{
		Mat image;												//Obraz z kamery
		Mat imageWText;											//Obraz z tekstem
		int id = -1;											//id kamery, -1 bo nie ma takiego id a cos trzeba podac do konstruktora VideoCapture
		//string wantedName = "Chicony USB 2.0 Camera";
		//string wantedName = "e2eSoft iVCam";
		string wantedName = "&3faa14&";							//Serial number wybranej kamery
		id = GetCameraID(cameraVector, wantedName);				//Ustawienie ID
		VideoCapture video(id);									//inicjalizacja VideoCapture
		int fps = 30;											//fps dla poprway wydajnosci
		int selectedCamera;										//kamera na duzym ekranie

		if (!video.isOpened())									//jezeli nie polaczy z kamera
		{
			printf("cannot connect to camera ");
			cameraBox1->Image = Image::FromFile("graphics/no_camera_icon.png");		//wyswietlanie ikony braku kamery
			Mat noCam = imread("graphics/no_camera_icon.png");
			mCameraView.SetCam1(noCam);
		}
		else													//jezeli polaczy z kamera
		{
			while (1)											//obraz pobierany w petli
			{
				video >> image;									//aktualizacja image
				mCameraView.SetCam1(image);						//aktualizacja obrazu w CameraView
				DrawCVImage(cameraBox1, image);					//rysowanie obrazu w odpowiednim boxie
				selectedCamera = mCameraView.GetSelectedCamera();	//numer kamery na duzym ekranie
				if (selectedCamera == 1)						//jezeli ta kamera jest na duzym ekranie to wyswietl ja
				{
					imageWText = AddText(image);
					DrawCVImage(bigCameraBox, imageWText);
				}
				Thread::Sleep(1 / fps);							//sleep dla V-sync i poprawy wydajnosci
			}
		}


	}
	void MainForm::SetImage2()
	{
		Mat image;
		Mat imageWText;
		int id = -1;
		//string wantedName = "Chicony USB 2.0 Camera";
		string wantedName = "nie&272c2bc4&";
		id = GetCameraID(cameraVector, wantedName);
		VideoCapture video(id);
		int fps = 30;
		int selectedCamera;
		if (!video.isOpened())
		{
			cameraBox2->Image = Image::FromFile("graphics/no_camera_icon.png");
			Mat noCam = imread("graphics/no_camera_icon.png");
			mCameraView.SetCam2(noCam);
			printf("cannot connect to camera ");
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam2(image);
				DrawCVImage(cameraBox2, image);
				selectedCamera = mCameraView.GetSelectedCamera();
				if (selectedCamera == 2)
				{
					imageWText = AddText(image);
					DrawCVImage(bigCameraBox, imageWText);
				}
				Thread::Sleep(1 / fps);
			}
		}

	}
	void MainForm::SetImage3()
	{
		Mat image;
		Mat imageWText;
		int id = -1;
		//string wantedName = "LifeCam";
		string wantedName = "nieusb#vid_04f2&pid_b5a7&";
		id = GetCameraID(cameraVector, wantedName);
		VideoCapture video(id);
		int fps = 30;
		int selectedCamera;
		if (!video.isOpened())
		{
			printf("cannot connect to camera ");
			cameraBox3->Image = Image::FromFile("graphics/no_camera_icon.png");
			Mat noCam = imread("graphics/no_camera_icon.png");
			mCameraView.SetCam3(noCam);
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam3(image);
				DrawCVImage(cameraBox3, image);
				selectedCamera = mCameraView.GetSelectedCamera();
				if (selectedCamera == 3)
				{
					imageWText = AddText(image);
					DrawCVImage(bigCameraBox, imageWText);
				}
				Thread::Sleep(1 / fps);
			}
		}

	}
	void MainForm::SetImage4()
	{
		Mat image;
		Mat imageWText;
		int id = -1;
		//string wantedName = "LifeCam";
		string wantedName = "&272c2bc4&";
		id = GetCameraID(cameraVector, wantedName);
		VideoCapture video(id);
		int fps = 30;
		int selectedCamera;
		if (!video.isOpened())
		{
			printf("cannot connect to camera ");
			cameraBox4->Image = Image::FromFile("graphics/no_camera_icon.png");
			Mat noCam = imread("graphics/no_camera_icon.png");
			mCameraView.SetCam4(noCam);
		}
		else
		{
			while (1)
			{
				video >> image;
				mCameraView.SetCam4(image);
				DrawCVImage(cameraBox4, image);
				selectedCamera = mCameraView.GetSelectedCamera();
				if (selectedCamera == 4)
				{
					imageWText = AddText(image);
					DrawCVImage(bigCameraBox, imageWText);
				}
				Thread::Sleep(1 / fps);
			}
		}

	}

	//metoda dodaje tekst do obrazu z parametru
	cv::Mat MainForm::AddText(cv::Mat image)
	{
		SensorData mData = mSensorStorage.getSensorData();
		Mat retImage;
		retImage = image;
		string text1 = string("First sensor: ") + to_string(mData.data1);
		string text2 = string("Second sensor: ") + to_string(mData.data2);
		//img, text, startPoint, font, scale, color, thickness, lineType
		cv::putText(retImage, text1, cv::Point(10, 50), FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0, 0), 2, 8);
		cv::putText(retImage, text1, cv::Point(10, 50), FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(255, 255, 255), 1, 8);
		cv::putText(retImage, text2, cv::Point(10, 100), FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0, 0), 2, 8);
		cv::putText(retImage, text2, cv::Point(10, 100), FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(255, 255, 255), 1, 8);
		return retImage;
	}

	//metoda rysuje obraz z parametru image na elemencie z paramteru control
	void MainForm::DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& image)
	{
		try
		{
			System::Drawing::Graphics^ graphics = control->CreateGraphics();
			System::IntPtr ptr(image.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			graphics->DrawImage(b, rect);
			delete graphics;
		}
		catch (string obj)
		{

		}
	}

	//metoda ustawiajaca wszystko
	void MainForm::SetStartUp()
	{
		cameraVector = ListDevices();
		cameraVector = SortDevices(cameraVector);
		th1->Start();
		th2->Start();
		th3->Start();
		th4->Start();

	}

	

	//metoda korzystajaca z klasy DeviceEnumerator tworzaca liste urzadzen
	vector<CameraDevice> MainForm::ListDevices()
	{
		DeviceEnumerator de;
		std::vector<CameraDevice> devices = de.GetCameraDevices();
		return devices;
	}

	//metoda sortujaca liste urzadzen (root na koniec)
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
			//ssButton->Text = ssButton->Text + c;
			c++;
		}

		return retList;
	}



	//metoda zwracajaca id kamery w ktorej sciezce jest serial number nazwany name
	int MainForm::GetCameraID(vector<CameraDevice> cameraVector, string name)
	{
		int retID = -1;
		System::String^ wn = gcnew System::String(name.c_str());
		for (auto x : cameraVector)
		{
			string path;
			path = x.devicePath;
			size_t found = path.find(name);
			if (found != string::npos)
			{
				retID = x.id;
				continue;
			}


		}
		return retID;
	}

	//metoda zapisujaca obraz na dysku
	void MainForm::SaveImages()
	{
		int sCam = mCameraView.GetSelectedCamera();
		Mat img;
		if (sCam == 1)
		{
			img = mCameraView.GetCam1();
		}
		else if (sCam == 2)
		{
			img = mCameraView.GetCam2();
		}
		else if (sCam == 3)
		{
			img = mCameraView.GetCam3();
		}
		else
		{
			img = mCameraView.GetCam4();
		}
		string currTime = GetTime();
		string path = "C:/GIRApp/";
		SensorData myData = mSensorStorage.getSensorData();
		bool bDir = CreateDirectory(L"C:/GIRApp/", NULL);
		cv::imwrite(path + "screenshot_" + currTime + ".jpg", img);
		std::ofstream outfile(path + "plik_" + currTime + ".txt");
		outfile << currTime << std::endl;
		outfile << "Jakieœ coœ: " << myData.data1 << std::endl;
		outfile.close();
	}

	string MainForm::GetTime()
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
		auto str = oss.str();
		return str;
	}



	//------------------------------------		Buttons and UI		---------------------------------------------

	void MainForm::closeButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		th1->Abort();
		th2->Abort();
		th3->Abort();
		th4->Abort();
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

	System::Void MainForm::cameraBox1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		mCameraView.SetSelectedCamera(1);
	}

	System::Void MainForm::cameraBox2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		mCameraView.SetSelectedCamera(2);
	}

	System::Void MainForm::cameraBox3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		mCameraView.SetSelectedCamera(3);
	}

	System::Void MainForm::cameraBox4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		mCameraView.SetSelectedCamera(4);
	}





}//end of namespace GIRApp












