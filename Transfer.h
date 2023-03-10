//---------------------------------------------------------------------------

#ifndef TransferH
#define TransferH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *radioGroupMethods;
	TGroupBox *groupValues;
	TGroupBox *groupEvents;
	TButton *buttonReset;
	TButton *buttonStart;
	TButton *buttonStop;
	TChart *Chart1;
	TLineSeries *Series1;
	TLabeledEdit *lEditU1;
	TLabeledEdit *lEditU2;
	TLabeledEdit *lEditDx;
	TLabeledEdit *lEditDt;
	TLabeledEdit *lEditA;
	TLabel *labelIterationClock;
	void __fastcall radioGroupMethodsClick(TObject *Sender);
	void __fastcall buttonResetClick(TObject *Sender);
	void __fastcall buttonStartClick(TObject *Sender);
	void __fastcall buttonStopClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
