#pragma hdrstop
#include <vcl.h>
#include <math.h>
#include "TSelectionMechanisms.h"
#include "TGenotype.h"
#include "EAbasics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void TSelectionMechanisms::FitnessProportionate(TGenotype **object, int population){
    RuletteWheel(object, population);
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::SigmaScaling(TGenotype **object, int population){
    float sum = 0;
    for(int i = 0; i < population; i ++)
        sum += object[ i] -> Get_Fitnes();
    float average = (float)sum / (float)population;
    float st_dew = 0;
    for(int i = 0; i < population; i ++)
        st_dew += pow((object[ i] -> Get_Fitnes() - (float)average), 2);
    st_dew = pow(st_dew / (population - 1), 0.5);
   
    float ExpVal;
    if(st_dew)
        for(int i = 0; i < population; i ++){
            ExpVal = 1. + (object[i] -> Get_Fitnes() - (float)average) / ( 2 * st_dew);
            if(ExpVal <= 0) object[ i] -> Scale_Fitnes(0);
            else object[ i] -> Scale_Fitnes(ExpVal);
        }
    RuletteWheel(object, population);
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::BoltzmannScaling(TGenotype **object, int population, double T){
    float sum = 0;
    for(int i = 0; i < population; i++)
        sum += exp(object[ i] -> Get_Fitnes() / T);
    float average = sum / population;
    float ExpVal;
    for(int i = 0; i < population; i ++){
        ExpVal = exp(object[ i] -> Get_Fitnes() / T) / average;
        object[ i] -> Scale_Fitnes(ExpVal);
    }
    RuletteWheel(object, population);
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::RankSelection(TGenotype **object, int population, float Min){
    float Max = 2 - Min;
    Sort(object, population);
    float ExpVal;
    for(int i = 0; i < population; i ++){
        ExpVal = Min + (Max - Min) * ((i + 1) - 1) / (population - 1);
        object[ i] -> Scale_Fitnes(ExpVal);
    }
    RuletteWheel(object, population);
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::TournamentSelection(TGenotype **object, int population, int K, float probability){ 
    TGenotype **subset = new TGenotype*[ K];
    TGenotype **next_mating_pool = new TGenotype*[ population / K];
    for(int i = 0; i < population / K; i ++)
        next_mating_pool[ i] = new TGenotype(object[ 0]->Get_Lenght());
    TGenotype **temp = new TGenotype*[population];
    for(int i = 0; i < population; i ++)
        temp[ i] = new TGenotype(object[ 0]->Get_Lenght());
    for(int l = 0; l < population; l ++){
        for(int i = 0; i < population / K; i ++){
            for(int j = 0; j < K; j ++){
                subset[ j] = new TGenotype(object[ 0]->Get_Lenght());
                for(int n = 0; n < object[ 0]-> Get_Lenght(); n ++)
                    subset[ j]->Put_Gen(n, object[ i * K + j]->Get_Gen(n));
                subset[ j]->FitnessEvaluation(Form1->Target);
            }
            Sort(subset, K);
            for(int j = K - 1; j >= 0; j --){
                if(random(101) <= probability){
                    for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                        next_mating_pool[ i]->Put_Gen(n, subset[ j]->Get_Gen(n));
                    next_mating_pool[ i]->FitnessEvaluation(Form1->Target);
                    goto end;
                }
                else if(j == 0)
                    for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                        next_mating_pool[ i]->Put_Gen(n, subset[ 0]->Get_Gen(n));
                next_mating_pool[ i]->FitnessEvaluation(Form1->Target);
            }   end:
        }
        Sort(next_mating_pool, population / K);
        for(int j = population / K - 1; j >= 0; j --){
            if(random(100) < probability){
                for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                    temp[ l]->Put_Gen(n, next_mating_pool[ j]->Get_Gen(n));
                temp[ l]->FitnessEvaluation(Form1->Target);
                goto end2;
            }
            else if(j == 0)
                for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
                    temp[ l]->Put_Gen(n, next_mating_pool[ 0]->Get_Gen(n));
            temp[ l]->FitnessEvaluation(Form1->Target);
        } end2:
    }
    for(int i = 0; i < population; i ++){
        for(int n = 0; n < object[ 0]->Get_Lenght(); n ++)
            object[ i]->Put_Gen(n, temp[ i]->Get_Gen(n));
        object[ i]->FitnessEvaluation(Form1->Target);
    }
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::Sort( TGenotype **object, int population){
    for(int i = 1; i < population; i ++){
        int j = i;
        TGenotype *temp = object[j];
        int temp_fitnes_value = object[j]->Get_Fitnes();
        while(( j > 0) && ( object[ j - 1]-> Get_Fitnes() > temp_fitnes_value)){
            object[ j] = object[ j - 1];
            j --;
        }
        object[ j] = temp;
    }
}
//---------------------------------------------------------------------------
void TSelectionMechanisms::RuletteWheel(TGenotype **object, int population){
    float sum = 0;
    for(int i = 0; i < population; i++)
        sum += object[ i] -> Get_Fitnes();
    float *treshold = new float[ population];
    treshold[ 0] = object[ 0] -> Get_Fitnes();
    for(int i = 1; i < population; i ++)
        treshold[ i] = treshold[ i - 1] + object[ i] -> Get_Fitnes();
    float rand;
    int *rank = new int[population];
    for(int i = 0; i < population; i ++){
        rand = random(sum * 1000) / 1000.;
        if(rand <= treshold[ 0])
            rank[ i] = 0;
        else for(int j = 1; j < population; j ++)
            if(rand > treshold[ j - 1] && rand <= treshold[ j])
                rank[ i] = j;
    }
    TGenotype **supplementary_pool = new TGenotype*[population];
    for(int i = 0; i < population; i ++){
        supplementary_pool[ i] = new TGenotype(object[ 0] -> Get_Lenght());
        for(int j = 0; j < object[ 0]-> Get_Lenght(); j ++)
            supplementary_pool[ i] -> Put_Gen(j, object[ i] -> Get_Gen(j));
    }
    for(int i = 0; i < population; i ++){
        for(int j = 0; j < object[ 0] -> Get_Lenght(); j ++)
            object[ i]->Put_Gen(j, supplementary_pool[rank[ i]]->Get_Gen(j) );
    }
    for(int i = 0; i < population; i ++)
        object[ i] -> FitnessEvaluation(Form1->Target);
}
//---------------------------------------------------------------------------
