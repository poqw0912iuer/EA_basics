#pragma hdrstop
#include <vcl.h>
#include "TGeneticOperators.h"
#include "TGenotype.h"
#include "EAbasics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void TGeneticOperators::Crossover(TGenotype **object, int probability, int population){
    for(int i = 0; i < population; i += 2){
        if(random(100) < probability){
            int cross_point = random(object[ i] -> Get_Lenght() - 1);
            int temp;
            for(int j = 0; j <= cross_point; j ++){
                temp = object[ i] -> Get_Gen(j);
                object[ i] -> Put_Gen(j, object[ i + 1] -> Get_Gen(j));
                object[ i + 1] -> Put_Gen(j, temp);
            }
        }
        object[ i] -> FitnessEvaluation(Form1->Target);
        object[ i + 1] -> FitnessEvaluation(Form1->Target);
    }
}
//---------------------------------------------------------------------------
void TGeneticOperators::Mutation(TGenotype **object, int probability, int population){
    for(int i = 0; i < population; i ++){
        if(random(100) < probability){
            int mut_point = random(object[ i] -> Get_Lenght());
            switch(object[ i] -> Get_Gen(mut_point)){
                case 0:
                       object[ i] -> Put_Gen(mut_point, 1);
                       break;
                case 1:
                       object[ i] -> Put_Gen(mut_point, 0);
                       break;
            }
        }
        object[i] -> FitnessEvaluation(Form1->Target);
    }
}
//---------------------------------------------------------------------------
