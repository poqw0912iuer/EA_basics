#ifndef TSelectionMechanismsH
#define TSelectionMechanismsH
//---------------------------------------------------------------------------
class TSelectionMechanisms{
friend class TGenotype;
private:
public:
    void FitnessProportionate(TGenotype **object, int population);
    void SigmaScaling(TGenotype **object, int population);
    void BoltzmannScaling(TGenotype **object, int population, double T);
    void RankSelection(TGenotype **object, int population, float Min);
    void TournamentSelection(TGenotype **object, int population, int K, float probability);
    void Sort( TGenotype **object, int population);
    void RuletteWheel(TGenotype **object, int population);
};
#endif
