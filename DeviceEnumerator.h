#pragma once

#include <Windows.h>
#include <dshow.h>

#pragma comment(lib, "strmiids")

#include <map>
#include <string>
#include <vector>
#include <iostream>

struct CameraDevice {
	int id;
	std::string deviceName;
	std::string devicePath;
};


class DeviceEnumerator {

public:

	DeviceEnumerator() = default;
	HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);
	std::vector<CameraDevice> DisplayDeviceInformation(IEnumMoniker *pEnum);
	std::vector<CameraDevice> GetCameraDevices();

private:

	std::string ConvertBSTRToMBS(BSTR bstr);
	std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);

};
