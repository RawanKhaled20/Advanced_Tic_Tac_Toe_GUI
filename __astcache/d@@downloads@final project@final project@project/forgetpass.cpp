#include <vcl.h>
#pragma hdrstop

#include "ForgetPass.h"
#include "Login.h"
#include <iostream>
#include <iomanip> // for setw, setfill
#include <sstream> // for stringstream
#include <functional> // for hash
#include <cstdlib>
#include <ctime>
#include <random> // for random number generation
#include <string> // for std::string
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

AnsiString identifier;
AnsiString otp;

// Function to generate a 6-digit OTP
AnsiString generate_otp() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(10000000, 9999999999);
	return IntToStr(dis(gen));
}

TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	Edit2->PasswordChar = '*'; // Set the password character to an asterisk by default
	SpeedButton2->Glyph->LoadFromFile("hidepassword.bmp");
	Edit3->PasswordChar = '*'; // Set the password character to an asterisk by default
	SpeedButton1->Glyph->LoadFromFile("hidepassword.bmp");

}
//---------------------------------------------------------------------------

// Function to hash the password
AnsiString hashPassword(const AnsiString& password) {
	std::hash<std::string> hasher;
	size_t hashed = hasher(password.c_str());
	std::stringstream ss;
	ss << std::setw(16) << std::setfill('0') << std::hex << hashed; // Convert hash to hexadecimal string
	return ss.str().c_str();
}

//---------------------------------------------------------------------------

void __fastcall TForm7::Button1Click(TObject *Sender)
{
	identifier = Edit1->Text.Trim();
	AnsiString newPassword = Edit2->Text.Trim();
	AnsiString pin = Edit4->Text.Trim();

	if (pin != otp) {
		ShowMessage("Invalid PIN. Password Reset failed.");
		return;
	}

	// Check if the password length is less than 5 characters
	if (newPassword.Length() < 5) {
		ShowMessage("Choose a longer password.");
		return;
	}

	AnsiString confnewPass = Edit3->Text.Trim();
	if (newPassword != confnewPass) {
		ShowMessage("Enter similar passwords.");
		return;
	}

	AnsiString hashedPassword = hashPassword(newPassword);

	AnsiString sql = "SELECT * FROM USERS WHERE EMAIL = '" + identifier + "' OR USERNAME = '" + identifier + "'";
	Form7->UsersTable->SQL->Text = sql;

	try {
		Form7->UsersTable->Open();
		if (!Form7->UsersTable->IsEmpty()) {
			AnsiString currentPasswordHash = Form7->UsersTable->FieldByName("USERPASSWORD")->AsString;
			if (currentPasswordHash == hashedPassword) {
				ShowMessage("The new password cannot be the same as the old password.");
				return;
			}

			Form7->UsersTable->Edit();
			Form7->UsersTable->FieldByName("USERPASSWORD")->AsString = hashedPassword;
			Form7->UsersTable->Post();
			ShowMessage("Password has been reset successfully.");
		} else {
			ShowMessage("User not found.");
		}
	} catch (Exception& ex) {
		ShowMessage("Error: " + ex.Message);
	}

	// Clear the edit cells after success or failure
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";

	Form7->UsersTable->Close();
	Form7->Hide();
	Form1->Show();
}

//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton1Click(TObject *Sender)
{
	if (Edit3->PasswordChar == '*')
	{
		Edit3->PasswordChar = 0; // Show password
		SpeedButton1->Glyph->LoadFromFile("showpassword.bmp"); // Change button icon to 'show'
	}
	else
	{
		Edit3->PasswordChar = '*'; // Hide password
		SpeedButton1->Glyph->LoadFromFile("hidepassword.bmp"); // Change button icon to 'hide'
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton2Click(TObject *Sender)
{
	if (Edit2->PasswordChar == '*')
	{
		Edit2->PasswordChar = 0; // Show password
		SpeedButton2->Glyph->LoadFromFile("showpassword.bmp"); // Change button icon to 'show'
	}
	else
	{
		Edit2->PasswordChar = '*'; // Hide password
		SpeedButton2->Glyph->LoadFromFile("hidepassword.bmp"); // Change button icon to 'hide'
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm7::Button2Click(TObject *Sender)
{
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
	this->Close();
	Form1->Show();
}

//---------------------------------------------------------------------------

void __fastcall TForm7::Button3Click(TObject *Sender)
{
    Button3->Caption = "Send PIN"; // Update button caption to indicate sending

    // Get identifier from the form field
    AnsiString identifier = Edit1->Text.Trim();

    AnsiString email;
    bool isEmail = identifier.Pos("@") > 0; // Check if the identifier contains an '@' symbol

    // Query the database to get the email associated with the identifier (either email or username)
    if (isEmail) {
        email = identifier;
    } else {
        AnsiString sql = "SELECT EMAIL FROM USERS WHERE USERNAME = '" + identifier + "'";
        Form7->UsersTable->SQL->Text = sql;

        try {
            Form7->UsersTable->Open();
            if (!Form7->UsersTable->IsEmpty()) {
                email = Form7->UsersTable->FieldByName("EMAIL")->AsString;
            } else {
                ShowMessage("Username not found.");
                Form7->UsersTable->Close();
                return;
            }
            Form7->UsersTable->Close();
        } catch (Exception& ex) {
            ShowMessage("Error retrieving email: " + ex.Message);
            Form7->UsersTable->Close();
            return;
        }
    }

    // Generate OTP
    otp = generate_otp();

    // Path to your Python script
    AnsiString scriptPath = "\"C:\\Users\\p.c\\OneDrive\\Documents\\Emailconnect\\main.py\"";

    // Create the command to call the Python script with email and OTP as arguments
    AnsiString command = "python " + scriptPath + " " + email + " " + otp;

    // Execute the Python script
    int result = system(command.c_str());

    // Check if the command executed successfully
	/*if (result == 0) {
        ShowMessage("PIN sent successfully to " + identifier);
    } else {
        // Capture error message from stderr
        AnsiString errorMessage = "Failed to send email. Error code: " + IntToStr(result);
        ShowMessage(errorMessage);
	} */

	Button3->Caption = "Send PIN again"; // Update button caption after sending
}


