#include "SensorStorage.h"

void SensorStorage::setSensorData(double data1, double data2, double data3,
	double data4, double data5, double data6)
{
	myData.data1 = data1;
	myData.data2 = data2;
	myData.data3 = data3;
	myData.data4 = data4;
	myData.data5 = data5;
	myData.data6 = data6;
}


SensorData SensorStorage::getSensorData()
{
	return myData;
}

