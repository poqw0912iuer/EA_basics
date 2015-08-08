#ifndef TGenotypeH
#define TGenotypeH
//---------------------------------------------------------------------------
class TGenotype{
friend class TForm1;
private:
    int *gens, *phenotypes;
    int lenght;
    float fitnes;
public:
    TGenotype(int lenght);
    void PhenotypeConvertion();
    int Get_Phenotype(int index);
    int Get_Gen(int index);
    void Put_Gen(int index, int value);
    void FitnessEvaluation(int *tab);
    float Get_Fitnes();
    void Scale_Fitnes(float value);
    int Get_Lenght();
};
#endif
