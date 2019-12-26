#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "DeviceEnumerator.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>
#include <fstream>  
#include "CameraView.h"
#include "SensorStorage.h"
#include <Windows.h>

#pragma comment(lib, "strmiids")

namespace GIRApp {

	using System::Runtime::InteropServices::Marshal;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Threading;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: 
		Thread^ th1 = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetImage1));
		Thread^ th2 = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetImage2));
		Thread^ th3 = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetImage3));
		Thread^ th4 = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetImage4));
	private: System::Windows::Forms::Button^  forwardButton;
	private: System::Windows::Forms::Button^  leftButton;
	private: System::Windows::Forms::Button^  rightButton;
	private: System::Windows::Forms::Button^  backwardButton;
	private: System::Windows::Forms::PictureBox^  bigCameraBox;
	private: System::Windows::Forms::PictureBox^  cameraBox4;
	private: System::Windows::Forms::CheckBox^  autofocusCB;
	private: System::Windows::Forms::CheckBox^  positionModeCB;
	private: System::Windows::Forms::Label^  speedLabel;
	private: System::Windows::Forms::Label^  posIncLabel;
	private: System::Windows::Forms::Label^  accelerationLabel;
	private: System::Windows::Forms::Label^  positionLabel;
	private: System::Windows::Forms::TrackBar^  autofocusTB;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  ssButton;


	public:
		MainForm(void)
		{
			InitializeComponent();
			SetStartUp();
			//
			//TODO: Add the constructor code here
			//
		}





	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		void SetStartUp();
		void closeButton_Click(System::Object^  sender, System::EventArgs^  e);
		void forwardButton_Click(System::Object^  sender, System::EventArgs^  e);
		void leftButton_Click(System::Object^  sender, System::EventArgs^  e);
		void rightButton_Click(System::Object^  sender, System::EventArgs^  e);
		void backwardButton_Click(System::Object^  sender, System::EventArgs^  e);
		void ssButton_Click(System::Object^  sender, System::EventArgs^  e); 
		System::Void cameraBox1_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void cameraBox2_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void cameraBox3_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void cameraBox4_Click(System::Object^  sender, System::EventArgs^  e);
		string GetTime();



		int GetCameraID(vector<CameraDevice> cameraVector, string name);
		cv::Mat AddText(cv::Mat image);
		void SetImage1();
		void SetImage2();
		void SetImage3();
		void SetImage4();
		void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage);
		vector<CameraDevice> ListDevices();
		vector<CameraDevice> SortDevices(vector<CameraDevice> deviceList);
		void SaveImages();


	private: System::Windows::Forms::PictureBox^  cameraBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  cameraBox2;
	private: System::Windows::Forms::Button^  closeButton;

	private: System::Windows::Forms::PictureBox^  cameraBox3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cameraBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cameraBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->cameraBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->forwardButton = (gcnew System::Windows::Forms::Button());
			this->leftButton = (gcnew System::Windows::Forms::Button());
			this->rightButton = (gcnew System::Windows::Forms::Button());
			this->backwardButton = (gcnew System::Windows::Forms::Button());
			this->ssButton = (gcnew System::Windows::Forms::Button());
			this->bigCameraBox = (gcnew System::Windows::Forms::PictureBox());
			this->cameraBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->autofocusCB = (gcnew System::Windows::Forms::CheckBox());
			this->positionModeCB = (gcnew System::Windows::Forms::CheckBox());
			this->speedLabel = (gcnew System::Windows::Forms::Label());
			this->posIncLabel = (gcnew System::Windows::Forms::Label());
			this->accelerationLabel = (gcnew System::Windows::Forms::Label());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->autofocusTB = (gcnew System::Windows::Forms::TrackBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bigCameraBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->autofocusTB))->BeginInit();
			this->SuspendLayout();
			// 
			// cameraBox1
			// 
			this->cameraBox1->Location = System::Drawing::Point(12, 12);
			this->cameraBox1->Name = L"cameraBox1";
			this->cameraBox1->Size = System::Drawing::Size(346, 234);
			this->cameraBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->cameraBox1->TabIndex = 0;
			this->cameraBox1->TabStop = false;
			this->cameraBox1->Click += gcnew System::EventHandler(this, &MainForm::cameraBox1_Click);
			// 
			// cameraBox2
			// 
			this->cameraBox2->Location = System::Drawing::Point(12, 255);
			this->cameraBox2->Name = L"cameraBox2";
			this->cameraBox2->Size = System::Drawing::Size(346, 234);
			this->cameraBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->cameraBox2->TabIndex = 1;
			this->cameraBox2->TabStop = false;
			this->cameraBox2->Click += gcnew System::EventHandler(this, &MainForm::cameraBox2_Click);
			// 
			// closeButton
			// 
			this->closeButton->Location = System::Drawing::Point(1476, 938);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(112, 59);
			this->closeButton->TabIndex = 2;
			this->closeButton->Text = L"Close";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &MainForm::closeButton_Click);
			// 
			// cameraBox3
			// 
			this->cameraBox3->Location = System::Drawing::Point(12, 495);
			this->cameraBox3->Name = L"cameraBox3";
			this->cameraBox3->Size = System::Drawing::Size(346, 234);
			this->cameraBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->cameraBox3->TabIndex = 3;
			this->cameraBox3->TabStop = false;
			this->cameraBox3->Click += gcnew System::EventHandler(this, &MainForm::cameraBox3_Click);
			// 
			// forwardButton
			// 
			this->forwardButton->Location = System::Drawing::Point(983, 735);
			this->forwardButton->Name = L"forwardButton";
			this->forwardButton->Size = System::Drawing::Size(88, 75);
			this->forwardButton->TabIndex = 4;
			this->forwardButton->Text = L"Forward";
			this->forwardButton->UseVisualStyleBackColor = true;
			this->forwardButton->Click += gcnew System::EventHandler(this, &MainForm::forwardButton_Click);
			// 
			// leftButton
			// 
			this->leftButton->Location = System::Drawing::Point(889, 802);
			this->leftButton->Name = L"leftButton";
			this->leftButton->Size = System::Drawing::Size(88, 75);
			this->leftButton->TabIndex = 5;
			this->leftButton->Text = L"Left";
			this->leftButton->UseVisualStyleBackColor = true;
			this->leftButton->Click += gcnew System::EventHandler(this, &MainForm::leftButton_Click);
			// 
			// rightButton
			// 
			this->rightButton->Location = System::Drawing::Point(1077, 802);
			this->rightButton->Name = L"rightButton";
			this->rightButton->Size = System::Drawing::Size(88, 75);
			this->rightButton->TabIndex = 6;
			this->rightButton->Text = L"Right";
			this->rightButton->UseVisualStyleBackColor = true;
			this->rightButton->Click += gcnew System::EventHandler(this, &MainForm::rightButton_Click);
			// 
			// backwardButton
			// 
			this->backwardButton->Location = System::Drawing::Point(983, 866);
			this->backwardButton->Name = L"backwardButton";
			this->backwardButton->Size = System::Drawing::Size(88, 75);
			this->backwardButton->TabIndex = 7;
			this->backwardButton->Text = L"Backward";
			this->backwardButton->UseVisualStyleBackColor = true;
			this->backwardButton->Click += gcnew System::EventHandler(this, &MainForm::backwardButton_Click);
			// 
			// ssButton
			// 
			this->ssButton->Location = System::Drawing::Point(1375, 109);
			this->ssButton->Name = L"ssButton";
			this->ssButton->Size = System::Drawing::Size(184, 75);
			this->ssButton->TabIndex = 8;
			this->ssButton->Text = L"Snapshot";
			this->ssButton->UseVisualStyleBackColor = true;
			this->ssButton->Click += gcnew System::EventHandler(this, &MainForm::ssButton_Click);
			// 
			// bigCameraBox
			// 
			this->bigCameraBox->Location = System::Drawing::Point(422, 15);
			this->bigCameraBox->Name = L"bigCameraBox";
			this->bigCameraBox->Size = System::Drawing::Size(889, 640);
			this->bigCameraBox->TabIndex = 9;
			this->bigCameraBox->TabStop = false;
			// 
			// cameraBox4
			// 
			this->cameraBox4->Location = System::Drawing::Point(12, 735);
			this->cameraBox4->Name = L"cameraBox4";
			this->cameraBox4->Size = System::Drawing::Size(346, 234);
			this->cameraBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->cameraBox4->TabIndex = 10;
			this->cameraBox4->TabStop = false;
			this->cameraBox4->Click += gcnew System::EventHandler(this, &MainForm::cameraBox4_Click);
			// 
			// autofocusCB
			// 
			this->autofocusCB->AutoSize = true;
			this->autofocusCB->Location = System::Drawing::Point(1375, 34);
			this->autofocusCB->Name = L"autofocusCB";
			this->autofocusCB->Size = System::Drawing::Size(74, 17);
			this->autofocusCB->TabIndex = 11;
			this->autofocusCB->Text = L"Autofocus";
			this->autofocusCB->UseVisualStyleBackColor = true;
			// 
			// positionModeCB
			// 
			this->positionModeCB->AutoSize = true;
			this->positionModeCB->Location = System::Drawing::Point(422, 798);
			this->positionModeCB->Name = L"positionModeCB";
			this->positionModeCB->Size = System::Drawing::Size(92, 17);
			this->positionModeCB->TabIndex = 12;
			this->positionModeCB->Text = L"Position mode";
			this->positionModeCB->UseVisualStyleBackColor = true;
			// 
			// speedLabel
			// 
			this->speedLabel->AutoSize = true;
			this->speedLabel->Location = System::Drawing::Point(419, 736);
			this->speedLabel->Name = L"speedLabel";
			this->speedLabel->Size = System::Drawing::Size(41, 13);
			this->speedLabel->TabIndex = 13;
			this->speedLabel->Text = L"Speed:";
			// 
			// posIncLabel
			// 
			this->posIncLabel->AutoSize = true;
			this->posIncLabel->Location = System::Drawing::Point(419, 835);
			this->posIncLabel->Name = L"posIncLabel";
			this->posIncLabel->Size = System::Drawing::Size(48, 13);
			this->posIncLabel->TabIndex = 15;
			this->posIncLabel->Text = L"Pos. inc:";
			// 
			// accelerationLabel
			// 
			this->accelerationLabel->AutoSize = true;
			this->accelerationLabel->Location = System::Drawing::Point(419, 768);
			this->accelerationLabel->Name = L"accelerationLabel";
			this->accelerationLabel->Size = System::Drawing::Size(37, 13);
			this->accelerationLabel->TabIndex = 16;
			this->accelerationLabel->Text = L"Accel:";
			// 
			// positionLabel
			// 
			this->positionLabel->AutoSize = true;
			this->positionLabel->Location = System::Drawing::Point(419, 866);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(78, 13);
			this->positionLabel->TabIndex = 17;
			this->positionLabel->Text = L"Robot position:";
			// 
			// autofocusTB
			// 
			this->autofocusTB->Location = System::Drawing::Point(1375, 58);
			this->autofocusTB->Maximum = 100;
			this->autofocusTB->Name = L"autofocusTB";
			this->autofocusTB->Size = System::Drawing::Size(184, 45);
			this->autofocusTB->TabIndex = 18;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkRed;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(1375, 710);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 170);
			this->button1->TabIndex = 19;
			this->button1->Text = L"STOP";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 1009);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->autofocusTB);
			this->Controls->Add(this->positionLabel);
			this->Controls->Add(this->accelerationLabel);
			this->Controls->Add(this->posIncLabel);
			this->Controls->Add(this->speedLabel);
			this->Controls->Add(this->positionModeCB);
			this->Controls->Add(this->autofocusCB);
			this->Controls->Add(this->cameraBox4);
			this->Controls->Add(this->bigCameraBox);
			this->Controls->Add(this->ssButton);
			this->Controls->Add(this->backwardButton);
			this->Controls->Add(this->rightButton);
			this->Controls->Add(this->leftButton);
			this->Controls->Add(this->forwardButton);
			this->Controls->Add(this->cameraBox3);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->cameraBox2);
			this->Controls->Add(this->cameraBox1);
			this->Name = L"MainForm";
			this->Text = L"Generator Inspection";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bigCameraBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->autofocusTB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

};//end of namespace
}
