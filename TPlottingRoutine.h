#ifndef TPlottingRoutineH
#define TPlottingRoutineH
class TPlottingRoutine{
friend class TGenotype;
friend class TForm1;
public:
    void Record_Data(TGenotype **object, int population, int generation);
    void Plot(int generations);
};
#endif

