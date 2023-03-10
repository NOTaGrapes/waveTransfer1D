// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Transfer.h"
#include "core.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

char* methodName;
bool CycleBreak = false;
core Core;
double buffer;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	buttonReset->Enabled = false;
	buttonStart->Enabled = false;
	buttonStop->Enabled = false;
	lEditU1->Enabled = false;
	lEditU2->Enabled = false;
	lEditDx->Enabled = false;
	lEditDt->Enabled = false;
	lEditA->Enabled = false;
	radioGroupMethods->Enabled = true;
	labelIterationClock->Enabled = false;
	labelIterationClock->Caption = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::radioGroupMethodsClick(TObject *Sender) {
	buttonReset->Enabled = true;
	buttonStart->Enabled = false;
	buttonStop->Enabled = false;
	lEditU1->Enabled = true;
	lEditU2->Enabled = true;
	lEditDx->Enabled = true;
	lEditDt->Enabled = true;
	lEditA->Enabled = true;
	radioGroupMethods->Enabled = true;
	labelIterationClock->Enabled = false;
	if (radioGroupMethods->ItemIndex == 0) {
		methodName = "ee";
	}
	if (radioGroupMethods->ItemIndex == 1) {
		methodName = "ie";
	}
	if (radioGroupMethods->ItemIndex == 2) {
		methodName = "lv";
	}
	if (radioGroupMethods->ItemIndex == 3) {
		methodName = "mk";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::buttonResetClick(TObject *Sender) {
	if (lEditA->Text == "" || lEditDt->Text == "" || lEditDx->Text == "" ||
		lEditU2->Text == "" || lEditU1->Text == "") {
		ShowMessage("Some value was not set-up!");
		return;
	}
	buttonReset->Enabled = true;
	buttonStart->Enabled = true;
	buttonStop->Enabled = false;
	lEditU1->Enabled = true;
	lEditU2->Enabled = true;
	lEditDx->Enabled = true;
	lEditDt->Enabled = true;
	lEditA->Enabled = true;
	radioGroupMethods->Enabled = true;
	labelIterationClock->Enabled = false;
	labelIterationClock->Caption = 0;
	Series1->Clear();
	Core.makeReset();
	Core.setValue(lEditU1->Text.ToDouble(), "u1");
	Core.setValue(lEditU2->Text.ToDouble(), "u2");
	Core.setValue(lEditDx->Text.ToDouble(), "dx");
	Core.setValue(lEditDt->Text.ToDouble(), "dt");
	Core.setValue(lEditA->Text.ToDouble(), "a");
	Core.computeLambda(methodName);
	buffer = lEditU1->Text.ToDouble();
	if (lEditU1->Text.ToDouble() >= lEditU2->Text.ToDouble()) {
		buffer = lEditU1->Text.ToDouble();
	}
	else {
		buffer = lEditU2->Text.ToDouble();
	}
	if (lEditU1->Text.ToDouble() == 0 && lEditU2->Text.ToDouble() == 0) {
		buffer = 1;
	}
	Chart1->LeftAxis->Maximum = buffer*2;
	Chart1->LeftAxis->Minimum = -buffer*2;
	Series1->Clear();
	Series1->AddArray(Core.layerLower_, 200);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::buttonStartClick(TObject *Sender) {
	buttonReset->Enabled = false;
	buttonStart->Enabled = false;
	buttonStop->Enabled = true;
	lEditU1->Enabled = false;
	lEditU2->Enabled = false;
	lEditDx->Enabled = false;
	lEditDt->Enabled = false;
	lEditA->Enabled = false;
	radioGroupMethods->Enabled = false;
	labelIterationClock->Enabled = true;
	if (CycleBreak == true) {
		CycleBreak = false;
	}
	while (CycleBreak == false) {

		Core.computeAndMoveLayer(methodName);
		labelIterationClock->Caption = Core.showValue("clock");
		Series1->Clear();
		Series1->AddArray(Core.layerLower_, 200);
		Application->ProcessMessages();
		if (CycleBreak == true) {
			break;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::buttonStopClick(TObject *Sender) {
	buttonReset->Enabled = true;
	buttonStart->Enabled = true;
	buttonStop->Enabled = false;
	lEditU1->Enabled = true;
	lEditU2->Enabled = true;
	lEditDx->Enabled = true;
	lEditDt->Enabled = true;
	lEditA->Enabled = true;
	radioGroupMethods->Enabled = true;
	labelIterationClock->Enabled = false;
	if (CycleBreak == false) {
		CycleBreak = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
	if (CycleBreak == false) {
		CycleBreak = true;
	}
}
// ---------------------------------------------------------------------------
