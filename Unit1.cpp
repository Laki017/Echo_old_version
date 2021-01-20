//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <time.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <fstream>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMyThread *FMyThread = 0;
TMyThread1 *FMyThread1 = 0;
TMyThread2 *FMyThread2 = 0;
TMyThread3 *FMyThread3 = 0;
TMyThread4 *FMyThread4 = 0;
TForm1 *Form1;
TForm2 *Form2;
TForm3 *Form3;
Dialog1 * dialog1;
DialogMain * dialogMain;

UINT IDSoundwall;
UINT IDMessage;

HANDLE hMap;
HANDLE hFile;
LPTSTR buffer;

HANDLE hMap1;
HANDLE hFile1;
LPTSTR buffer1;
//---------------------------------------------------------------------------
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

typedef void(CALLBACK* t1_func)(int );
typedef void(CALLBACK* t1_func0)();
typedef int(CALLBACK* t1_func1)();
typedef void(CALLBACK* t1_func2)(int *, int *);
typedef void(CALLBACK* t1_func3)(int , int );
typedef int(CALLBACK* t1_func4)(int );
typedef bool(CALLBACK* t1_func5)(int );

t1_func4 OpenDevice1;
t1_func0 CloseDevices1;
t1_func0 Version_1;
t1_func4 ReadAnalogChannel1;
t1_func2 ReadAllAnalog1;
t1_func3 OutputAnalogChannel1;
t1_func3 OutputAllAnalog1;
t1_func ClearAnalogChannel1;
t1_func0 ClearAllAnalog1;
t1_func SetAnalogChannel1;
t1_func0 SetAllAnalog1;
t1_func WriteAllDigital1;
t1_func ClearDigitalChannel1;
t1_func0 ClearAllDigital1;
t1_func SetDigitalChannel1;
t1_func0 SetAllDigital1;
t1_func5 ReadDigitalChannel1;
t1_func1 ReadAllDigital1;


HINSTANCE hDLL;
HINSTANCE hDLL1;
int foundDLL = 0;
int foundDLL1 = 0;
int CardAddress;
int CardAddress1;
int CardAddress2;

//---------------------------------------------------------------------------
__fastcall TMyThread::TMyThread(const bool CreateSuspended) //----работа с контроллером
        :TThread(CreateSuspended)
{
}

__fastcall TMyThread1::TMyThread1(const bool CreateSuspended)//----тексты на экране
        :TThread(CreateSuspended)
{
}

__fastcall TMyThread2::TMyThread2(const bool CreateSuspended) //----тексты на экране
        :TThread(CreateSuspended)
{
}

__fastcall TMyThread3::TMyThread3(const bool CreateSuspended) //блинк освещения 1
        :TThread(CreateSuspended)
{
}

__fastcall TMyThread4::TMyThread4(const bool CreateSuspended) //блинк освещения 2
        :TThread(CreateSuspended)
{
}


__fastcall TForm1::~TForm1() //----------ДЕСТРУКТОР ОСНОВНОГО КЛАССА , убьем здесь процесс SOUNDWALL.exe
{
   //-----------------------------------ОТКЛЮЧИМ MAP ФАЙЛА ДЛЯ ОБМЕНА С SOUNDWALL
  WriteMap(hMap, "halt;;;;");//---[command;file;delay;channel]
  CloseMap();
  CloseMap1();
  delete dialog1;
  delete dialogMain;
  //-----------------------------------END ОТКЛЮЧИМ MAP ФАЙЛА ДЛЯ ОБМЕНА С SOUNDWALL
}

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
//--------------------------------------------------ЗАПУСКАЕМ ВТОРОЙ ПРОЦЕСС soundwall.exe
STARTUPINFO si = {sizeof(si)};
PROCESS_INFORMATION pi;
TCHAR czCommandLine[] = "soundwall.exe";
CreateProcess(NULL, czCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
//--------------------------------------------------END ЗАПУСКАЕМ ВТОРОЙ ПРОЦЕСС soundwall.exe
//-------проинициализируем массив
for (int i = 0; i < 50; i++){
Grid2[i] = 0;
}

for (int i = 0; i < 10; i++){
Grid3[i] = 0;
}
//-------------------------------

StringGrid1->ColWidths[0]=1;
StringGrid1->ColWidths[1]=180;
StringGrid1->ColWidths[2]=25;

StringGrid1->Cells[1][0]="ВХОДЫ";
StringGrid1->Cells[1][1]="РЫЧАГ ВЕРА (1_D1)";
StringGrid1->Cells[1][2]="ЗВОНОК ДОМИК (1_D2)";
StringGrid1->Cells[1][3]="(ФИГУРА 1) (1_D3)";
StringGrid1->Cells[1][4]="КНОПКА ПРОЖЕКТОРА 1 (1_D4)";
StringGrid1->Cells[1][5]="ДОМИК КРЮЧОК (1_D5)";
StringGrid1->Cells[1][6]="ДОМИК КНИГА (1_D6)";
StringGrid1->Cells[1][7]="ДОМИК ЛАМПА (1_D7)";
StringGrid1->Cells[1][8]="ЗАМОК МОТ (1_D8)";
StringGrid1->Cells[1][9]="А_ЩИТОК ПЕРЕКЛ. (1_A1)";
StringGrid1->Cells[1][10]="А_ЩИТОК КНОПКИ (1_A2)";
StringGrid1->Cells[1][11]="А_ПОДСКАЗКА (1_A3)";
StringGrid1->Cells[1][12]="А_ЩИТОК АВТОМАТЫ вкл (1_A4)";
StringGrid1->Cells[1][13]="А_ЩИТОК АВТОМАТЫ выкл (1_A5)";
StringGrid1->Cells[1][14]="А_НОМЕР ДОМА (1_A6)";
StringGrid1->Cells[1][15]="А_ПЕРЕКЛЮЧАТЕЛИ (1_A7)";
StringGrid1->Cells[1][16]="А_РАЗЪЕМ ВЕРЫ (1_A8)";
StringGrid1->Cells[1][17]="РЫЧАГ СТАРТА";
StringGrid1->Cells[1][18]="ДО";
StringGrid1->Cells[1][19]="ФА";
StringGrid1->Cells[1][20]="СИ";
StringGrid1->Cells[1][21]="СОЛЬ";
StringGrid1->Cells[1][22]="Free";
StringGrid1->Cells[1][23]="КНОПКА ДЕРЕВО (2_D1)";
StringGrid1->Cells[1][24]="Птица на чердаке (2_D2)";
StringGrid1->Cells[1][25]="Цепь в будке (2_D3)";
StringGrid1->Cells[1][26]="РХД АКТИВАЦИЯ (2_D4)";
StringGrid1->Cells[1][27]=" (2_D5)";
StringGrid1->Cells[1][28]=" (2_D6)";
StringGrid1->Cells[1][29]="ТРУБА ВЕРА (2_D7)";
StringGrid1->Cells[1][30]="ТРУБА ДОМИК (2_D8)";
StringGrid1->Cells[1][31]="КОД ДЕРЕВО (2_A1)";
StringGrid1->Cells[1][32]="Кнопки Доп.Задания (2_A2)";
StringGrid1->Cells[1][33]="А_ДОП КНОПКА B (2_A3)";
StringGrid1->Cells[1][34]="A_ТЕЛЕФОН (2_A4)";
StringGrid1->Cells[1][35]="А_ (2_A5)";
StringGrid1->Cells[1][36]="А_ (2_6)";
StringGrid1->Cells[1][37]="А_Кнопка ДИАЛОГА (2_A7)";
StringGrid1->Cells[1][38]="А_КАЧЕЛИ (2_A8)";


//---------------------------------------------------------данные входов
StringGrid1->Cells[2][1]="1";
StringGrid1->Cells[2][2]="0";
StringGrid1->Cells[2][3]="0";
StringGrid1->Cells[2][4]="0";
StringGrid1->Cells[2][5]="0";
StringGrid1->Cells[2][6]="1";
StringGrid1->Cells[2][7]="0";
StringGrid1->Cells[2][8]="1";
StringGrid1->Cells[2][9]="900";
StringGrid1->Cells[2][10]="900";
StringGrid1->Cells[2][11]="900";
StringGrid1->Cells[2][12]="900";
StringGrid1->Cells[2][13]="500";
StringGrid1->Cells[2][14]="900";
StringGrid1->Cells[2][15]="900";
StringGrid1->Cells[2][16]="500";
StringGrid1->Cells[2][17]="1";
StringGrid1->Cells[2][18]="1";
StringGrid1->Cells[2][19]="1";
StringGrid1->Cells[2][20]="1";
StringGrid1->Cells[2][21]="1";
StringGrid1->Cells[2][22]="1";
StringGrid1->Cells[2][23]="0";
StringGrid1->Cells[2][24]="0";
StringGrid1->Cells[2][25]="1";
StringGrid1->Cells[2][26]="1";
StringGrid1->Cells[2][27]="1";
StringGrid1->Cells[2][28]="1";
StringGrid1->Cells[2][29]="1";
StringGrid1->Cells[2][30]="0";
StringGrid1->Cells[2][31]="900";
StringGrid1->Cells[2][32]="900";
StringGrid1->Cells[2][33]="900";
StringGrid1->Cells[2][34]="900";
StringGrid1->Cells[2][35]="900";
StringGrid1->Cells[2][36]="900";
StringGrid1->Cells[2][37]="900";
StringGrid1->Cells[2][38]="900";

StringGrid2->ColWidths[0]=1;
StringGrid2->ColWidths[1]=170;
StringGrid2->ColWidths[2]=20;

StringGrid3->ColWidths[0]=1;
StringGrid3->ColWidths[1]=90;
StringGrid3->ColWidths[2]=60;

StringGrid2->Cells[1][0]="ВЫХОДЫ";
StringGrid2->Cells[1][1]="Щиток Веры";
StringGrid2->Cells[1][2]="ДОМИК ЯЩИК";
StringGrid2->Cells[1][3]="Домик, настольная лампа";
StringGrid2->Cells[1][4]="ДОМИК ДВЕРЬ";
StringGrid2->Cells[1][5]="Посветка пол, РХД";
StringGrid2->Cells[1][6]="КРЫШКА ПИАНИНО";
StringGrid2->Cells[1][7]="ВХОДНАЯ ДВЕРЬ";
StringGrid2->Cells[1][8]="Свет под столом";
StringGrid2->Cells[1][9]="Свет ДОМ";
StringGrid2->Cells[1][10]="ФОНАРЬ МОТ";
StringGrid2->Cells[1][11]="СВЕТ ЩИТОК";
StringGrid2->Cells[1][12]="СВЕТ ПИАНИНО";
StringGrid2->Cells[1][13]="СВЕТ ЧЕРДАК";
StringGrid2->Cells[1][14]="РХД выполнено";
StringGrid2->Cells[1][15]="Луч 2";
StringGrid2->Cells[1][16]="ПЕРЕДВИЖ. ПРОЖ.";
StringGrid2->Cells[1][17]="ЩИТОК ДВЕРЦА М.";
StringGrid2->Cells[1][18]="ЩИТОК ДВЕРЦА Б.";
StringGrid2->Cells[1][19]="Луч 1";
StringGrid2->Cells[1][20]="УЛЬТРАФИОЛЕТ";
StringGrid2->Cells[1][21]="--";
StringGrid2->Cells[1][22]="--";
StringGrid2->Cells[1][23]="ДИОД ВЕРЫ 1";
StringGrid2->Cells[1][24]="ДИОД ВЕРЫ 2";
StringGrid2->Cells[1][25]="АУДИО ДОМИК";
StringGrid2->Cells[1][26]="ТРУБА ДОМИК";
StringGrid2->Cells[1][27]="АУДИО БУДКА";
StringGrid2->Cells[1][28]="ФИОЛЕТ ВЕРА";
StringGrid2->Cells[1][29]="АУДИО ДЕРЕВО";
StringGrid2->Cells[1][30]="ТАЙМЕР ВЕРА";
StringGrid2->Cells[1][31]="РЕШЕТКА ДОМИК";
StringGrid2->Cells[1][32]="РЕШЕТКА В КОМН.";
StringGrid2->Cells[1][33]="ЛЮК РЕШЕТКИ";
StringGrid2->Cells[1][34]="ЛЮК ДОМИКА";
StringGrid2->Cells[1][35]="РАЗРУШЕНИЕ 1";
StringGrid2->Cells[1][36]="РАЗРУШЕНИЕ 2";
StringGrid2->Cells[1][37]="РАЗРУШЕНИЕ 3";
StringGrid2->Cells[1][38]="РАЗРУШЕНИЕ 4";
StringGrid2->Cells[1][39]="СВЕТ РХД";
StringGrid2->Cells[1][40]="Дерево выполнено";
StringGrid2->Cells[1][41]="ДЕРЕВО СВЕТ";
StringGrid2->Cells[1][42]="ЯЩИК РЫЧАГ СТАРТ";
StringGrid2->Cells[1][43]="СВЕТ ФИГУРЫ";
StringGrid2->Cells[1][44]="20";

StringGrid3->Cells[1][1] = "ВХОД ОТКРЫТ";
StringGrid3->Cells[1][2] = "ВХОД ЗАКРЫТ";
StringGrid3->Cells[1][3] = "ГОВОРИТЕ";
StringGrid3->Cells[1][4] = "СВЕТ КНОПОК";

//------------------------------------------------данные выходов
StringGrid2->Cells[2][1]="0";
StringGrid2->Cells[2][2]="0";
StringGrid2->Cells[2][3]="0";
StringGrid2->Cells[2][4]="0";
StringGrid2->Cells[2][5]="0";
StringGrid2->Cells[2][6]="0";
StringGrid2->Cells[2][7]="0";
StringGrid2->Cells[2][8]="0";
StringGrid2->Cells[2][9]="0";
StringGrid2->Cells[2][10]="0";
StringGrid2->Cells[2][11]="0";
StringGrid2->Cells[2][12]="0";
StringGrid2->Cells[2][13]="0";
StringGrid2->Cells[2][14]="0";
StringGrid2->Cells[2][15]="0";
StringGrid2->Cells[2][16]="0";
StringGrid2->Cells[2][17]="0";
StringGrid2->Cells[2][18]="0";
StringGrid2->Cells[2][19]="0";
StringGrid2->Cells[2][20]="0";
StringGrid2->Cells[2][21]="0";
StringGrid2->Cells[2][22]="0";
StringGrid2->Cells[2][23]="0";
StringGrid2->Cells[2][24]="0";
StringGrid2->Cells[2][25]="0";
StringGrid2->Cells[2][26]="0";
StringGrid2->Cells[2][27]="0";
StringGrid2->Cells[2][28]="0";
StringGrid2->Cells[2][29]="0";
StringGrid2->Cells[2][30]="0";
StringGrid2->Cells[2][31]="0";
StringGrid2->Cells[2][32]="0";
StringGrid2->Cells[2][33]="0";
StringGrid2->Cells[2][34]="0";
StringGrid2->Cells[2][35]="0";
StringGrid2->Cells[2][36]="0";
StringGrid2->Cells[2][37]="0";
StringGrid2->Cells[2][38]="0";
StringGrid2->Cells[2][39]="0";
StringGrid2->Cells[2][40]="0";
StringGrid2->Cells[2][41]="0";
StringGrid2->Cells[2][42]="0";
StringGrid2->Cells[2][43]="0";
StringGrid2->Cells[2][44]="0";

StringGrid3->Cells[2][1] = "0";
StringGrid3->Cells[2][2] = "0";
StringGrid3->Cells[2][3] = "0";
StringGrid3->Cells[2][4] = "0";

    //--------------------------------------------------------ПОДКЛЮЧИМ MAP ФАЙЛА ДЛЯ ОБМЕНА С SOUNDWALL
    CreateMap();
    CreateMap1();
    ReadMap1(hMap1, buffer1);
    //--------------------------------------------------------END ПОДКЛЮЧИМ MAP ФАЙЛА ДЛЯ ОБМЕНА С SOUNDWALL

    dialog1 = new Dialog1();
    dialogMain = new DialogMain();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
int i;
AnsiString textmess, txt;
char * temp = new char[256];

//------------------------------------create Forms
int CountMon = Screen->MonitorCount; // количество мониторов.
textmess="Обнаружено " + IntToStr(CountMon-1) + " подключенных мониторов\n На дополнительный монитор(ы) будет выведена форма игры!";
//--------------------------------#1

if(CountMon > 1){
mon=1;
Form3->Show();
TRect Bounds = Screen->Monitors[mon]->BoundsRect; // получаем границы
textmess = textmess + "\n\r" + "Координаты 2-го экрана " + IntToStr(Bounds.left) + "X" + IntToStr(Bounds.Top);
Form3->SetBounds(Bounds.Left,Bounds.Top,Bounds.Left+1024,Bounds.Top+767);
}
//--------------------------------#2

if(CountMon > 2){

mon=2;
Form2->Show();
TRect Bounds1 = Screen->Monitors[mon]->BoundsRect; // получаем границы
//Form3->SetBounds(Bounds1.Left,Bounds1.Top,Bounds1.Left-260,Bounds1.Top+768);
Form2->SetBounds(Bounds1.Left,Bounds1.Top,Bounds1.Left+1024,Bounds1.Top+767);
textmess = textmess + "\n\r" + "Координаты 3-го экрана " + IntToStr(Bounds1.left) + "X" + IntToStr(Bounds1.Top);
}

Form1->Show();
ShowMessage(textmess);

hDLL = LoadLibrary("K8061.DLL");
	if (hDLL != NULL)
	{
		OpenDevice = (t_func5) GetProcAddress(hDLL, "OpenDevice");
		if (!OpenDevice)
		{						// handle the error
			FreeLibrary(hDLL);
	 		Label1->Caption="Нет соединения";
		}
		CloseDevices = (t_func0) GetProcAddress(hDLL, "CloseDevices");
		if (!CloseDevices)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не закрылось подключение";
		}
		ReadAnalogChannel = (t_func7) GetProcAddress(hDLL, "ReadAnalogChannel");
		if (!ReadAnalogChannel)
		{
                        FreeLibrary(hDLL);					// handle the error
			Label1->Caption="Не удалось прочитать аналоговый вход";
		}
		ReadAllAnalog = (t_func4) GetProcAddress(hDLL, "ReadAllAnalog");
		if (!ReadAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось прочитать все аналоговые входы";
		}
		OutputAnalogChannel = (t_func3) GetProcAddress(hDLL, "OutputAnalogChannel");
		if (!OutputAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось установить аналоговый выход";
		}
		OutputAllAnalog = (t_func4) GetProcAddress(hDLL, "OutputAllAnalog");
		if (!OutputAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось установить все аналоговые выходы";
		}
		ClearAnalogChannel = (t_func2) GetProcAddress(hDLL, "ClearAnalogChannel");
		if (!ClearAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось сбросить аналоговый выход";
		}
		ClearAllAnalog = (t_func1) GetProcAddress(hDLL, "ClearAllAnalog");
		if (!ClearAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось сбросить все аналоговые выходы";
		}
		SetAnalogChannel = (t_func2) GetProcAddress(hDLL, "SetAnalogChannel");
		if (!SetAnalogChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось (!) установить аналоговый выход";
		}
		SetAllAnalog = (t_func1) GetProcAddress(hDLL, "SetAllAnalog");
		if (!SetAllAnalog)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось (!) установить все аналоговые выходы";
		}
		OutputAllDigital = (t_func2) GetProcAddress(hDLL, "OutputAllDigital");
		if (!OutputAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось установить все цифровые выходы";
		}
		ClearDigitalChannel = (t_func2) GetProcAddress(hDLL, "ClearDigitalChannel");
		if (!ClearDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось сбросить цифровой выход";
		}
		ClearAllDigital = (t_func1) GetProcAddress(hDLL, "ClearAllDigital");
		if (!ClearAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось сбросить все цифровые выходы";
		}
		SetDigitalChannel = (t_func2) GetProcAddress(hDLL, "SetDigitalChannel");
		if (!SetDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось установить цифровой выход";
		}
		SetAllDigital = (t_func1) GetProcAddress(hDLL, "SetAllDigital");
		if (!SetAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось установить все цифровые выходы";
		}
		ReadDigitalChannel = (t_func8) GetProcAddress(hDLL, "ReadDigitalChannel");
		if (!ReadDigitalChannel)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось прочитать цифровой вход";
		}
		ReadAllDigital = (t_func6) GetProcAddress(hDLL, "ReadAllDigital");
		if (!ReadAllDigital)
		{						// handle the error
			FreeLibrary(hDLL);
			Label1->Caption="Не удалось прочитать все цифровые входы";
		}
/*		Version = (t_func0) GetProcAddress(hDLL, "Version");
		if (!Version)
		{						// handle the error
			FreeLibrary(hDLL);
			return -19;
		}

*/
        CardAddress = OpenDevice();
        if(CardAddress == 0){
       	Label5->Caption="Контроллер K8061 #1 подключен ";
        controllerflag = 0;
        }else{
        Label5->Caption="Проверьте соединение с контроллером K8061 #1";
        controllerflag = 1;
        }
        foundDLL = 1;
       // FreeLibrary(hDLL);
        			                        // OK
        }
        else
        {
	Label5->Caption="DLL не найдена K8061";
        				// error load DLL
        }

        CardAddress2 = OpenDevice();
        if(CardAddress2 == 1){
       	Label34->Caption="Контроллер K8061 #2 подключен ";
        controllerflag = 0;
        }else{
        Label34->Caption="Проверьте соединение с контроллером K8061 #2";
        controllerflag = 1;
        }
        CloseDevices();
        FreeLibrary(hDLL);

        hDLL1 = LoadLibrary("k8055d");
	if (hDLL1 != NULL)
	{
		OpenDevice1 = (t1_func4) GetProcAddress(hDLL1, "OpenDevice");
		if (!OpenDevice1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		CloseDevices1 = (t1_func0) GetProcAddress(hDLL1, "CloseDevice");
		if (!CloseDevices1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ReadAnalogChannel1 = (t1_func4) GetProcAddress(hDLL1, "ReadAnalogChannel");
		if (!ReadAnalogChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ReadAllAnalog1 = (t1_func2) GetProcAddress(hDLL1, "ReadAllAnalog");
		if (!ReadAllAnalog1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		OutputAnalogChannel1 = (t1_func3) GetProcAddress(hDLL1, "OutputAnalogChannel");
		if (!OutputAnalogChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		OutputAllAnalog1 = (t1_func3) GetProcAddress(hDLL1, "OutputAllAnalog");
		if (!OutputAllAnalog1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ClearAnalogChannel1 = (t1_func) GetProcAddress(hDLL1, "ClearAnalogChannel");
		if (!ClearAnalogChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ClearAllAnalog1 = (t1_func0) GetProcAddress(hDLL1, "ClearAllAnalog");
		if (!ClearAllAnalog1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		SetAnalogChannel1 = (t1_func) GetProcAddress(hDLL1, "SetAnalogChannel");
		if (!SetAnalogChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		SetAllAnalog1 = (t1_func0) GetProcAddress(hDLL1, "SetAllAnalog");
		if (!SetAllAnalog1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		WriteAllDigital1 = (t1_func) GetProcAddress(hDLL1, "WriteAllDigital");
		if (!WriteAllDigital1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ClearDigitalChannel1 = (t1_func) GetProcAddress(hDLL1, "ClearDigitalChannel");
		if (!ClearDigitalChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ClearAllDigital1 = (t1_func0) GetProcAddress(hDLL1, "ClearAllDigital");
		if (!ClearAllDigital1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		SetDigitalChannel1 = (t1_func) GetProcAddress(hDLL1, "SetDigitalChannel");
		if (!SetDigitalChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		SetAllDigital1 = (t1_func0) GetProcAddress(hDLL1, "SetAllDigital");
		if (!SetAllDigital1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ReadDigitalChannel1 = (t1_func5) GetProcAddress(hDLL1, "ReadDigitalChannel");
		if (!ReadDigitalChannel1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		ReadAllDigital1 = (t1_func1) GetProcAddress(hDLL1, "ReadAllDigital");
		if (!ReadAllDigital1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}
		Version_1 = (t1_func0) GetProcAddress(hDLL1, "Version");
		if (!Version_1)
		{						// handle the error
			FreeLibrary(hDLL1);

		}



        CardAddress1 = OpenDevice1(3);


        if(CardAddress1 == 3){
       	Label2->Caption="Контроллер K8055 подключен ";
        controllerflag1 = 0;
        }else{
        Label2->Caption="Проверьте соединение с контроллером K8055";
        controllerflag1 = 1;
        }
         CloseDevices1();
        foundDLL1 = 1;
        			                        // OK
        }
        else
        {
	Label2->Caption="DLL K8055 не найдена";
        				// error load DLL
        }

    if (controllerflag == 0 && controllerflag1 == 0){
       Label19->Caption="Контроллеры подключены";
    }else{
    controllerflag=1;
    Label19->Caption="Ошибка подключения контроллеров";
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{

flagScene=true;
timecount=3600;      //----------------установка часа для обратного отсчета
timenull=1;
Label1->Caption="Фоновое сообщение. ИГРА НАЧАЛАСЬ !";
Button72Click(Form1);
check14=true;
//-----------------------------------обновление надписей пройденных стадий игры
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][20]) > 0){
        StringGrid2->Cells[2][20] = 0;
        }else{
        StringGrid2->Cells[2][20] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)      //----------------------------------ТАЙМЕР
{
int a,b,c,d,min,sec,a1,b1,c1,d1,min1,sec1;
AnsiString timeput,timeput1;
//---------------------------------------------------------глобальный счетчик для задержек
timercount++;

//-----------------------------------------------общий счетчик прохождения игры
if(timecountrealflag){
        timecountreal++;
        timecount--;
}
//---------------------------------------------------------глобальный обратный отсчет времени

if(timecount < 0){timecount=0;}
//--------------------------------------------обработка времени обратного отсчета
//----------------------------int to time
min=timecount/60;
sec=timecount-(min*60);
//----------------------------convert
a=min/10;
b=min-(a*10);
c=sec/10;
d=sec-(c*10);
//---------------------------
timeput=IntToStr(a) +  IntToStr(b) + ":" +  IntToStr(c) + IntToStr(d);
Label26->Caption=timeput;
//---------------------------------------------обработка времени общего игры
//----------------------------int to time
min1=timecountreal/60;
sec1=timecountreal-(min1*60);
//----------------------------convert
a1=min1/10;
b1=min1-(a1*10);
c1=sec1/10;
d1=sec1-(c1*10);
//---------------------------
timeput1=IntToStr(a1) +  IntToStr(b1) + ":" +  IntToStr(c1) + IntToStr(d1);
Label45->Caption=timeput1;           //------------------общее время игры
//-----------------------------------мигание подсветки призмы
if(flagblink == 1){

                }
//-----------------------------------------------------------
}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{

byte inpdig;

flagScene=false;
Label1->Caption="";

Timer1->Enabled=true;
Timer2->Enabled=true;

stopflag=0;

AnsiString temppath="";

//------------------------------------------------------запускаем поток
    if (FMyThread) {
        ShowMessage("Thread is already launched");
    }
    else {
        FMyThread = new TMyThread(false);
        FMyThread->FreeOnTerminate = false;
}
   if (FMyThread1) {
        ShowMessage("Thread1 is already launched");
    }
    else {
        FMyThread1 = new TMyThread1(false);
        FMyThread1->FreeOnTerminate = false;
}
   if (FMyThread2) {
        ShowMessage("Thread2 is already launched");
    }
    else {
        FMyThread2 = new TMyThread2(false);
        FMyThread2->FreeOnTerminate = false;
}
   if (FMyThread3) {
        ShowMessage("Thread3 is already launched");
    }
    else {
        FMyThread3 = new TMyThread3(false);
        FMyThread3->FreeOnTerminate = false;
}
   if (FMyThread4) {
        ShowMessage("Thread4 is already launched");
    }
    else {
        FMyThread4 = new TMyThread4(false);
        FMyThread4->FreeOnTerminate = false;
}
//-----------------------------------------------------------

FMyThread->goblink=false;
setPIO = true;   //-----------первоначальная установка выходов

int i=0;
int j=0;
int f=0;             //------счетчик цифр телефонного номера
int m = 0;
byte digAA1,digAA2,digAA3,digAA4,digAA5,digAA6,digAA7,digAA8;
byte digBB[20];
byte digA1,digA2,digA3,digA4,digA5,digA6,digA7,digA8;
byte digB1,digB2,digB3,digB4,digB5,digB6,digB7,digB8;
byte digC1,digC2,digC3,digC4;

while(stopflag != 1){
   Sleep(5);
   Label19->Caption="Выполняется цикл опроса.";

  //--------------------------------------------записываем в скоростной массив данные о выходах
  if(StrToInt(StringGrid2->Cells[2][1]) == 1){digAA1=true;}else{digAA1=false;}
  if(StrToInt(StringGrid2->Cells[2][2]) == 1){digAA2=true;}else{digAA2=false;}
  if(StrToInt(StringGrid2->Cells[2][3]) == 1){digAA3=true;}else{digAA3=false;}
  if(StrToInt(StringGrid2->Cells[2][4]) == 1){digAA4=true;}else{digAA4=false;}
  if(StrToInt(StringGrid2->Cells[2][5]) == 1){digAA5=true;}else{digAA5=false;}
  if(StrToInt(StringGrid2->Cells[2][6]) == 1){digAA6=true;}else{digAA6=false;}
  if(StrToInt(StringGrid2->Cells[2][7]) == 1){digAA7=true;}else{digAA7=false;}
  if(StrToInt(StringGrid2->Cells[2][8]) == 1){digAA8=true;}else{digAA8=false;}

  for(m = 0; m < 20; m++){
   if(StrToInt(StringGrid2->Cells[2][25 + m]) == 1){digBB[m] = true;}else{digBB[m] = false;}
  }

  if(StrToInt(StringGrid2->Cells[2][9]) == 1){digA1=true;}else{digA1=false;}
  if(StrToInt(StringGrid2->Cells[2][10]) == 1){digA2=true;}else{digA2=false;}
  if(StrToInt(StringGrid2->Cells[2][11]) == 1){digA3=true;}else{digA3=false;}
  if(StrToInt(StringGrid2->Cells[2][12]) == 1){digA4=true;}else{digA4=false;}
  if(StrToInt(StringGrid2->Cells[2][13]) == 1){digA5=true;}else{digA5=false;}
  if(StrToInt(StringGrid2->Cells[2][14]) == 1){digA6=true;}else{digA6=false;}
  if(StrToInt(StringGrid2->Cells[2][15]) == 1){digA7=true;}else{digA7=false;}
  if(StrToInt(StringGrid2->Cells[2][16]) == 1){digA8=true;}else{digA8=false;}

  if(StrToInt(StringGrid2->Cells[2][17]) == 1){digB1=true;}else{digB1=false;}
  if(StrToInt(StringGrid2->Cells[2][18]) == 1){digB2=true;}else{digB2=false;}
  if(StrToInt(StringGrid2->Cells[2][19]) == 1){digB3=true;}else{digB3=false;}
  if(StrToInt(StringGrid2->Cells[2][20]) == 1){digB4=true;}else{digB4=false;}
  if(StrToInt(StringGrid2->Cells[2][21]) == 1){digB5=true;}else{digB5=false;}
  if(StrToInt(StringGrid2->Cells[2][22]) == 1){digB6=true;}else{digB6=false;}
  if(StrToInt(StringGrid2->Cells[2][23]) == 1){digB7=true;}else{digB7=false;}
  if(StrToInt(StringGrid2->Cells[2][24]) == 1){digB8=true;}else{digB8=false;}

  if(StrToInt(StringGrid3->Cells[2][1]) == 1){digC1 = true;}else{digC1 = false;}
  if(StrToInt(StringGrid3->Cells[2][2]) == 1){digC2 = true;}else{digC2 = false;}
  if(StrToInt(StringGrid3->Cells[2][3]) == 1){digC3 = true;}else{digC3 = false;}
  if(StrToInt(StringGrid3->Cells[2][4]) == 1){digC4 = true;}else{digC4 = false;}
  //----------------------------------------------------записываем данные о выходах в поток
  if (controllerflag == 0){

  FMyThread->digAA1=digAA1;
  FMyThread->digAA2=digAA2;
  FMyThread->digAA3=digAA3;
  FMyThread->digAA4=digAA4;
  FMyThread->digAA5=digAA5;
  FMyThread->digAA6=digAA6;
  FMyThread->digAA7=digAA7;
  FMyThread->digAA8=digAA8;

  for(m = 0; m < 20; m++){
   FMyThread->digBB[m] = digBB[m];
  }

  FMyThread->digA1=digA1;
  FMyThread->digA2=digA2;
  FMyThread->digA3=digA3;
  FMyThread->digA4=digA4;
  FMyThread->digA5=digA5;
  FMyThread->digA6=digA6;
  FMyThread->digA7=digA7;
  FMyThread->digA8=digA8;

  FMyThread->digB1=digB1;
  FMyThread->digB2=digB2;
  FMyThread->digB3=digB3;
  FMyThread->digB4=digB4;
  FMyThread->digB5=digB5;
  FMyThread->digB6=digB6;
  FMyThread->digB7=digB7;
  FMyThread->digB8=digB8;

  FMyThread->digC1=digC1;
  FMyThread->digC2=digC2;
  FMyThread->digC3=digC3;
  FMyThread->digC4=digC4;

  if(setPIO){
        FMyThread->set = true;
        setPIO = false;
        }

  //--------------------------------------------записываем данные о входах из потока

  if(readkey == 1){
  StringGrid1->Cells[2][1]=IntToStr((FMyThread->idigA & 1) > 0);
  StringGrid1->Cells[2][2]=IntToStr((FMyThread->idigA & 2) > 0);
  StringGrid1->Cells[2][3]=IntToStr((FMyThread->idigA & 4) > 0);
  StringGrid1->Cells[2][4]=IntToStr((FMyThread->idigA & 8) > 0);
  StringGrid1->Cells[2][5]=IntToStr((FMyThread->idigA & 16) > 0);
  StringGrid1->Cells[2][6]=IntToStr((FMyThread->idigA & 32) > 0);
  StringGrid1->Cells[2][7]=IntToStr((FMyThread->idigA & 64) > 0);
  StringGrid1->Cells[2][8]=IntToStr((FMyThread->idigA & 128) > 0);

  StringGrid1->Cells[2][23]=IntToStr((FMyThread->idigD & 1) > 0);
  StringGrid1->Cells[2][24]=IntToStr((FMyThread->idigD & 2) > 0);
  StringGrid1->Cells[2][25]=IntToStr((FMyThread->idigD & 4) > 0);
  StringGrid1->Cells[2][26]=IntToStr((FMyThread->idigD & 8) > 0);
  StringGrid1->Cells[2][27]=IntToStr((FMyThread->idigD & 16) > 0);
  StringGrid1->Cells[2][28]=IntToStr((FMyThread->idigD & 32) > 0);
  StringGrid1->Cells[2][29]=IntToStr((FMyThread->idigD & 64) > 0);
  StringGrid1->Cells[2][30]=IntToStr((FMyThread->idigD & 128) > 0);

  StringGrid1->Cells[2][17]=IntToStr((FMyThread->idigB & 1) > 0);
  StringGrid1->Cells[2][18]=IntToStr((FMyThread->idigB & 2) > 0);
  StringGrid1->Cells[2][19]=IntToStr((FMyThread->idigB & 4) > 0);
  StringGrid1->Cells[2][20]=IntToStr((FMyThread->idigB & 8) > 0);
  StringGrid1->Cells[2][21]=IntToStr((FMyThread->idigB & 16) > 0);
  StringGrid1->Cells[2][22]=IntToStr(FMyThread->idigC);

  for (int i=1; i<9; i++){
                        StringGrid1->Cells[2][i+8]=IntToStr(FMyThread->imasanalog[i-1]);
                        }
  for (int i=1; i<9; i++){
                        StringGrid1->Cells[2][i+30]=IntToStr(FMyThread->imasanalog2[i-1]);
                        }
 } //--------------------readkey flag end

 }//------------------------controllerflag end
//------------------------------------------------отслеживание кнопки СТАРТ 1 и старт легенды
if(startcontrol1){
        if(StringGrid1->Cells[2][17] == "0"){
                   timevalueLEGflag=true;
                   timevalueLEG=timercount + 77;
                   startcontrol1=false;
        }
}
//------------------------------------------------отслеживание кнопки СТАРТ 2
if(startcontrol2){
        if(StringGrid1->Cells[2][17] == "0"){
                   startcontrol2=false;
                   Button9Click(Form1);
        }
}
//-----------------------------------------------------------------------ТАЙМЕР 0
if(timecount == 0 && flaglooser == 0){

        if(timenull == 1 && flagtimenull == 0){   //-----если не успели дойти до посл комнаты
                                flaglooser=1;
                                Button70Click(Form1);
                                Label1->Caption="Вышло время";
                                }
//        if(flagtimenull == 1 && fatalscene == 2){  //---если не успели правильно пройти призму
//
//                              }
//        if(flagtimenull == 1 && fatalscene == 0){  //---------если не успели приложить ключи
//                              GetFatalScene();
//                              fatalscene=2;
//                             }
}
//--------------------------------------------------------------- обновление системных сообщений в интерфейсе
Label7->Caption = buffer1;

//-----------------------------------------------------------------запуск стадии по условию прохождения предыдущей

if(check14){Edit14->Text="Активен";}else{Edit14->Text="ВЫКЛ";}
if(check13){Button71Click(Form1);}
if(flagkassette == 0){Edit11->Text="ВЫКЛ";}
if(flagkassette == 1){Edit11->Text="Ожидает";}
if(flagkassette == 2){Edit11->Text="Пройден";}
if(check8){Button66Click(Form1);}
if(check7){Button65Click(Form1);}
if(check6){Button64Click(Form1);}
if(check5){Button63Click(Form1);}
if(check4){Button62Click(Form1);}
if(shitok_color){Edit10->Text="ЦВЕТ";}else{Edit10->Text="";}
if(shitok_name){Edit15->Text="ИМЯ";}else{Edit15->Text="";}
if(shitok_memory){Edit16->Text="ПАМЯТЬ";}else{Edit16->Text="";}
if(check2){Button60Click(Form1);}

switch(stagestatus1){
     case 1:
     Edit18->Text="Ожидание";
     break;

     case 2:
     Edit18->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus2){
     case 1:
     Edit1->Text="Ожидание";
     break;

     case 2:
     Edit1->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus3){
     case 1:
     Edit19->Text="Ожидание";
     break;

     case 2:
     Edit19->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus4){
     case 1:
     Edit2->Text="Ожидание";
     break;

     case 2:
     Edit2->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus5){
     case 1:
     Edit3->Text="Ожидание";
     break;

     case 2:
     Edit3->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus6){
     case 1:
     Edit4->Text="Ожидание";
     break;

     case 2:
     Edit4->Text="НОМЕР OK";
     break;

     case 3:
     Edit4->Text="БЕЗ НОМЕРА";
     break;

     default:
     break;
}
switch(stagestatus7){
     case 1:
     Edit20->Text="Ожидание";
     break;

     case 2:
     Edit20->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus8){
     case 1:
     Edit5->Text="Ожидание";
     break;

     case 2:
     Edit5->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus9){
     case 1:
     Edit6->Text="Ожидание";
     break;

     case 2:
     Edit6->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus10){
     case 1:
     Edit7->Text="Ожидание";
     break;

     case 2:
     Edit7->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus11){
     case 1:
     Edit17->Text="Ожидание";
     break;

     case 2:
     Edit17->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus12){
     case 1:
     Edit8->Text="Ожидание";
     break;

     case 2:
     Edit8->Text="Выполнен";
     break;

     default:
     break;
}

switch(stagestatus13){
     case 1:
     Edit9->Text="Ожидание";
     break;

     case 2:
     Edit9->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus14){
     case 1:
     Edit12->Text="Ожидание";
     break;

     case 2:
     Edit12->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus15){
     case 1:
     Edit13->Text="Ожидание";
     break;

     case 2:
     Edit13->Text="Выполнен";
     break;

     default:
     break;
}
switch(stagestatus16){
     case 1:
     Edit14->Text="Ожидание";
     break;

     case 2:
     Edit14->Text="Выполнен";
     break;

     default:
     break;
}
//-------------------------------------------------------------------------------ПЕРЕКЛЮЧЕНИЕ КАНАЛОВ АУДИО ПРИ ОТЛОЖЕННОМ ВОСПРОИЗВЕДЕНИИ
buffer1_ansi = buffer1;

if(delaysound_flag){
        if(buffer1_ansi == "false"){//ждем когда доиграет звук и тогда переключим канал
                        SetRelaySound(delaysound_channel);
                        delaysound_flag = false;
        }
}
//------------------------------------------------------------------------------НОМЕР ИГРОКОВ ЗВУКОМ
if(numberplayer_flag){
     if(buffer1_ansi == "false"){
        PlayNumberPlayers(true, "");
        numberplayer_flag = false;
     }
}
//-------------------------------------------------------------------------------АВАРИЙНАЯ КНОПКА ВЫХОДА
if(check15){
     if(StrToInt(StringGrid1->Cells[2][11]) > 900){
                FMyThread1->textflag=false;
                FMyThread1->counttext=1;
                FMyThread1->text[1]="";
                FMyThread1->speedtext1=0;
                FMyThread1->speedtext2=0;
                Label1->Caption="Нажали кнопку подсказок, экраны погасли.";
                FPlaySound("smeh", 1);
                }

     if(StringGrid1->Cells[2][2] == "0"){
                FMyThread1->textflag=false;
                FMyThread1->counttext=1;
                FMyThread1->text[1]="";
                FMyThread1->speedtext1=0;
                FMyThread1->speedtext2=0;
                Label1->Caption="Нажали кнопку подсказок, экраны погасли.";
                FPlaySound("smeh", 1);
                }
     if(StringGrid1->Cells[2][7] == "0"){
                        StringGrid2->Cells[2][14]="0";
                        StringGrid2->Cells[2][7]="0";
                        FMyThread->set=true;
                        Label1->Caption="Нажали аварийную кнопку открытия выходной двери";
                        StopScene();
                        }
}
//--------------------------------------------------------------------------------1-й этап
if(check0){
                //---------------0 уровень диалога
           if(startdialog_level == 0){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600){

                        FMyThread2->text[1]="\n\n Выберите режим игры:\n ДА. Триллер\n НЕТ. Драма";
                        FMyThread2->speedtext1=30;
                        FMyThread2->speedtext2=500;
                        FMyThread2->size[1]=32;
                        FMyThread2->textflag=true;
                        // timevaluestartflag=true;
                        // timevaluestart=timercount + 43;
                        FPlaySound("Echo_Main_Messages\\0_0_choosegame", 1);
                        dialog_flag = true;
                        }else{
                             if(dialog_flag){
                                            startdialog_level = 1;
                                            dialog_flag = false;
                                            };
                        }
                }
                //---------------1 уровень диалога
           if(startdialog_level == 1){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                      dialog1->triller = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                      dialog1->drama = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 600){//-------при нажатии на любую
                     FMyThread2->text[1]="\n\n Вы уверены в своем выборе?\n ДА. Начать игру\n НЕТ. Обратно в меню";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FPlaySound("Echo_Main_Messages\\0_0_confirmgame", 1);
                     dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 2;
                                    dialog_flag = false;
                                    };
                     }
           }
                 //---------------2 уровень диалога
           if(startdialog_level == 2){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                     FMyThread2->text[1]="\n ДОБРО ПОЖАЛОВАТЬ!\n\n";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=54;
                     FMyThread2->textflag=true;
                     timevaluestartflag=true;
                     timevaluestart=timercount + 13;
                     FPlaySound("Echo_Main_Messages\\0_1_system_instraction", 1);
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                        FMyThread2->text[1]="\n\n Выберите режим игры:\n ДА. Триллер\n НЕТ. Драма";
                        FMyThread2->speedtext1=30;
                        FMyThread2->speedtext2=500;
                        FMyThread2->size[1]=32;
                        FMyThread2->textflag=true;
                        // timevaluestartflag=true;
                        // timevaluestart=timercount + 43;
                        FPlaySound("Echo_Main_Messages\\0_0_choosegame", 1);
                        dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 1;
                                    dialog_flag = false;
                                    };
                     }
           }
                           //---------------3 уровень диалога
           if(startdialog_level == 3){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600){ //-----любая кнопка
                     FMyThread2->text[1]="\n Мне трудно понять\n людей, которые плохо \n относятся к моим советам.";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FMyThread2->textflag=true;
                     dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 4;
                                    dialog_flag = false;
                                    };
                     }
           }
                                      //---------------4 уровень диалога
           if(startdialog_level == 4){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                        dialog1->question1 = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                        dialog1->question1 = false;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 600) {
                     FMyThread2->text[1]="\n Иногда мне кажется, \n что я знаю, чего хотят \n люди, лучше их самих.";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FMyThread2->textflag=true;
                     dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 5;
                                    dialog_flag = false;
                                    };
                     }

           }
                                                 //---------------5 уровень диалога
           if(startdialog_level == 5){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                        dialog1->question2 = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                        dialog1->question2 = false;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 600) {
                     FMyThread2->text[1]="\n Нет таких обстоятельств,\n когда выбор против \n воли другого оправдан.";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FMyThread2->textflag=true;
                     dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 6;
                                    dialog_flag = false;
                                    };
                     }

           }
                                                           //---------------6 уровень диалога
           if(startdialog_level == 6){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                        dialog1->question3 = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                        dialog1->question3 = false;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 600) {
                     FMyThread2->text[1]="\n Иногда проще просто заставить \n человека сделать что-то,\n чем разъяснять ему детали.";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FMyThread2->textflag=true;
                     dialog_flag = true;
                }else{
                     if(dialog_flag){
                                    startdialog_level = 7;
                                    dialog_flag = false;
                                    };
                     }

           }
                                                               //---------------7 уровень диалога
           if(startdialog_level == 7){
                if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                        dialog1->question4 = true;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                        dialog1->question4 = false;
                }
                if(StrToInt(StringGrid1->Cells[2][37]) < 600) {
                     FMyThread2->text[1]="\n\n БЛАГОДАРИМ ЗА ОТВЕТЫ";
                     FMyThread2->speedtext1=30;
                     FMyThread2->speedtext2=500;
                     FMyThread2->size[1]=32;
                     FMyThread2->textflag=true;
                     startdialog_level = 7;
                     FPlaySound("Echo_Main_Messages\\0_2_testcompleted", 1);
                     timevaluestart1flag=true;
                     timevaluestart1=timercount + 6;
                     startdialog_level = -1;
                     check0=false;
                }

           }
}
if(check0_1){   //--------------------------------------------------------------продолжение 1-й этап

        if(flagGM1 || StringGrid1->Cells[2][17] == "0"){
                check0_1=false;
              //  countdownflag=false;
                Label1->Caption="Рычаг старта игры активировали";
                FMyThread2->text[1]="\n ПОДГОТОВКА \n КОНФИГУРАЦИИ";
                FMyThread2->speedtext1=30;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=54;
                FMyThread2->textflag=true;
                FPlaySound("Echo_Main_Messages\\0_2_startecho",1);

                timevaluestart2flag=true;
                timevaluestart2=timercount + 20;

                flagSM1=false;

        }
}
//--------------------------------------------------------------------------------2-й этап установка фигур
if(check0_2){
text_figura_status=" ГЕОМЕТРИЧЕСКИЙ ПРОЦЕССОР\n\n\n ПЛОСКОСТЬ А – ";
 if(StringGrid1->Cells[2][3] == "1" && StringGrid1->Cells[2][23] == "1" && StringGrid1->Cells[2][24] == "1" || flagGM2){
        check0_2=false;
        flagGM2 = false;
        stagestatus2 = 2;
        Label1->Caption="Все три фигуры установили правильно !";
        Button143Click(Form1);
        }else{

        if(StringGrid1->Cells[2][3] == "1"){
                if(!flag_figura1){FPlaySound("Echo_Main_Messages\\1_1_goodwork", 1); flag_figura1 = true;};
                text_figura_status += "ВКЛ";

        }else{
                flag_figura1 = false;
                text_figura_status += "ВЫКЛ";
        }

        text_figura_status += "\n\n ПЛОСКОСТЬ B – ";
        if(StringGrid1->Cells[2][23] == "1"){
                if(!flag_figura2){FPlaySound("Echo_Main_Messages\\1_1_goodwork", 1); flag_figura2 = true;};
                text_figura_status += "ВКЛ";
        }else{
                flag_figura2 = false;
                text_figura_status += "ВЫКЛ";
        }

        text_figura_status += "\n\n ПЛОСКОСТЬ C – ";
        if(StringGrid1->Cells[2][24] == "1"){
                if(!flag_figura3){FPlaySound("Echo_Main_Messages\\1_1_goodwork", 1); flag_figura3 = true;};
                text_figura_status += "ВКЛ";
        }else{
                flag_figura3 = false;
                text_figura_status += "ВЫКЛ";
        }

        text_figura_status += "       \n         \n        ";

        if(geometry_change != text_figura_status){
                FMyThread1->text[1] = text_figura_status.c_str();
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=20;
                FMyThread1->speedtext2=40;
                FMyThread1->size[1]=32;
                FMyThread1->textflag=true;
                geometry_change = text_figura_status;
                }
        }

}
//--------------------------------------------------------------------------------ДИАЛОГ
if(check0_3){
  if(dialogMain->index != 0){
     if(flag_maindialog){
        FMyThread1->text[1]=(dialogMain->text[dialogMain->index]).c_str();
        FMyThread1->speedtext1=30;
        FMyThread1->speedtext2=500;
        FMyThread1->size[1]=50;
        FMyThread1->textflag=true;
        flag_maindialog = false;
        if(dialogMain->index != 15 ){  // 15 файла не существует, это первый этап диалога
                FPlaySound("Echo_Story1_Dialog1\\" + IntToStr(dialogMain->index), 1);
        }

     }
     if(!flag_maindialog && flag_maindialog_ready){
        if(StrToInt(StringGrid1->Cells[2][37]) < 600 && StrToInt(StringGrid1->Cells[2][37]) > 300){ //-----левая кнопка
                      flag_maindialog = true;
                      flag_maindialog_ready = false;
                      dialogMain->result = dialogMain->index;
                      dialogMain->index = dialogMain->Agoto[dialogMain->result];
                      if(dialogMain->index == 0){result_maindialog = dialogMain->GetResultCode(dialogMain->result, 1);}
        }
        if(StrToInt(StringGrid1->Cells[2][37]) < 300){//-------правая кнопка
                      flag_maindialog = true;
                      flag_maindialog_ready = false;
                      dialogMain->result = dialogMain->index;
                      dialogMain->index = dialogMain->Bgoto[dialogMain->result];
                      if(dialogMain->index == 0){result_maindialog = dialogMain->GetResultCode(dialogMain->result, 2);}
        }
     }
     if(StrToInt(StringGrid1->Cells[2][37]) > 600){
              flag_maindialog_ready = true;
     }
 }else{//-----------------выход из диалога
 timevalue1_2flag=true;
 timevalue1_2=timercount + 8;
                FMyThread1->text[1]="\n ГЛАВА 2. \n\n Тьма";
                FMyThread1->speedtext1=30;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=56;
                FMyThread1->textflag=true;
 check0_3 = false;
 }
}
//------------------------------------------------------------------------ТАЙМЕР ФОНАРЯ
if(fonarcheck){
        if(StrToInt(StringGrid1->Cells[2][31]) < 500  && StrToInt(StringGrid1->Cells[2][31]) > 200){
                fonar_light_flag = true;
        }
        if(timercount == (fonartimer - 3)){
                StringGrid2->Cells[2][19] = 0;
                if(fonar_light_flag){StringGrid2->Cells[2][3] = 1;}
                    else{
                        check1 = true;
                        fonarcheck = false;
                        }
                setPIO = true;
        }
        if(timercount > (fonartimer - 3)){
                if(StrToInt(StringGrid1->Cells[2][31]) < 200){
                        fonar_light_flag_2 = true;

                }
        }
        if(timercount == fonartimer){
                StringGrid2->Cells[2][3] = 0;
                setPIO = true;
                if(fonar_light_flag_2){
                                stagestatus4 = 2;
                                Button60Click(Form1);
                         }else{
                              check1 = true;
                             }
                fonarcheck = false;
                }
        }
//----------------------------------------------------------------------------- ФОНАРЬ СРАБАТЫВАНИЕ НА КНОПКУ
//-----------------------------------------------------------------------------------4-й этап  ФОНАРЬ
if(check_random_audio_0){
        Label13->Caption=IntToStr(timevaluerandommessage - timercount);

        if(key_check_random_audio){
             key_check_random_audio = false;
             timevaluerandommessage = timercount + 80;
        }

        if(timercount == timevaluerandommessage){
                key_check_random_audio = true;
                RandomPlaySound(1, 7, "Extra\\Extra_Messages_Breakdown", 1); //---max значение random на 1 больше реального
        }
}
//-----------------------------------------
//----------------------------------------

if(check1){
  if(StringGrid1->Cells[2][4] == "1"){
        fonartimer = timercount + 6;
        fonarcheck=true;
        StringGrid2->Cells[2][19] = 1;
        setPIO = true;
        check1 = false;
        }
}

//------------------------------------------------------------------------------------------------------------RANDOM AUDIO    RANDOM AUDIO
if(check_random_audio){
        Label13->Caption=IntToStr(timevaluerandommessage - timercount);

        if(key_check_random_audio){
             key_check_random_audio = false;
             timevaluerandommessage = timercount + 80;
        }

        if(timercount == timevaluerandommessage){
                key_check_random_audio = true;
                RandomPlaySound(1, 9, "Echo_Story1_Darkness\\Darkness1", 1);  //---max значение random на 1 больше реального
        }
}
if(check_random_audio_1){
        Label13->Caption=IntToStr(timevaluerandommessage - timercount);

        if(key_check_random_audio){
             key_check_random_audio = false;
             timevaluerandommessage = timercount + 80;
        }

        if(timercount == timevaluerandommessage){
                key_check_random_audio = true;
                RandomPlaySound(1, 8, "Echo_Story1_Darkness\\Darkness2", 1);  //---max значение random на 1 больше реального
        }
}
if(check_random_audio_cherdak){
        Label10->Caption=IntToStr(timevaluerandommessagecherdak - timercount);

        if(key_check_random_audio_cherdak){
             key_check_random_audio_cherdak = false;
             timevaluerandommessagecherdak = timercount + 80;
        }

        if(timercount == timevaluerandommessagecherdak){
                key_check_random_audio_cherdak = true;
                if(count_audio_random_cherdak < 4){
                        RandomPlaySoundDiff(1, 4, "Echo_Story1_Darkness\\Attic", 2);  //---max значение random на 1 больше реального
                        count_audio_random_cherdak++;
                }
        }
}
if(check_random_audio_moto){
        Label17->Caption=IntToStr(timevaluerandommessagemoto - timercount);

        if(key_check_random_audio_moto){
             key_check_random_audio_moto = false;
             timevaluerandommessagemoto = timercount + 25;
        }

        if(timercount == timevaluerandommessagemoto){
                key_check_random_audio_moto = true;
                RandomPlaySound(1, 9, "Extra\\Extra_Messages_Silence", 1);  //---max значение random на 1 больше реального
        }
}
if(check_random_audio_piano){
        Label27->Caption=IntToStr(timevaluerandommessagepiano - timercount);

        if(key_check_random_audio_piano){
             key_check_random_audio_piano = false;
             timevaluerandommessagepiano = timercount + 60;
        }

        if(timercount == timevaluerandommessagepiano){
                key_check_random_audio_piano = true;
                RandomPlaySound(1, 5, "Extra\\Extra_Messages_Piano", 1);  //---max значение random на 1 больше реального
        }
}
//------------------------------------------------------------------------------------------------------------RANDOM AUDIO    RANDOM AUDIO  END
//-----------------------------------------
if(check2_1){
//----------------------------------------------------------------------------------ЦВЕТ
if(!shitok_color){
        if(!colorflag && StrToInt(StringGrid1->Cells[2][10]) < 700){ //----------цвет
                colortimer=timercount+3;
                colorflag=true;
        }

        if(colorflag && StrToInt(StringGrid1->Cells[2][10]) > 700){
                colorflag=false;
        }

        if((colorflag && timercount == colortimer) || flagGM3_1){
                flagGM3_1=false;
                colorflag=false;
                flag_oneofthree = true;
                FPlaySound("Echo_Main_Messages\\4_4_colorok", 1);
                UpMemory(5);
                shitok_color=true;
                GetTextForTerminal();
                k=0;               //--------------------счетчик временных сообщений
                Label1->Caption="Кнопки цветового кодирования нажали";
        }
}
//-----------------------------------------------------------------------------------ИМЯ
if(!shitok_name){
        if(!nameflag && StrToInt(StringGrid1->Cells[2][9]) < 700){ //----------имя
                nametimer=timercount+3;
                nameflag=true;
        }

        if(nameflag && StrToInt(StringGrid1->Cells[2][9]) > 700){
                nameflag=false;
        }

        if((nameflag && (timercount == nametimer)) || flagGM3_2){
                flagGM3_2=false;
                nameflag=false;
                flag_oneofthree = true;
                FPlaySound("Echo_Main_Messages\\4_4_nameok", 1);
                Label1->Caption="Переключатели ИМЕНИ выставили";
                UpMemory(5);
                k=0;        //--------------------счетчик временных сообщений
                shitok_name=true;
                GetTextForTerminal();
        }
}
//-----------------------------------------------------------------------------     ПАМЯТЬ
if((!shitok_memory && StrToInt(StringGrid1->Cells[2][12]) < 700 && StrToInt(StringGrid1->Cells[2][13]) > 700) || flagGM3_3){  //----------память
        flagGM3_3=false;
        flag_oneofthree = true;
        check_random_audio_cherdak = false;
        FPlaySound("Echo_Main_Messages\\4_4_constructorok", 1);
        k=0;   //--------------------счетчик временных сообщений
        Label1->Caption="Переключатели ПАМЯТИ выставили";
        shitok_memory=true;
        UpMemory(10);
        GetTextForTerminal();
 }
//--------------------------------------------------------------------------------
if(fon3_1checkflag && flag_oneofthree){  //-------смена фона
        fon3_1checkflag=false;
        chain = false;
        check_random_audio = false;
        check_random_audio_1 = true;
        ChangeSoundWall("FON\\6_darkness_2");
}
//-----------------------------------------------------------------------------таймер завершение поднятия процента памяти
if(memorycount_flag){
        if(memorytimervalue == timercount){
                SetMemoryCount(memorycount,1);

                FMyThread1->counttext=2;
                FMyThread1->speedtext1=30;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=308;
                FMyThread1->size[2]=32;
                FMyThread1->digitflag=false;
                FMyThread1->textflag=true;

                memorycount_flag = false;
        }
}
//--------------------------------------------------------------------------------БУДКА ЦЕПЬ
if(chain){

        if(!timerdog_flag && StrToInt(StringGrid1->Cells[2][22]) < 10){
                timerdog_flag = true;
                timerdogvalue = timercount + 2;
        }
        if(timerdog_flag){
                if(StrToInt(StringGrid1->Cells[2][22]) > 10){timerdog_flag = false;}
                if(timercount == timerdogvalue){
                        count_chain++;
                        chain_audio = true;
                        timerdog_flag = false;
                }
        }
        //============================================

        //===============================================
        if(chain_audio){
        switch (count_chain){
                case 1:
                        FPlaySound("Echo_Main_Messages\\4_4_dogbark_1", 3);
                        check_random_audio_cherdak = true;
                        break;
                case 2:
                        FPlaySound("Echo_Main_Messages\\4_4_dogbark_2", 3);
                        break;
                case 3:
                        FPlaySound("Echo_Main_Messages\\4_4_dogbark_3", 3);
                        break;
                case 4:
                        FPlaySound("Echo_Main_Messages\\4_4_dogbark_4", 3);
                        break;
                default:
                        break;
        };
        chain_audio = false;
        }
        if(count_chain >= 4){chain = false;}
}
 //----------------------------------===-----------------------------------------КОНЕЦ БУДКА ЦЕПЬ


if((shitok_color && shitok_name && shitok_memory) || flagGM3){

        flagGM3=false;
        check_random_audio_cherdak = false;
        check_random_audio_1 = false;
        timevalue3=timercount + 5;
        timevalue3flag=true;
        check2_1=false;
        Label1->Caption="Три задачи терминала пройдены !";
        }
}


//-----------------------------------------------------------------------------------------6-й этап номер дома
if(check3_1){

if(StrToInt(StringGrid1->Cells[2][14]) < 570 && number_flag){
        number_timer=timercount + 2;
        number_flag=false;
        }
  if(StrToInt(StringGrid1->Cells[2][14]) > 570 && !number_flag){
        number_timer = 0;
        number_flag=true;
        }

if(number_timer == timercount || flagGM4){

stagestatus6 = 2;
Label1->Caption="Выставили номер дома и прошли !";
check3_1=false;
flagSM4=false;
Button151Click(Form1);
}

if(StrToInt(StringGrid1->Cells[2][14]) > 570 && StringGrid1->Cells[2][2] == "1"){
if((checkworktimer1 + 1) < timercount && !timevalue4_1flag){
        if(!CheckPlayMessages()){
        checkworktimer1 = timercount;
        k++;
        Label15->Caption=IntToStr(k);
        Label1->Caption="Нажали кнопку звонка дома " + IntToStr(k) + " раз";
        if(k < 11){
                  FPlaySound("Echo_Main_Messages\\Story1_zvonok\\"+IntToStr(k), 1);
                  }

        if(k > 10)
                 {
                        flagSM4=false;
                        check3_1 = false;
                        stagestatus6 = 3;
                        Label1->Caption="Прошли в дом без решения номера дома !";
                        Button151Click(Form1);
                 }

       }
 }
 }

}
//-----------------------------------------------------------------------------------ДОМ АКТИВАЦИЯ ЭЛЕМЕНТОВ
if(check4_0){
//----------------------------------------звуковые сообщения
 if(StringGrid1->Cells[2][6] != tempbook){
         tempbook = StringGrid1->Cells[2][6];
 if(timercount - checkworktimer2 > 1){
      if(dom1c < 1){
        FPlaySound("Echo_Main_Messages\\6_2_activated", 1);
        Label1->Caption="Потеребили книгу домика";
        checkworktimer2 = timercount;
        domcount++;
        dom1c++;
        z++;
        if(z == 1){housecounttext="1 / 4";}
        if(z == 2){housecounttext="2 / 4";}
        if(z == 3){housecounttext="3 / 4";}
        if(z == 4){housecounttext="4 / 4";}
        FMyThread1->text[2]=housecounttext;
      }
 }
 }

 if(StringGrid1->Cells[2][7] == "1" && dom2c < 1){
 if(timercount - checkworktimer2 > 1){
     FPlaySound("Echo_Main_Messages\\6_2_activated", 1);
        Label1->Caption="Нажали кнопку настольной лампы";
        checkworktimer2 = timercount;
        domcount++;
        dom2c++;
        z++;
        if(z == 1){housecounttext="1 / 4";}
        if(z == 2){housecounttext="2 / 4";}
        if(z == 3){housecounttext="3 / 4";}
        if(z == 4){housecounttext="4 / 4";}
        FMyThread1->text[2]=housecounttext;

     }
 }

  if(StrToInt(StringGrid1->Cells[2][34]) < 350 && dom3c < 1){
 if(timercount - checkworktimer2 > 1){
        FPlaySound("Echo_Main_Messages\\6_2_activated", 1);
        Label1->Caption="Нажали теелфон";
        checkworktimer2 = timercount;
        domcount++;
        dom3c++;
        z++;
        if(z == 1){housecounttext="1 / 4";}
        if(z == 2){housecounttext="2 / 4";}
        if(z == 3){housecounttext="3 / 4";}
        if(z == 4){housecounttext="4 / 4";}
        FMyThread1->text[2]=housecounttext;

 }
 }

  if(StringGrid1->Cells[2][5] != tempambrella){
        tempambrella =  StringGrid1->Cells[2][5];
 if(timercount - checkworktimer2 > 1){
      if(dom4c < 1){
        FPlaySound("Echo_Main_Messages\\6_2_activated", 1);
        Label1->Caption="Потеребили крючок зонтика";
        checkworktimer2 = timercount;
        domcount++;
        dom4c++;
        z++;
        if(z == 1){housecounttext="1 / 4";}
        if(z == 2){housecounttext="2 / 4";}
        if(z == 3){housecounttext="3 / 4";}
        if(z == 4){housecounttext="4 / 4";}
        FMyThread1->text[2]=housecounttext;
      }
 }
 }


 if(domcount == 4){
        domcount = 0;
        dom1t=0;
        dom2t=0;
        dom3t=0;
        dom4t=0;
        stagestatus7 = 2;
        Button62Click(Form1);
        check4_0=false;
        }


}//--------------------------------------------------------------------------------7-й этап   ДОМИК
if(check4){
 //flagScene=true;
 //SetManualBeforeStage(4);

 //----------------------------------------звуковые сообщения
 if(StringGrid1->Cells[2][6] != tempbook){
        tempbook = StringGrid1->Cells[2][6];
 if(timercount - checkworktimer2 > 1){
        if(dom1c < 1){FPlaySound("NARRATIVE\\Book2", 1);}else{FPlaySound("NARRATIVE\\Book2", 1);}
        Label1->Caption="Потеребили книгу домика";
        dom1t=dom2t;
        dom2t=dom3t;
        dom3t=dom4t;
        dom4t=1;
        checkworktimer2 = timercount;
        domcount++;
        dom1c++;
        SetLampTable(dom1t,dom2t,dom3t,dom4t);
 }
 }

  if(StringGrid1->Cells[2][7] == "1"){
 if(timercount - checkworktimer2 > 1){
     if(dom2c < 1){FPlaySound("NARRATIVE\\Desk2", 1);}else{FPlaySound("NARRATIVE\\Desk2", 1);}
        Label1->Caption="Нажали кнопку настольной лампы";
        dom1t=dom2t;
        dom2t=dom3t;
        dom3t=dom4t;
        dom4t=2;
        checkworktimer2 = timercount;
        domcount++;
        dom2c++;
        SetLampTable(dom1t,dom2t,dom3t,dom4t);
}
 }

  if(StrToInt(StringGrid1->Cells[2][34]) < 350){
 if(timercount - checkworktimer2 > 1){
      if(dom3c < 1){FPlaySound("NARRATIVE\\telephone", 1);}else{FPlaySound("NARRATIVE\\telephone", 1);}
        Label1->Caption="Нажали телефон";
        dom1t=dom2t;
        dom2t=dom3t;
        dom3t=dom4t;
        dom4t=3;
        checkworktimer2 = timercount;
        domcount++;
        dom3c++;
        SetLampTable(dom1t,dom2t,dom3t,dom4t);
}
 }

  if(StringGrid1->Cells[2][5] != tempambrella){
        tempambrella =  StringGrid1->Cells[2][5];
 if(timercount - checkworktimer2 > 1){
        if(dom4c < 1){FPlaySound("NARRATIVE\\Umbrella2", 1);}else{FPlaySound("NARRATIVE\\Umbrella2", 1);}
        Label1->Caption="Потеребили крючок зонтика";
        dom1t=dom2t;
        dom2t=dom3t;
        dom3t=dom4t;
        dom4t=4;
        checkworktimer2 = timercount;
        domcount++;
        dom4c++;
        SetLampTable(dom1t,dom2t,dom3t,dom4t);
 }
 }

Label20->Caption=IntToStr(dom1t)+IntToStr(dom2t)+IntToStr(dom3t)+IntToStr(dom4t);

if(domcount == 10){
        domcount = 11;
        FMyThread1->size[1]=80;
        FMyThread1->text[1]="   ?\n     ?\n       ?\n         ?";
       // FPlaySound("BONUS\\BONUS-positive", 1);

}

if(domcount == 20){
        domcount = 21;
        FMyThread1->text[1]="   ?\n     ?\n     ТЕЛЕФОН\n         ?";
        //FPlaySound("BONUS\\BONUS-positive", 1);

}

if(domcount == 30){
        domcount = 31;
        FMyThread1->text[1]="   ?\n    ЛАМПА\n     ТЕЛЕФОН\n         ?";
       // FPlaySound("BONUS\\BONUS-positive", 1);

}

if(domcount == 40){
        domcount = 41;
        FMyThread1->text[1]="   ?\n    ЛАМПА\n     ТЕЛЕФОН\n          ЗОНТ";
        //FPlaySound("BONUS\\BONUS-positive", 1);

}

if(domcount == 50){
        domcount = 51;
        FMyThread1->text[1]="   КНИГА\n    ЛАМПА\n     ТЕЛЕФОН\n          ЗОНТ";
        //FPlaySound("BONUS\\BONUS-positive", 1);
}

if((dom1t == 1 && dom2t == 2 && dom3t == 3 && dom4t == 4) || flagGM5){
        flagGM5=false;
        check4=false;
        Label1->Caption="Домик последователдьтность действий пройдена !";
        dom1t=0;
        dom2t=0;
        dom3t=0;
        dom4t=0;
        stagestatus8 = 2;
        Button63Click(Form1);
        }
}
//--------------------------------------------------------------------------------9-й этап МОТОЦИКЛ
if(check5){
  flagScene=true;
  SetManualBeforeStage(5);
  Label1->Caption="Ожидание поворота ключа мотоцикла";
  if(flagkassette == 0){flagkassette=1;}
  if(StrToInt(StringGrid1->Cells[2][8]) == 0 && motoflag){
        mototimer=timercount + 2;
        motoflag=false;
        }
  if(StrToInt(StringGrid1->Cells[2][8]) == 1 && !motoflag){
        mototimer = 0;
        motoflag=true;
        }

  if(mototimer == timercount || flagGM6){
                flagGM6=false;
                flagSM6=false;
                check5=false;
                Label1->Caption="Ключ в мотоцикле повернули";
                stagestatus9 = 2;
                Button64Click(Form1);
  }
}
//-----------------------------------------------------------------------------------7-й этап продолжение
if(check6_1){
   if(StringGrid1->Cells[2][18] == "1" && pianoflag){
        piano1t=piano2t;
        piano2t=piano3t;
        piano3t=piano4t;
        piano4t=1;
        pianoflag=false;
        }

   if(StringGrid1->Cells[2][21] == "1" && pianoflag){
        piano1t=piano2t;
        piano2t=piano3t;
        piano3t=piano4t;
        piano4t=2;
        pianoflag=false;
        }
   if(StringGrid1->Cells[2][19] == "1" && pianoflag){
        piano1t=piano2t;
        piano2t=piano3t;
        piano3t=piano4t;
        piano4t=3;
        pianoflag=false;
        }
   if(StringGrid1->Cells[2][20] == "1" && pianoflag){
        piano1t=piano2t;
        piano2t=piano3t;
        piano3t=piano4t;
        piano4t=4;
        pianoflag=false;
        }

   if(StringGrid1->Cells[2][18] == "0" && StringGrid1->Cells[2][19] == "0" && StringGrid1->Cells[2][20] == "0" && StringGrid1->Cells[2][21] == "0"){
        pianoflag=true;
   }

   Label22->Caption=IntToStr(piano1t) + IntToStr(piano2t) + IntToStr(piano3t) + IntToStr(piano4t);

   if((piano1t == 1 && piano2t == 2 && piano3t == 3 && piano4t == 4) || flagGM7){
        check6_1 = false;
        stagestatus10 = 2;
        Button40Click(Form1);
   }
}
//---------------------------------------------------------------------------------7-2 этап ПЕРЕКЛЮЧАТЕЛИ
if(check7_2){
          Edit17->Text="Ожидает";
if(!timevalue7_3flag){timevalue7_3flag=true;}



  if(StrToInt(StringGrid1->Cells[2][15]) < 750 && switch_flag){
        switch_timer=timercount + 1;
        switch_flag=false;
        }
  if(StrToInt(StringGrid1->Cells[2][15]) > 750 && !switch_flag){
        switch_timer = 0;
        switch_flag=true;
        }
  if(flagGM7_1 || switch_timer == timercount){
          timevalue7_2flag=false;
          timevalue7_3flag=false;
          Edit17->Text="Пройден";
          check7_2=false;
          StringGrid2->Cells[2][15]="1";
          StringGrid2->Cells[2][23]="0";
          StringGrid2->Cells[2][24]="0";
          setPIO = true;
          FMyThread3->ldiod1=0;
          FMyThread3->ldiod2=0;
          FMyThread3->goblink=false;
          FMyThread->goblink=true;
                FMyThread1->countdown=false;
                FMyThread1->digitflag=false;
                FMyThread1->textflag=true;
                FMyThread1->text[1]="";
                FMyThread1->size[1]=108;
          Button65Click(Form1);

  }
}
//--------------------------------------------------------------------------------8-этап ФИНАЛ
if(check7_1){

        if(StrToInt(StringGrid1->Cells[2][16]) > 750 && provodflag){
                provodtimer=timercount + 2;
                provodflag=false;
                }
        if(StrToInt(StringGrid1->Cells[2][16]) < 750 && !provodflag){
                provodtimer = 0;
                provodflag=true;
                }


        if(provodtimer == timercount){
                Edit8->Text="1 ПРОВОД";
                Label1->Caption="Разъединили первый провод Вероники";
                check7_1=false;
                timevalue8flag=false;
                check8=true;
                }

        }
if(check8_1){
        if(StrToInt(StringGrid1->Cells[2][16]) > 750){
                Edit9->Text="2 ПРОВОД";
                Label1->Caption="Разъединили второй провод Вероники";
                check8_1=false;
                timevalue9flag=false;
                timevalue9_1flag=true;
                timevalue9_1=timercount + 61;
                }

        }
//-------------------------------------------------------------------------------КАССЕТЫ
if(flagkassette == 1){
  if((kassettetimer < timercount) && (StringGrid1->Cells[2][3] == "0")){
        kassettetimer = timercount + 2;
        kassettecheck=true;
        }
  if(kassettecheck && StringGrid1->Cells[2][3] == "1"){kassettecheck=false;}

  if(((kassettetimer == timercount) && kassettecheck) || flagGM11){

        Label1->Caption="Установили все найденные кассеты в полку !";
  //---------------------------------------------запоминаем на чем остановились
        if(check5){
                stagemem=5;
                check5=false;
                if(timevalue5_1flag){
                        stagemem=4;
                        timevalue5_1flag=false;
                        }
                 }
        if(check6_1){
                stagemem=6;
                check6=false;
                check6_1=false;
                timevalue7flag=false;
                }
//----------------------------------------------------------------этап сработавших кассет
                timevalue11=timercount + 61;
                memorycount=memorycount + 10;
                timecount = timecount + 300;
                timevalue11flag=true;
                flagkassette=2;
//------------------------------------------------
        }
}
//-------------------------------------------------------------------------------ЭТАП 12 ТЕЛЕФОННЫЙ ЗВОНОК КАССЕТ
if(check12){

 
}
//-------------------------------------------------------------------------------ЭТАП 11 (2)
if(check12_1){
        Label1->Caption="Возвращение на прерванный этап после задачи с кассетами";
        if(stagemem == 4){
                Edit12->Text="-> УФ";
                timevalue5_1flag=true;
                timevalue5_1=timercount + 154;

                FMyThread3->speedlight1=10000;
                FMyThread3->speedlight2=15000;
                FMyThread3->lfonar=1;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;

                ChangeSoundWall("FON\\Silence");
                }
        if(stagemem == 5){
                Edit12->Text="-> МОТ";
                flagSM5=true;
                Button63Click(Form1);
                }

        if(stagemem == 6){
                Edit12->Text="->ПИАНИНО";
                flagSM6=true;
                Button64Click(Form1);
                }
        check12_1=false;
}

//----------------------------------обработка событий таймера поэтапно               ТАЙМЕР ЛЕГЕНДЫ
if(timevalueLEGflag){
         if(timercount == (timevalueLEG-77)){
              if(checkworktimer != timercount){
                checkworktimer = timercount;
                Label1->Caption="ИГРАЕТ ЛЕГЕНДА 1";
                FPlaySound("System_Instraction", 1);
                FMyThread2->text[1]="  LOADING .........";
                FMyThread2->speedtext1=50;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=108;
                FMyThread2->textflag=true;
                }}
         if(timercount == (timevalueLEG-25)){
              if(checkworktimer != timercount){
                checkworktimer = timercount;
                FMyThread2->text[1]="";
                Label1->Caption="ИГРАЕТ ЛЕГЕНДА 2";
                FPlaySound("Loading", 1);
                FMyThread2->text[1]="  ПОДГОТОВКА\n  ИМПУЛЬСА";
                FMyThread2->speedtext1=50;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=108;
                }}
         if(timercount == (timevalueLEG-1)){
               if(checkworktimer != timercount){
                checkworktimer = timercount;
                FMyThread2->text[1]="        ECHO\n           IS\n       ONLINE";
                FMyThread2->speedtext1=30;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=108;
                Label1->Caption="Открылась входная дверь";
                StringGrid2->Cells[2][7]="0";
                setPIO = true;
                }}
         if(timercount == timevalueLEG){    //-----таймер легенды
               if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid2->Cells[2][7]="1";
                setPIO = true;
                timevalueLEGflag=false;
                startcontrol2=true;
                Label1->Caption="Легенда закончилась, ожидание нажатия кнопки СТАРТ !";
                }}
        }
//--------------------------------------обработка таймера сообщений ошибок
if(timevalueERRflag){
         if(timercount == timevalueERR){    //-----таймер длительности ошибки сообщения
                timevalueERRflag=false;
                }
        }
//--------------------------------------------------------------------------------ТАЙМЕР  1-й этап A
if(timevaluestartflag){    //13

       if(timercount >= timevaluestart){
                startdialog_level = 3;
                timevaluestartflag=false;
                FMyThread2->text[1]="\n\n НАЖМИТЕ ЛЮБУЮ КНОПКУ,\n ЧТОБЫ НАЧАТЬ АНКЕТИРОВАНИЕ";
                FMyThread2->speedtext1=30;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=32;
                FMyThread2->textflag=true;
                Label1->Caption="Игроки проходят анкетирование";
                }
        }
//--------------------------------------------------------------------------------ТАЙМЕР  1-й этап   B
if(timevaluestart1flag){    //6

        if(timercount == (timevaluestart1 - 3)){
                if(checkworktimer != timercount){
                checkworktimer = timercount;
             StringGrid2->Cells[2][42] = "1";
             setPIO = true;
             Label1->Caption="Открыли ящик рубильника";
             }
        }

       if(timercount >= timevaluestart1){
                //startdialog_level = 3;
                timevaluestart1flag=false;
                FMyThread2->text[1]="\n ГЛАВА 1. \n\n Очередная неудача";
                FMyThread2->speedtext1=30;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=56;
                FMyThread2->textflag=true;
                Label1->Caption="Ожидание запуска";
                check0_1 = true;
                check0 = false;
                }
        }
       //-------------------------------------------------ТАЙМЕР ДИАЛОГОВ 2-й этап
if(timevaluestart1_1flag){    //10
       if(timercount == (timevaluestart1_1 - 8)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                ChangeSoundWall("Fon\\3_dia_1");
                }
       }
       if(timercount == (timevaluestart1_1 - 2)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid3->Cells[2][3] = 1;
                setPIO = true;
                }
       }


       if(timercount >= timevaluestart1_1){
                Label1->Caption="Диалог Активен";
                check2 = true;
                timevaluestart1_1flag = false;
                }
        }
       //-------------------------------------------------ТАЙМЕР ДИАЛОГОВ 2-й этап
if(timevalue1_2flag){    //8
       if(timercount == (timevalue1_2 - 7)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                switch(result_maindialog){
                        case 1:
                                FPlaySound("Echo_Story1_Dialog1\\Ex1", 1);
                                break;
                        case 2:
                                FPlaySound("Echo_Story1_Dialog1\\Ex2", 1);
                                break;
                        case 3:
                                FPlaySound("Echo_Story1_Dialog1\\Ex3", 1);
                                break;
                        case 4:
                                FPlaySound("Echo_Story1_Dialog1\\Ex4", 1);
                                break;
                        default:
                                break;
                }
                }
       }
       if(timercount == (timevalue1_2 - 4)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid2->Cells[2][43] = 0;
                setPIO = true;
                }
       }
       if(timercount == (timevalue1_2 - 2)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid3->Cells[2][3] = 0;
                setPIO = true;
                }
       }


       if(timercount >= timevalue1_2){
                Label1->Caption="Диалог завершен";
                Button59Click(Form1);
                stagestatus3 = 2;
                timevalue1_2flag = false;
                }
        }
        //--------------------------------------------------------------------------------ТАЙМЕР  1-й этап   C
if(timevaluestart2flag){    //20
       if(timercount == (timevaluestart2 - 8)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                FMyThread2->text[1]="\n СИСТЕМА \n АКТИВИРОВАНА";
                FMyThread2->speedtext1=30;
                FMyThread2->speedtext2=500;
                FMyThread2->size[1]=54;
                FMyThread2->textflag=true;
                }
       }
       if(timercount == (timevaluestart2 - 5)){
                  if(checkworktimer != timercount){
                checkworktimer = timercount;
               StringGrid2->Cells[2][7] = 0;
                setPIO = true;
                }
       }
       if(timercount == (timevaluestart2 - 3)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid3->Cells[2][1] = 1;
                StringGrid3->Cells[2][2] = 0;
                setPIO = true;
                }
       }

       if(timercount >= timevaluestart2){
                timevaluestart2flag=false;

                Label1->Caption="Игроки вошли в комнату";
                stagestatus1 = 2;
                Button72Click(Form1);
                }
        }
//--------------------------------------------------------------------------------ТАЙМЕР 2-й этап

if(timevalue1flag){//15
        if(timercount == (timevalue1 - 12)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                FPlaySound("Echo_Main_Messages\\1_1_geometryfail", 1);
                }
        }
        if(timercount == (timevalue1 - 3)){
           if(checkworktimer != timercount){
                checkworktimer = timercount;
                FMyThread1->text[1]=" ГЕОМЕТРИЧЕСКИЙ ПРОЦЕССОР\n\n\n ПЛОСКОСТЬ А – ВЫКЛ\n\n ПЛОСКОСТЬ B – ВЫКЛ\n\n ПЛОСКОСТЬ C – ВЫКЛ";
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=20;
                FMyThread1->speedtext2=40;
                FMyThread1->size[1]=32;
                FMyThread1->textflag=true;
                }
        }


         if(timercount == timevalue1){
                check0_2=true;
                timevalue1flag=false;
                Label1->Caption="Ожидание установки фигур !";
         }
}
//-----------------------------------------------------------------------------ТАЙМЕР 3-1 этап ГЕОМЕТРИЧЕСКАЯ ЗАДАЧА решена
if(timevalue1_1flag){//15
        if(timercount == (timevalue1_1 - 12)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                FPlaySound("Echo_Main_Messages\\1_2_geometryok", 1);
                FMyThread1->text[1]="\n ГЕОМЕТРИЯ \n ВОССТАНОВЛЕНА";
                FMyThread1->speedtext1=30;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=54;
                }
        }

        if(timercount == (timevalue1_1 - 4)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                FMyThread1->text[1]="\n АКТИВАЦИЯ \n ДИАЛОГОВОГО\n ИНТЕРФЕЙСА";
                FMyThread1->speedtext1=30;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=54;
                }
        }

        if(timercount == (timevalue1_1 - 2)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                StringGrid3->Cells[2][3] = 1;
                setPIO = true;
                }
        }

         if(timercount == timevalue1_1){
                check0_3=true;
                timevalue1_1flag=false;
                Label1->Caption="Диалог запущен";
         }
}
//--------------------------------------------------------------------------------ТАЙМЕР  4-й этап ПРОЖЕКТОРА
if(timevalue1_3flag){    //10
       if(timercount == (timevalue1_3 - 6)){
                   if(checkworktimer != timercount){
                checkworktimer = timercount;
                SetMemoryCount(memorycount,1);
                FMyThread1->text[2]=" ПОДАЙТЕ \n РЕЗЕРВНОЕ \n ПИТАНИЕ ";
                FMyThread1->counttext=2;
                FMyThread1->speedtext1=100;
                FMyThread1->speedtext2=2000;
                FMyThread1->size[1]=308;
                FMyThread1->size[2]=100;
                FMyThread1->textflag=true;
                }
       }
       if(timercount == (timevalue1_3 - 5)){
        if(checkworktimer != timercount){
                checkworktimer = timercount;

                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread3->lfigura=1;
                FMyThread3->lshitok=2;
                FMyThread3->lpianino=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
       }
       if(timercount == (timevalue1_3 - 2)){
        //        StringGrid3->Cells[2][1] = 1;
        //        StringGrid3->Cells[2][2] = 0;
        //        setPIO = true;
       }

       if(timercount >= timevalue1_3){
                timevalue1_3flag=false;

                Label1->Caption="Прожекторы активированы";
                check1 = true;
                }
        }
//--------------------------------------------------------------------------------ТАЙМЕР-4-й этап ПРОЖЕКТОРА ВЫХОД
 if(timevalue2flag){  // 31 общее
         if(timercount == (timevalue2 - 23)){
         if(checkworktimer != timercount){
                        checkworktimer = timercount;

                        FPlaySound("Echo_Main_Messages\\4_2_openterminal", 1);
                        StringGrid2->Cells[2][11] = 1;
                        setPIO = true;
                        FMyThread1->text[1]="";
                        FMyThread1->textflag=false;
                        FMyThread1->textdigit1=0; //----наименьшее
                        FMyThread1->textdigit2=5; //----наибольшее
                        FMyThread1->speedtext1=400;  //---задержка счета
                        FMyThread1->speedtext2=1000; //---сколько показывать конечную цифру
                        FMyThread1->size[1]=380;
                        FMyThread1->digitflag=true;
                        FMyThread1->countdown = false;
                        memorycount=5;
                        }
         }
        if(timercount == (timevalue2 - 21)){
        if(checkworktimer != timercount){
                checkworktimer = timercount;

                StringGrid2->Cells[2][17] = 0;
                setPIO = true;
                }
        }

        if(timercount == (timevalue2 - 20)){
        if(checkworktimer != timercount){
                checkworktimer = timercount;

                SetMemoryCount(memorycount,1);
                FMyThread1->text[2]=" КОНСТРУКТОР ЛИЧНОСТИ \n ОТКЛЮЧЕНО\n\n ЦВЕТОВОЕ КОДИРОВАНИЕ \n ОТКЛЮЧЕНО\n\n КЛЮЧЕВОЕ ИМЯ \n ОТКЛЮЧЕНО";
                FMyThread1->counttext=2;
                FMyThread1->speedtext1=30;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=308;
                FMyThread1->size[2]=32;
                FMyThread1->digitflag=false;
                FMyThread1->textflag=true;
                }
        }

        if(timercount == (timevalue2 - 16)){
        if(checkworktimer != timercount){
                checkworktimer = timercount;

                StringGrid2->Cells[2][18] = 0;
                setPIO = true;
                }
        }

        if(timercount == (timevalue2 - 12)){
            if(checkworktimer != timercount){
                        checkworktimer = timercount;

                        FPlaySound("Echo_Main_Messages\\4_3_useterminal", 1);
            }
        }

       if(timercount == (timevalue2 - 5)){
            if(checkworktimer != timercount){
                        checkworktimer = timercount;

                        StringGrid2->Cells[2][16] = 1;
                        setPIO = true;
            }
        }
        if(timercount == (timevalue2 - 2)){
            if(checkworktimer != timercount){
                        checkworktimer = timercount;

                        lightfonar = true;
                        lightfonar_timer = timercount;
            }
        }

        if(timercount == timevalue2){
                 check2_1=true;
                 timevalue2flag=false;
                 Label1->Caption="Ожидание решения трех задач с щитком";
        }
 }
 //-------------------------------------ПЕРИОДИЧЕСКОЕ МИГАНИЕ СВЕТОМ
 if(lightfonar){
        if(timercount == (lightfonar_timer - 1)){
                if(lightfonar_flag){
                     StringGrid2->Cells[2][13] = 1;
                     lightfonar_flag = false;
                }else{
                        StringGrid2->Cells[2][13] = 0;
                        lightfonar_flag = true;
                }
                setPIO = true;
        }

        if(lightfonar_timer == timercount){
                lightfonar_timer = timercount + Random(20, 31, false);
                StringGrid2->Cells[2][13] = 1;
                setPIO = true;
        }
 }
 //------------------------------------------------------------------------------ТАЙМЕР 5-й этап концовка этапа
 if(timevalue3flag){//45  общее

       if(timercount == timevalue3){
                stagestatus5 = 2;
                timevalue3flag=false;
                flagSM3=false;
                Button61Click(Form1);
                }
 }

 //------------------------------------------------------------------------------ТАЙМЕР 6-й этап завершение Терминала
 if(timevalue3_1flag){//45  общее
        if(timercount == (timevalue3_1-42)){

                StringGrid2->Cells[2][11] = 0;
                setPIO = true;
                ChangeSoundWall("Fon\\7_home_1");
        }
        if(timercount == (timevalue3_1-41)){
                 StringGrid2->Cells[2][9] = 1;
                 setPIO = true;
                }
        if(timercount == (timevalue3_1-40)){

        FPlaySound("Echo_Main_Messages\\5_2_getnumber", 1);
        }

        if(timercount == (timevalue3_1-39)){
                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread3->lfigura=2;
                FMyThread3->lshitok=2;
                FMyThread3->lpianino=2;
                FMyThread3->lhouse=2;
                FMyThread3->lcherdak=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;

       }
        if(timercount == (timevalue3_1-37)){
                FMyThread3->lfigura=0;
                FMyThread3->lshitok=0;
                FMyThread3->lpianino=0;
                FMyThread3->lhouse=1;
                FMyThread3->lcherdak=1;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
        }

      if(timercount == (timevalue3_1-35)){
                 FMyThread1->text[1]=" ВОССТАНОВИТЕ\n НОМЕР\n ДОМА";
                 FMyThread1->counttext=1;
                 FMyThread1->speedtext1=80;
                 FMyThread1->speedtext2=1000;
                 FMyThread1->size[1]=54;
                }
      if(timercount == (timevalue3_1-30)){
                 check3_1 = true;
                 Label1->Caption="Активирован считыватель номера дома";
                }
       if(timercount == timevalue3_1){
                StringGrid2->Cells[2][11]= 0;
                StringGrid2->Cells[2][13]= 0;
                StringGrid2->Cells[2][16]= 0;
                setPIO = true;
                check3_1=true;
                timevalue3_1flag=false;
                flagSM3=false;
                }
 }
 //------------------------------------------------------------------------------ТАЙМЕР 4-й этап
 if(timevalue4flag){  //  60 общее
         if(timercount == timevalue4){
                 timevalue4flag=false;
                }
        }
 //------------------------------------------------------------------------------ТАЙМЕР 4-й (1) этап     5-е нажатие кнопки
 if(timevalue4_1flag){//   18общее
        if(timercount == (timevalue4_1-8)){
                 FPlaySound("BONUS\\BONUS_1", 1);
        }
        if(timercount == timevalue4_1){
                 timevalue4_1flag=false;
                }
        }

//-------------------------------------------------------------------------------ТАЙМЕР 4-й (2) этап      9-е нажатие кнопки
 if(timevalue4_2flag){//   11общее
        if(timercount == (timevalue4_2-9)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->speedlight1=100;
                        FMyThread3->speedlight2=100;
                        FMyThread3->lhouse=2;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                }

        }
 if(timercount == (timevalue4_2-8)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread1->textflag=true;
                        FMyThread1->text[1]="\n\n\n ВОСПОМИНАНИЕ ВЗЛОМАНО";
                        FMyThread1->counttext=1;
                        FMyThread1->speedtext1=60;
                        FMyThread1->speedtext2=1000;
                        FMyThread1->size[1]=54;
                        }
        }
 if(timercount == (timevalue4_2-7)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->lhouse=0;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                        }

        }
 if(timercount == (timevalue4_2-6)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid2->Cells[2][4]=0;
                        StringGrid2->Cells[2][9]=1;
                        setPIO = true;
                        FPlaySound("Echo_Main_Messages\\5_3_numberok", 1);
                        ChangeSoundWall("Fon\\8_home_2");
                        }
        }
 if(timercount == (timevalue4_2-4)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FPlaySound("Echo_Main_Messages\\6_1_activatefrag", 1);

                        }
        }
 if(timercount == (timevalue4_2-2)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        check4_0 = true;
                        Label1->Caption="Активирована активация фрагментов";

                        }
        }
 if(timercount == timevalue4_2){
                 timevalue4_2flag=false;
                 }
 }
 //------------------------------------------------------------------------------ТАЙМЕР 8-й  этап  ОКОНЧАНИЕ АКТИВАЦИИ ЭЛЕМЕНТОВ ДОМИКА
if(timevalue4_3flag){//   8общее
        if(timercount == (timevalue4_3-6)){
            if(checkworktimer != timercount){
                checkworktimer=timercount;
                FPlaySound("Echo_Main_Messages\\6_4_fragmentok", 1);
                }
         }
         if(timercount == (timevalue4_3-5)){
            if(checkworktimer != timercount){
                checkworktimer=timercount;
                FMyThread1->textflag=true;
                FMyThread1->text[1]="\n ВОССТАНОВИТЕ \n ХРОНОЛОГИЮ \n СОБЫТИЙ ";
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=54;
                }
         }

         if(timercount == timevalue4_3){
                tempbook = StringGrid1->Cells[2][6];
                tempambrella = StringGrid1->Cells[2][5];
                timevalue4_3flag=false;
                check4=true;
                Label1->Caption = "АКТИВИРОВАНА ЗАДАЧА ПОИСКА ХРОНОЛОГИИ СОБЫТИЙ";
         }
}

if(timevalue4_4flag){//   11общее  //------------------------------------ТАЙМЕР ЗАВЕРЩЕНИЯ НОМЕРА ДОМА
        if(timercount == (timevalue4_4-8)){
                z=0;

                FMyThread1->textflag=true;
                FMyThread1->text[1]="\n\n\n ДОСТУП ПОЛУЧЕН";
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=54;

         }
 if(timercount == (timevalue4_4-7)){
                StringGrid2->Cells[2][9] = 1;
                StringGrid2->Cells[2][4] = 0;
                setPIO = true;

        }
 if(timercount == (timevalue4_4-6)){
                if(checkworktimer != timercount){
                checkworktimer=timercount;
                FPlaySound("Echo_Main_Messages\\5_3_numberok", 1);
                }
        }

 if(timercount == (timevalue4_4-5)){
                if(checkworktimer != timercount){
                checkworktimer=timercount;
                ChangeSoundWall("Fon\\8_home_2");
                }
        }
 if(timercount == (timevalue4_4-4)){
                if(checkworktimer != timercount){
                checkworktimer=timercount;
                FPlaySound("Echo_Main_Messages\\6_1_activatefrag", 1);
                }
        }

 if(timercount == (timevalue4_4-2)){
                if(checkworktimer != timercount){
                checkworktimer=timercount;
                check4_0 = true;
                Label1->Caption="Активирована активация фрагментов";
                }
        }
 if(timercount == timevalue4_4){
                 timevalue4_4flag=false;
                }
 }
 //------------------------------------------------------------------------------ТАЙМЕР 9-й этап   мотоцикл
 if(timevalue5flag){  //  15 сек общее
        if(timercount == (timevalue5 - 12)){
                if(checkworktimer != timercount){
                checkworktimer=timercount;
                FMyThread1->text[1]="\n\n\nГЛАВА 4. Авария.";
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=54;
                }
        }
        if(timercount == (timevalue5 - 5)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->speedlight1=100;
                        FMyThread3->speedlight2=100;
                        FMyThread3->lhouse=2;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                }
                }
        if(timercount == (timevalue5 - 3)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid2->Cells[2][2] = 0;
                        setPIO = true;
                }
                }
        if(timercount == (timevalue5 - 1)){

                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->lhouse=0;
                        FMyThread3->goblink=false;
                        FMyThread->goblink=false;
                }
         }
         if(timercount == timevalue5){
                 timevalue5flag=false;
                 lightfonar = true;
                 lightfonar_timer = timercount;
                 StringGrid2->Cells[2][20] = 1;
                 setPIO = true;
                 FPlaySound("Echo_Main_Messages\\7_2_activatemoto", 1);
                 FMyThread1->text[1]="\n\n\n АКТИВИРУЙТЕ \n ВОСПОМИНАНИЕ \n ОБ АВАРИИ ";
                 FMyThread1->counttext=1;
                 FMyThread1->speedtext1=60;
                 FMyThread1->speedtext2=1000;
                 FMyThread1->size[1]=54;
                 check_random_audio_moto = true;
                 check5 = true;
                 Label1->Caption = "Эмблемма мотоцикла ожидает срабатывания .";
         }
}

 //------------------------------------------------------------------------------ТАЙМЕР 6-й этап
 if(timevalue6flag){  //30 общее

        if(timercount == (timevalue6 - 27)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        lightfonar = false;
                        FMyThread3->speedlight1=500;
                        FMyThread3->speedlight2=100;
                        FMyThread3->lfonar=2;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                 }
                }
         if(timercount == (timevalue6 - 26)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread1->text[1]="\n ВЫГРУЖАЕМ \n ДАННЫЕ \n ОБ АВАРИИ";
                        FMyThread1->counttext=1;
                        FMyThread1->speedtext1=60;
                        FMyThread1->speedtext2=1000;
                        FMyThread1->size[1]=54;
                        FMyThread1->textflag=true;
                        }
                }
         if(timercount == (timevalue6 - 25)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid2->Cells[2][11] = 1;
                        setPIO;
                        }
                }
         if(timercount == (timevalue6 - 23)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid2->Cells[2][12] = 1;
                        setPIO = true;
                        }
                }
          if(timercount == (timevalue6 - 20)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread1->text[1]="\n ПРОСЛЕДУЙТЕ \n В ЗОНУ \n СБОРКИ";
                        FMyThread1->counttext=1;
                        FMyThread1->speedtext1=60;
                        FMyThread1->speedtext2=1000;
                        FMyThread1->size[1]=54;
                        FMyThread1->textflag=true;
                        }
                }

          if(timercount == (timevalue6 - 19)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->lfonar=0;
                        FMyThread3->goblink=false;
                        FMyThread->goblink=false;
                        }
                }
           if(timercount == (timevalue6 - 15)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid2->Cells[2][6] = 0;
                        setPIO = true;
                        }
                }
          if(timercount == (timevalue6 - 10)){
                  if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        ChangeSoundWall("FON\\10_piano");
                        FMyThread1->text[1]="\n СИНТЕЗИРУЙТЕ \n СОЗНАНИЕ ";
                        FMyThread1->counttext=1;
                        FMyThread1->speedtext1=60;
                        FMyThread1->speedtext2=1000;
                        FMyThread1->size[1]=54;
                        FMyThread1->textflag=true;
                        }
                }
          if(timercount == (timevalue6 - 8)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->speedlight1=500;
                        FMyThread3->speedlight2=100;
                        FMyThread3->lshitok = 2;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                        }
                }
          if(timercount == (timevalue6 - 5)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->lshitok = 0;
                        FMyThread3->goblink=false;
                        FMyThread->goblink=false;
                        }
                }
          if(timercount == timevalue6){
                  StringGrid2->Cells[2][5] = 0;
                  setPIO = true;
                  check_random_audio_piano = true;
                  check6_1=true;
                  timevalue6flag=false;
                }
        }
 //-------------------------------------------------------------------------------ТАЙМЕР 11-й этап    ПЕРЕД ДИАЛОГОМ
 if(timevalue7flag){//15 общее
        if(timercount == (timevalue7 - 11)){
                if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FPlaySound("Echo_Main_Messages\\8_2_pianook_1", 1);
                        }

                }
         if(timercount == (timevalue7 - 9)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->speedlight1=500;
                        FMyThread3->speedlight2=100;
                        FMyThread3->lpianino = 2;
                        FMyThread3->goblink=true;
                        FMyThread->goblink=true;
                        FMyThread1->text[1]="\n СБОРКА № ***\n ЗАВЕРШЕНА ";
                        FMyThread1->counttext=1;
                        FMyThread1->speedtext1=60;
                        FMyThread1->speedtext2=1000;
                        FMyThread1->size[1]=54;
                        FMyThread1->textflag=true;
                        }
                 }
         if(timercount == (timevalue7 - 8)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FMyThread3->lpianino = 1;
                        FMyThread3->goblink=false;
                        FMyThread->goblink=false;
                        StringGrid2->Cells[2][43] = 1;
                        setPIO = true;
                        PlayNumberPlayers(false, "Echo_Main_Messages\\8_2_pianook_2"); //--всегда указывать false
                        }
                 }
         if(timercount == (timevalue7 - 6)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        FPlaySound("Echo_Main_Messages\\8_2_pianook_3", 1);
                        }
                 }
         if(timercount == (timevalue7 - 1)){
                 if(checkworktimer != timercount){
                        checkworktimer = timercount;
                        StringGrid3->Cells[2][3] = 1;
                        setPIO = true;
                        }
                 }

         if(timercount == timevalue7){

                timevalue7flag=false;
                }
        }

 //------------------------------------------------------------------------------ТАЙМЕР 7 ЭТАП (1)

 if(timevalue7_1flag){//  175 общее
        if(timercount == (timevalue7_1 - 174)){
                FPlaySound("MESSAGES\\25-callingVeronica", 1);
                FMyThread3->lpianino=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][12]="0";
                setPIO = true;
                }
        if(timercount == (timevalue7_1 - 164)){
                StringGrid2->Cells[2][19]="1";
                setPIO = true;
                }
        if(timercount == (timevalue7_1 - 173)){
                ChangeSoundWall("FON\\GrandFinal_1-cut");
                }
         if(timercount == (timevalue7_1 - 157)){
                FPlaySound("MESSAGES\\26-PHONECALL_2", 1);
                }
         if(timercount == (timevalue7_1 - 124)){
                FMyThread1->text[1]="";
                }
         if(timercount == (timevalue7_1 - 123)){
                FMyThread1->size[1]=90;
                FMyThread1->text[1]="\n     СОЗНАНИЕ\n ВОССТАНОВЛЕНО";
                }

         if(timercount == (timevalue7_1 - 123)){
                FMyThread3->speedlight1=1000;
                FMyThread3->speedlight2=100;
                FMyThread3->lfigura=1;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
               }
          if(timercount == (timevalue7_1 - 98)){
                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=50;
               }
          if(timercount == (timevalue7_1 - 94)){
                FMyThread3->lfigura=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
               }
         if(timercount == (timevalue7_1 - 92)){
                FMyThread1->text[1]="";
                }
         if(timercount == (timevalue7_1 - 91)){
                FMyThread1->text[1]="СБОЙСБОЙСБОЙ\n СБОЙСБОЙСБОЙ\nСБОЙСБОЙСБОЙ";
                FPlaySound("MESSAGES\\27-VERONICA", 1);
                }
         if(timercount == (timevalue7_1 - 68)){
                StringGrid2->Cells[2][11]="1";
                setPIO = true;
                }
         if(timercount == (timevalue7_1 - 56)){
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][14]="1";
                setPIO = true;
                }
         if(timercount == (timevalue7_1 - 49)){
                StringGrid2->Cells[2][14]="0";
                StringGrid2->Cells[2][10]="1";
                setPIO = true;
                }
          if(timercount == (timevalue7_1 - 26)){
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][12]="1";
                setPIO = true;
                }

          if(timercount == timevalue7_1){
                StringGrid2->Cells[2][12]="0";
                setPIO = true;
                check7_2=true;
                timevalue7_1flag=false;
                timevalue7_2flag=true;
                timevalue7_2=timercount + 430;
                }
        }
//--------------------------------------------------------------------------------ТАЙМЕР 7-2 этап
if(timevalue7_2flag){//  430 общее
        if(timercount == (timevalue7_2 - 430)){

                FMyThread1->size[1]=60;
                FMyThread1->text[1]="\n\n ОЖИДАНИЕ ПОДКЛЮЧЕНИЯ";
                FMyThread3->lpianino=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][10]="1";
                StringGrid2->Cells[2][12]="0";
                setPIO = true;

                FPlaySound("1", 1);

                FMyThread3->lpianino=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][12]="0";
                setPIO = true;
                }
        if(timercount == (timevalue7_2 - 420)){
                ChangeSoundWall("FinalTask_1");
                }
        if(timercount == (timevalue7_2 - 419)){
                FMyThread1->text[1]="";
                FMyThread1->textflag=false;
                }
        if(timercount == (timevalue7_2 - 418)){
                FMyThread1->countdown=true;
                FMyThread1->percent=false;
                FMyThread1->textdigit1=0;
                FMyThread1->textdigit2=418;
                FMyThread1->speedtext1=1000;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=308;
                FMyThread1->digitflag=true;
                }
        if(timercount == (timevalue7_2 - 417)){
             if(checkworktimer != timercount){
                FMyThread4->speedlight1=2000;
                FMyThread4->speedlight2=1000;
                FMyThread4->lfonar=0;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;

                StringGrid2->Cells[2][10] = "1";
                setPIO = true;

                }}
        if(timercount == (timevalue7_2 - 406)){
                check7_2=true;
                }
        if(timercount == (timevalue7_2 - 404)){
             if(checkworktimer != timercount){
                FMyThread4->speedlight1=200;
                FMyThread4->speedlight2=400;
                FMyThread4->lpianino=2;
                FMyThread4->lshitok=1;
                FMyThread4->lfigura=2;
                FMyThread4->ldomlampa=1;
                FMyThread4->lcherdak=2;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;
                }}

        if(timercount == timevalue7_2){
                FMyThread4->goblink=false;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                check7_2=false;
                timevalue7_3flag=false;
                timevalue7_2flag=false;
                timenull = 0;
                flagtimenull = 0;
                flaglooser=1;
                Button70Click(Form1);
                Label1->Caption="Вышло время";
                }
        }


if(timevalue7_3flag){  // 22 общее

        if(timercount == (timevalue7_3 - 22)){
                FPlaySound("FinalTaskCycle", 1);
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 21)){
                FMyThread3->speedlight1=70;
                FMyThread3->speedlight2=70;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 18)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 17)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }

        if(timercount == (timevalue7_3 - 16)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 15)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=1;
                FMyThread3->ldiod2=1;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 13)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 12)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=1;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 10)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 9)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=1;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 7)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 6)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=1;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 4)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 3)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=1;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue7_3 - 1)){
                FMyThread3->speedlight1=500;
                FMyThread3->speedlight2=1;
                FMyThread3->ldiod1=2;
                FMyThread3->ldiod2=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                }

        if(timevalue7_3 == 0 || timevalue7_3 == timercount){


                timevalue7_3 = timercount + 22;
                }
}
//-------------------------------------------------------------------------------ТАЙМЕР 8-й этап  ОЖИДАНИЕ РАЗРЫВА ПРОВОДА
 if(timevalue8flag){//120 общее

        if(timercount == (timevalue8 - 120)){
                FMyThread1->textflag=true;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=20;
                FMyThread1->speedtext2=600;
                FMyThread1->size[1]=308;
                FMyThread1->text[1]="";
                PlayVideo5("video1");
                ChangeSoundWall("FON\\GrandFinal_2");
                }
        if(timercount == (timevalue8 - 119)){
                 StringGrid2->Cells[2][1]="0";
                 StringGrid2->Cells[2][15]="1";
                 setPIO = true;
                }

        if(timercount == (timevalue8 - 115)){
                FMyThread3->speedlight1=200;
                FMyThread3->speedlight2=200;
                FMyThread4->speedlight1=800;
                FMyThread4->speedlight2=400;
                FMyThread3->lfigura=2;
                FMyThread3->ldomlampa=2;
                FMyThread3->lcherdak=2;
                FMyThread3->lpianino=2;
                FMyThread3->ldiod1=2;
                FMyThread3->lfonar=2;
                FMyThread3->lvera=0;
                FMyThread4->ldiod2=2;
                FMyThread4->lfonar=2;
                FMyThread4->lhouse=2;
                FMyThread4->lshitok=2;
                FMyThread4->lvera=0;
                FMyThread3->goblink=true;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;
                }
        if(timercount == (timevalue8 - 114)){

             if(checkworktimer != timercount){
                checkworktimer=timercount;
                 StringGrid2->Cells[2][15]="1";
                 setPIO = true;
                }
             }



          if(timercount == timevalue8){
               Edit8->Text="НЕРАЗОРВАЛИ";
               Edit9->Text="НЕРАЗОРВАЛИ";
               countdownflag=false;  //-------флаг отключения принудительного вывода текста на экран
                timevalue8flag=false;
                timevalue8_1flag=true;
                timevalue8_1=timercount + 60;
                check7_1=false;
                StopVideo5();
                }
        }
//-------------------------------------------------------------------------------ТАЙМЕР ЭТАП 8 (1)  ВЫШЛО ВРЕМЯ ОЖИДАНИЯ РАЗРЫВА ПРОВОДА
if(timevalue8_1flag){//----общее 60

       if(timercount == timevalue8_1 - 60){

               FMyThread1->textflag=true;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=90;
                FMyThread1->text[1]="  СОЗНАНИЕ\n  ПОЛНОСТЬЮ\n  ВЫГРУЖЕНО";
                Label1->Caption="НЕ Отключили Веронику";
                ChangeSoundWall("FON\\GrandFinal_endingCUT_1");
                temp="Время игры " + Label45->Caption + "\nПамять " + IntToStr(memorycount) + "%\nСОЗНАНИЕ ВЫГРУЖЕНО";
                FMyThread2->text[1]=temp.c_str();
                FMyThread2->speedtext1=50;
                FMyThread2->speedtext2=1000;
                FMyThread2->size[1]=50;
                FMyThread2->textflag=true;
                }


       if(timercount == timevalue8_1 - 41){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue8_1 - 40){
                FMyThread1->size[1]=100;
                FMyThread1->text[1]="\n  ПОГРУЖЕНИЕ\n     ОКОНЧЕНО";
                }
       if(timercount == timevalue8_1 - 33){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue8_1 - 32){
                FMyThread1->size[1]=100;
                FMyThread1->text[1]="  БЛАГОДАРИМ\n          ЗА\n      УЧАСТИЕ";
                }
      if(timercount == timevalue8_1 - 31){
                 FMyThread3->lfigura=0;
                FMyThread3->ldomlampa=0;
                FMyThread3->lcherdak=0;
                FMyThread3->lpianino=0;
                FMyThread3->ldiod1=0;
                FMyThread3->lfonar=0;
                FMyThread3->lvera=0;
                FMyThread4->ldiod2=0;
                FMyThread4->lfonar=0;
                FMyThread4->lhouse=0;
                FMyThread4->lshitok=0;
                FMyThread4->lvera=0;
                FMyThread3->goblink=false;
                FMyThread4->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][9]="0";
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                StringGrid2->Cells[2][13]="0";
                StringGrid2->Cells[2][14]="1";
                StringGrid2->Cells[2][15]="0";
                StringGrid2->Cells[2][16]="0";
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
                }
      if(timercount == timevalue8_1 - 30){
                StringGrid2->Cells[2][7]="0";
                setPIO = true;
                }
      if(timercount == timevalue8_1 - 10){
                StringGrid2->Cells[2][14]="0";
                setPIO = true;
                }
       if(timercount == timevalue8_1 - 10){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue8_1 - 9){
                FMyThread1->size[1]=108;
                FMyThread1->text[1]="        ECHO\n           IS\n      OFFLINE";
                }

       if(timercount == timevalue8_1){
                timevalue8_1flag=false;
             //   StopScene();
                Label1->Caption="Игра закончилась !";
                }

}
 //------------------------------------------------------------------------------9-й этап РАЗОРВАЛИ ПРОВОД
 if(timevalue9flag){  //--------общая 60

       if(timercount == timevalue9 - 60){
                Label1->Caption="Отключили Веронику";
                temp="Время игры " + Label45->Caption + "\nПамять " + IntToStr(memorycount) + "%\nСОЗНАНИЕ РАЗРУШЕНО";
                FMyThread2->text[1]=temp.c_str();
                FMyThread2->speedtext1=50;
                FMyThread2->speedtext2=1000;
                FMyThread2->size[1]=50;
                FMyThread2->textflag=true;
              ChangeSoundWall("FON\\GrandFinal_endingCUT");
                }
       if(timercount == timevalue9 - 51){
                StopVideo5();
                FMyThread1->textflag=true;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=90;
                FMyThread1->text[1]="  СОЗНАНИЕ\n  ПОЛНОСТЬЮ\n  РАЗРУШЕНО";
                }
       if(timercount == timevalue9 - 45){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue9 - 40){
                FMyThread1->size[1]=100;
                FMyThread1->text[1]="\n  ПОГРУЖЕНИЕ\n     ОКОНЧЕНО";
                }
       if(timercount == timevalue9 - 33){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue9 - 32){
                FMyThread1->size[1]=100;
                FMyThread1->text[1]="  БЛАГОДАРИМ\n          ЗА\n      УЧАСТИЕ";
                }
      if(timercount == timevalue9 - 31){
                 FMyThread3->lfigura=0;
                FMyThread3->ldomlampa=0;
                FMyThread3->lcherdak=0;
                FMyThread3->lpianino=0;
                FMyThread3->ldiod1=0;
                FMyThread3->lfonar=0;
                FMyThread3->lvera=0;
                FMyThread4->ldiod2=0;
                FMyThread4->lfonar=0;
                FMyThread4->lhouse=0;
                FMyThread4->lshitok=0;
                FMyThread4->lvera=0;
                FMyThread3->goblink=false;
                FMyThread4->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][9]="0";
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                StringGrid2->Cells[2][13]="0";
                StringGrid2->Cells[2][14]="1";
                StringGrid2->Cells[2][15]="0";
                StringGrid2->Cells[2][16]="0";
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
                }
      if(timercount == timevalue9 - 30){
                StringGrid2->Cells[2][7]="0";
                StringGrid2->Cells[2][15]="0";
                setPIO = true;
                }
      if(timercount == timevalue9 - 8){
                StringGrid2->Cells[2][14]="0";
                setPIO = true;
                }
       if(timercount == timevalue9 - 10){
                FMyThread1->text[1]="";
                }
       if(timercount == timevalue9 - 9){
                FMyThread1->size[1]=108;
                FMyThread1->text[1]="        ECHO\n           IS\n      OFFLINE";
                }

       if(timercount == timevalue9){
                timevalue9flag=false;
             //   StopScene();
                Label1->Caption="Игра закончена !";
                }


        }
 //------------------------------------------------------------------------------ТАЙМЕР ЭТАП 9 (1) РАЗОРВАЛИ ПРОВОД  (НЕ ЗАДЕЙСТВОВАНО)
 if(timevalue9_1flag){  //--------общая 61


        }
//-------------------------------------------------------------------------------ТАЙМЕР ЭТАП 10 ПРОИГРЫШ (КОНЧИЛОСЬ ИГРОВОЕ ВРЕМЯ)
 if(timevalue10flag){//----общее 60
        if(timercount == (timevalue10 - 60)){
                check15=true;
                FMyThread1->text[1]="";

                FMyThread3->lfigura=0;
                FMyThread3->ldomlampa=0;
                FMyThread3->lcherdak=0;
                FMyThread3->lpianino=0;
                FMyThread3->ldiod1=0;
                FMyThread3->lfonar=0;
                FMyThread3->lvera=0;
                FMyThread4->ldiod2=0;
                FMyThread4->lfonar=0;
                FMyThread4->lhouse=0;
                FMyThread4->lshitok=0;
                FMyThread4->lvera=0;
                FMyThread3->goblink=false;
                FMyThread4->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][9]="0";
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                StringGrid2->Cells[2][13]="0";
                StringGrid2->Cells[2][14]="0";
                StringGrid2->Cells[2][15]="0";
                StringGrid2->Cells[2][16]="0";
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
                }
        if(timercount == (timevalue10 - 59)){
                StopSoundWall();
                countdownflag=false;
                Form3->Label1->Font->Color=ColorRed;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=2;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=90;
                FMyThread1->text[1]="\n      СОЗНАНИЕ\n    УНИЧТОЖЕНО";
                FMyThread1->textflag=true;
                temp="Время игры " + Label45->Caption + "\nПамять " + IntToStr(memorycount) + "%\nСОЗНАНИЕ УНИЧТОЖЕНО";
                FMyThread2->text[1]=temp.c_str();
                FMyThread2->speedtext1=50;
                FMyThread2->speedtext2=1000;
                FMyThread2->size[1]=50;
                FMyThread2->textflag=true;
                }
        if(timercount == (timevalue10 - 57)){
                FPlaySound("ENDINGS\\TIME_OUT_1", 1);
                FMyThread1->text[1]="";
                }
        if(timercount == (timevalue10 - 56)){
                FMyThread1->text[1]="       СИСТЕМА\n    ОБЕСТОЧЕНА\n         ВЫХОД\n   ЗАБЛОКИРОВАН";
                }
        if(timercount == (timevalue10 - 40)){
                FPlaySound("ALARM", 1);
                FMyThread1->text[1]="";
                }

       if(timercount == timevalue10 - 39){
                FMyThread1->text[1]="\n    ИЩИТЕ КНОПКУ\n    АВАРИЙНОГО\n      ОТКРЫТИЯ";

                }
        if(timercount == timevalue10){
                StringGrid2->Cells[2][14]="1";
                setPIO = true;
                timevalue9_1flag=false;
                check15=true;
 //               StopScene();
                }
}
//-------------------------------------------------------------------------------ТАЙМЕР КАССЕТЫ 11 этап
  if(timevalue11flag){//----общее 60
        if(timercount == (timevalue11 - 60)){
                FMyThread1->text[1]="";
                FMyThread1->text[2]="";
                FMyThread1->textflag=false;
               FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread3->lfigura=1;
                FMyThread3->lshitok=2;
                FMyThread3->lpianino=2;
                FMyThread3->lfonar=0;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][12]="0";
                setPIO = true;
                FPlaySound("VHS\\VHS", 1);
                }
       if(timercount == (timevalue11 - 58)){
                FMyThread1->size[1]=380;
                FMyThread1->textdigit1=memorycount-10;
                FMyThread1->textdigit2=memorycount;
                FMyThread1->speedtext1=400;
                FMyThread1->speedtext2=500;
                FMyThread1->digitflag=true;
                }
        if(timercount == (timevalue11 - 53)){
                FMyThread1->text[1]="";
                }
        if(timercount == (timevalue11 - 52)){
                FMyThread1->size[1]=90;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=600;
                FMyThread1->text[1]="   ЧАСТЬ 17 \n   РАЗЛОМ";
                FMyThread1->textflag=true;

                }

        if(timercount == (timevalue11 - 44)){
                ChangeSoundWall("FON\\VHS_Broken");
                }
        if(timercount == (timevalue11 - 43)){
                FMyThread1->text[1]="";
                }

        if(timercount == (timevalue11 - 42)){
                FMyThread1->size[1]=90;
                FMyThread1->text[1]="      ОЖИДАНИЕ\n  КОНТРОЛЬНОГО\n        ЗВОНКА";
                }
        if(timercount == (timevalue11 - 41)){
                FMyThread3->speedlight1=2000;
                FMyThread3->speedlight2=1000;
                FMyThread3->lfigura=1;
                FMyThread3->lshitok=0;
                FMyThread3->lpianino=0;
                FMyThread3->lfonar=0;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                setPIO = true;
                }

        if(timercount == timevalue11 - 30){
                timevalue11flag=false;
                FMyThread3->lfigura=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][19]="1";
                setPIO = true;
                check12=true;
}}
 //-------------------------------------------------------------------------------ТАЙМЕР ЭТАП 11 (1)
  if(timevalue12flag){//----общее 68
        if(timercount == (timevalue12 - 68)){
                FMyThread1->size[1]=95;
                FMyThread1->text[1]=" \n 2 года назад ...";
                }
        if(timercount == (timevalue12 - 67)){
                FPlaySound("VHS\\Phonecall_17", 1);
                }
        if(timercount == (timevalue12 - 63)){
                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread4->speedlight1=400;
                FMyThread4->speedlight2=200;
                FMyThread3->lfigura=2;
                FMyThread3->ldomlampa=2;
                FMyThread3->lcherdak=2;
                FMyThread3->lpianino=2;
                FMyThread3->ldiod1=2;
                FMyThread3->lfonar=2;
                FMyThread3->lvera=2;
                FMyThread4->ldiod2=2;
                FMyThread4->lfonar=2;
                FMyThread4->lhouse=2;
                FMyThread4->lshitok=2;
                FMyThread4->lvera=2;
                FMyThread3->goblink=true;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;
                }
       if(timercount == (timevalue12 - 12)){
                FMyThread1->textflag=false;
                }
        if(timercount == (timevalue12 - 11)){
                FMyThread1->textdigit1=memorycount-10;
                FMyThread1->textdigit2=memorycount;
                FMyThread1->speedtext1=400;
                FMyThread1->speedtext2=500;
                FMyThread1->size[1]=380;
                FMyThread1->digitflag=true;
                }
        if(timercount == (timevalue12 - 10)){
                FMyThread3->lfigura=0;
                FMyThread3->ldomlampa=0;
                FMyThread3->lcherdak=0;
                FMyThread3->lpianino=0;
                FMyThread3->ldiod1=0;
                FMyThread3->lfonar=0;
                FMyThread3->lvera=0;
                FMyThread4->ldiod2=0;
                FMyThread4->lfonar=0;
                FMyThread4->lhouse=0;
                FMyThread4->lshitok=0;
                FMyThread4->lvera=0;
                FMyThread3->goblink=false;
                FMyThread4->goblink=false;
                FMyThread->goblink=false;
                StringGrid2->Cells[2][9]="0";
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                StringGrid2->Cells[2][13]="0";
                StringGrid2->Cells[2][14]="0";
                StringGrid2->Cells[2][15]="0";
                StringGrid2->Cells[2][16]="0";
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
                }
        if(timercount == (timevalue12 - 5)){
                FMyThread1->size[1]=90;
                FMyThread1->counttext=1;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=600;
                FMyThread1->size[1]=100;
                FMyThread1->text[1]="ВОЗВРАТ К\nОСНОВНОЙ\nВРЕМЕННОЙ\nЛИНИИ";
                FMyThread1->textflag=true;
                }
        if(timercount == timevalue12){
                timevalue12flag=false;
                check12_1=true;
                StringGrid2->Cells[2][19]="0";
                setPIO = true;
                }
}

 if(manual_timer == timercount){  //-------------------------отключение ручного ввода
           readkey=1;
 }


 //------------------------------------------------------------------------------------конец обработки условий входов и выходов
 if(readkey == 1){Label44->Caption="Чтение датчиков вкл";}
 else{Label44->Caption="Ручное управление";}

 Label11->Caption=memorycount;
 Label25->Caption=IntToStr(timercount - buttonvalue);
  //-------------------------------------------------------------------------------обновление текстового окна экранов
 if(!countdownflag){
         Form3->Panel1->Visible=FMyThread1->visiblescreen;
         Form3->Label1->Caption=FMyThread1->textscreen;
         Form3->Label1->Font->Size=FMyThread1->sizetext;
         }else{
         FMyThread1->text[1]="";
         }

 Form2->Panel2->Visible=FMyThread2->visiblescreen;
 Form2->Label1->Caption=FMyThread2->textscreen;
 Form2->Label1->Font->Size=FMyThread2->sizetext;

if(check2_1){
         if(shitok_color){FMyThread1->text[3]="ЦВЕТОПЕРЕДАЧА\nНАСТРОЕНА";}else{FMyThread1->text[3]="НАСТРОЙТЕ\nЦВЕТОВОЕ\nКОДИРОВАНИЕ";}
         if(shitok_name){FMyThread1->text[5]="        ИМЯ\n     ПОЛУЧЕНО";}else{FMyThread1->text[5]="      ВВЕДИТЕ\n         ИМЯ";}
         if(shitok_memory){FMyThread1->text[7]="КЛЮЧЕВЫЕ\nФРАГМЕНТЫ\nОБНАРУЖЕНЫ";}else{FMyThread1->text[7]="УСТАНОВИТЕ\nКЛЮЧЕВЫЕ\nВОСПОМИНАНИЯ";}
         SetMemoryCount(memorycount,1);
}

 //------------------------------------------------------------------------------мигание светом обновление выходов
if(FMyThread3->goblink){
        FMyThread->goblink=true;
        if(FMyThread3->lhouse == 1){StringGrid2->Cells[2][9]="1";}
        if(FMyThread3->lfonar == 1){StringGrid2->Cells[2][10]="1";}
        if(FMyThread3->lshitok == 1){StringGrid2->Cells[2][11]="1";}
        if(FMyThread3->lpianino == 1){StringGrid2->Cells[2][12]="1";}
        if(FMyThread3->lcherdak == 1){StringGrid2->Cells[2][13]="1";}
        if(FMyThread3->ldomlampa == 1){StringGrid2->Cells[2][14]="1";}
        if(FMyThread3->lvera == 1){StringGrid2->Cells[2][15]="1";}
        if(FMyThread3->lfigura == 1){StringGrid2->Cells[2][43]="1";}
        if(FMyThread3->ldiod1 == 1){StringGrid2->Cells[2][23]="1";}
        if(FMyThread3->ldiod2 == 1){StringGrid2->Cells[2][24]="1";}
        if(FMyThread3->lhouse == 2){StringGrid2->Cells[2][9]="0";}
        if(FMyThread3->lfonar == 2){StringGrid2->Cells[2][10]="0";}
        if(FMyThread3->lshitok == 2){StringGrid2->Cells[2][11]="0";}
        if(FMyThread3->lpianino == 2){StringGrid2->Cells[2][12]="0";}
        if(FMyThread3->lcherdak == 2){StringGrid2->Cells[2][13]="0";}
        if(FMyThread3->ldomlampa == 2){StringGrid2->Cells[2][14]="0";}
        if(FMyThread3->lvera == 2){StringGrid2->Cells[2][15]="0";}
        if(FMyThread3->lfigura == 2){StringGrid2->Cells[2][43]="0";}
        if(FMyThread3->ldiod1 == 2){StringGrid2->Cells[2][23]="0";}
        if(FMyThread3->ldiod2 == 2){StringGrid2->Cells[2][24]="0";}

        setPIO = true;
        }else{
        FMyThread->goblink=false;
        }

if(FMyThread4->goblink){

        if(FMyThread4->lhouse == 1){StringGrid2->Cells[2][9]="1";}
        if(FMyThread4->lfonar == 1){StringGrid2->Cells[2][10]="1";}
        if(FMyThread4->lshitok == 1){StringGrid2->Cells[2][11]="1";}
        if(FMyThread4->lpianino == 1){StringGrid2->Cells[2][12]="1";}
        if(FMyThread4->lcherdak == 1){StringGrid2->Cells[2][13]="1";}
        if(FMyThread4->ldomlampa == 1){StringGrid2->Cells[2][14]="1";}
        if(FMyThread4->lvera == 1){StringGrid2->Cells[2][15]="1";}
        if(FMyThread4->lfigura == 1){StringGrid2->Cells[2][43]="1";}
        if(FMyThread4->ldiod1 == 1){StringGrid2->Cells[2][23]="1";}
        if(FMyThread4->ldiod2 == 1){StringGrid2->Cells[2][24]="1";}
        if(FMyThread4->lhouse == 2){StringGrid2->Cells[2][9]="0";}
        if(FMyThread4->lfonar == 2){StringGrid2->Cells[2][10]="0";}
        if(FMyThread4->lshitok == 2){StringGrid2->Cells[2][11]="0";}
        if(FMyThread4->lpianino == 2){StringGrid2->Cells[2][12]="0";}
        if(FMyThread4->lcherdak == 2){StringGrid2->Cells[2][13]="0";}
        if(FMyThread4->ldomlampa == 2){StringGrid2->Cells[2][14]="0";}
        if(FMyThread4->lvera == 2){StringGrid2->Cells[2][15]="0";}
        if(FMyThread4->lfigura == 2){StringGrid2->Cells[2][43]="0";}
        if(FMyThread4->ldiod1 == 2){StringGrid2->Cells[2][23]="0";}
        if(FMyThread4->ldiod2 == 2){StringGrid2->Cells[2][24]="0";}

        setPIO = true;
        }


  //------------------------------------------------------------------

  Application->ProcessMessages();

//---------------------- проверка на СТОП
  if(stopflag == 1){
        Label19->Caption="Цикл Остановлен.";
        Application->ProcessMessages();
        break;
        }
//--------------------
 }
}
//--------------------------------------------------------------------------------------------------------------АУДИОБЛОК
//--------------------------------------------------------------------------------------------------------------АУДИОБЛОК

//-------------------------------------------------------------------------
void __fastcall TForm1::SoundVolumeUP(int channel, int delay){

 WriteMap(hMap, "volumeup;;1000;soundwall;");//---[command;file;delay;channel]
}
//-----------------------------------------------------------------------------
void __fastcall TForm1::SoundVolumeDOWN(int channel, int delay){

WriteMap(hMap, "volumedown;;1000;soundwall;");//---[command;file;delay;channel]

}
//--------------------------------------------------------------------------

void __fastcall TForm1::StopSoundWall(void){

 WriteMap(hMap, "stop;;;soundwall;");//---[command;file;delay;channel]

}
//-------------------------------------------------------------------------
void __fastcall TForm1::FPlaySound(AnsiString file, int channel){

        ChangePlayMessage(file, channel);
}
//-------------------------------------------------------------------------
void __fastcall TForm1::SetRelaySound(int channel){

        switch (channel)
        {
        case 2:
                {
                StringGrid2->Cells[2][27]="0";
                StringGrid2->Cells[2][29]="0";
                StringGrid2->Cells[2][25]="1";
                break;
                }
        case 3:
                {
                StringGrid2->Cells[2][25]="0";
                StringGrid2->Cells[2][29]="0";
                StringGrid2->Cells[2][27]="1";
                break;
                }
        case 4:
                {
                StringGrid2->Cells[2][25]="0";
                StringGrid2->Cells[2][27]="0";
                StringGrid2->Cells[2][29]="1";
                break;
                }
        default:
                {
                StringGrid2->Cells[2][25]="0";
                StringGrid2->Cells[2][27]="0";
                StringGrid2->Cells[2][29]="0";
                break;
                }
        }
        setPIO = true;
}
//-------------------------------------------------------------------------
void __fastcall TForm1::RandomPlaySound(int min, int max, AnsiString file, int channel){

        file = path + file + "\\" + IntToStr(Random(min, max, false)) + ".wav";

        AnsiString txt = "playwait;" + file + ";1000;message;";

        if(buffer1_ansi == "true"){
                delaysound_flag = true;
                delaysound_channel = channel;
                }else{
                      SetRelaySound(channel);
                }

        WriteMap(hMap, txt);//---[command;file;delay;channel]
}
//-------------------------------------------------------------------------
void __fastcall TForm1::RandomPlaySoundDiff(int min, int max, AnsiString file, int channel){

        file = path + file + "\\" + IntToStr(RandomDiff(min, max, false)) + ".wav";

        AnsiString txt = "playwait;" + file + ";1000;message;";

         if(buffer1_ansi == "true"){
                delaysound_flag = true;
                delaysound_channel = channel;
                }else{
                      SetRelaySound(channel);
                }

        WriteMap(hMap, txt);//---[command;file;delay;channel]
}
//-------------------------------------------------------------------------
void __fastcall TForm1::PlayWaitMessage(AnsiString file, int channel){

        file = path + file + ".wav";

        AnsiString txt = "playwait;" + file + ";1000;message;";

         if(buffer1_ansi == "true"){
                delaysound_flag = true;
                delaysound_channel = channel;
                }else{
                      SetRelaySound(channel);
                }
        
        WriteMap(hMap, txt);//---[command;file;delay;channel]
}
//-------------------------------------------------------------------------
bool __fastcall TForm1::CheckPlayMessages(void){
        bool out = false;
        if(buffer1_ansi == "true"){out = true;}
        return out;
}
//-------------------------------------------------------------------------
void __fastcall TForm1::ChangePlayMessage(AnsiString file, int channel){

        file = path + file + ".wav";
        if(mixed_random_sound == "1"){mixed_random_sound = "2";}else{mixed_random_sound = "1";}
        //--в soundwall/exe срабатывает команда если послание отличается от предыдушего, для этого вводим изменяемый эоемент

        AnsiString txt = "play;" + file + ";1000;message;" + mixed_random_sound + ";";

        SetRelaySound(channel);
        WriteMap(hMap, txt);//---[command;file;delay;channel]
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChangeSoundWall(AnsiString file){

        file = path + file + ".wav";
        AnsiString txt;
        txt = "changesoundwall;" + file + ";1000;soundwall;";

        WriteMap(hMap, txt);//---[command;file;delay;channel]

}

//----------------------------------------------------------------------------------------------------КОНЕЦ АУДИОБЛОК
//-------------------------------------------------------------------------------MAP MEMORY TO SOUNDWALL PROC
void __fastcall TForm1::ReadMap1(HANDLE h, LPTSTR &buffer)
{
	h=OpenFileMapping(FILE_MAP_ALL_ACCESS, TRUE, "Map1");
	buffer = (LPTSTR)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if(buffer == NULL){ShowMessage("Can't read from map file");}
}

void __fastcall TForm1::WriteMap(HANDLE h, AnsiString txt)
{
     	h=OpenFileMapping(FILE_MAP_ALL_ACCESS, TRUE, "Map");
	buffer = (LPTSTR)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if(buffer==NULL){ShowMessage("Can't read the map file");}
        strcpy(buffer, (LPTSTR)txt.c_str());
//        if(!FlushViewOfFile( buffer, lstrlen( buffer ) )){
//		ShowMessage("Cant't write the map file");
//                }
}

void __fastcall TForm1::CreateMap(void){
   hFile=CreateFile("file.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ
   | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  hMap=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, "Map");
}

void __fastcall TForm1::CloseMap(void){
  UnmapViewOfFile(buffer);
  CloseHandle(hFile);
  CloseHandle(hMap);
}

void __fastcall TForm1::CreateMap1(void){
   hFile1=CreateFile("file1.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ
   | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  hMap1=CreateFileMapping(hFile1, NULL, PAGE_READWRITE, 0, 100, "Map1");
}

void __fastcall TForm1::CloseMap1(void){
  UnmapViewOfFile(buffer1);
  CloseHandle(hFile1);
  CloseHandle(hMap1);
}
//-------------------------------------------------------------------------------END MAP MEMORY TO SOUNDWALL PROC
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Label19->Caption="Цикл опроса остановлен !";
StopScene();

if(stopflag == 0){
setPIO = true;
}

FMyThread3->goblink=false;
FMyThread1->textflag=false;
FMyThread2->textflag=false;

timenull=0;
timecount=0;
flagtimenull=0;
flagblink=0;
flaglooser=0;
stage=-2;
tempokscene=0;
color=false;               //-----------стадия пар розеток
timestagevalue=0;
timestageflag=false;
fatalscene=0;
okscene=0;
stopflag=1;
Timer1->Enabled=false;
Timer2->Enabled=false;
//-------------------------------убиваем поток
    if (FMyThread) {
        FMyThread->Terminate();
        delete FMyThread;
        FMyThread = 0;
    }
    if (FMyThread1) {
        FMyThread1->Terminate();
        delete FMyThread1;
        FMyThread1 = 0;
    }
        if (FMyThread2) {
        FMyThread2->Terminate();
        delete FMyThread2;
        FMyThread2 = 0;
    }
        if (FMyThread3) {
        FMyThread3->Terminate();
        delete FMyThread3;
        FMyThread3 = 0;
    }
        if (FMyThread4) {
        FMyThread4->Terminate();
        delete FMyThread4;
        FMyThread4 = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][1]) > 0){
        StringGrid2->Cells[2][1] = 0;
        }else{
        StringGrid2->Cells[2][1] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][2]) > 0){
        StringGrid2->Cells[2][2] = 0;
        }else{
        StringGrid2->Cells[2][2] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][3]) > 0){
        StringGrid2->Cells[2][3] = 0;
        }else{
        StringGrid2->Cells[2][3] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][4]) > 0){
        StringGrid2->Cells[2][4] = 0;
        }else{
        StringGrid2->Cells[2][4] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][5]) > 0){
        StringGrid2->Cells[2][5] = 0;
        }else{
        StringGrid2->Cells[2][5] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][6]) > 0){
        StringGrid2->Cells[2][6] = 0;
        }else{
        StringGrid2->Cells[2][6] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][7]) > 0){
        StringGrid2->Cells[2][7] = 0;
        }else{
        StringGrid2->Cells[2][7] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][8]) > 0){
        StringGrid2->Cells[2][8] = 0;
        }else{
        StringGrid2->Cells[2][8] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][9]) > 0){
        StringGrid2->Cells[2][9] = 0;
        }else{
        StringGrid2->Cells[2][9] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][10]) > 0){
        StringGrid2->Cells[2][10] = 0;
        }else{
        StringGrid2->Cells[2][10] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][11]) > 0){
        StringGrid2->Cells[2][11] = 0;
        }else{
        StringGrid2->Cells[2][11] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][12]) > 0){
        StringGrid2->Cells[2][12] = 0;
        }else{
        StringGrid2->Cells[2][12] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][13]) > 0){
        StringGrid2->Cells[2][13] = 0;
        }else{
        StringGrid2->Cells[2][13] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][14]) > 0){
        StringGrid2->Cells[2][14] = 0;
        }else{
        StringGrid2->Cells[2][14] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][15]) > 0){
        StringGrid2->Cells[2][15] = 0;
        }else{
        StringGrid2->Cells[2][15] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][16]) > 0){
        StringGrid2->Cells[2][16] = 0;
        }else{
        StringGrid2->Cells[2][16] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][17]) > 0){
        StringGrid2->Cells[2][17] = 0;
        }else{
        StringGrid2->Cells[2][17] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][18]) > 0){
        StringGrid2->Cells[2][18] = 0;
        }else{
        StringGrid2->Cells[2][18] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][19]) > 0){
        StringGrid2->Cells[2][19] = 0;
        }else{
        StringGrid2->Cells[2][19] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][21]) > 0){
        StringGrid2->Cells[2][21] = 0;
        }else{
        StringGrid2->Cells[2][21] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][22]) > 0){
        StringGrid2->Cells[2][22] = 0;
        }else{
        StringGrid2->Cells[2][22] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][23]) > 0){
        StringGrid2->Cells[2][23] = 0;
        }else{
        StringGrid2->Cells[2][23] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][24]) > 0){
        StringGrid2->Cells[2][24] = 0;
        }else{
        StringGrid2->Cells[2][24] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  PlayVideo5("test1");
 }
//------------------------------------------------------------------------


void __fastcall TForm1::StopScene(void){

 flagScene=false;
//---------------------------остановка таймера
flagblink=0;
timecount=0;
timenull=0;
timecountrealflag=false;
//--------------------------установка 0 для розеток призмы
stage=-2;
//----------------------------установка 0 концов таймеров
flagtimenull=0;
//--------------------------Остановка сценария
Edit14->Text="";
Edit13->Text="";
Edit12->Text="";
Edit11->Text="";
Edit10->Text="";
Edit9->Text="";
Edit8->Text="";
Edit7->Text="";
Edit6->Text="";
Edit5->Text="";
Edit4->Text="";
Edit3->Text="";
Edit2->Text="";
Edit1->Text="";

check0=false;
check1=false;
check2=false;
check3=false;
check4=false;
check5=false;
check6=false;
check7=false;
check8=false;
check9=false;
check10=false;
check11=false;
check12=false;
check13=false;

timevalue1flag=false;
timevalue2flag=false;
timevalue3flag=false;
timevalue4flag=false;
timevalue5flag=false;
timevalue6flag=false;
timevalue7flag=false;
timevalue8flag=false;
timevalue9flag=false;
timevalue10flag=false;
timevalue11flag=false;
timevalue12flag=false;

StopSoundWall();
flagdatacorrect=false;
Label1->Caption="Сценарий и таймеры остановлены !";
OffAll();

if(stopflag == 0){

setPIO = true;
}
//---------------------------------

}
//---------------------------------------

void __fastcall TForm1::HideText(void){
FMyThread1->visiblescreen=false;
}

void __fastcall TForm1::StopVideo5(){

try{
   Form3->MediaPlayer1->Stop();
   Form3->MediaPlayer1->Close();
   Form3->Panel2->Visible=false;
   }
   catch(...){}
}


void __fastcall TForm1::PlayVideo5(AnsiString file){
TRect vsize, vsize_mon;

        vsize.Left=0;
        vsize.Top=0;
        vsize.Right=1024;
        vsize.Bottom=768;

        vsize_mon.Left=0;
        vsize_mon.Top=0;
        vsize_mon.Right=320;
        vsize_mon.Bottom=240;

        Form3->Panel2->Visible = true;

        Form3->MediaPlayer1->Notify=false;
        Form3->MediaPlayer1->FileName = path + file + ".avi";
        Form3->MediaPlayer1->Open();
        Form3->MediaPlayer1->DisplayRect=vsize;
        Form3->MediaPlayer1->Notify=true;
        Form3->MediaPlayer1->Play();
}
void __fastcall TForm1::SetCountdown(int timercount_f, int timevalue_f, int dig_f2, int dig_f1, int size){
AnsiString temp;
int z;

        if(timercount_f <= (timevalue_f - dig_f1) && timercount_f >= (timevalue_f - dig_f2)){
                countdownflag=true;
                if(checkworktimer != timercount){
                checkworktimer = timercount;
                        for(z=dig_f2;z >= dig_f1;z--){
                                if(timercount_f == (timevalue_f - z)){
                                        temp=IntToStr(z);
                                        if(z < 100){temp="  " + temp;}
                                        if(z < 10){temp=" " + temp;}
                                        Form3->Panel1->Visible=true;
                                        Form3->Label1->Caption=temp;
                                        Form3->Label1->Font->Size=size;
                                        }
                                }
                       }
                }

}

void __fastcall TForm1::MemoryMessages(void){
                                        if(memorycount == 0){buttonvalue = buttonvalue=buttonvalue - 5;}
                                        if(memorycount == 5){FPlaySound("HELPSTATUS\\Memory5", 1);}
                                        if(memorycount == 10){FPlaySound("HELPSTATUS\\Memory10", 1);}
                                        if(memorycount == 15){FPlaySound("HELPSTATUS\\Memory15", 1);}
                                        if(memorycount == 20){FPlaySound("HELPSTATUS\\Memory20", 1);}
                                        if(memorycount == 25){FPlaySound("HELPSTATUS\\Memory25", 1);}
                                        if(memorycount == 30){FPlaySound("HELPSTATUS\\Memory30", 1);}
                                        if(memorycount == 35){FPlaySound("HELPSTATUS\\Memory35", 1);}
                                        if(memorycount == 40){FPlaySound("HELPSTATUS\\Memory40", 1);}
                                        if(memorycount == 45){FPlaySound("HELPSTATUS\\Memory45", 1);}
                                        if(memorycount == 50){FPlaySound("HELPSTATUS\\Memory50", 1);}
                                        if(memorycount == 55){FPlaySound("HELPSTATUS\\Memory55", 1);}
                                        if(memorycount == 60){FPlaySound("HELPSTATUS\\Memory60", 1);}
                                        if(memorycount == 65){FPlaySound("HELPSTATUS\\Memory65", 1);}
                                        if(memorycount == 70){FPlaySound("HELPSTATUS\\Memory70", 1);}
                                        if(memorycount == 75){FPlaySound("HELPSTATUS\\Memory75", 1);}
                                        if(memorycount == 80){FPlaySound("HELPSTATUS\\Memory80", 1);}
                                        if(memorycount == 85){FPlaySound("HELPSTATUS\\Memory85", 1);}
                                        if(memorycount == 90){FPlaySound("HELPSTATUS\\Memory90", 1);}
                                        if(memorycount == 95){FPlaySound("HELPSTATUS\\Memory95", 1);}
}

void __fastcall TForm1::TimeMessages(void){
                                        if(timecount <= 3600 && timecount > 3300){FPlaySound("Echo_Main_Messages\\4_1_powerok_55", 1);}
                                        if(timecount <= 3300 && timecount > 3000){FPlaySound("Echo_Main_Messages\\4_1_powerok_50", 1);}
                                        if(timecount <= 3000 && timecount > 2700){FPlaySound("Echo_Main_Messages\\4_1_powerok_45", 1);}
                                        if(timecount <= 2700 && timecount > 2400){FPlaySound("Echo_Main_Messages\\4_1_powerok_40", 1);}
                                        if(timecount <= 2400 && timecount > 2100){FPlaySound("Echo_Main_Messages\\4_1_powerok_35", 1);}
                                        if(timecount <= 2100){FPlaySound("Echo_Main_Messages\\4_1_powerok_30", 1);}

}
void __fastcall TForm1::SetLampTable(int dom1t, int dom2t, int dom3t, int dom4t){
int tempflag=false;

if(dom1t == 1 && dom2t == 2 && dom3t == 3 && dom4t == 4){
              StringGrid2->Cells[2][14] = "1";
              setPIO = true;
              tempflag=true;
 }
if(dom2t == 1 && dom3t == 2 && dom4t == 3){
              StringGrid2->Cells[2][14] = "1";
              setPIO = true;
              tempflag=true;
 }
 if(dom3t == 1 && dom4t == 2){
              StringGrid2->Cells[2][14] = "1";
              setPIO = true;
              tempflag=true;
 }
 if(!tempflag){
              StringGrid2->Cells[2][14] = "0";
              setPIO = true;
              }

}

void __fastcall TForm1::SetMemoryCount(int mc , int index){

        switch(mc){
                case 0:
                        FMyThread1->text[index] = "0%";
                        break;
                case 1:
                        FMyThread1->text[index] = "1%";
                        break;
                case 2:
                        FMyThread1->text[index] = "2%";
                        break;
                case 3:
                        FMyThread1->text[index] = "3%";
                        break;
                case 4:
                        FMyThread1->text[index] = "4%";
                        break;
                case 5:
                        FMyThread1->text[index] = "5%";
                        break;
                case 6:
                        FMyThread1->text[index] = "6%";
                        break;
                case 7:
                        FMyThread1->text[index] = "7%";
                        break;
                case 8:
                        FMyThread1->text[index] = "8%";
                        break;
                case 9:
                        FMyThread1->text[index] = "9%";
                        break;
                case 10:
                        FMyThread1->text[index] = "10%";
                        break;
                case 11:
                        FMyThread1->text[index] = "11%";
                        break;
                case 12:
                        FMyThread1->text[index] = "12%";
                        break;
                case 13:
                        FMyThread1->text[index] = "13%";
                        break;
                case 14:
                        FMyThread1->text[index] = "14%";
                        break;
                case 15:
                        FMyThread1->text[index] = "15%";
                        break;
                case 16:
                        FMyThread1->text[index] = "16%";
                        break;
                case 17:
                        FMyThread1->text[index] = "17%";
                        break;
                case 18:
                        FMyThread1->text[index] = "18%";
                        break;
                case 19:
                        FMyThread1->text[index] = "19%";
                        break;
                case 20:
                        FMyThread1->text[index] = "20%";
                        break;
                case 21:
                        FMyThread1->text[index] = "21%";
                        break;
                case 22:
                        FMyThread1->text[index] = "22%";
                        break;
                case 23:
                        FMyThread1->text[index] = "24%";
                        break;
                case 25:
                        FMyThread1->text[index] = "25%";
                        break;
                case 26:
                        FMyThread1->text[index] = "26%";
                        break;
                case 27:
                        FMyThread1->text[index] = "27%";
                        break;
                case 28:
                        FMyThread1->text[index] = "28%";
                        break;
                case 29:
                        FMyThread1->text[index] = "29%";
                        break;
                case 30:
                        FMyThread1->text[index] = "30%";
                        break;
                case 31:
                        FMyThread1->text[index] = "31%";
                        break;
                case 32:
                        FMyThread1->text[index] = "32%";
                        break;
                case 33:
                        FMyThread1->text[index] = "33%";
                        break;
                case 34:
                        FMyThread1->text[index] = "34%";
                        break;
                case 35:
                        FMyThread1->text[index] = "35%";
                        break;
                case 36:
                        FMyThread1->text[index] = "36%";
                        break;
                case 37:
                        FMyThread1->text[index] = "37%";
                        break;
                case 38:
                        FMyThread1->text[index] = "38%";
                        break;
                case 39:
                        FMyThread1->text[index] = "39%";
                        break;
                case 40:
                        FMyThread1->text[index] = "40%";
                        break;
                case 41:
                        FMyThread1->text[index] = "41%";
                        break;
                case 42:
                        FMyThread1->text[index] = "42%";
                        break;
                case 43:
                        FMyThread1->text[index] = "43%";
                        break;
                case 44:
                        FMyThread1->text[index] = "44%";
                        break;
                case 45:
                        FMyThread1->text[index] = "45%";
                        break;
                case 46:
                        FMyThread1->text[index] = "46%";
                        break;
                case 47:
                        FMyThread1->text[index] = "47%";
                        break;
                case 48:
                        FMyThread1->text[index] = "48%";
                        break;
                case 49:
                        FMyThread1->text[index] = "49%";
                        break;
                case 50:
                        FMyThread1->text[index] = "50%";
                        break;
                case 51:
                        FMyThread1->text[index] = "51%";
                        break;
                case 52:
                        FMyThread1->text[index] = "52%";
                        break;
                case 53:
                        FMyThread1->text[index] = "53%";
                        break;
                case 54:
                        FMyThread1->text[index] = "54%";
                        break;
                case 55:
                        FMyThread1->text[index] = "55%";
                        break;
                case 56:
                        FMyThread1->text[index] = "56%";
                        break;
                case 57:
                        FMyThread1->text[index] = "57%";
                        break;
                case 58:
                        FMyThread1->text[index] = "58%";
                        break;
                case 59:
                        FMyThread1->text[index] = "59%";
                        break;
                case 60:
                        FMyThread1->text[index] = "60%";
                        break;
                case 61:
                        FMyThread1->text[index] = "61%";
                        break;
                case 62:
                        FMyThread1->text[index] = "62%";
                        break;
                case 63:
                        FMyThread1->text[index] = "63%";
                        break;
                case 64:
                        FMyThread1->text[index] = "64%";
                        break;
                case 65:
                        FMyThread1->text[index] = "65%";
                        break;
                case 66:
                        FMyThread1->text[index] = "66%";
                        break;
                case 67:
                        FMyThread1->text[index] = "67%";
                        break;
                case 68:
                        FMyThread1->text[index] = "68%";
                        break;
                case 69:
                        FMyThread1->text[index] = "69%";
                        break;
                case 70:
                        FMyThread1->text[index] = "70%";
                        break;
                case 71:
                        FMyThread1->text[index] = "71%";
                        break;
                case 72:
                        FMyThread1->text[index] = "72%";
                        break;
                case 73:
                        FMyThread1->text[index] = "73%";
                        break;
                case 74:
                        FMyThread1->text[index] = "74%";
                        break;
                case 75:
                        FMyThread1->text[index] = "75%";
                        break;
                case 76:
                        FMyThread1->text[index] = "76%";
                        break;
                case 77:
                        FMyThread1->text[index] = "77%";
                        break;
                case 78:
                        FMyThread1->text[index] = "78%";
                        break;
                case 79:
                        FMyThread1->text[index] = "79%";
                        break;
                case 80:
                        FMyThread1->text[index] = "80%";
                        break;
                case 81:
                        FMyThread1->text[index] = "81%";
                        break;
                case 82:
                        FMyThread1->text[index] = "82%";
                        break;
                case 83:
                        FMyThread1->text[index] = "83%";
                        break;
                case 84:
                        FMyThread1->text[index] = "84%";
                        break;
                case 85:
                        FMyThread1->text[index] = "85%";
                        break;
                case 86:
                        FMyThread1->text[index] = "86%";
                        break;
                case 87:
                        FMyThread1->text[index] = "87%";
                        break;
                case 88:
                        FMyThread1->text[index] = "88%";
                        break;
                case 89:
                        FMyThread1->text[index] = "89%";
                        break;
                case 90:
                        FMyThread1->text[index] = "90%";
                        break;
                case 91:
                        FMyThread1->text[index] = "91%";
                        break;
                case 92:
                        FMyThread1->text[index] = "92%";
                        break;
                case 93:
                        FMyThread1->text[index] = "93%";
                        break;
                case 94:
                        FMyThread1->text[index] = "94%";
                        break;
                case 95:
                        FMyThread1->text[index] = "95%";
                        break;
                case 96:
                        FMyThread1->text[index] = "96%";
                        break;
                case 97:
                        FMyThread1->text[index] = "97%";
                        break;
                case 98:
                        FMyThread1->text[index] = "98%";
                        break;
                case 99:
                        FMyThread1->text[index] = "99%";
                        break;
                case 100:
                        FMyThread1->text[index] = "100%";
                        break;
                default:
                        FMyThread1->text[index] = "--%";
                        break;
        }
}


//-----------------------------------------------------------------------------  OFFALL
void __fastcall TForm1::OffAll(void){
StringGrid2->Cells[2][10]="0";
StringGrid2->Cells[2][18]="0";
StringGrid2->Cells[2][2]="0";
StringGrid2->Cells[2][3]="0";
StringGrid2->Cells[2][4]="0";
StringGrid2->Cells[2][5]="0";
StringGrid2->Cells[2][6]="0";
StringGrid2->Cells[2][7]="0";
StringGrid2->Cells[2][9]="0";
StringGrid2->Cells[2][11]="0";
StringGrid2->Cells[2][12]="0";
StringGrid2->Cells[2][13]="0";
StringGrid2->Cells[2][14]="0";
StringGrid2->Cells[2][15]="0";
StringGrid2->Cells[2][16]="0";
StringGrid2->Cells[2][19]="0";
StringGrid2->Cells[2][20]="0";
StringGrid2->Cells[2][21]="0";
StringGrid2->Cells[2][22]="0";
StringGrid2->Cells[2][24]="0";
Label1->Caption="Сценарий и таймеры остановлены, Все устройства отключены !";

}
//------------------------------
void __fastcall TForm1::GetFatalScene(void){   //-------------------------------------FATAL SCENE


timevalue11flag=true;
timevalue11=timercount + 10;
timecount=421;
setPIO = true;
okscene=0;
Label1->Caption="3мин отсчет до правильного прохождения Призмы!";
}
//------------------------------------------------------------------------------------------------------------------------------

void __fastcall TForm1::SetManualBeforeStage(int num){   //----установка выходов для ручного включения нужного этапа

if(num == 1 && flagSM1){
                flagSM1=false;
                memorycount = 0;

              
                }
if(num == 2 && flagSM2){
                flagSM2=false;

                }
if(num == 3 && flagSM3){


                }
if(num == 4 && flagSM4){

                }
if(num == 5 && flagSM5){
                flagSM5=false;
                if(memorycount == 0){memorycount=50;}
                ChangeSoundWall("FON\\Silence");
                FMyThread1->text[1]="        ECHO\n           IS\n       ONLINE";
                SetMemoryCount(memorycount,2);
                FMyThread1->counttext=2;
                FMyThread1->speedtext1=60;
                FMyThread1->speedtext2=1000;
                FMyThread1->size[1]=108;
                FMyThread1->size[2]=308;
                FMyThread1->textflag=true;
                StringGrid2->Cells[2][20]="1";
                StringGrid2->Cells[2][2]="0";
                StringGrid2->Cells[2][4]="0";
                setPIO = true;
                FMyThread3->speedlight1=10000;
                FMyThread3->speedlight2=15000;
                FMyThread3->lfonar=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                FPlaySound("MESSAGES\\16-1-echo", 1);
                }
if(num == 6 && flagSM6){
                flagSM6=false;
                StringGrid2->Cells[2][20]="0";
                setPIO = true;

                FMyThread3->speedlight1=3000;
                FMyThread3->speedlight2=100;
                FMyThread3->lfonar=2;
                FMyThread3->goblink=true;
                FMyThread->goblink=true;
                ChangeSoundWall("FON\\TheEcho");
               }
if(num == 7 && flagSM7){

                flagSM7=false;


                }
if(num == 8 && flagSM8){
                flagSM8=false;

                }
if(num == 9 && flagSM9){
                flagSM9=false;

                }
if(num == 10 && flagSM10){
                flagSM10=false;

                }
if(num == 11 && flagSM11){
                flagSM11=false;

                FPlaySound("null", 1);
                flagtimenull=0;
                timenull=0;
                timecount=0;
                }
}
//-------------------------------------------------------------конец пренастроек
void __fastcall TForm1::Button52Click(TObject *Sender)
{
 StringGrid2->Cells[2][9]="1";
 StringGrid2->Cells[2][10]="1";
 StringGrid2->Cells[2][11]="1";
 StringGrid2->Cells[2][12]="1";
 StringGrid2->Cells[2][13]="1";
 //StringGrid2->Cells[2][14]="1";
 //StringGrid2->Cells[2][15]="1";
 //StringGrid2->Cells[2][19]="1";
 setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button53Click(TObject *Sender)
{
 StringGrid2->Cells[2][9]="0";
 StringGrid2->Cells[2][10]="0";
 StringGrid2->Cells[2][11]="0";
 StringGrid2->Cells[2][12]="0";
 StringGrid2->Cells[2][13]="0";
 //StringGrid2->Cells[2][14]="0";
 //StringGrid2->Cells[2][15]="0";
 //StringGrid2->Cells[2][19]="0";
 setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button54Click(TObject *Sender)
{
 StringGrid2->Cells[2][4]="0";
 StringGrid2->Cells[2][7]="0";
 setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button55Click(TObject *Sender)
{
 StringGrid2->Cells[2][4]="1";
 StringGrid2->Cells[2][7]="1";
 setPIO = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button58Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][34]) ==  1){
                 StringGrid1->Cells[2][34] = "0";
                }else{
                   StringGrid1->Cells[2][34] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//--------------------------------------------------------------------------- Функции обработки стадий игры

void __fastcall TForm1::Button59Click(TObject *Sender)            //------------------------2-й этап
{
 flagScene=true;
 SetManualBeforeStage(1);
 timevalue1_3 = timercount + 10;
 timevalue1_3flag = true;
 ChangeSoundWall("Fon\\4_breakdown");
 FPlaySound("Echo_Main_Messages\\3_1_echobroken", 1);
        FMyThread1->text[1]="";
        FMyThread1->textflag=false;
        FMyThread1->textdigit1=0; //----наименьшее
        FMyThread1->textdigit2=100; //----наибольшее
        FMyThread1->speedtext1=15;  //---задержка счета
        FMyThread1->speedtext2=1000; //---сколько показывать конечную цифру
        FMyThread1->size[1]=380;
        FMyThread1->digitflag=true;
        FMyThread1->countdown = true;
 stagestatus4 = 1;
 flagGM1=false;
 Label1->Caption="Подготовка ПРОЖЕКТОРА";

 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button60Click(TObject *Sender)           //----------------------- 5-й этап   ТЕРМИНАЛ
{
  flagScene=true;
  check2=true;
  check_random_audio_0 = false;
                FMyThread3->lfigura=0;
                FMyThread3->lshitok=0;
                FMyThread3->lpianino=0;
                FMyThread3->goblink=false;
                FMyThread->goblink=false;
        SetManualBeforeStage(2);
        FMyThread1->text[1]="\n\n СИГНАЛ ВОССТАНОВЛЕН";
        FMyThread1->textflag=true;
        FMyThread1->counttext = 1;
        FMyThread1->speedtext1=50;  //---задержка счета
        FMyThread1->speedtext2=1000; //---сколько показывать конечную цифру
        FMyThread1->size[1]=54;
        FMyThread1->digitflag=false;
  stagestatus5 = 1;
  ChangeSoundWall("Fon\\5_darkness_1");
  TimeMessages();
  check_random_audio = true;
  flagGM2=false;
  Label1->Caption="Ожидание решения терминала";
  timevalue2=timercount + 31;
  timevalue2flag=true;
  check2=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button61Click(TObject *Sender)        //--------------------------  6-й этап
{
  stagestatus6 = 1;
  flagScene=true;
  SetManualBeforeStage(3);
  timevalue3_1flag=true;
  timevalue3_1=timercount+45;
  lightfonar = false;

  StringGrid2->Cells[2][11] = 1;
  StringGrid2->Cells[2][16] = 1;
  setPIO = 1;
  FPlaySound("Echo_Main_Messages\\5_1_terminalok", 1);
  FMyThread1->text[1]=" БАЗОВЫЕ\n ПАРАМЕТРЫ\n ПОЛУЧЕНЫ";
  FMyThread1->counttext=1;
  FMyThread1->speedtext1=80;
  FMyThread1->speedtext2=1000;
  FMyThread1->size[1]=54;
  Label1->Caption="Ожидание задачи с номером дома";
  k=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button62Click(TObject *Sender)      //-------------------------- 8-й этап  ДОМ
{
UpMemory(5);
timevalue4_3flag=true;
timevalue4_3=timercount + 8;
Label1->Caption = "ПЕРЕХОД К ОСНОВНОЙ ЗАДАЧЕ ДОМИКА";
stagestatus8 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button63Click(TObject *Sender)      //---------------------------6-й этап
{
 stagestatus9 = 1;
 check_random_audio_moto = false;
 ChangeSoundWall("Fon\\9_silence");
 FPlaySound("Echo_Main_Messages\\7_1_chronook", 1);
 UpMemory(5);

 timevalue5flag=true;
 timevalue5=timercount + 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button64Click(TObject *Sender)     //------------------------- этап 7
{
  mototimer = 0;
  stagestatus10 = 1;
  FPlaySound("Echo_Main_Messages\\7_to_8_avaria_plus_piano_tranzition_story_1", 1);
  StringGrid2->Cells[2][20] = 0;
  setPIO = true;
  lightfonar = true;
  lightfonar_timer = timercount;
  UpMemory(10);
  timevalue6flag=true;
  timevalue6=timercount + 30;
}

void __fastcall TForm1::Button65Click(TObject *Sender)      //-----------------------  этап 8
{
 timecountrealflag=false;   //--------останавливаем время - дошли в финал
 flagScene=true;
 check7=true;
 SetManualBeforeStage(7);
 Edit8->Text="Ожидает";
 Label1->Caption="Открылись дверцы Вероники";
 timevalue8flag=true;
 timevalue8=timercount + 120;
 StringGrid2->Cells[2][12]="0";
 StringGrid2->Cells[2][11]="0";
 StringGrid2->Cells[2][10]="1";
 StringGrid2->Cells[2][14]="0";
 setPIO = true;
 check7_1=true;
 check7=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button66Click(TObject *Sender)      //-----------------------этап 9
{

  PlayVideo5("video2");
  flagScene=true;
  check8=true;
  SetManualBeforeStage(8);
  timevalue9flag=true;
  timevalue9=timercount + 60;
                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread4->speedlight1=200;
                FMyThread4->speedlight2=100;
                FMyThread3->lfigura=2;
                FMyThread3->ldomlampa=2;
                FMyThread3->lcherdak=2;
                FMyThread3->lpianino=2;
                FMyThread3->ldiod1=2;
                FMyThread3->lfonar=2;
                FMyThread3->lvera=2;
                FMyThread4->ldiod2=2;
                FMyThread4->lfonar=2;
                FMyThread4->lhouse=2;
                FMyThread4->lshitok=2;
                FMyThread4->lvera=2;
                FMyThread3->goblink=true;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;
  Edit9->Text="Пройден";
  //-----------


     check8=false;
        Label1->Caption="Разъединили один из разъемов Вероники";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



void __fastcall TForm1::Button70Click(TObject *Sender)  //--------вышло время до входа в 4 комнату
{
 //----------------------------------нету check12 true из-за отсутствия условия
check0=false;
check1=false;
check1_1=false;
check0_1=false;
check2=false;
check2_1=false;
check3_1=false;
check3=false;
check4=false;
check4_0=false;
check4_1=false;
check5=false;
check6=false;
check6_1=false;
check7=false;
check7_1=false;
check7_2=false;
check8=false;
check8_1=false;
check9=false;
check10=false;
check11=false;
check12=false;
check12_1=false;
check13=false;
check14=false;
check15=false;
timevaluereader1flag=false;
timevaluestartflag=false;
timevalue0flag=false;
timevalue1flag=false;
timevalue2flag=false;
timevalue3flag=false;
timevalue4flag=false;
timevalue4_1flag=false;
timevalue4_2flag=false;
timevalue4_3flag=false;
timevalue4_4flag=false;
timevalue5flag=false;
timevalue5_1flag=false;
timevalue6flag=false;
timevalue7flag=false;
timevalue7_1flag=false;
timevalue7_2flag=false;
timevalue7_3flag=false;
timevalue8flag=false;
timevalue8_1flag=false;
timevalue9flag=false;
timevalue9_1flag=false;
timevalue10flag=false;
timevalue11flag=false;
timevalue12flag=false;
                StringGrid2->Cells[2][9]="0";
                StringGrid2->Cells[2][10]="0";
                StringGrid2->Cells[2][11]="0";
                StringGrid2->Cells[2][12]="0";
                StringGrid2->Cells[2][13]="0";
                StringGrid2->Cells[2][14]="0";
                StringGrid2->Cells[2][15]="0";
                StringGrid2->Cells[2][16]="0";
                StringGrid2->Cells[2][19]="0";
                setPIO = true;

                FMyThread3->speedlight1=100;
                FMyThread3->speedlight2=100;
                FMyThread4->speedlight1=200;
                FMyThread4->speedlight2=100;
                FMyThread3->lfigura=1;
                FMyThread3->ldomlampa=1;
                FMyThread3->lcherdak=1;
                FMyThread3->lpianino=1;
                FMyThread3->ldiod1=1;
                FMyThread3->lfonar=1;
                FMyThread3->lvera=1;
                FMyThread4->ldiod2=1;
                FMyThread4->lfonar=1;
                FMyThread4->lhouse=1;
                FMyThread4->lshitok=1;
                FMyThread4->lvera=1;
                FMyThread3->goblink=true;
                FMyThread4->goblink=true;
                FMyThread->goblink=true;


FPlaySound("null", 1);
flaglooser=1;

timevalue10flag=true;
timevalue10=timercount + 60;
check12=false;
Label1->Caption="Вышло общее время, ИГРА ПРОИГРАНА, 1 мин отсчет до выхода!";
Edit13->Text="Пройден";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button71Click(TObject *Sender)   //---------белый ящик провод
{
 if(StrToInt(StringGrid1->Cells[2][36]) ==  1){
                 StringGrid1->Cells[2][36] = "0";
                }else{
                   StringGrid1->Cells[2][36] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button76Click(TObject *Sender)
{
StopScene();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button77Click(TObject *Sender)
{
if(stopflag != 1){
                flagScene=true;
                FPlaySound("legend", 1);
                legendflag=true;
                timevalueLEGflag=true;
                timevalueLEG=timercount + 62;
                Label1->Caption="Играет Легенда !";
                }
                else{
                ShowMessage("Не запущен цикл игры");
                }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button78Click(TObject *Sender)
{

Label1->Caption="Соберите игру и закройте все что надо закрыть, свет включен !";

FMyThread2->text[1]="\n Нажмите любую\n кнопку";
FMyThread2->speedtext1=30;
FMyThread2->speedtext2=500;
FMyThread2->size[1]=54;
FMyThread2->textflag=true;

flagScene=false;
flagSM1=true;
flagSM2=true;
flagSM3=true;
flagSM4=true;
flagSM5=true;
flagSM6=true;
flagSM7=true;
flagSM8=true;
flagSM9=true;
flagSM10=true;
flagSM11=true;
flagSM12=true;

 StringGrid2->Cells[2][9]="1";
 StringGrid2->Cells[2][10]="1";
 StringGrid2->Cells[2][11]="1";
 StringGrid2->Cells[2][12]="1";
 StringGrid2->Cells[2][13]="0";
 StringGrid2->Cells[2][14]="1";
 StringGrid2->Cells[2][15]="1";
 StringGrid2->Cells[2][19]="1";
 StringGrid2->Cells[2][1] = "1";
 StringGrid2->Cells[2][2] = "0";
 StringGrid2->Cells[2][3] = "0";
 StringGrid2->Cells[2][5] = "1";
 StringGrid2->Cells[2][6] = "1";
 StringGrid2->Cells[2][17] = "1";
 StringGrid2->Cells[2][18] = "1";
 StringGrid2->Cells[2][4]="1";
 StringGrid2->Cells[2][7]="1";
 StringGrid3->Cells[2][2]="1";

 setPIO = true;
 ChangeSoundWall("Fon\\1_echo_waiting");
 //---------------------------------------------------------------вывод текста на экран
 FMyThread1->text[1]="        ECHO\n           IS\n       ONLINE";
 FMyThread1->speedtext1=30;
 FMyThread1->speedtext2=500;
 FMyThread1->size[1]=108;
 FMyThread1->textflag=true;
 Sleep(300);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button79Click(TObject *Sender)
{
   stopflag=1;
    controllerflag=1;
    if (FMyThread) {
        FMyThread->Terminate();
        delete FMyThread;
        FMyThread = 0;
    }
    Button1Click(Form1);
    //-------------------стартуем поток
      if (FMyThread) {
        ShowMessage("Thread is already launched");
    }
    else {
        FMyThread = new TMyThread(false);
        FMyThread->FreeOnTerminate = false;
        }
   controllerflag=0;
   stopflag=0;
   setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button80Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][1]) == 0){
                 StringGrid1->Cells[2][1] = "1";
                }else{
                   StringGrid1->Cells[2][1] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button81Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][2]) == 0){
                 StringGrid1->Cells[2][2] = "1";
                }else{
                   StringGrid1->Cells[2][2] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button82Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][3]) == 0){
                 StringGrid1->Cells[2][3] = "1";
                }else{
                   StringGrid1->Cells[2][3] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button83Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][4]) == 0){
                 StringGrid1->Cells[2][4] = "1";
                }else{
                   StringGrid1->Cells[2][4] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button84Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][5]) == 0){
                 StringGrid1->Cells[2][5] = "1";
                }else{
                   StringGrid1->Cells[2][5] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button85Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][6]) == 0){
                 StringGrid1->Cells[2][6] = "1";
                }else{
                   StringGrid1->Cells[2][6] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button86Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][7]) == 0){
                 StringGrid1->Cells[2][7] = "1";
                }else{
                   StringGrid1->Cells[2][7] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button87Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][8]) == 0){
                 StringGrid1->Cells[2][8] = "1";
                }else{
                   StringGrid1->Cells[2][8] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button88Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][9]) < 500){
                 StringGrid1->Cells[2][9] = "900";
                }else{
                   StringGrid1->Cells[2][9] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button89Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][10]) < 500){
                 StringGrid1->Cells[2][10] = "900";
                }else{
                   StringGrid1->Cells[2][10] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button90Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][11]) < 500){
                 StringGrid1->Cells[2][11] = "900";
                }else{
                   StringGrid1->Cells[2][11] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button91Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][12]) < 1000){
                 StringGrid1->Cells[2][12] = "1000";
                }else{
                   StringGrid1->Cells[2][12] = "550";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button92Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][13]) < 500){
                 StringGrid1->Cells[2][13] = "900";
                }else{
                   StringGrid1->Cells[2][13] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button93Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][14]) < 500){
                 StringGrid1->Cells[2][14] = "900";
                }else{
                   StringGrid1->Cells[2][14] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button94Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][15]) < 500){
                 StringGrid1->Cells[2][15] = "900";
                }else{
                   StringGrid1->Cells[2][15] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button95Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][16]) < 500){
                 StringGrid1->Cells[2][16] = "900";
                }else{
                   StringGrid1->Cells[2][16] = "350";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button96Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][17]) == 0){
                 StringGrid1->Cells[2][17] = "1";
                }else{
                   StringGrid1->Cells[2][17] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button97Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][18]) == 0){
                 StringGrid1->Cells[2][18] = "1";
                }else{
                   StringGrid1->Cells[2][18] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button98Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][19]) == 0){
                 StringGrid1->Cells[2][19] = "1";
                }else{
                   StringGrid1->Cells[2][19] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button99Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][20]) == 0){
                 StringGrid1->Cells[2][20] = "1";
                }else{
                   StringGrid1->Cells[2][20] = "0";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button100Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][21]) ==  1){
                 StringGrid1->Cells[2][21] = "0";
                }else{
                   StringGrid1->Cells[2][21] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button101Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][25]) > 0){
        StringGrid2->Cells[2][25] = 0;
        }else{
        StringGrid2->Cells[2][25] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button102Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][26]) > 0){
        StringGrid2->Cells[2][26] = 0;
        }else{
        StringGrid2->Cells[2][26] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button103Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][27]) > 0){
        StringGrid2->Cells[2][27] = 0;
        }else{
        StringGrid2->Cells[2][27] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button104Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][28]) > 0){
        StringGrid2->Cells[2][28] = 0;
        }else{
        StringGrid2->Cells[2][28] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button105Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][29]) > 0){
        StringGrid2->Cells[2][29] = 0;
        }else{
        StringGrid2->Cells[2][29] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button106Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][30]) > 0){
        StringGrid2->Cells[2][30] = 0;
        }else{
        StringGrid2->Cells[2][30] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button107Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][31]) > 0){
        StringGrid2->Cells[2][31] = 0;
        }else{
        StringGrid2->Cells[2][31] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button108Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][32]) > 0){
        StringGrid2->Cells[2][32] = 0;
        }else{
        StringGrid2->Cells[2][32] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button109Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][33]) > 0){
        StringGrid2->Cells[2][33] = 0;
        }else{
        StringGrid2->Cells[2][33] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button110Click(TObject *Sender)
{
if(readkey == 1){
        readkey=0;
        }else{
        readkey=1;
        }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


void __fastcall TForm1::Button111Click(TObject *Sender)
{
 if(StrToInt(StringGrid2->Cells[2][34]) > 0){
        StringGrid2->Cells[2][34] = 0;
        }else{
        StringGrid2->Cells[2][34] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button72Click(TObject *Sender)
{
stagestatus2 = 1;
ChangeSoundWall("Fon\\2_echo_online");
FMyThread1->text[1]="\n АНАЛИЗ \n НЕИСПРАВНОСТЕЙ";
FMyThread1->speedtext1=30;
FMyThread1->speedtext2=500;
FMyThread1->size[1]=54;
FMyThread1->textflag=true;
StringGrid2->Cells[2][43] = 1;
setPIO = true;
FPlaySound("Echo_Main_Messages\\0_3_obeytooperator", 1);
timevalue1flag=true;
timevalue1=timercount + 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button74Click(TObject *Sender)
{
StopSoundWall();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button112Click(TObject *Sender)
{
flagGM2=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button113Click(TObject *Sender)
{
                stagestatus4 = 2;
                StringGrid2->Cells[2][19] = 0;
                StringGrid2->Cells[2][3] = 0;
                setPIO = true;
                Button60Click(Form1);
                fonarcheck = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button114Click(TObject *Sender)
{
flagGM3=true;
memorycount=40;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button115Click(TObject *Sender)
{
flagGM4=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button116Click(TObject *Sender)
{
flagGM5=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button117Click(TObject *Sender)
{
flagGM6=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button118Click(TObject *Sender)
{
flagGM7=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button119Click(TObject *Sender)
{
flagGM8=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button120Click(TObject *Sender)
{
flagGM9=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button121Click(TObject *Sender)
{
 timecount = timecount + 300;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button122Click(TObject *Sender)
{
flagGM11=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button123Click(TObject *Sender)
{
flagGM12=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button124Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][35]) > 0){
        StringGrid2->Cells[2][35] = 0;
        }else{
        StringGrid2->Cells[2][35] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button125Click(TObject *Sender)
{
flagScene=true;
timecount=3600;      //----------------установка часа для обратного отсчета
timenull=1;
timecountrealflag=true;         //---установка и запуск общего времени игры
timecountreal=0;
flagSM1=true;
flagSM2=true;
flagSM3=true;
flagSM4=true;
flagSM5=true;
flagSM6=true;
flagSM7=true;
flagSM8=true;
flagSM9=true;
flagSM10=true;
flagSM11=true;
flagSM12=true;
check14=true;
Label1->Caption="Режим игры не с начала!\nНАЖМИТЕ ЛЕВУЮ КНОПКУ НУЖНОГО ЭТАПА ИГРЫ !";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button126Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][36]) > 0){
        StringGrid2->Cells[2][36] = 0;
        }else{
        StringGrid2->Cells[2][36] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button127Click(TObject *Sender)
{
 timecount = timecount - 300;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
StringGrid2->Cells[2][1] = "1";
StringGrid2->Cells[2][2] = "1";
StringGrid2->Cells[2][3] = "1";
StringGrid2->Cells[2][5] = "1";
StringGrid2->Cells[2][6] = "1";
StringGrid2->Cells[2][17] = "1";
StringGrid2->Cells[2][18] = "1";
setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
StringGrid2->Cells[2][1] = "0";
StringGrid2->Cells[2][2] = "0";
StringGrid2->Cells[2][3] = "0";
StringGrid2->Cells[2][5] = "0";
StringGrid2->Cells[2][6] = "0";
StringGrid2->Cells[2][17] = "0";
StringGrid2->Cells[2][18] = "0";
setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button34Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][22]) > 10){
                 StringGrid1->Cells[2][22] = "0";
                }else{
                   StringGrid1->Cells[2][22] = "200";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{

 setPIO = true;
 StringGrid2->Cells[2][9]="0";
 StringGrid2->Cells[2][10]="0";
 StringGrid2->Cells[2][11]="0";
 StringGrid2->Cells[2][12]="0";
 StringGrid2->Cells[2][13]="0";
 StringGrid2->Cells[2][14]="0";
 StringGrid2->Cells[2][15]="0";
 StringGrid2->Cells[2][19]="0";
 StringGrid2->Cells[2][2] = "1";
 Button140Click(Form1);//-----------------Первый этап
 Label1->Caption="Игра готова к старту, свет выключен, идите запускать игроков !";

 tempbook=StringGrid1->Cells[2][6]; //-------------------------------запоминаем первоначальное положение книги
 tempambrella=StringGrid1->Cells[2][5];//----------запоминаем певроначальное положение зонтика
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender)
{
flagGM3_1=true;

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Label23Click(TObject *Sender)
{
 FPlaySound("MESSAGES\\18-Goandplay", 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender)
{
flagGM3_2=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button38Click(TObject *Sender)
{
flagGM3_3=true;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button39Click(TObject *Sender)
{
if(check14){
        check14=false;
        }else{
        check14=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button40Click(TObject *Sender)
{
      stagestatus11 = 1;
      ChangeSoundWall("Fon\\11_dia_2");
      UpMemory(15);
      timevalue7flag = true;
      timevalue7 = timercount + 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender)
{
flagGM13=true;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button42Click(TObject *Sender)
{
flagGM7_1=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
timercount2++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender)
{
 if(StrToInt(StringGrid1->Cells[2][23]) ==  1){
                 StringGrid1->Cells[2][23] = "0";
                }else{
                   StringGrid1->Cells[2][23] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button44Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][24]) ==  1){
                 StringGrid1->Cells[2][24] = "0";
                }else{
                   StringGrid1->Cells[2][24] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button45Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][25]) ==  1){
                 StringGrid1->Cells[2][25] = "0";
                }else{
                   StringGrid1->Cells[2][25] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button46Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][26]) ==  1){
                 StringGrid1->Cells[2][26] = "0";
                }else{
                   StringGrid1->Cells[2][26] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button47Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][27]) ==  1){
                 StringGrid1->Cells[2][27] = "0";
                }else{
                   StringGrid1->Cells[2][27] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button48Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][28]) ==  1){
                 StringGrid1->Cells[2][28] = "0";
                }else{
                   StringGrid1->Cells[2][28] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button49Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][29]) ==  1){
                 StringGrid1->Cells[2][29] = "0";
                }else{
                   StringGrid1->Cells[2][29] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button50Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][30]) == 1){
                 StringGrid1->Cells[2][30]= "0";
                }else{
                   StringGrid1->Cells[2][30] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button51Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][31]) > 500){
                 StringGrid1->Cells[2][31] = "350";
                }else{
                   StringGrid1->Cells[2][31] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button56Click(TObject *Sender)
{
 if(StrToInt(StringGrid1->Cells[2][32]) >  500){
                 StringGrid1->Cells[2][32] = "350";
                }else{
                   StringGrid1->Cells[2][32] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button57Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][33]) >  500){
                 StringGrid1->Cells[2][33] = "350";
                }else{
                   StringGrid1->Cells[2][33] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button67Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][35]) ==  1){
                 StringGrid1->Cells[2][35] = "0";
                }else{
                   StringGrid1->Cells[2][35] = "1";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button73Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][37]) >  500){
                 StringGrid1->Cells[2][37] = "350";
                }else{
                   StringGrid1->Cells[2][37] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button75Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][38]) > 500){
                 StringGrid1->Cells[2][38] = "350";
                }else{
                   StringGrid1->Cells[2][38] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button128Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][37]) > 0){
        StringGrid2->Cells[2][37] = 0;
        }else{
        StringGrid2->Cells[2][37] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button129Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][38]) > 0){
        StringGrid2->Cells[2][38] = 0;
        }else{
        StringGrid2->Cells[2][38] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button130Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][39]) > 0){
        StringGrid2->Cells[2][39] = 0;
        }else{
        StringGrid2->Cells[2][39] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button131Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][40]) > 0){
        StringGrid2->Cells[2][40] = 0;
        }else{
        StringGrid2->Cells[2][40] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button132Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][41]) > 0){
        StringGrid2->Cells[2][41] = 0;
        }else{
        StringGrid2->Cells[2][41] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button133Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][42]) > 0){
        StringGrid2->Cells[2][42] = 0;
        }else{
        StringGrid2->Cells[2][42] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button134Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][43]) > 0){
        StringGrid2->Cells[2][43] = 0;
        }else{
        StringGrid2->Cells[2][43] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button135Click(TObject *Sender)
{
if(StrToInt(StringGrid2->Cells[2][44]) > 0){
        StringGrid2->Cells[2][44] = 0;
        }else{
        StringGrid2->Cells[2][44] = 1;
        }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button136Click(TObject *Sender)
{
if(StrToInt(StringGrid3->Cells[2][1]) ==  1){
                 StringGrid3->Cells[2][1] = "0";
                }else{
                   StringGrid3->Cells[2][1] = "1";
                }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button137Click(TObject *Sender)
{
if(StrToInt(StringGrid3->Cells[2][2]) ==  1){
                 StringGrid3->Cells[2][2] = "0";
                }else{
                   StringGrid3->Cells[2][2] = "1";
                }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button138Click(TObject *Sender)
{
if(StrToInt(StringGrid3->Cells[2][3]) ==  1){
                 StringGrid3->Cells[2][3] = "0";
                }else{
                   StringGrid3->Cells[2][3] = "1";
                }
        setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button139Click(TObject *Sender)
{
if(StrToInt(StringGrid3->Cells[2][4]) ==  1){
                 StringGrid3->Cells[2][4] = "0";
                }else{
                   StringGrid3->Cells[2][4] = "1";
                }
        setPIO = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button140Click(TObject *Sender)
{

check0=true;
flagScene=true;
stagestatus1 = 1; //--первый этап
stagestatus14 = 1; // "не успели" в форме игры
timecountrealflag=true;         //---установка и запуск общего времени игры
timecountreal=0;
timecount=3600;      //----------------установка часа для обратного отсчета
Label1->Caption="При Входе диалог - первая задача";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button143Click(TObject *Sender)
{
 stagestatus3 = 1;
 timevalue1_1flag=true;
 timevalue1_1=timercount + 15;
 StringGrid2->Cells[2][43] = 1;
 setPIO = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button145Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][37]) >  200){
                 StringGrid1->Cells[2][37] = "150";
                }else{
                   StringGrid1->Cells[2][37] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button146Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][38]) > 200){
                 StringGrid1->Cells[2][38] = "150";
                }else{
                   StringGrid1->Cells[2][38] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button147Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][32]) >  200){
                 StringGrid1->Cells[2][32] = "150";
                }else{
                   StringGrid1->Cells[2][32] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button148Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][33]) >  200){
                 StringGrid1->Cells[2][33] = "150";
                }else{
                   StringGrid1->Cells[2][33] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button149Click(TObject *Sender)
{
if(StrToInt(StringGrid1->Cells[2][31]) > 200){
                 StringGrid1->Cells[2][31] = "150";
                }else{
                   StringGrid1->Cells[2][31] = "900";
                }
readkey = 0;
manual_timer = timercount + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button141Click(TObject *Sender)
{
check0_1 = true;
check0 = false;
flagGM1 = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
int temp = 0;

if(ACol == 1){
     if(StringGrid2->Cells[2][ARow] != ""){
        temp = StrToInt(StringGrid2->Cells[2][ARow]);
        if (Grid2[ARow] != temp){
            Grid2[ARow] = temp;
            StringGrid2->Canvas->Brush->Color = clBlue;
            StringGrid2->Canvas->FillRect(Rect);
            StringGrid2->Canvas->Font->Color = clWhite;
            StringGrid2->Canvas->TextRect(Rect, (ACol * StringGrid2->DefaultColWidth) - 76,
            ARow * (StringGrid2->DefaultRowHeight + 1), StringGrid2->Cells[ACol][ARow]);
            }else{
                StringGrid2->Canvas->Brush->Color = clWhite;
                StringGrid2->Canvas->FillRect(Rect);
                StringGrid2->Canvas->Font->Color = clBlack;
                StringGrid2->Canvas->TextRect(Rect, (ACol * StringGrid2->DefaultColWidth) - 76,
                ARow * (StringGrid2->DefaultRowHeight + 1), StringGrid2->Cells[ACol][ARow]);
            }
     }
    if (ARow > 0){
        if (StrToInt(StringGrid2->Cells[2][ARow]) == 1){
            StringGrid2->Canvas->Brush->Color = clBlue;
            StringGrid2->Canvas->FillRect(Rect);
            StringGrid2->Canvas->Font->Color = clWhite;
            StringGrid2->Canvas->TextRect(Rect, (ACol * StringGrid2->DefaultColWidth) - 76,
            ARow * (StringGrid2->DefaultRowHeight + 1), StringGrid2->Cells[ACol][ARow]);
        }
    }
}
        //Устанавливает цвет фона если включено


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
Form1->StringGrid2->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
int temp = 0;


if(ACol == 1){

     if(StringGrid3->Cells[2][ARow] != ""){
        temp = StrToInt(StringGrid3->Cells[2][ARow]);
        if (Grid3[ARow] != temp){
                Grid3[ARow] = temp;
                StringGrid3->Canvas->Brush->Color = clBlue;
                StringGrid3->Canvas->FillRect(Rect);
                StringGrid3->Canvas->Font->Color = clWhite;
                StringGrid3->Canvas->TextRect(Rect, (ACol * StringGrid3->DefaultColWidth) - 60,
                ARow * (StringGrid3->DefaultRowHeight + 1), StringGrid3->Cells[ACol][ARow]);
                }else{
                StringGrid3->Canvas->Brush->Color = clWhite;
                StringGrid3->Canvas->FillRect(Rect);
                StringGrid3->Canvas->Font->Color = clBlack;
                StringGrid3->Canvas->TextRect(Rect, (ACol * StringGrid3->DefaultColWidth) - 60,
                ARow * (StringGrid3->DefaultRowHeight + 1), StringGrid3->Cells[ACol][ARow]);
                }

        }
     }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
Form1->StringGrid3->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button150Click(TObject *Sender)
{
PlayNumberPlayers(false, "");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button144Click(TObject *Sender)
{
dialogMain->index = 0;
}
//---------------------------------------------------------------------------
int __fastcall TForm1::Random(int min, int max, bool reset) {
int temp = 0;
int key = false;
int Mkey = true;
int delta = max - min;

  if(reset){
           random_i = 0;
           for (int i = 0; i < 25; i++){
              random_value[i] = 0;
           }
        }
  while(Mkey){
    if(delta  > random_i){
        key = false;
        randomize;
        temp = min + rand() % (max - min);
        for (int i = 0; i < 25; i++){
                if(random_value[i] == temp){
                        key = true;
                }
        }
        if(!key){
                random_value[random_i] = temp;
                random_i++;
                Mkey = false;
        }
    }else{
         Mkey = false;
         reset = true; //---когда все варианты выданы, сбрасываем, и начинаем сначала
         }
  }
  return temp;
}

int __fastcall TForm1::RandomDiff(int min, int max, bool reset) {
int temp = 0;
int key = false;
int Mkey = true;
int delta = max - min;

  if(reset){
           random_i_diff = 0;
           for (int i = 0; i < 25; i++){
              random_value_diff[i] = 0;
           }
        }
  while(Mkey){
    if(delta  > random_i_diff){
        key = false;
        randomize;
        temp = min + rand() % (max - min);
        for (int i = 0; i < 25; i++){
                if(random_value_diff[i] == temp){
                        key = true;
                }
        }
        if(!key){
                random_value_diff[random_i_diff] = temp;
                random_i_diff++;
                Mkey = false;
        }
    }else{
         Mkey = false;
         reset = true; //---когда все варианты выданы, сбрасываем, и начинаем сначала
         }
  }
  return temp;
}

//=========================================================ПОДГОТОВКА НАДПИСЕЙ ДЛЯ ЭТАПА ТЕРМИНАЛА
void __fastcall TForm1::GetTextForTerminal(void){
        if(!shitok_name){terminal3 = "ОТКЛЮЧЕНО";}else{terminal3 = "ВКЛЮЧЕНО";}
        if(!shitok_color){terminal2 = "ОТКЛЮЧЕНО";}else{terminal2 = "ВКЛЮЧЕНО";}
        if(!shitok_memory){terminal1 = "ОТКЛЮЧЕНО";}else{terminal1 = "ВКЛЮЧЕНО";}
        temptext = " КОНСТРУКТОР ЛИЧНОСТИ \n " + terminal1 + "\n\n ЦВЕТОВОЕ КОДИРОВАНИЕ \n " + terminal2 + "\n\n КЛЮЧЕВОЕ ИМЯ \n " + terminal3;
        FMyThread1->text[2]= temptext.c_str();
}

//-------------------------------------------------------ПРОЦЕДУРА ДОБАВДЕНИЯ ПРОЦЕНТА ПАМЯТИ

void __fastcall TForm1::UpMemory(int range){

FMyThread1->text[1]="";
FMyThread1->textflag=false;
FMyThread1->textdigit1=memorycount; //----наименьшее
FMyThread1->textdigit2=memorycount + range; //----наибольшее
FMyThread1->speedtext1=400;  //---задержка счета
FMyThread1->speedtext2=1000; //---сколько показывать конечную цифру
FMyThread1->size[1]=380;
FMyThread1->digitflag=true;
FMyThread1->countdown = false;
memorycount = memorycount + range;
memorycount_flag = true;
memorytimervalue = timercount + 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button151Click(TObject *Sender)
{
stagestatus7 = 1;
if(stagestatus6 == 2){
        timevalue4_4flag=true;
        timevalue4_4=timercount + 11;
        FPlaySound("Echo_Main_Messages\\zvonok_veronika_OK", 1);
        UpMemory(10);
}
if(stagestatus6 == 3){
        timevalue4_2flag=true;
        timevalue4_2=timercount + 11;
        FPlaySound("Echo_Main_Messages\\zvonok_veronika_NOT_OK", 1);
        UpMemory(5);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PlayNumberPlayers(bool flag, AnsiString file){

AnsiString temp = Edit21->Text;
AnsiString A, B, C;
AnsiString path;

A = temp.SubString(1, 1);
B = temp.SubString(2, 1);
C = temp.SubString(3, 1);

if(file != ""){numberplayers_play = file;};

if(!flag){
        path = "Extra\\Numbers\\" + A;
        FPlaySound(path, 1);
        path = "Extra\\Numbers\\" + B;
        PlayWaitMessage(path, 1);
        numberplayer_flag = true;
}else{
        path = "Extra\\Numbers\\" + C;
        FPlaySound(path, 1);
        PlayWaitMessage(numberplayers_play, 1);
}
}
void __fastcall TForm1::StringGrid2DblClick(TObject *Sender)                    //Обработка события двойного клика по строке
{       TStringGrid* sender = (TStringGrid *)Sender;
        int col = 2, row = 0;
        row = sender->Row;
        if (row >0){
                if(StrToInt(StringGrid2->Cells[col][row]) > 0){
                        StringGrid2->Cells[col][row] = 0;
                }else{
                        StringGrid2->Cells[col][row] = 1;
                }
                setPIO = true;
        }
}
//---------------------------------------------------------------------------

