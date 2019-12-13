#include "DeviceEnumerator.h"

using namespace std;


std::string DeviceEnumerator::ConvertWCSToMBS(const wchar_t* pstr, long wslen)
{
	int len = ::WideCharToMultiByte(CP_ACP, 0, pstr, wslen, NULL, 0, NULL, NULL);

	std::string dblstr(len, '\0');
	len = ::WideCharToMultiByte(CP_ACP, 0 /* no flags */,
		pstr, wslen /* not necessary NULL-terminated */,
		&dblstr[0], len,
		NULL, NULL /* no default char */);

	return dblstr;
}

std::string DeviceEnumerator::ConvertBSTRToMBS(BSTR bstr)
{
	int wslen = ::SysStringLen(bstr);
	return ConvertWCSToMBS((wchar_t*)bstr, wslen);
}



HRESULT DeviceEnumerator::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)
{
	// Create the System Device Enumerator.
	ICreateDevEnum *pDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));

	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the category.
		hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);
		if (hr == S_FALSE)
		{
			hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
		}
		pDevEnum->Release();
	}
	return hr;
}

vector<CameraDevice> DeviceEnumerator::GetCameraDevices()
{
	vector<CameraDevice> deviceVector;
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		IEnumMoniker *pEnum;

		hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);
		if (SUCCEEDED(hr))
		{
			deviceVector = DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}
		/*hr = EnumerateDevices(CLSID_AudioInputDeviceCategory, &pEnum);
		if (SUCCEEDED(hr))
		{
			deviceVector = DisplayDeviceInformation(pEnum);
			pEnum->Release();
		}*/					//audio devices, not needed
		CoUninitialize();
	}
	return deviceVector;
}


vector<CameraDevice> DeviceEnumerator::DisplayDeviceInformation(IEnumMoniker *pEnum)
{
	vector<CameraDevice> deviceVector;
	IMoniker *pMoniker = NULL;
	int deviceId = -1;

	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
		if (FAILED(hr))
		{
			pMoniker->Release();
			continue;
		}

		VARIANT var;
		VariantInit(&var);

		std::string deviceName;
		std::string devicePath;

		// Get description or friendly name.
		hr = pPropBag->Read(L"Description", &var, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &var, 0);
		}
		if (SUCCEEDED(hr))
		{
			//printf("%S\n", var.bstrVal);
			deviceName = ConvertBSTRToMBS(var.bstrVal);
			VariantClear(&var);
		}

		hr = pPropBag->Write(L"FriendlyName", &var);

		// WaveInID applies only to audio capture devices.
		hr = pPropBag->Read(L"WaveInID", &var, 0);
		if (SUCCEEDED(hr))
		{
			//printf("WaveIn ID: %d\n", var.lVal);
			VariantClear(&var);
		}

		hr = pPropBag->Read(L"DevicePath", &var, 0);
		if (SUCCEEDED(hr))
		{
			// The device path is not intended for display.
			//printf("Device path: %S\n", var.bstrVal);
			devicePath = ConvertBSTRToMBS(var.bstrVal);
			VariantClear(&var);
		}

		pPropBag->Release();
		pMoniker->Release();


		deviceId++;
		CameraDevice currentDevice;
		currentDevice.id = deviceId;
		currentDevice.deviceName = deviceName;
		currentDevice.devicePath = devicePath;
		deviceVector.push_back(currentDevice);
	}
	return deviceVector;
}