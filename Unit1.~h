//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <mmsystem.h>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
#include <jpeg.hpp>
#include <fstream>

//--------------------------------------------------
class TMyThread1 : public TThread
{
private:
int i,j;

protected:
public:
bool textflag;
bool digitflag;
bool percent;
const char * text[10];
const char * Ttext[10];

int sizetext;

int size[10];

AnsiString textscreen;
int counttext;
int textdigit1,textdigit2;
bool visiblescreen;
int speedtext1;
int speedtext2;
bool countdown;

 void __fastcall Execute(void){
 textflag=false;
 digitflag=false;
 visiblescreen=false;
 counttext=1;
 countdown=false;
 percent = true;

 while (!this->Terminated){

if(textflag && !digitflag){       //--------------------цикл вывода текстов на экраны
        visiblescreen=true;
        textscreen="";
        sizetext=0;
        if(counttext > 0){

        for(j=1;j <= counttext;j++){
        textscreen="";
        i = 0;
        while(i < strlen(text[j])){
                if(Ttext[j] != text[j]){
                        Ttext[j] = text[j];
                        textscreen = "";
                        break;
                        }
                textscreen=textscreen+text[j][i];
                sizetext=size[j];
                i++;
                Sleep(speedtext1);
        }
        Sleep(speedtext2);
        }}
};

if(digitflag && !textflag){              //--------------------цикл вывода отсчетов на экраны
        visiblescreen=true;
        textscreen="";
        if(!countdown){
                for(i=textdigit1;i <= textdigit2;i++){
                 if(percent){
                        textscreen=IntToStr(i)+"%";
                        }else{
                        textscreen=IntToStr(i);
                        }
                if(!digitflag){break;}
                sizetext=size[1];
                Sleep(speedtext1);
                }
        }else{
                for(i=textdigit1;i <= textdigit2;i++){
                if(percent){
                        textscreen=IntToStr(textdigit2-i)+"%";
                        }else{
                        textscreen=IntToStr(textdigit2-i);
                        }
                if(!digitflag){break;}
                sizetext=size[1];
                Sleep(speedtext1);
                }
        }
Sleep(speedtext2);
digitflag=false;
countdown=false;
};
Sleep(12);
 if(!digitflag && !textflag){
        visiblescreen=false;
         }
}

 };

__fastcall TMyThread1(bool CreateSuspended);
 };

 class TMyThread2 : public TThread
{
private:
int i,j;

protected:
public:
bool textflag;
bool digitflag;
const char * text[10];
const char * Ttext[10];

int sizetext;

int size[11];

AnsiString textscreen;
int counttext;
int textdigit1,textdigit2;
bool visiblescreen;
int speedtext1;
int speedtext2;
bool countdown;

 void __fastcall Execute(void){
 textflag=false;
 digitflag=false;
 visiblescreen=false;
 counttext=1;
 countdown=false;

 while (!this->Terminated){

if(textflag && !digitflag){       //--------------------цикл вывода текстов на экраны

        visiblescreen=true;
        textscreen="";
        sizetext=0;
        if(counttext > 0){

        for(j=1;j <= counttext;j++){
        textscreen="";
        i = 0;
        while(i < strlen(text[j])){
                if(Ttext[j] != text[j]){
                        Ttext[j] = text[j];
                        textscreen = "";
                        i = 0;
                        }
                textscreen=textscreen+text[j][i];
                sizetext=size[j];
                i++;
                Sleep(speedtext1);
        }
        Sleep(speedtext2);
        }}
};

if(digitflag && !textflag){              //--------------------цикл вывода отсчетов на экраны
        visiblescreen=true;
        textscreen="";
        if(!countdown){
                for(i=textdigit1;i <= textdigit2;i++){
                textscreen=IntToStr(i)+"%";
                sizetext=size[1];
                Sleep(speedtext1);

                }
        }else{
                for(i=textdigit1;i <= textdigit2;i++){
                textscreen=IntToStr(textdigit2-i)+"%";
                sizetext=size[1];
                Sleep(speedtext1);
                }
        }
Sleep(speedtext2);
digitflag=false;
countdown=false;
};
Sleep(500);
 if(!digitflag && !textflag){
        visiblescreen=false;
         }
}

 };

__fastcall TMyThread2(bool CreateSuspended);
 };



 class TMyThread3 : public TThread
{
private:
int i,j;

protected:
public:

int lhouse;
int lfonar;
int lshitok;
int lpianino;
int lcherdak;
int ldomlampa;
int lvera;
int lfigura;
int ldiod1;
int ldiod2;


int speedlight1,speedlight2;

bool goblink;

 void __fastcall Execute(void){

lhouse=0;
lfonar=0;
lshitok=0;
lpianino=0;
lcherdak=0;
ldomlampa=0;
lvera=0;
lfigura=0;
lhouse=0;
lfonar=0;
lshitok=0;
lpianino=0;
lcherdak=0;
ldomlampa=0;
lvera=0;
lfigura=0;
ldiod1=0;
ldiod2=0;

goblink=false;


 while (!this->Terminated){

 if(lhouse != 0){
 if(lhouse == 2){lhouse = 1;}
 Sleep(speedlight1);
 if(lhouse == 1){lhouse = 2;}
 Sleep(speedlight2);
 }

 if(lfonar != 0){
 if(lfonar == 2){lfonar = 1;}
 Sleep(speedlight1);
 if(lfonar == 1){lfonar = 2;}
 Sleep(speedlight2);
 }

 if(lshitok != 0){
 if(lshitok == 2){lshitok = 1;}
 Sleep(speedlight1);
 if(lshitok == 1){lshitok = 2;}
 Sleep(speedlight2);
 }

 if(lpianino != 0){
 if(lpianino == 2){lpianino = 1;}
 Sleep(speedlight1);
 if(lpianino == 1){lpianino = 2;}
 Sleep(speedlight2);
 }

 if(lcherdak != 0){
 if(lcherdak == 2){lcherdak = 1;}
 Sleep(speedlight1);
 if(lcherdak == 1){lcherdak = 2;}
 Sleep(speedlight2);
 }

 if(ldomlampa != 0){
 if(ldomlampa == 2){ldomlampa = 1;}
 Sleep(speedlight1);
 if(ldomlampa == 1){ldomlampa = 2;}
 Sleep(speedlight2);
 }

 if(lvera != 0){
 if(lvera == 2){lvera = 1;}
 Sleep(speedlight1);
 if(lvera == 1){lvera = 2;}
 Sleep(speedlight2);
 }

 if(lfigura != 0){
 if(lfigura == 2){lfigura = 1;}
 Sleep(speedlight1);
 if(lfigura == 1){lfigura = 2;}
 Sleep(speedlight2);
 }

 if(ldiod1 != 0){
 if(ldiod1 == 2){ldiod1 = 1;}
 Sleep(speedlight1);
 if(ldiod1 == 1){ldiod1 = 2;}
 Sleep(speedlight2);
 }

 if(ldiod2 != 0){
 if(ldiod2 == 2){ldiod2 = 1;}
 Sleep(speedlight1);
 if(ldiod2 == 1){ldiod2 = 2;}
 Sleep(speedlight2);
 }

 Sleep(10);
 }
 };

__fastcall TMyThread3(bool CreateSuspended);
 };

  class TMyThread4 : public TThread
{
private:
int i,j;

protected:
public:

int lhouse;
int lfonar;
int lshitok;
int lpianino;
int lcherdak;
int ldomlampa;
int lvera;
int lfigura;
int ldiod1;
int ldiod2;


int speedlight1,speedlight2;

bool goblink;

 void __fastcall Execute(void){

lhouse=0;
lfonar=0;
lshitok=0;
lpianino=0;
lcherdak=0;
ldomlampa=0;
lvera=0;
lfigura=0;
lhouse=0;
lfonar=0;
lshitok=0;
lpianino=0;
lcherdak=0;
ldomlampa=0;
lvera=0;
lfigura=0;
ldiod1=0;
ldiod2=0;

goblink=false;


 while (!this->Terminated){

 if(lhouse != 0){
 if(lhouse == 2){lhouse = 1;}
 Sleep(speedlight1);
 if(lhouse == 1){lhouse = 2;}
 Sleep(speedlight2);
 }

 if(lfonar != 0){
 if(lfonar == 2){lfonar = 1;}
 Sleep(speedlight1);
 if(lfonar == 1){lfonar = 2;}
 Sleep(speedlight2);
 }

 if(lshitok != 0){
 if(lshitok == 2){lshitok = 1;}
 Sleep(speedlight1);
 if(lshitok == 1){lshitok = 2;}
 Sleep(speedlight2);
 }

 if(lpianino != 0){
 if(lpianino == 2){lpianino = 1;}
 Sleep(speedlight1);
 if(lpianino == 1){lpianino = 2;}
 Sleep(speedlight2);
 }

 if(lcherdak != 0){
 if(lcherdak == 2){lcherdak = 1;}
 Sleep(speedlight1);
 if(lcherdak == 1){lcherdak = 2;}
 Sleep(speedlight2);
 }

 if(ldomlampa != 0){
 if(ldomlampa == 2){ldomlampa = 1;}
 Sleep(speedlight1);
 if(ldomlampa == 1){ldomlampa = 2;}
 Sleep(speedlight2);
 }

 if(lvera != 0){
 if(lvera == 2){lvera = 1;}
 Sleep(speedlight1);
 if(lvera == 1){lvera = 2;}
 Sleep(speedlight2);
 }

 if(lfigura != 0){
 if(lfigura == 2){lfigura = 1;}
 Sleep(speedlight1);
 if(lfigura == 1){lfigura = 2;}
 Sleep(speedlight2);
 }

 if(ldiod1 != 0){
 if(ldiod1 == 2){ldiod1 = 1;}
 Sleep(speedlight1);
 if(ldiod1 == 1){ldiod1 = 2;}
 Sleep(speedlight2);
 }

 if(ldiod2 != 0){
 if(ldiod2 == 2){ldiod2 = 1;}
 Sleep(speedlight1);
 if(ldiod2 == 1){ldiod2 = 2;}
 Sleep(speedlight2);
 }

 Sleep(9);
 }
 };

__fastcall TMyThread4(bool CreateSuspended);
 };
//-----------------------------------------------------
class TMyThread : public TThread
{
private:
//-------------------------------------
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

int digdata[40];
int cnt,k,m;
int displayshow2;
//--------------------------------------
protected:
public:

int CardAddress, CardAddress1, CardAddress2;

byte digAA1;
byte digAA2;
byte digAA3;
byte digAA4;
byte digAA5;
byte digAA6;
byte digAA7;
byte digAA8;

byte digBB[20];

byte digA1;
byte digA2;
byte digA3;
byte digA4;
byte digA5;
byte digA6;
byte digA7;
byte digA8;

byte digB1;
byte digB2;
byte digB3;
byte digB4;
byte digB5;
byte digB6;
byte digB7;
byte digB8;

byte TdigA1;
byte TdigA2;
byte TdigA3;
byte TdigA4;
byte TdigA5;
byte TdigA6;
byte TdigA7;
byte TdigA8;

byte TdigB1;
byte TdigB2;
byte TdigB3;
byte TdigB4;
byte TdigB5;
byte TdigB6;
byte TdigB7;
byte TdigB8;

byte digC1;
byte digC2;
byte digC3;
byte digC4;

byte idigA;

byte idigB;

byte idigC;

byte idigD;

bool goblink;

int imasanalog[9];
int imasanalog2[9];
bool set;

 void __fastcall Execute(void){
 //-----------------------------------------------
 goblink=false;
 set=0;
 k=0;

 hDLL = LoadLibrary("K8061.DLL");
 	if (hDLL != NULL)
	{
		OpenDevice = (t_func5) GetProcAddress(hDLL, "OpenDevice");
		CloseDevices = (t_func0) GetProcAddress(hDLL, "CloseDevices");
		ReadAnalogChannel = (t_func7) GetProcAddress(hDLL, "ReadAnalogChannel");
		ReadAllAnalog = (t_func4) GetProcAddress(hDLL, "ReadAllAnalog");
		OutputAnalogChannel = (t_func3) GetProcAddress(hDLL, "OutputAnalogChannel");
		OutputAllAnalog = (t_func4) GetProcAddress(hDLL, "OutputAllAnalog");
		ClearAnalogChannel = (t_func2) GetProcAddress(hDLL, "ClearAnalogChannel");
		ClearAllAnalog = (t_func1) GetProcAddress(hDLL, "ClearAllAnalog");
		SetAnalogChannel = (t_func2) GetProcAddress(hDLL, "SetAnalogChannel");
		SetAllAnalog = (t_func1) GetProcAddress(hDLL, "SetAllAnalog");
		OutputAllDigital = (t_func2) GetProcAddress(hDLL, "OutputAllDigital");
		ClearDigitalChannel = (t_func2) GetProcAddress(hDLL, "ClearDigitalChannel");
		ClearAllDigital = (t_func1) GetProcAddress(hDLL, "ClearAllDigital");
		SetDigitalChannel = (t_func2) GetProcAddress(hDLL, "SetDigitalChannel");
		SetAllDigital = (t_func1) GetProcAddress(hDLL, "SetAllDigital");
		ReadDigitalChannel = (t_func8) GetProcAddress(hDLL, "ReadDigitalChannel");
		ReadAllDigital = (t_func6) GetProcAddress(hDLL, "ReadAllDigital");
        }

 hDLL1 = LoadLibrary("k8055d");
	if (hDLL1 != NULL)
	{
		OpenDevice1 = (t1_func4) GetProcAddress(hDLL1, "OpenDevice");
 		CloseDevices1 = (t1_func0) GetProcAddress(hDLL1, "CloseDevice");
 		ReadAnalogChannel1 = (t1_func4) GetProcAddress(hDLL1, "ReadAnalogChannel");
 		ReadAllAnalog1 = (t1_func2) GetProcAddress(hDLL1, "ReadAllAnalog");
  		OutputAnalogChannel1 = (t1_func3) GetProcAddress(hDLL1, "OutputAnalogChannel");
  		OutputAllAnalog1 = (t1_func3) GetProcAddress(hDLL1, "OutputAllAnalog");
  		ClearAnalogChannel1 = (t1_func) GetProcAddress(hDLL1, "ClearAnalogChannel");
   		ClearAllAnalog1 = (t1_func0) GetProcAddress(hDLL1, "ClearAllAnalog");
   		SetAnalogChannel1 = (t1_func) GetProcAddress(hDLL1, "SetAnalogChannel");
   		SetAllAnalog1 = (t1_func0) GetProcAddress(hDLL1, "SetAllAnalog");
   		WriteAllDigital1 = (t1_func) GetProcAddress(hDLL1, "WriteAllDigital");
   		ClearDigitalChannel1 = (t1_func) GetProcAddress(hDLL1, "ClearDigitalChannel");
   		ClearAllDigital1 = (t1_func0) GetProcAddress(hDLL1, "ClearAllDigital");
   		SetDigitalChannel1 = (t1_func) GetProcAddress(hDLL1, "SetDigitalChannel");
   		SetAllDigital1 = (t1_func0) GetProcAddress(hDLL1, "SetAllDigital");
   		ReadDigitalChannel1 = (t1_func5) GetProcAddress(hDLL1, "ReadDigitalChannel");
   		ReadAllDigital1 = (t1_func1) GetProcAddress(hDLL1, "ReadAllDigital");
   		Version_1 = (t1_func0) GetProcAddress(hDLL1, "Version");
           }

CardAddress = OpenDevice();
CardAddress1 = OpenDevice1(3);
CardAddress2 = OpenDevice();

 //-----------------------------------------------
 while (!this->Terminated){

 //-------------------------------------------------------запись выходов
 if(set){

  if(!digAA1){SetDigitalChannel(CardAddress,1);}else{ClearDigitalChannel(CardAddress,1);}
  if(!digAA2){SetDigitalChannel(CardAddress,2);}else{ClearDigitalChannel(CardAddress,2);}
  if(!digAA3){SetDigitalChannel(CardAddress,3);}else{ClearDigitalChannel(CardAddress,3);}
  if(!digAA4){SetDigitalChannel(CardAddress,4);}else{ClearDigitalChannel(CardAddress,4);}
  if(!digAA5){SetDigitalChannel(CardAddress,5);}else{ClearDigitalChannel(CardAddress,5);}
  if(!digAA6){SetDigitalChannel(CardAddress,6);}else{ClearDigitalChannel(CardAddress,6);}
  if(!digAA7){SetDigitalChannel(CardAddress,7);}else{ClearDigitalChannel(CardAddress,7);}
  if(digAA8){SetDigitalChannel(CardAddress,8);}else{ClearDigitalChannel(CardAddress,8);}

  //-------------Контроллер с регистрами
  for(m = 19; m >= 0; m--){
       if(digBB[m]){SetDigitalChannel(CardAddress2,7);}else{ClearDigitalChannel(CardAddress2,7);}
       SetDigitalChannel(CardAddress2,5);
       ClearDigitalChannel(CardAddress2,5);
  }
  SetDigitalChannel(CardAddress2,6);
  ClearDigitalChannel(CardAddress2,6);

  if(digC1){SetDigitalChannel(CardAddress2,1);}else{ClearDigitalChannel(CardAddress2,1);}
  if(digC2){SetDigitalChannel(CardAddress2,2);}else{ClearDigitalChannel(CardAddress2,2);}
  if(digC3){SetDigitalChannel(CardAddress2,3);}else{ClearDigitalChannel(CardAddress2,3);}
  if(digC4){SetDigitalChannel(CardAddress2,4);}else{ClearDigitalChannel(CardAddress2,4);}
  //------------Конец Контроллер с регистрами

  if(!digAA1){SetDigitalChannel(CardAddress,1);}else{ClearDigitalChannel(CardAddress,1);}
  if(!digAA2){SetDigitalChannel(CardAddress,2);}else{ClearDigitalChannel(CardAddress,2);}
  if(!digAA3){SetDigitalChannel(CardAddress,3);}else{ClearDigitalChannel(CardAddress,3);}
  if(!digAA4){SetDigitalChannel(CardAddress,4);}else{ClearDigitalChannel(CardAddress,4);}
  if(!digAA5){SetDigitalChannel(CardAddress,5);}else{ClearDigitalChannel(CardAddress,5);}
  if(!digAA6){SetDigitalChannel(CardAddress,6);}else{ClearDigitalChannel(CardAddress,6);}
  if(!digAA7){SetDigitalChannel(CardAddress,7);}else{ClearDigitalChannel(CardAddress,7);}
  if(digAA8){SetDigitalChannel(CardAddress,8);}else{ClearDigitalChannel(CardAddress,8);}

  if(TdigA1 != digA1){
  TdigA1 = digA1;
  if(digA1){OutputAnalogChannel(CardAddress,1,120);}else{OutputAnalogChannel(CardAddress,1,0);}
  }
   if(TdigA2 != digA2){
  TdigA2 = digA2;
  if(digA2){OutputAnalogChannel(CardAddress,2,120);}else{OutputAnalogChannel(CardAddress,2,0);}
   }
   if(TdigA3 != digA3){
  TdigA3 = digA3;
  if(digA3){OutputAnalogChannel(CardAddress,3,120);}else{OutputAnalogChannel(CardAddress,3,0);}
   }
   if(TdigA4 != digA4){
  TdigA4 = digA4;
  if(digA4){OutputAnalogChannel(CardAddress,4,120);}else{OutputAnalogChannel(CardAddress,4,0);}
   }
   if(TdigA5 != digA5){
  TdigA5 = digA5;
  if(digA5){OutputAnalogChannel(CardAddress,5,120);}else{OutputAnalogChannel(CardAddress,5,0);}
   }
   if(TdigA6 != digA6){
  TdigA6 = digA6;
  if(digA6){OutputAnalogChannel(CardAddress,6,120);}else{OutputAnalogChannel(CardAddress,6,0);}
   }
   if(TdigA7 != digA7){
  TdigA7 = digA7;
  if(digA7){OutputAnalogChannel(CardAddress,7,120);}else{OutputAnalogChannel(CardAddress,7,0);}
   }
   if(TdigA8 != digA8){
  TdigA8 = digA8;
  if(digA8){OutputAnalogChannel(CardAddress,8,120);}else{OutputAnalogChannel(CardAddress,8,0);}
    }

   if(TdigB1 != digB1){
  TdigB1 = digB1;
  if(digB1){SetDigitalChannel1(1);}else{ClearDigitalChannel1(1);}
   }
   if(TdigB2 != digB2){
  TdigB2 = digB2;
  if(digB2){SetDigitalChannel1(2);}else{ClearDigitalChannel1(2);}
   }
   if(TdigB3 != digB3){
  TdigB3 = digB3;
  if(digB3){SetDigitalChannel1(3);}else{ClearDigitalChannel1(3);}
   }
   if(TdigB4 != digB4){
  TdigB4 = digB4;
  if(digB4){SetDigitalChannel1(4);}else{ClearDigitalChannel1(4);}
   }
   if(TdigB5 != digB5){
  TdigB5 = digB5;
  if(digB5){SetDigitalChannel1(5);}else{ClearDigitalChannel1(5);}
   }
   if(TdigB6 != digB6){
  TdigB6 = digB6;
  if(digB6){SetDigitalChannel1(6);}else{ClearDigitalChannel1(6);}
   }
   if(TdigB7 != digB7){
  TdigB7 = digB7;
  if(digB7){SetDigitalChannel1(7);}else{ClearDigitalChannel1(7);}
   }
   if(TdigB8 != digB8){
  TdigB8 = digB8;
  if(digB8){SetDigitalChannel1(8);}else{ClearDigitalChannel1(8);}
   }
   set = false;
 }//--------------------------------------------------------------конец проверки set
 //-----------------------------------------чтение входов
 idigA=ReadAllDigital(CardAddress);
 idigD=ReadAllDigital(CardAddress2);
 idigB=ReadAllDigital1();
 idigC=ReadAnalogChannel1(2);
 //-------------------------------------------- чтение обычных входов контроллера
 ReadAllAnalog(CardAddress,imasanalog);
 ReadAllAnalog(CardAddress2,imasanalog2);

 }
};

__fastcall TMyThread(bool CreateSuspended);
 };

//-----------------------------------------------ДИАЛОГ ОСНОВНОЙ
class DialogMain{
private:
public:

AnsiString text[16];
int Agoto[16];
int Bgoto[16];
int index;
int result;
//------------------ОПИСАНИЕ КОДОВ ВЫХОДА МЕНЮ
//--   1: не с той ноги
//---  2; смтрашный сон
//---  3: попытка страшного сна
//--   4: хоти м помочь!


int __fastcall GetResultCode(int index, int button){
int result = 0;

        switch(index){
             case 12:
                result = 1;
                break;
             case 13:
                result = 2;
                break;
             case 14:
                if(button == 1){result = 4;}
                if(button == 2){result = 3;}
                break;
             default:
                result = 0;
                break;
        }
  return result;

}


__fastcall DialogMain(){
    index = 15;

    text[1] = "1. Мы пришли помочь тебе\n2. Кто ты?";
    text[2] = "1. Произошла автокатастрофа\n2. Какая-то авария... Помнишь?";
    text[3] = "1. Произошла автокатастрофа\n2. Какая-то авария... Помнишь?";
    text[4] = "1. Ты серьезно пострадала\n2. Кто-то кроме тебя?";
    text[5] = "1. Дорожное происшествие\n2. Система вышла из строя";
    text[6] = "1. Мы не знаем...\n2. Нет. Только ты";
    text[7] = "1. Что случилось?\n2. Что ты помнишь?";
    text[8] = "1. Не волнуйся...\n2. Что ты помнишь?";
    text[9] = "1. Ты уверена в этом?\n2. Кто за тобой гнался?";
    text[10] = "1. Мы здесь, чтобы помочь\n2. О чем ты говоришь?";
    text[11] = "1. Ты в порядке?\n2. Что с тобой?";
    text[12] = "1. Что происходит?\n2. Что происходит?";
    text[13] = "1. Компания? Это связано с\n системой ЭХО?\n2. Вероятно, это просто\n страшный сон...";
    text[14] = "1. Мы поможем тебе вспомнить!\n2. Вероятно, это просто\n страшный сон...";
    text[15] = "Выбирайте ответ 1 или 2, \n чтобы ответить\n1. Понятно\n2.Непонятно";
    Agoto[1] = 2;
    Bgoto[1] = 3;
    Agoto[2] = 4;
    Bgoto[2] = 5;
    Agoto[3] = 4;
    Bgoto[3] = 5;
    Agoto[4] = 8;
    Bgoto[4] = 6;
    Agoto[5] = 4;
    Bgoto[5] = 10;
    Agoto[6] = 7;
    Bgoto[6] = 7;
    Agoto[7] = 9;
    Bgoto[7] = 9;
    Agoto[8] = 7;
    Bgoto[8] = 9;
    Agoto[9] = 13;
    Bgoto[9] = 13;
    Agoto[10] = 11;
    Bgoto[10] = 14;
    Agoto[11] = 12;
    Bgoto[11] = 12;
    Agoto[12] = 0;
    Bgoto[12] = 0;
    Agoto[13] = 10;
    Bgoto[13] = 0;
    Agoto[14] = 0;
    Bgoto[14] = 0;
    Agoto[15] = 1;
    Bgoto[15] = 15;
}
};

 //-----------------------------------------------ДИАЛОГ ПРИ СТАРТЕ ИГРЫ
class Dialog1{
private:
public:
bool triller;
bool drama;
bool question1;
bool question2;
bool question3;
bool question4;

__fastcall Dialog1(){
        triller = false;
        drama = false;
        question1 = false;
        question2 = false;
        question3 = false;
        question4 = false;
}
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TStringGrid *StringGrid1;
        TStringGrid *StringGrid2;
        TLabel *Label19;
        TLabel *Label30;
        TLabel *Label36;
        TLabel *Label41;
        TButton *Button7;
        TTimer *Timer1;
        TButton *Button3;
        TButton *Button5;
        TButton *Button31;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button9;
        TButton *Button52;
        TButton *Button53;
        TButton *Button54;
        TButton *Button55;
        TPanel *Panel17;
        TButton *Button59;
        TButton *Button60;
        TButton *Button61;
        TButton *Button62;
        TButton *Button63;
        TButton *Button64;
        TButton *Button65;
        TButton *Button66;
        TButton *Button68;
        TButton *Button69;
        TButton *Button70;
        TButton *Button76;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TEdit *Edit14;
        TEdit *Edit15;
        TEdit *Edit16;
        TButton *Button77;
        TButton *Button78;
        TButton *Button80;
        TButton *Button81;
        TButton *Button82;
        TButton *Button83;
        TButton *Button84;
        TButton *Button85;
        TButton *Button86;
        TButton *Button87;
        TButton *Button88;
        TButton *Button89;
        TButton *Button90;
        TButton *Button91;
        TButton *Button92;
        TButton *Button93;
        TButton *Button94;
        TButton *Button95;
        TButton *Button96;
        TButton *Button97;
        TButton *Button98;
        TButton *Button99;
        TButton *Button100;
        TLabel *Label26;
        TLabel *Label31;
        TButton *Button72;
        TButton *Button74;
        TLabel *Label33;
        TButton *Button112;
        TButton *Button113;
        TButton *Button114;
        TButton *Button115;
        TButton *Button116;
        TButton *Button117;
        TButton *Button118;
        TButton *Button119;
        TButton *Button120;
        TButton *Button122;
        TButton *Button123;
        TPanel *Panel25;
        TLabel *Label44;
        TButton *Button110;
        TLabel *Label45;
        TButton *Button79;
        TButton *Button121;
        TButton *Button125;
        TButton *Button127;
        TButton *Button4;
        TButton *Button6;
        TButton *Button8;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TButton *Button16;
        TButton *Button17;
        TButton *Button18;
        TButton *Button19;
        TButton *Button20;
        TButton *Button21;
        TButton *Button22;
        TButton *Button23;
        TButton *Button24;
        TButton *Button25;
        TButton *Button26;
        TButton *Button27;
        TButton *Button28;
        TButton *Button29;
        TButton *Button30;
        TButton *Button32;
        TButton *Button33;
        TButton *Button34;
        TButton *Button36;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label9;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label18;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TButton *Button39;
        TLabel *Label24;
        TLabel *Label25;
        TButton *Button41;
        TLabel *Label28;
        TLabel *Label29;
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TLabel *Label32;
        TButton *Button35;
        TButton *Button37;
        TButton *Button38;
        TButton *Button40;
        TEdit *Edit17;
        TButton *Button42;
        TTimer *Timer2;
        TButton *Button43;
        TButton *Button44;
        TButton *Button45;
        TButton *Button46;
        TButton *Button47;
        TButton *Button48;
        TButton *Button49;
        TButton *Button50;
        TButton *Button51;
        TButton *Button56;
        TButton *Button57;
        TButton *Button58;
        TButton *Button67;
        TButton *Button71;
        TButton *Button73;
        TButton *Button75;
        TButton *Button101;
        TButton *Button102;
        TButton *Button103;
        TButton *Button104;
        TButton *Button105;
        TButton *Button106;
        TButton *Button107;
        TButton *Button108;
        TButton *Button109;
        TButton *Button111;
        TButton *Button124;
        TButton *Button126;
        TButton *Button128;
        TButton *Button129;
        TButton *Button130;
        TButton *Button131;
        TButton *Button132;
        TButton *Button133;
        TButton *Button134;
        TButton *Button135;
        TStringGrid *StringGrid3;
        TLabel *Label34;
        TButton *Button136;
        TButton *Button137;
        TButton *Button138;
        TButton *Button139;
        TButton *Button140;
        TEdit *Edit18;
        TButton *Button141;
        TButton *Button142;
        TButton *Button143;
        TButton *Button144;
        TEdit *Edit19;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Button145;
        TButton *Button146;
        TButton *Button147;
        TButton *Button148;
        TButton *Button149;
        TTimer *Timer3;
        TTimer *Timer4;
        TButton *Button150;
        TLabel *Label8;
        TLabel *Label10;
        TEdit *Edit20;
        TButton *Button151;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label23;
        TLabel *Label27;
        TEdit *Edit21;
        TLabel *Label35;
        TButton *Button152;
        TEdit *Edit22;
        TButton *Button153;

        void __fastcall PlayNumberPlayers(bool flag, AnsiString file);
        void __fastcall SoundVolumeDOWN(int channel, int delay);
        void __fastcall SoundVolumeUP(int channel, int delay);
        void __fastcall FPlaySound(AnsiString file, int channel);
        void __fastcall PlayWaitMessage(AnsiString file, int channel);
        void __fastcall ChangePlayMessage(AnsiString file, int channel);
        bool __fastcall CheckPlayMessages(void);
        void __fastcall ChangeSoundWall(AnsiString file);
        void __fastcall StopSoundWall(void);
        void __fastcall SetRelaySound(int channel);
        void __fastcall RandomPlaySound(int min, int max, AnsiString file, int channel);
        void __fastcall RandomPlaySoundDiff(int min, int max, AnsiString file, int channel);

        void __fastcall ReadMap1(HANDLE h, LPTSTR &buffer);
        void __fastcall WriteMap(HANDLE h, AnsiString txt);
        void __fastcall CreateMap(void);
        void __fastcall CloseMap(void);
        void __fastcall CreateMap1(void);
        void __fastcall CloseMap1(void);

        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button26Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
        void __fastcall Button27Click(TObject *Sender);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button30Click(TObject *Sender);

        void __fastcall Button5Click(TObject *Sender);
        void __fastcall PlayVideo5(AnsiString file);
        void __fastcall StopVideo5(void);
        void __fastcall StopScene(void);
        void __fastcall HideText(void);
        void __fastcall Button52Click(TObject *Sender);
        void __fastcall Button53Click(TObject *Sender);
        void __fastcall Button54Click(TObject *Sender);
        void __fastcall Button55Click(TObject *Sender);


        void __fastcall Button58Click(TObject *Sender);
        void __fastcall Button59Click(TObject *Sender);
        void __fastcall Button60Click(TObject *Sender);
        void __fastcall Button61Click(TObject *Sender);
        void __fastcall Button62Click(TObject *Sender);
        void __fastcall Button63Click(TObject *Sender);
        void __fastcall Button65Click(TObject *Sender);
        void __fastcall Button66Click(TObject *Sender);
        void __fastcall Button70Click(TObject *Sender);
        void __fastcall Button71Click(TObject *Sender);
        void __fastcall Button76Click(TObject *Sender);
        void __fastcall Button77Click(TObject *Sender);
        void __fastcall Button78Click(TObject *Sender);
        void __fastcall Button79Click(TObject *Sender);
        void __fastcall Button80Click(TObject *Sender);
        void __fastcall Button81Click(TObject *Sender);
        void __fastcall Button82Click(TObject *Sender);
        void __fastcall Button83Click(TObject *Sender);
        void __fastcall Button84Click(TObject *Sender);
        void __fastcall Button85Click(TObject *Sender);
        void __fastcall Button86Click(TObject *Sender);
        void __fastcall Button87Click(TObject *Sender);
        void __fastcall Button88Click(TObject *Sender);
        void __fastcall Button89Click(TObject *Sender);
        void __fastcall Button90Click(TObject *Sender);
        void __fastcall Button91Click(TObject *Sender);
        void __fastcall Button92Click(TObject *Sender);
        void __fastcall Button93Click(TObject *Sender);
        void __fastcall Button94Click(TObject *Sender);
        void __fastcall Button95Click(TObject *Sender);
        void __fastcall Button96Click(TObject *Sender);
        void __fastcall Button97Click(TObject *Sender);
        void __fastcall Button98Click(TObject *Sender);
        void __fastcall Button99Click(TObject *Sender);
        void __fastcall Button100Click(TObject *Sender);
        void __fastcall Button101Click(TObject *Sender);
        void __fastcall Button102Click(TObject *Sender);
        void __fastcall Button103Click(TObject *Sender);
        void __fastcall Button104Click(TObject *Sender);
        void __fastcall Button105Click(TObject *Sender);
        void __fastcall Button106Click(TObject *Sender);
        void __fastcall Button107Click(TObject *Sender);
        void __fastcall Button108Click(TObject *Sender);
        void __fastcall Button109Click(TObject *Sender);
        void __fastcall Button110Click(TObject *Sender);
        void __fastcall Button64Click(TObject *Sender);
        void __fastcall Button111Click(TObject *Sender);
        void __fastcall SetLampTable(int dom1t, int dom2t, int dom3t, int dom4t);
        void __fastcall GetFatalScene(void);
        void __fastcall SetMemoryCount(int mc, int index);
        void __fastcall SetCountdown(int timercount_f, int timevalue_f, int dig_f2, int dig_f1, int size);
        void __fastcall OffAll(void);
        void __fastcall MemoryMessages(void);
        void __fastcall TimeMessages(void);
        void __fastcall Button72Click(TObject *Sender);
        void __fastcall Button74Click(TObject *Sender);
        void __fastcall SetManualBeforeStage(int num);
        void __fastcall Button112Click(TObject *Sender);
        void __fastcall Button113Click(TObject *Sender);
        void __fastcall Button114Click(TObject *Sender);
        void __fastcall Button115Click(TObject *Sender);
        void __fastcall Button116Click(TObject *Sender);
        void __fastcall Button117Click(TObject *Sender);
        void __fastcall Button118Click(TObject *Sender);
        void __fastcall Button119Click(TObject *Sender);
        void __fastcall Button120Click(TObject *Sender);
        void __fastcall Button121Click(TObject *Sender);
        void __fastcall Button122Click(TObject *Sender);
        void __fastcall Button123Click(TObject *Sender);
        void __fastcall Button124Click(TObject *Sender);
        void __fastcall Button125Click(TObject *Sender);
        void __fastcall Button126Click(TObject *Sender);
        void __fastcall Button127Click(TObject *Sender);
        void __fastcall Button32Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button34Click(TObject *Sender);
        void __fastcall Button36Click(TObject *Sender);
        void __fastcall Button35Click(TObject *Sender);
        void __fastcall Label23Click(TObject *Sender);
        void __fastcall Button37Click(TObject *Sender);
        void __fastcall Button38Click(TObject *Sender);
        void __fastcall Button39Click(TObject *Sender);
        void __fastcall Button40Click(TObject *Sender);
        void __fastcall Button41Click(TObject *Sender);
        void __fastcall Button42Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Button43Click(TObject *Sender);
        void __fastcall Button44Click(TObject *Sender);
        void __fastcall Button45Click(TObject *Sender);
        void __fastcall Button46Click(TObject *Sender);
        void __fastcall Button47Click(TObject *Sender);
        void __fastcall Button48Click(TObject *Sender);
        void __fastcall Button49Click(TObject *Sender);
        void __fastcall Button50Click(TObject *Sender);
        void __fastcall Button51Click(TObject *Sender);
        void __fastcall Button56Click(TObject *Sender);
        void __fastcall Button57Click(TObject *Sender);
        void __fastcall Button67Click(TObject *Sender);
        void __fastcall Button73Click(TObject *Sender);
        void __fastcall Button75Click(TObject *Sender);
        void __fastcall Button128Click(TObject *Sender);
        void __fastcall Button129Click(TObject *Sender);
        void __fastcall Button130Click(TObject *Sender);
        void __fastcall Button131Click(TObject *Sender);
        void __fastcall Button132Click(TObject *Sender);
        void __fastcall Button133Click(TObject *Sender);
        void __fastcall Button134Click(TObject *Sender);
        void __fastcall Button135Click(TObject *Sender);
        void __fastcall Button136Click(TObject *Sender);
        void __fastcall Button137Click(TObject *Sender);
        void __fastcall Button138Click(TObject *Sender);
        void __fastcall Button139Click(TObject *Sender);
        void __fastcall Button140Click(TObject *Sender);
        void __fastcall Button143Click(TObject *Sender);
        void __fastcall Button145Click(TObject *Sender);
        void __fastcall Button146Click(TObject *Sender);
        void __fastcall Button147Click(TObject *Sender);
        void __fastcall Button148Click(TObject *Sender);
        void __fastcall Button149Click(TObject *Sender);
        void __fastcall Button141Click(TObject *Sender);
        void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall StringGrid3DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Timer4Timer(TObject *Sender);
        void __fastcall Button150Click(TObject *Sender);
        void __fastcall Button144Click(TObject *Sender);
        int __fastcall Random(int min, int max, bool reset);
        int __fastcall RandomDiff(int min, int max, bool reset);
        void __fastcall GetTextForTerminal(void);
        void __fastcall UpMemory(int range);
        void __fastcall Button151Click(TObject *Sender);
        void __fastcall StringGrid2DblClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
        int Grid2[50];
        int Grid3[10];
        int random_value[25];
        int random_value_diff[25];


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern int controllerflag=1;
extern int controllerflag1=1;
extern bool settimeflag=false;      //----------флаг для ручного ввода времени обратного отсчета
extern int timercount=0;                           //глобальный счетчик по таймеру
//---------------------------значения задержек для стадий игры и их флаги
extern int timevalueLEG=0;
extern bool timevalueLEGflag=false;
extern int timevalueERR=0;
extern bool timevalueERRflag=false;
extern int timevaluereader1=0,timevaluestart=0,timevaluestart1=0,timevaluestart1_1=0,timevalue1_1=0,timevalue1_2=0, timevalue1_3 = 0, timevalue1_4 = 0, timevaluestart2=0,timevalue0=0,timevalue1=0,timevalue2=0,timevalue3=0,timevalue3_1=0,timevalue4=0,timevalue4_1=0,timevalue4_2=0,timevalue4_3=0,timevalue4_4=0,timevalue5=0,timevalue5_1=0,timevalue6=0,timevalue7=0,timevalue7_1=0,timevalue7_2=0,timevalue7_3=0,timevalue8=0,timevalue8_1=0,timevalue9=0,timevalue9_1=0,timevalue10=0,timevalue11=0,timevalue12=0;
extern bool timevaluereader1flag=false,timevaluestartflag=false,timevaluestart1flag=false,timevaluestart1_1flag=false ,timevalue1_1flag=false ,timevalue1_2flag=false ,timevalue1_3flag = false, timevalue1_4flag = false, timevaluestart2flag=false,timevalue0flag=false,timevalue1flag=false,timevalue2flag=false,timevalue3flag=false,timevalue3_1flag=false,timevalue4flag=false,timevalue4_1flag=false,timevalue4_2flag=false,timevalue4_3flag=false,timevalue4_4flag=false,timevalue5flag=false,timevalue5_1flag=false,timevalue6flag=false,timevalue7flag=false,timevalue7_1flag=false,timevalue7_2flag=false,timevalue7_3flag=false,timevalue8flag=false,timevalue8_1flag=false,timevalue9flag=false,timevalue9_1flag=false,timevalue10flag=false,timevalue11flag=false,timevalue12flag=false;
extern int timevaluerandommessage = 0;
extern int timevaluerandommessagecherdak = 0;
extern int timevaluerandommessagemoto = 0;
extern int timevaluerandommessagepiano = 0;
//----------------------------------------------------------------
extern int stage=-2;
extern int tempokscene=0;
extern bool color=false;               //-----------стадия пар розеток
extern int timestagevalue=0;
extern bool timestageflag=false;
extern int fatalscene=0;
extern int okscene=0;
//--------------------------------------
extern bool startcontrol1=false;      //-----------флаги отслеживания кнопки старта игры
extern bool startcontrol2=false;
extern int stopflag=1;
extern int keyset=0;
extern int mon=0;     //----------------кол-во подключенных мониторов
extern AnsiString path="C:\\SoundVideo-ECHO\\";
extern int timecount=0;          //----------счетчик секунд для обратного отсчета
extern int timecountreal=0;          //----------счетчик секунд общего времени
extern bool timecountrealflag=false;          //----------aфлаг счетчик секунд общего времени
extern int temptimecount=0;
//---------при изменении времени отчсета либо нуле обновить дисплей
extern bool check0=false;
extern bool check1=false;
extern bool check1_1=false;
extern bool check0_1=false;
extern bool check0_2=false;
extern bool check0_3=false;
extern bool check2=false;
extern bool check2_1=false;
extern bool check3_1=false;
extern bool check3=false;
extern bool check4=false;
extern bool check4_0=false;
extern bool check4_1=false;
extern bool check5=false;
extern bool check6=false;
extern bool check6_1=false;
extern bool check7=false;
extern bool check7_1=false;
extern bool check7_2=false;
extern bool check8=false;
extern bool check8_1=false;
extern bool check9=false;
extern bool check10=false;
extern bool check11=false;
extern bool check12=false;
extern bool check12_1=false;
extern bool check13=false;
extern bool check14=true;
extern bool check15=false;
extern bool check_random_audio = false;//-------------------------------флаг рандомного аудио этап терминала
extern bool check_random_audio_0 = false;//-------------------------------флаг рандомного аудио этап фонарей
extern bool check_random_audio_1 = false; //----------------------флаг рандомного аудио этап терминала после решения первой задачи
extern bool check_random_audio_moto = false; //----------------------флаг рандомного аудио этап МОТО
extern bool key_check_random_audio = true;//-------------------------ключ обновления таймера рандомного аудио
extern bool check_random_audio_cherdak = false;//======================фдаг рандомного аудио для чердака
extern bool check_random_audio_piano = false;//======================фдаг рандомного аудио для пианино
extern bool key_check_random_audio_cherdak = true;
extern bool key_check_random_audio_moto = true;
extern bool key_check_random_audio_piano = true;
extern int stagestatus1 = 0;//-------статусы этапов отображаемые в интерфейсе программы   ВХОД
extern int stagestatus2 = 0;//-------статусы этапов отображаемые в интерфейсе программы   ГЕОМЕТРИЧЕСКАЯ ЗАДАЧА
extern int stagestatus3 = 0;//-------статусы этапов отображаемые в интерфейсе программы
extern int stagestatus4 = 0;//-------статусы этапов отображаемые в интерфейсе программы   ПРОЖЕКТОРЫ
extern int stagestatus5 = 0;//-------статусы этапов отображаемые в интерфейсе программы   ТЕРМИНАЛ
extern int stagestatus6 = 0;//-------статусы этапов отображаемые в интерфейсе программы   НОМЕР ДОМА
extern int stagestatus7 = 0; //-------статусы этапов отображаемые в интерфейсе программы  АКТИВАЦИЯ ФРАГМЕНТОВ
extern int stagestatus8 = 0;//-------статусы этапов отображаемые в интерфейсе программы   ДОМИК
extern int stagestatus9 = 0;//-------статусы этапов отображаемые в интерфейсе программы   МОТО
extern int stagestatus10 = 0;//-------статусы этапов отображаемые в интерфейсе программы  ПИАНИНО
extern int stagestatus11 = 0;//-------статусы этапов отображаемые в интерфейсе программы  ДИАЛОГ
extern int stagestatus12 = 0;//-------статусы этапов отображаемые в интерфейсе программы
extern int stagestatus13 = 0;//-------статусы этапов отображаемые в интерфейсе программы
extern int stagestatus14 = 0;//-------статусы этапов отображаемые в интерфейсе программы
extern int stagestatus15 = 0; //-------статусы этапов отображаемые в интерфейсе программы
extern int stagestatus16 = 0; //-------статусы этапов отображаемые в интерфейсе программы
extern int readkey=1;
extern int flagtimenull=0;
extern int timenull=0;
extern int flagblink=0;
extern bool flagdatacorrect=false;
extern bool legendflag=false;
extern bool flagreader=true;
extern int flaglooser=0;
extern int flagSM1=false;    //--------флаги ручной установки нужного этапа сценария
extern int flagSM2=false;
extern int flagSM3=false;
extern int flagSM4=false;
extern int flagSM5=false;
extern int flagSM6=false;
extern int flagSM7=false;
extern int flagSM8=false;
extern int flagSM9=false;
extern int flagSM10=false;
extern int flagSM11=false;
extern int flagSM12=false;
extern int flagSM13=false;
extern int flagSM14=false;
extern int flagSM15=false;
extern bool flagGM1=false;    //----------флаги ручного срабатывания нужного этапа сценария
extern bool flagGM2=false;
extern bool flagGM3=false;
extern bool flagGM3_1=false;
extern bool flagGM3_2=false;
extern bool flagGM3_3=false;
extern bool flagGM4=false;
extern bool flagGM5=false;
extern bool flagGM6=false;
extern bool flagGM7=false;
extern bool flagGM7_1=false;
extern bool flagGM8=false;
extern bool flagGM9=false;
extern bool flagGM10=false;
extern bool flagGM11=false;
extern bool flagGM12=false;
extern bool flagGM13=false;
extern bool flagGM14=false;
extern bool flagGM15=false;

extern int stagemem=0;
extern bool kassettecheck=false;
extern int kassettetimer=0;
extern bool flagScene=false;     //------------флаг работы сценария
extern bool flagSceneT=true;
extern bool flagplay=false;      //------------для единичного вызова звука внутри одной секунды по таймеру
extern int playtimer=0;
extern int playtimerSW=0;
extern int playtimerchange=0;
extern int checkworktimer=0;     //для исключения повторения срабатываний внутри одной секунды
extern int checkworktimer1=0;     //для исключения повторения срабатываний внутри одной секунды
extern int checkworktimer2=0;     //для исключения повторения срабатываний внутри одной секунды
extern int checkworktimer3=0;     //для исключения повторения срабатываний внутри одной секунды
extern int  fonartimer=0;         //задержка установки фонаря
extern bool fonarcheck=false;
extern int memorycount=0;          //процент памяти по игре
extern bool shitok_color=false;
extern bool shitok_name=false;
extern bool shitok_memory=false;
extern bool chain = true;
extern bool count_chain = 0;
extern bool flag_chain = false;
extern bool chain_audio = false;
extern colortimer=0;           //--------задержка трехкнопок щитка
extern bool colorflag=false;
extern nametimer=0;           //--------задержка переключателей щитка
extern bool nameflag=false;
extern bool fon3_1checkflag=true;   //для смены фона единожды во время трех задач щитка
extern timermess=0;             //--------таймер сообщение периодических 3-го этапа
extern int k=0;                 //---------счетчик аудиосообщениеййййййй
extern int domcount=0;          //----------счетчик нажатий элементов домика общий
extern int domcounttemp=0;          //----------счетчик нажатий элементов домика общий для сравнения
extern int  dom1c=0;            //----------счетчик нажатия элемента домика
extern int  dom2c=0;            //----------счетчик нажатия элемента домика
extern int  dom3c=0;            //----------счетчик нажатия элемента домика
extern int  dom4c=0;            //----------счетчик нажатия элемента домика
extern int  dom1t=0;           //------------последовательная ячейка элементов дома
extern int  dom2t=0;           //------------последовательная ячейка элементов дома
extern int  dom3t=0;           //------------последовательная ячейка элементов дома
extern int  dom4t=0;           //------------последовательная ячейка элементов дома
extern bool flagpostbutton=false;   //-------флаг нажатия кнопки в почтовом ящике
extern int piano1t=0;           //----------------последовательная ячейка ноты
extern int piano2t=0;           //----------------последовательная ячейка ноты
extern int piano3t=0;           //----------------последовательная ячейка ноты
extern int piano4t=0;           //----------------последовательная ячейка ноты
extern bool pianoflag=true;
extern bool motoflag=true;      //-----------------флаг таймера ключа мота
extern int mototimer=0;         //-----------------таймер ключа мото
extern bool countdownflag=false; // ---------------флаг обновлений экрана текста для функции SetCountdown
extern AnsiString temp="";
extern AnsiString temp1="";
extern AnsiString temp2="";
extern AnsiString temp3="";
extern int flagkassette=0; //------------------флаг кассет
extern int buttonvalue=0;
extern bool buttonflag=false;
extern AnsiString tempbook="1";
extern AnsiString tempambrella="1";
extern TColor ColorRed=clRed;
extern int z=0;
const char * housecounttext="";
extern bool number_flag = false;
extern int number_timer = 0;
extern bool switch_flag = false;
extern int switch_timer = 0;
extern int manual_timer = 0;
extern int timercount2 = 0;
extern int provodtimer = 0;
extern bool provodflag = true;
extern int startdialog_level = 0;
extern bool flag_figura1 = false;
extern bool flag_figura2 = false;
extern bool flag_figura3 = false;
extern AnsiString text_figura_status = "";
extern bool flag_maindialog = true;
extern bool flag_maindialog_ready = true;
extern int result_maindialog = 0;
extern bool setPIO = false;
extern bool dialog_flag = false;
extern bool fonar_light_flag  = false;
extern bool fonar_light_flag_2  = false;
extern AnsiString mixed_random_sound = "";
extern int random_i = 0;//----------------счетчик выдачи рандомного имени файла звука
extern int random_i_diff = 0;//----------------счетчик выдачи рандомного имени файла звука ждя дополнительного канала
extern bool lightfonar_flag = false;
extern bool lightfonar = false;
extern int lightfonar_timer = 0;//--------таймер мигания фонаря у чердака дома
extern AnsiString terminal1 = "";
extern AnsiString terminal2 = "";
extern AnsiString terminal3 = "";
extern AnsiString temptext = "";
extern int count_audio_random_cherdak = 0;
extern int memorytimervalue = 0;
extern bool memorycount_flag = false;
extern bool delaysound_flag = false;
extern int delaysound_channel = 0;
extern AnsiString buffer1_ansi = "";
extern bool numberplayer_flag = false;
extern AnsiString numberplayers_play = "";
extern AnsiString geometry_change = "";
extern bool timerdog_flag = false;
extern int timerdogvalue = 0;
extern bool flag_oneofthree = false;
//---------------------------------------------------------------------------
#endif


