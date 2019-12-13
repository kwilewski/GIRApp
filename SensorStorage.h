#pragma once

struct SensorData {
	volatile double data1;
	volatile double data2;
	volatile double data3;
	volatile double data4;
	volatile double data5;
	volatile double data6;
};//end of struct


class SensorStorage {

public:
	SensorStorage() = default;
	SensorData getSensorData();
	void setSensorData(double data1, double data2, double data3, 
		double data4, double data5, double data6);

private:
	SensorData myData;


};//end of class