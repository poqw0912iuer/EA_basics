//---------------------------------------------------------------------------
#ifndef EAbasicsH
#define EAbasicsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
friend class TGenotype;
__published:	// IDE-managed Components
        TButton *Button1;
        TStringGrid *StringGrid1;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit3;
        TEdit *Edit4;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TEdit *Edit5;
        TRadioButton *RadioButton4;
        TEdit *Edit6;
        TEdit *Edit7;
        TGroupBox *GroupBox2;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TLabel *Label5;
        TEdit *Edit8;
        TButton *Button2;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton10;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RadioButton10Click(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        int lenght, population, generations, generation;
        int cross_probability, mut_probability;
        int K, E;
        int SelectionMechanismNr;
        float *max, *average, *st_dew;
        TGenotype *best_genotype;
        int Target[99999];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
