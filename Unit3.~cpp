//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}


void __fastcall TForm3::MediaPlayer1Notify(TObject *Sender)
{
if (MediaPlayer1->NotifyValue == nvSuccessful){
                                MediaPlayer1->Notify=false;
                                MediaPlayer1->Close();
                                }
}





//---------------------------------------------------------------------------

