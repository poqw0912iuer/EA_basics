#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "EAbasics.h"
#include "TPlottingRoutine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPlottingRoutine GrphTool;
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormPaint(TObject *Sender)
{
    GrphTool.Plot(Form1->generations);
}
//---------------------------------------------------------------------------


