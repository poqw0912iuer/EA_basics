#ifndef TSelectionProtocolsH
#define TSelectionProtocolsH
//---------------------------------------------------------------------------
class TSelectionProtocols{
friend class TGenotype;
public:
    void FullGenerationalReplacement(TGenotype **object, int populationint, int generations,
                                     int cross_probability, int mut_probability, int SelectionMechanismNr);
    void OverProduction(TGenotype **object, int population, int generations, int cross_probability,
                                     int mut_probability, int SelectionMechanismNr);
    void GenerationalMixing(TGenotype **object, int population, int generations, int cross_probability,
                                     int mut_probability, int SelectionMechanismNr);
    void ChooseSelectionMechanism(int number, TGenotype **object, int population);
};
#endif
