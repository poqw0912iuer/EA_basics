#ifndef TGeneticOperatorsH
#define TGeneticOperatorsH
//---------------------------------------------------------------------------
class TGeneticOperators{
friend class TGenotype;
public:
    void Crossover(TGenotype **object,  int probability, int population);
    void Mutation(TGenotype **object, int probability, int population);
};
#endif
