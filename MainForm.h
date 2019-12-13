#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "DeviceEnumerator.h"
#include <iostream>
#include <map>
#include <vector>
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
	private: System::Windows::Forms::Button^  forwardButton;
	private: System::Windows::Forms::Button^  leftButton;
	private: System::Windows::Forms::Button^  rightButton;
	private: System::Windows::Forms::Button^  backwardButton;
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
		int GetCameraID(vector<CameraDevice> cameraVector, string name);
		cv::Mat AddText(cv::Mat image);
		void SetImage1();
		void SetImage2();
		void SetImage3();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// cameraBox1
			// 
			this->cameraBox1->Location = System::Drawing::Point(12, 12);
			this->cameraBox1->Name = L"cameraBox1";
			this->cameraBox1->Size = System::Drawing::Size(511, 326);
			this->cameraBox1->TabIndex = 0;
			this->cameraBox1->TabStop = false;
			// 
			// cameraBox2
			// 
			this->cameraBox2->Location = System::Drawing::Point(546, 12);
			this->cameraBox2->Name = L"cameraBox2";
			this->cameraBox2->Size = System::Drawing::Size(535, 326);
			this->cameraBox2->TabIndex = 1;
			this->cameraBox2->TabStop = false;
			// 
			// closeButton
			// 
			this->closeButton->Location = System::Drawing::Point(1450, 507);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(168, 87);
			this->closeButton->TabIndex = 2;
			this->closeButton->Text = L"Close";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &MainForm::closeButton_Click);
			// 
			// cameraBox3
			// 
			this->cameraBox3->Location = System::Drawing::Point(1101, 12);
			this->cameraBox3->Name = L"cameraBox3";
			this->cameraBox3->Size = System::Drawing::Size(517, 326);
			this->cameraBox3->TabIndex = 3;
			this->cameraBox3->TabStop = false;
			// 
			// forwardButton
			// 
			this->forwardButton->Location = System::Drawing::Point(756, 370);
			this->forwardButton->Name = L"forwardButton";
			this->forwardButton->Size = System::Drawing::Size(88, 75);
			this->forwardButton->TabIndex = 4;
			this->forwardButton->Text = L"Forward";
			this->forwardButton->UseVisualStyleBackColor = true;
			this->forwardButton->Click += gcnew System::EventHandler(this, &MainForm::forwardButton_Click);
			// 
			// leftButton
			// 
			this->leftButton->Location = System::Drawing::Point(662, 437);
			this->leftButton->Name = L"leftButton";
			this->leftButton->Size = System::Drawing::Size(88, 75);
			this->leftButton->TabIndex = 5;
			this->leftButton->Text = L"Left";
			this->leftButton->UseVisualStyleBackColor = true;
			this->leftButton->Click += gcnew System::EventHandler(this, &MainForm::leftButton_Click);
			// 
			// rightButton
			// 
			this->rightButton->Location = System::Drawing::Point(850, 437);
			this->rightButton->Name = L"rightButton";
			this->rightButton->Size = System::Drawing::Size(88, 75);
			this->rightButton->TabIndex = 6;
			this->rightButton->Text = L"Right";
			this->rightButton->UseVisualStyleBackColor = true;
			this->rightButton->Click += gcnew System::EventHandler(this, &MainForm::rightButton_Click);
			// 
			// backwardButton
			// 
			this->backwardButton->Location = System::Drawing::Point(756, 501);
			this->backwardButton->Name = L"backwardButton";
			this->backwardButton->Size = System::Drawing::Size(88, 75);
			this->backwardButton->TabIndex = 7;
			this->backwardButton->Text = L"Backward";
			this->backwardButton->UseVisualStyleBackColor = true;
			this->backwardButton->Click += gcnew System::EventHandler(this, &MainForm::backwardButton_Click);
			// 
			// ssButton
			// 
			this->ssButton->Location = System::Drawing::Point(188, 370);
			this->ssButton->Name = L"ssButton";
			this->ssButton->Size = System::Drawing::Size(133, 75);
			this->ssButton->TabIndex = 8;
			this->ssButton->Text = L"Screenshoot";
			this->ssButton->UseVisualStyleBackColor = true;
			this->ssButton->Click += gcnew System::EventHandler(this, &MainForm::ssButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1630, 606);
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
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
};//end of namespace
}
