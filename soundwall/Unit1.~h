//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
void __fastcall main_module(void);

class TForm1 : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
//        __fastcall TForm1(TComponent* Owner);

        void __fastcall ReadMap(HANDLE h, LPTSTR &buffer);
        void __fastcall WriteMap(HANDLE h, AnsiString txt);
        void __fastcall CreateMap(void);
        void __fastcall CloseMap(void);
        void __fastcall SoundVolumeDOWN(int channel, int delay);
        void __fastcall SoundVolumeUP(int channel, int delay);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 