#include <vcl.h>
#pragma hdrstop

#include "HomePage.h"
#include "Register.h"
#include "Login.h"
#include "playervsplayer.h"
#include "aivsplayer.h"
#include "gamehistory.h"
#include <iostream>
#include <vector>
#include <string>

#include <string> // For std::string
#include <cstdlib> // For std::atoi
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

int currentRecordIndex = 0;
int currentRecordIndexloc = 0;
std::vector<int> recordPositions;
AnsiString history;
AnsiString positions;
static int target;
int maxGameNumber;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	 int idFromForm1 = ((TForm1*)Owner)->ID; // Access integer ID property from Form1
	 Form6->ButtonNext->Caption = "Replay";
	 Form6->ButtonPrevious->Visible = false;

}

//---------------------------------------------------------------------------
void clearBoard() {
	Form6->Button1->Caption = "";
	Form6->Button2->Caption = "";
	Form6->Button3->Caption = "";
	Form6->Button4->Caption = "";
	Form6->Button5->Caption = "";
	Form6->Button6->Caption = "";
	Form6->Button7->Caption = "";
	Form6->Button8->Caption = "";
	Form6->Button9->Caption = "";
}

AnsiString getCharAtIndex(const AnsiString& inputString, int index) {
	int count = 0;
	for (int i = 1; i <= inputString.Length(); ++i) {
		char c = inputString[i];
		if (c == ',') {
			if (count == index) {
				return "";  // Return an empty string for empty positions
			}
			count++;
		} else {
			if (count == index) {
				return AnsiString(c);
			}
		}
	}
	return "";  // Return an empty string if index is out of bounds
}

int getintAtIndex(const AnsiString& inputString, int index) {
	int count = 0;
	std::string number;
	for (int i = 1; i <= inputString.Length(); ++i) {
		char c = inputString[i];
		if (c == ',') {
			if (count == index) {
                // Convert the collected number to an integer and return it
                return number.empty() ? -1 : std::atoi(number.c_str());
			}
            count++;
            number.clear(); // Reset the number string for the next number
		} else {
			if (count == index) {
				number += c; // Collect the digit for the current number
			}
		}
	}

	// Check the last number in the string
	if (count == index) {
		return number.empty() ? -1 : std::atoi(number.c_str());
	}

	return -1;  // Return -1 if index is out of bounds
}

void displayGameResult() {
	// Display the data in the form controls
	int gameID = Form6->GameresultsTable->FieldByName("GameID")->AsInteger;
	int gamenumber = Form6->GameresultsTable->FieldByName("gamenumber")->AsInteger;

	AnsiString winOrLose = Form6->GameresultsTable->FieldByName("WinOrLose")->AsString;
	history = Form6->GameresultsTable->FieldByName("history")->AsString;
	positions = Form6->GameresultsTable->FieldByName("positions")->AsString;
	AnsiString playertype = Form6->GameresultsTable->FieldByName("playertype")->AsString;
	AnsiString opponent = Form6->GameresultsTable->FieldByName("opponent")->AsString;

	// Display the data in the form controls
	Form6->Label10->Caption = gamenumber;
	Form6->Label11->Caption = winOrLose;
	Form6->Label12->Caption = opponent;
	Form6->Label13->Caption = playertype;
	Form6->Button1->Caption = getCharAtIndex(history, 0);
	Form6->Button2->Caption = getCharAtIndex(history, 1);
	Form6->Button3->Caption = getCharAtIndex(history, 2);
	Form6->Button4->Caption = getCharAtIndex(history, 3);
	Form6->Button5->Caption = getCharAtIndex(history, 4);
	Form6->Button6->Caption = getCharAtIndex(history, 5);
	Form6->Button7->Caption = getCharAtIndex(history, 6);
	Form6->Button8->Caption = getCharAtIndex(history, 7);
	Form6->Button9->Caption = getCharAtIndex(history, 8);

	// Parse positions
	recordPositions.clear();
	for (int i = 0; i < 9; ++i) {
		int pos = getintAtIndex(positions, i);
		if (pos != -1) {
			recordPositions.push_back(pos);
		}
	}

	Form6->GameresultsTable->Next();
	currentRecordIndex++;
	currentRecordIndexloc = 0;
}

void readGameResults(int userID, int targetGameNumber) {
	try {
		// Initialize the query to start from the target game number
		Form6->GameresultsTable->SQL->Text = "SELECT history, GameID, WinOrLose, gamenumber, positions, playertype, opponent FROM GameResults WHERE ID = :userID AND gamenumber >= :targetGameNumber ORDER BY gamenumber";
		Form6->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form6->GameresultsTable->Params->ParamByName("targetGameNumber")->AsInteger = targetGameNumber;

		Form6->GameresultsTable->Open();

		// Reset display elements and variables
		currentRecordIndex = 0;
		recordPositions.clear();
		Form6->ButtonNext->Caption = "Replay";  // Adjust button caption if needed
		Form6->ButtonPrevious->Visible = false;  // Hide previous button if needed

		if (!Form6->GameresultsTable->Eof) {
			displayGameResult();  // Call a function to display the first record
			Form6->ButtonNext->Visible = true;
			Form6->ButtonNext->Caption = "Replay";  // Adjust button caption if needed

		} else {
			ShowMessage("No records found starting from game number " + IntToStr(targetGameNumber));
			Form6->ButtonNext->Visible = false;
			Form6->ButtonPrevious->Visible = false;
		}
	} catch (const Exception& e) {
		ShowMessage("Error reading game results: " + e.Message);
	}
}

//-------------------------------------------------------------------------------
AnsiString serializeChars(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
	AnsiString result;
	result = c1; result += ','; result += c2;result += ','; result += c3;
	result += ',';result += c4; result += ',';result += c5; result += ',';
	result += c6;result += ','; result += c7;result += ','; result += c8;
	result += ',';result += c9;
	return result;
}

void displayCurrentMove(int moveIndex) {
	clearBoard();
	// Iterate through all moves up to the current move index
    for (int i = 0; i <= moveIndex; ++i) {
		int posIndex = recordPositions[i] - 1;
		AnsiString charAtPos = getCharAtIndex(history, posIndex);
        switch (posIndex) {
            case 0: Form6->Button1->Caption = charAtPos; break;
            case 1: Form6->Button2->Caption = charAtPos; break;
            case 2: Form6->Button3->Caption = charAtPos; break;
			case 3: Form6->Button4->Caption = charAtPos; break;
            case 4: Form6->Button5->Caption = charAtPos; break;
            case 5: Form6->Button6->Caption = charAtPos; break;
            case 6: Form6->Button7->Caption = charAtPos; break;
            case 7: Form6->Button8->Caption = charAtPos; break;
            case 8: Form6->Button9->Caption = charAtPos; break;
        }
	}
}

void __fastcall TForm6::Button10Click(TObject *Sender)
{
	//AnsiString targetGameNumberStr = Edit1->Text.Trim();
	//target= StrToInt(targetGameNumberStr);  // Convert AnsiString to int
	if (target > 0) {
		readGameResults(Form1->ID, target);
	} else {
		ShowMessage("Please enter a valid game number.");
		Form6->ButtonNext->Visible = false;
		Form6->ButtonPrevious->Visible = false;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button12Click(TObject *Sender)
{
	target++;
	ComboBox1->ItemIndex = target-1 ; // Update ComboBox selection
	//Edit1->Text = IntToStr(target);
	if (target > 0) {
		readGameResults(Form1->ID, target);
	} else {
		ShowMessage("Not a valid game number.");
		Form6->ButtonNext->Visible = false;
		Form6->ButtonPrevious->Visible = false;
	}
}

void __fastcall TForm6::Button11Click(TObject *Sender)
{    Form6->Button13->Caption = 'N';
	 Form6->ButtonNext->Caption = "Replay";
	 Form6->ButtonPrevious->Visible = false;
	 clearBoard();
	 Form6->ComboBox1->Clear();
	Form6->Label10->Caption = "";
	Form6->Label11->Caption = "";
	Form6->Label12->Caption = "";
	Form6->Label13->Caption = "";
	 this->Close();
	 Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ButtonPreviousClick(TObject *Sender)
{
	if (currentRecordIndexloc > 0) {
			currentRecordIndexloc--;
	displayCurrentMove(currentRecordIndexloc);
	} else {
		ShowMessage("No previous moves.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ButtonNextClick(TObject *Sender)
{       if (ButtonNext->Caption == "Replay") {
		ButtonNext->Caption = "Next Move";
		ButtonPrevious->Visible = true;
	}
	if (currentRecordIndexloc < recordPositions.size()) {
	displayCurrentMove(currentRecordIndexloc);
	currentRecordIndexloc++;

	} else {
		ShowMessage("No next moves.");
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm6::Button13Click(TObject *Sender)
{
	int maxGameNumber;
		 Form6->GameresultsTable->SQL->Text = "SELECT MAX(gamenumber) AS MaxGameNumber FROM GameResults WHERE ID = :userID";
		 Form6->GameresultsTable->Params->ParamByName("userID")->AsInteger = Form1->ID;
		 Form6->GameresultsTable->Open();
		if (!Form6->GameresultsTable->Eof) {
			maxGameNumber = Form6->GameresultsTable->FieldByName("MaxGameNumber")->AsInteger ;
		 }
		Form6->GameresultsTable->Close();
		Form6->Button13->Caption = maxGameNumber;
	// Populate the ComboBox
	Form6->ComboBox1->Clear();
	for (int i = 1; i <= maxGameNumber; ++i) {
        Form6->ComboBox1->Items->Add(IntToStr(i));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button14Click(TObject *Sender)
{
	target--;
	ComboBox1->ItemIndex = target-1; // Update ComboBox selection
	//Edit1->Text = IntToStr(target);
	if (target > 0) {
		readGameResults(Form1->ID, target);
	} else {
		ShowMessage("Not a valid game number.");
		Form6->ButtonNext->Visible = false;
		Form6->ButtonPrevious->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox1Change(TObject *Sender)
{

	if (ComboBox1->ItemIndex >= 0) {
		target = StrToInt(ComboBox1->Items->Strings[ComboBox1->ItemIndex]);
	}

}
//---------------------------------------------------------------------------

