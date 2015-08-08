#pragma hdrstop
#include <vcl.h>
#include "TGenotype.h"
#include "EAbasics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TGenotype::TGenotype(int _lenght){
    lenght = _lenght;
    gens = new int[ lenght];
    phenotypes = new int [ lenght];
    for(int i = 0; i < lenght; i ++)
        gens[ i] = random(2);
    FitnessEvaluation(Form1->Target);
}
//---------------------------------------------------------------------------
void TGenotype::PhenotypeConvertion(){
    for(int i = 0; i < lenght; i ++)
        phenotypes[ i] = gens[ i];   
}
//---------------------------------------------------------------------------
int TGenotype::Get_Phenotype(int index){
    return phenotypes[ index];
}
//---------------------------------------------------------------------------
int TGenotype::Get_Gen(int index){
    return gens[index];
}
//---------------------------------------------------------------------------
void TGenotype::Put_Gen(int index, int value){
    gens[ index] = value;
}
//---------------------------------------------------------------------------
void TGenotype::FitnessEvaluation(int *tab){
    fitnes = 0;
    PhenotypeConvertion();
    for(int i = 0; i < lenght; i ++)
        if(phenotypes[ i] == tab[ i])
            fitnes += 1;
}
//---------------------------------------------------------------------------
float TGenotype::Get_Fitnes(){
    return fitnes;
}
//---------------------------------------------------------------------------
void TGenotype::Scale_Fitnes(float value){
    fitnes = value;
}
//---------------------------------------------------------------------------
int TGenotype::Get_Lenght(){
    return lenght;
}
//---------------------------------------------------------------------------
