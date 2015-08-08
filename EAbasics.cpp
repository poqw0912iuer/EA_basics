#include <vcl.h>
#include <math.h>
#pragma hdrstop
#include "EAbasics.h"
#include "TGenotype.h"
#include "TGeneticOperators.h"
#include "TSelectionProtocols.h"
#include "TSelectionMechanisms.h"
#include "Unit2.h"
#include "TPlottingRoutine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"            
TForm1 *Form1;
TGenotype **Adult, **Child;
TGeneticOperators GA_Operator;
TSelectionMechanisms SelectionMechanism;
TPlottingRoutine GrphTool;
TSelectionProtocols SelectionProtocol;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner){
    for(int i = 1; i <= 40; i ++)
        StringGrid1 -> Cells[ i][ 0] = i;
    StringGrid1 -> Cells[ 41][ 0] = "Fit";
    StringGrid1 -> Cells[ 0][ 1] = "Sol";
    StringGrid1 -> Cells[ 0][ 2] = "Tar";
    SelectionMechanismNr = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender){ 
    population = Edit2 -> Text.ToInt();
    K = Edit6 -> Text.ToInt();
    if(population % 2 )   MessageBox( NULL, "Type in even volume of population!", "EA_Basic", MB_OK);
    else if((population % K) || K == population || K == 1)   MessageBox( NULL, "Choose different K!", "EA_Basic", MB_OK);
    else{
        for(int i = 1; i <= 42; i ++){
             StringGrid1 -> Cells[ i + 1][ 1] = " "; StringGrid1 -> Cells[ i + 1][ 2] = " ";}
        lenght = Edit1 -> Text.ToInt();
        generations = Edit8->Text.ToInt();
        cross_probability = 100 * Edit3 -> Text.ToDouble();
        mut_probability = 100 * Edit4 -> Text.ToDouble();
        max = new float[ generations];
        average = new float[ generations];
        st_dew = new float[ generations];
        best_genotype = new TGenotype(lenght);   int sum = 0;
        if(RadioButton8 -> Checked == true){
            for(int i = 0; i < lenght; i ++){Target[ i] = 1;         sum += Target[ i];}
        }
        else if(RadioButton9 -> Checked == true){
            for(int i = 0; i < lenght; i ++){Target[ i] = random(2); sum += Target[ i];}
        }  
        Adult = new TGenotype*[population];
        for(int i = 0; i < population; i ++)
            Adult[ i] = new TGenotype(lenght);
        GrphTool.Record_Data(Adult, population, 0);

        if(RadioButton5 -> Checked == true){
            SelectionProtocol.FullGenerationalReplacement(Adult, population, generations,
                             cross_probability, mut_probability, SelectionMechanismNr);
        }
        else if(RadioButton6 -> Checked == true){
            SelectionProtocol.OverProduction(Adult, population, generations, cross_probability,
                                                      mut_probability, SelectionMechanismNr);
        }
        else if(RadioButton7->Checked == true){
            SelectionProtocol.GenerationalMixing(Adult, population, generations, cross_probability,
                                                          mut_probability, SelectionMechanismNr);
        }
        for(int i = 0; i < lenght; i ++){
            StringGrid1->Cells[ i + 1][ 1] = best_genotype->Get_Phenotype(i);
            StringGrid1->Cells[ i + 1][ 2] = Target[ i];
        }
        StringGrid1->Cells[ 41][ 1] = best_genotype->Get_Fitnes();//max[ generations - 1];//
        StringGrid1->Cells[ 41][ 2] = sum;
        Button2->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender){
    Edit5 -> Enabled = false;
    Edit6 -> Enabled = false;
    Edit7 -> Enabled = false;
    SelectionMechanismNr = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender){
    Edit5 -> Enabled = true;
    Edit6 -> Enabled = false;
    Edit7 -> Enabled = false;
    SelectionMechanismNr = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender){
    Edit5 -> Enabled = false;
    Edit6 -> Enabled = false;
    Edit7 -> Enabled = false;
    SelectionMechanismNr = 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender){
    Edit5 -> Enabled = false;
    Edit6 -> Enabled = true;
    Edit7 -> Enabled = true;
    SelectionMechanismNr = 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton10Click(TObject *Sender)
{
    Edit5 -> Enabled = false;
    Edit6 -> Enabled = false;
    Edit7 -> Enabled = false;
    SelectionMechanismNr = 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    GrphTool.Plot(generations);
}
//---------------------------------------------------------------------------





