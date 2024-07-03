//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Login.h"
#include "Entrypage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
    Hide();
	Form1->Show();
}
//---------------------------------------------------------------------------
