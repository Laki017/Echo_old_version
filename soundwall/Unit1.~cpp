//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <mmsystem.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
TForm1 *Form1;
HANDLE hMap;
HANDLE hFile;
LPTSTR buffer;
bool key;

void __fastcall main_module(void){
key = true;
LPTSTR buffer;
AnsiString Abuffer, TAbuffer, WAbuffer;
AnsiString command = "";
AnsiString delay = "";
AnsiString file = "";
int Pos = 0;

Form1->CreateMap();
Form1->ReadMap(hMap, buffer);
while(key){
//-------------------------------------------------MAIN MODULE
Abuffer = buffer;
WAbuffer = buffer;

Pos = Abuffer.Pos(";");
if(Pos != 0){
            command = WAbuffer.SubString(0, Pos - 1);
            WAbuffer = WAbuffer.SubString(Pos + 1, WAbuffer.Length());
            Pos = WAbuffer.Pos(";");
            file = WAbuffer.SubString(0, Pos - 1);
            WAbuffer = WAbuffer.SubString(Pos + 1, WAbuffer.Length());
            Pos = WAbuffer.Pos(";");
            delay = WAbuffer.SubString(0, Pos - 1);
            }

if(TAbuffer != Abuffer){
        TAbuffer = Abuffer;

        if(command == "play"){
                             try{
                                PlaySound( file.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                                }
                                catch(...){ShowMessage("Не удалось открыть файл фона.");}
                             };
        if(command == "stop"){PlaySound(NULL, 0, 0);};
        if(command == "volumeup"){Form1->SoundVolumeUP(1, StrToInt(delay));};
        if(command == "volumedown"){Form1->SoundVolumeDOWN(1, StrToInt(delay));};
        if(command == "halt"){key = false;};
        }
//-------------------------------------------------END MAIN MODULE
Sleep(50);
}
Form1->CloseMap();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReadMap(HANDLE h, LPTSTR &buffer)
{
	h=OpenFileMapping(FILE_MAP_ALL_ACCESS, TRUE, "Map");
	buffer = (LPTSTR)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if(buffer == NULL){ShowMessage("Can't read from map file");}
}
 //----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
void __fastcall TForm1::CreateMap(void){
   hFile=CreateFile("file.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ
   | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  hMap=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, "Map");
}
//----------------------------------------------------------------------------
void __fastcall TForm1::CloseMap(void){
  UnmapViewOfFile(hMap);
  CloseHandle(hFile);
  CloseHandle(hMap);
}
//-----------------------------------------------------------------------------
void __fastcall TForm1::SoundVolumeUP(int channel, int delay){

 DWORD levels[16] = {0xFFFF, 0xEEEE, 0xDDDD, 0xCCCC, 0xBBBB, 0xAAAA, 0x9999, 0x8888, 0x7777, 0x6666, 0x5555, 0x4444, 0x3333, 0x2222, 0x1111, 0x0000} ;

 for(int i = 15; i >= 0; i--){
     if(channel == 0){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(levels[i], levels[i] ));
        }
     if(channel == 1){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(levels[i], 0xFFFF ));
        }
     if(channel == 2){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(0xFFFF, levels[i] ));
        }
     Sleep(int(delay/16));
 }
}
//------------------------------------------------------------------------------
void __fastcall TForm1::SoundVolumeDOWN(int channel, int delay){

 DWORD levels[16] = {0xFFFF, 0xEEEE, 0xDDDD, 0xCCCC, 0xBBBB, 0xAAAA, 0x9999, 0x8888, 0x7777, 0x6666, 0x5555, 0x4444, 0x3333, 0x2222, 0x1111, 0x0000} ;

 for(int i = 0; i < 16; i++){
     if(channel == 0){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(levels[i], levels[i] ));
        }
     if(channel == 1){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(levels[i], 0xFFFF ));
        }
     if(channel == 2){
        waveOutSetVolume((HWAVEOUT)WAVE_MAPPER, MAKELONG(0xFFFF, levels[i] ));
        }
     Sleep(int(delay/16));
 }
}