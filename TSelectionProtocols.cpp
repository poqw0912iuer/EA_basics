#pragma hdrstop
#include <vcl.h>
#include "TSelectionProtocols.h"
#include "EAbasics.h"
#include "TGenotype.h"
#include "TGeneticOperators.h"
#include "TSelectionMechanisms.h"
#include "TPlottingRoutine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TGeneticOperators GA_Operator;
TSelectionMechanisms SelectionMechanism;
TPlottingRoutine GrphTool;
//---------------------------------------------------------------------------
void TSelectionProtocols::FullGenerationalReplacement(TGenotype **object,int population,int generations,
                                    int cross_probability, int mut_probability, int SelectionMechanismNr){
    for(int l = 1; l < generations; l ++){
        ChooseSelectionMechanism(SelectionMechanismNr, object, population);
        GA_Operator.Crossover(object, cross_probability, population);
        GA_Operator.Mutation(object, mut_probability, population);
        GrphTool.Record_Data(object, population, l);
    }         
}
//---------------------------------------------------------------------------
void TSelectionProtocols::OverProduction(TGenotype **object, int population, int generations,
                         int cross_probability, int mut_probability, int SelectionMechanismNr){
    TGenotype **Child = new TGenotype*[ 2 * population];
    for(int i = 0; i < 2 * population; i ++)
        Child[ i] = new TGenotype(object[ 0] -> Get_Lenght());
    TGenotype **Adult2 = new TGenotype*[ population];
    for(int i = 0; i < population; i ++){
        Adult2[ i] = new TGenotype(object[ 0] -> Get_Lenght());
        for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
            Adult2[ i]->Put_Gen(n, object[ i]->Get_Gen(n));
    }
    for(int l = 1; l < generations; l ++){
        ChooseSelectionMechanism(SelectionMechanismNr, object, population);
        GA_Operator.Crossover(object, cross_probability, population);
        GA_Operator.Mutation(object, mut_probability, population);
        GA_Operator.Crossover(Adult2, cross_probability, population);
        GA_Operator.Mutation(Adult2, mut_probability, population);
        for(int j = 0; j < population; j ++){
            for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                Child[ j]->Put_Gen(n, object[ j]->Get_Gen(n));
            Child[ j]->FitnessEvaluation(Form1->Target);
        }
        for(int j = 0; j < population; j ++){
            for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                Child[ population + j]->Put_Gen(n, Adult2[ j]->Get_Gen(n));
            Child[ population + j]->FitnessEvaluation(Form1->Target);
        }
        SelectionMechanism.Sort(Child, 2 * population);
        for(int i = 2 * population - 1; i >= population; i --){
            for(int n = 0; n  < object[ 0]->Get_Lenght(); n ++)
                object[ 2*population-1 - i]->Put_Gen(n, Child[ i]->Get_Gen(n));
            object[ 2*population-1 - i]->FitnessEvaluation(Form1->Target);
        }
        GrphTool.Record_Data(object, population, l);
    }
}
//---------------------------------------------------------------------------
void TSelectionProtocols::GenerationalMixing(TGenotype **object, int population, int generations,
                             int cross_probability, int mut_probability, int SelectionMechanismNr){
    TGenotype **Child = new TGenotype*[ 3 * population];
    for(int i = 0; i < 3 * population; i ++)
        Child[ i] = new TGenotype(object[ 0] -> Get_Lenght());
    TGenotype **Adult2 = new TGenotype*[ population];
    for(int i = 0; i < population; i ++){
        Adult2[ i] = new TGenotype(object[ 0] -> Get_Lenght());
        for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
            Adult2[ i]->Put_Gen(n, object[ i]->Get_Gen(n));
    }
    for(int l = 1; l < generations; l ++){
        ChooseSelectionMechanism(SelectionMechanismNr, object, population);
        for(int j = 0; j < population; j ++){
            for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                Child[ j]->Put_Gen(n, object[ j]->Get_Gen(n));
            Child[ j]->FitnessEvaluation(Form1->Target);
        }
        GA_Operator.Crossover(object, cross_probability, population);
        GA_Operator.Mutation(object, mut_probability, population);
        GA_Operator.Crossover(Adult2, cross_probability, population);
        GA_Operator.Mutation(Adult2, mut_probability, population);
        for(int j = 0; j < population; j ++){
            for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                Child[ population + j]->Put_Gen(n, object[ j]->Get_Gen(n));
            Child[ population + j]->FitnessEvaluation(Form1->Target);
        }
        for(int j = 0; j < population; j ++){
            for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                Child[ 2 * population + j]->Put_Gen(n, Adult2[ j]->Get_Gen(n));
            Child[ 2 * population + j]->FitnessEvaluation(Form1->Target);
        }
        SelectionMechanism.Sort(Child, 3 * population);
        for(int i = 3 * population - 1; i >= 2 * population; i --){
            for(int n = 0; n  < object[ 0]->Get_Lenght(); n ++)
                object[ 3*population-1 - i]->Put_Gen(n, Child[ i]->Get_Gen(n));
            object[ 3*population-1 - i]->FitnessEvaluation(Form1->Target);
        }
        GrphTool.Record_Data(object, population, l);
    }
}
//---------------------------------------------------------------------------
void TSelectionProtocols::ChooseSelectionMechanism(int number, TGenotype **object, int population){
    if(number == 1)
        SelectionMechanism.SigmaScaling(object, population);
    else if(number == 2)
        SelectionMechanism.BoltzmannScaling(object, population, Form1 -> Edit5->Text.ToDouble());
    else if(number == 3)
        SelectionMechanism.RankSelection(object, population, 0.5);
    else if(number == 4)
        SelectionMechanism.TournamentSelection(object, population, Form1 -> Edit6->Text.ToInt(),
                                               100 * Form1 -> Edit7->Text.ToDouble());
    else if(number == 10)
        SelectionMechanism.FitnessProportionate(object, population);
}
//---------------------------------------------------------------------------
