#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

typedef void(WINAPI *t_func0)();
typedef void(WINAPI *t_func1)(int);
typedef void(WINAPI *t_func2)(int, int);
typedef void(WINAPI *t_func3)(int, int, int);
typedef void(WINAPI * t_func4)(int, int *);
typedef int(WINAPI *t_func5)();
typedef int(WINAPI *t_func6)(int);
typedef int(WINAPI *t_func7)(int, int);
typedef bool(WINAPI *t_func8)(int, int );

t_func5 OpenDevice;
t_func0 CloseDevices;
t_func0 Version;
t_func7 ReadAnalogChannel;
t_func4 ReadAllAnalog;
t_func3 OutputAnalogChannel;
t_func4 OutputAllAnalog;
t_func2 ClearAnalogChannel; 
t_func1 ClearAllAnalog;
t_func2 SetAnalogChannel; 
t_func1 SetAllAnalog;
t_func2 OutputAllDigital;
t_func2 ClearDigitalChannel;
t_func1 ClearAllDigital;
t_func2 SetDigitalChannel;
t_func1 SetAllDigital;
t_func8 ReadDigitalChannel;
t_func6 ReadAllDigital;

int init();

HINSTANCE hDLL;
int foundDLL = 0;

int main(void)
{
    int CardAddress;
    int dataOut[8] = {20, 50, 70, 100, 120, 150, 180, 220};
    int dataIn[8];
 
    int h = init();
	if (!h)
	{
		cout << "DLL found" << endl;
		foundDLL = 1;
	}
	else
	{
		cout << "DLL not found" << endl;
		cout << "Error code: " << h << endl;		
        cout << "Press a key to exit." << endl;
        cin.get();
	}
	if (foundDLL)
	{
		CardAddress = OpenDevice();
		if (CardAddress >= 0)
		{
			cout << "Card #"<< CardAddress << " opened." << endl;
		}
		else
		{
			cout << "Card not found" << endl;
		}
	}
	if (foundDLL)
	{     
        cout << "Press Enter to \"SetAllDigital\"" << endl;
        cin.get();
        SetAllDigital(CardAddress);
        cout << "Press Enter to \"OutputAllDigital 0x55\"" << endl;
        cin.get();
        OutputAllDigital(CardAddress, 0x55);
        cout << "Press Enter to \"ReadAllDigital\"" << endl;
        cin.get();
        int i = ReadAllDigital(CardAddress);
        cout << i << endl;        
        cout << "Press Enter to \"ClearAllDigital\"" << endl;
        cin.get();        
        ClearAllDigital(CardAddress);
        cout << "Press Enter to \"OutputAllAnalog dataOut\"" << endl;
        cin.get();
        OutputAllAnalog(CardAddress, dataOut);        
        cout << "Press Enter to \"ReadAllAnalog dataIn\"" << endl;
        cin.get();
        ReadAllAnalog(CardAddress, dataIn);        
        for (int i = 0; i < 8; i++)
        {
            cout << "dataIn[" << i << "] = " << dataIn[i] << endl;
        }
        cout << "Press Enter to \"CloseDevices\" and to \"FreeLibrary\"" << endl;
        cin.get();          	
        CloseDevices();
        FreeLibrary(hDLL);
    }
    return EXIT_SUCCESS;
}

int init()
{
	hDLL = LoadLibrary("K8061.DLL");
	if (hDLL != NULL)
	{
		OpenDevice = (t_func5) GetProcAddress(hDLL, "OpenDevice");
		if (!OpenDevice)		
		{						// handle the error
			FreeLibrary(hDLL);	
			return -2;
		}
		CloseDevices = (t_func0) GetProcAddress(hDLL, "CloseDevices");
		if (!CloseDevices)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -3;
		}
		ReadAnalogChannel = (t_func7) GetProcAddress(hDLL, "ReadAnalogChannel");
		if (!ReadAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -4;
		}
		ReadAllAnalog = (t_func4) GetProcAddress(hDLL, "ReadAllAnalog");
		if (!ReadAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -5;
		}
		OutputAnalogChannel = (t_func3) GetProcAddress(hDLL, "OutputAnalogChannel");
		if (!OutputAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -6;
		}
		OutputAllAnalog = (t_func4) GetProcAddress(hDLL, "OutputAllAnalog");
		if (!OutputAllAnalog)		
		{						// handle the error
			FreeLibrary(hDLL);	
			return -7;
		}
		ClearAnalogChannel = (t_func2) GetProcAddress(hDLL, "ClearAnalogChannel");
		if (!ClearAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -8;
		}
		ClearAllAnalog = (t_func1) GetProcAddress(hDLL, "ClearAllAnalog");
		if (!ClearAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -9;
		}
		SetAnalogChannel = (t_func2) GetProcAddress(hDLL, "SetAnalogChannel");
		if (!SetAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -10;
		}
		SetAllAnalog = (t_func1) GetProcAddress(hDLL, "SetAllAnalog");
		if (!SetAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -11;
		}
		OutputAllDigital = (t_func2) GetProcAddress(hDLL, "OutputAllDigital");
		if (!OutputAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -12;
		}
		ClearDigitalChannel = (t_func2) GetProcAddress(hDLL, "ClearDigitalChannel");
		if (!ClearDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -13;
		}
		ClearAllDigital = (t_func1) GetProcAddress(hDLL, "ClearAllDigital");
		if (!ClearAllDigital)		
		{						// handle the error
			FreeLibrary(hDLL);	
			return -14;
		}
		SetDigitalChannel = (t_func2) GetProcAddress(hDLL, "SetDigitalChannel");
		if (!SetDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -15;
		}
		SetAllDigital = (t_func1) GetProcAddress(hDLL, "SetAllDigital");
		if (!SetAllDigital)		
		{						// handle the error
			FreeLibrary(hDLL);	
			return -16;
		}
		ReadDigitalChannel = (t_func8) GetProcAddress(hDLL, "ReadDigitalChannel");
		if (!ReadDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -17;
		}
		ReadAllDigital = (t_func6) GetProcAddress(hDLL, "ReadAllDigital");
		if (!ReadAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -18;
		}
/*		Version = (t_func0) GetProcAddress(hDLL, "Version");
		if (!Version)
		{						// handle the error
			FreeLibrary(hDLL);	
			return -19;
		}
*/
		return 0;				// OK
	}       
	return -1;					// error load DLL
}
