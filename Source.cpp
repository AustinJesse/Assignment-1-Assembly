#include<iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <math.h>
#include <sstream>
#include <iomanip>

//#include "Header.h"

using namespace std;

void decimalToBinaryConversion(unsigned numberInserted, vector<int>& answerToSelection) {
	int oneOrZero;
	for (int i = 0; numberInserted > 0; i++) {
		oneOrZero = numberInserted % 2;
		answerToSelection.push_back(oneOrZero); //used google to find the formula for how to convert
		numberInserted = numberInserted / 2;
		oneOrZero = 0;
	}
	for (int j = answerToSelection.size() - 1; j >= 0; j--) { // used this site for reverse indexing https://thispointer.com/c-print-a-vector-in-reverse-order-5-ways/
		cout << answerToSelection[j]; //modified their code but its still cool
	}
}



void decimalToHexadecimalConversion(unsigned numberInserted, vector<int>& answerToSelection) {
	int carryThis;
	while (numberInserted > 0) {
		carryThis = numberInserted % 16; //should get the remainder
		numberInserted = numberInserted / 16; //lowers the number down
		answerToSelection.push_back(carryThis);
	}
	for (int j = answerToSelection.size() - 1; j >= 0; j--) {
		int tempVal = answerToSelection[j];
		switch (tempVal) {
		case 10:
			cout << "A";
			break;
		case 11:
			cout << "B";
			break;
		case 12:
			cout << "C";
			break;
		case 13:
			cout << "D";
			break;
		case 14:
			cout << "E";
			break;
		case 15:
			cout << "F";
			break;
		default:
			cout << answerToSelection[j];
			break;
		}
	}
}

void decimalToFloatConversion(double numberInserted, vector<int>& answerToSelection) {
	stringstream ss;
	vector<string> stringedDecimalPointHolder;
	string stringedDecimalPoint;
	int noDecimalPoint;
	string decimalHereString;

	noDecimalPoint = numberInserted;
	numberInserted = numberInserted - noDecimalPoint;
	ss << numberInserted;
	ss >> stringedDecimalPoint;

	for (int i = 2; i < stringedDecimalPoint.length(); i++) {
		decimalHereString = stringedDecimalPoint[i];
		stringedDecimalPointHolder.push_back(decimalHereString);
	}
	for (int j = 0; j < stringedDecimalPointHolder.size(); j++) {
		cout << stringedDecimalPointHolder[j] << endl;
	}


	/*cout << setprecision(2);
	cout << fixed;
	cout << numberInserted;*/

	/*cout << "scientific: " << scientific << numberInserted << endl;*/
}

void binaryToDecimalConversion(unsigned numberInserted, vector<int>& answerToSelection) {
	stringstream ss;
	string stringedNum;
	vector<string> conversionHolder;
	string numToVector;
	int takeMeBack;
	int finalConversion = 0;
	int thePower = 0;
	int singleNumber = 0;
	int powerHolder;

	//make sure to clean this up later, looks bad lmao

	ss << numberInserted;
	ss >> stringedNum;

	for (int i = 0; i < stringedNum.length(); i++) {
		numToVector = stringedNum.at(i);
		conversionHolder.push_back(numToVector);
	}

	for (int j = 0; j < conversionHolder.size(); j++) {
		takeMeBack = std::stoi(conversionHolder[j]);
		answerToSelection.push_back(takeMeBack);
	}

	powerHolder = answerToSelection.size() - 1;
	for (int f = 0; f < answerToSelection.size(); f++) {
		thePower = pow(2, powerHolder);
		singleNumber = answerToSelection[f];
		finalConversion = finalConversion + (singleNumber * thePower);
		powerHolder--;
	}

	cout << finalConversion << endl;

}

void binaryToHexadecimalConversion(unsigned numberInserted, vector<int>& answerToSelection) {
	stringstream ss;
	string stringedNum;
	vector<string> conversionHolder;
	vector<int> theRealAnswer;
	string numToVector;
	int takeMeBack;
	int finalConversion = 0;
	int thePower = 0;
	int singleNumber = 0;
	int powerHolder;

	//make sure to clean this up later, looks bad lmao

	ss << numberInserted;
	ss >> stringedNum;

	for (int i = 0; i < stringedNum.length(); i++) {
		numToVector = stringedNum.at(i);
		conversionHolder.push_back(numToVector);
	}

	for (int j = 0; j < conversionHolder.size(); j++) {
		takeMeBack = std::stoi(conversionHolder[j]);
		answerToSelection.push_back(takeMeBack);
	}

	powerHolder = answerToSelection.size() - 1;
	for (int f = 0; f < answerToSelection.size(); f++) {
		thePower = pow(2, powerHolder);
		singleNumber = answerToSelection[f];
		finalConversion = finalConversion + (singleNumber * thePower);
		powerHolder--;
	}

	cout << finalConversion << endl;
	//
	//
	// If you cant beat em, join em
	//
	//
	int carryThis;
	while (finalConversion > 0) {
		carryThis = finalConversion % 16; //should get the remainder
		finalConversion = finalConversion / 16; //lowers the number down
		theRealAnswer.push_back(carryThis);
	}
	for (int j = theRealAnswer.size() - 1; j >= 0; j--) {
		int tempVal = theRealAnswer[j];
		switch (tempVal) {
		case 10:
			cout << "A";
			break;
		case 11:
			cout << "B";
			break;
		case 12:
			cout << "C";
			break;
		case 13:
			cout << "D";
			break;
		case 14:
			cout << "E";
			break;
		case 15:
			cout << "F";
			break;
		default:
			cout << theRealAnswer[j];
			break;
		}
	}

}

void hexadecimalToDecimalConversion(string numberInserted, vector<int>& answerToSelection) {
	stringstream ss;
	stringstream tempS;
	vector<string> stringSections;
	vector<int> middleVector;
	string numVector;
	int valueAt;
	int powerHolder = 0;
	int convertedAnswer = 0;
	int answerHolder;
	int mathHolder = 0;
	string valueHere;

	for (int i = 0; i < numberInserted.length(); i++) {
		numVector = numberInserted.at(i);
		stringSections.push_back(numVector);
	}

	for (int j = 0; j < numberInserted.length(); j++) { //go back if time allows and find a better pseudoswitch
		valueHere = numberInserted.at(j);
		if (numberInserted[j] == 'A') {
			answerToSelection.push_back(10);
		}
		else if (numberInserted[j] == 'B') {
			answerToSelection.push_back(11);
		}
		else if (numberInserted[j] == 'C') {
			answerToSelection.push_back(12);
		}
		else if (numberInserted[j] == 'D') {
			answerToSelection.push_back(13);
		}
		else if (numberInserted[j] == 'E') {
			answerToSelection.push_back(14);
		}
		else if (numberInserted[j] == 'F') {
			answerToSelection.push_back(15);
		}
		else {
			valueAt = stoi(valueHere);
			ss << valueHere;
			ss >> valueAt;
			answerToSelection.push_back(valueAt);
		}
	}

	powerHolder = answerToSelection.size() - 1;
	for (int a = 0; a < answerToSelection.size(); a++) {
		int thePower = pow(16, powerHolder);
		convertedAnswer = convertedAnswer + (answerToSelection[a] * thePower);
		powerHolder--;
	}

	cout << convertedAnswer << endl;

}

void hexadecimalToBinary(string numberInserted, vector<int>& answerToSelection) {
	stringstream ss;
	vector<string> stringSections;
	int valueAt;
	string valueHere;

	for (int j = 0; j < numberInserted.length(); j++) { //go back if time allows and find a better pseudoswitch
		valueHere = numberInserted.at(j);
		if (numberInserted[j] == 'A') {
			stringSections.push_back("1010");
		}
		else if (numberInserted[j] == 'B') {
			stringSections.push_back("1011");
		}
		else if (numberInserted[j] == 'C') {
			stringSections.push_back("1100");
		}
		else if (numberInserted[j] == 'D') {
			stringSections.push_back("1101");
		}
		else if (numberInserted[j] == 'E') {
			stringSections.push_back("1110");
		}
		else if (numberInserted[j] == 'F') {
			stringSections.push_back("1111");
		}
		else {
			valueAt = stoi(valueHere);
			ss << valueHere;
			ss >> valueAt;
			cout << valueAt << endl;
			switch (valueAt) {
			case 0:
				stringSections.push_back("0000");
				break;
			case 1:
				stringSections.push_back("0001");
				break;
			case 2:
				stringSections.push_back("0010");
				break;
			case 3:
				stringSections.push_back("0011");
				break;
			case 4:
				stringSections.push_back("0100");
				break;
			case 5:
				stringSections.push_back("0101");
				break;
			case 6:
				stringSections.push_back("0110");
				break;
			case 7:
				stringSections.push_back("0111");
				break;
			case 8:
				stringSections.push_back("1000");
				break;
			case 9:
				stringSections.push_back("1001");
				break;
			default:
				cout << "ERR0R" << endl;
				break;
			}
		}
	}
	for (int a = 0; a < stringSections.size(); a++) {
		cout << stringSections[a];
	}
}

int main() {
	int typeNumber;
	int conversionType;
	unsigned userNum;
	double floatUserNum;
	vector<int> answerToSelection;
	string backupUserNum; //change this later
	stringstream ss;

	cout << "Hi! Please select, using the numbers, format of your number:" << endl;
	cout << "1. DECIMAL" << endl << "2. BINARY" <<
		endl << "3. HEX" << endl << "4. FLOAT" << endl;
	cin >> typeNumber;
	cout << "Hi! Please select, using the numbers, which conversion you wish to perform:" << endl;
	cout << "1. DECIMAL" << endl << "2. BINARY" <<
		endl << "3. HEX" << endl << "4. FLOAT" << endl;
	cin >> conversionType;

	switch (typeNumber) {
	case 1:
		if (conversionType == 4) {
			cout << "Please type your number: " << endl;
			cin >> floatUserNum;
		}
		else {
			cout << "Please type your number: " << endl;
			cin >> userNum;
		}
		break;
	case 2:
		if (conversionType == 4) {
			cout << "Please type your number: " << endl;
			cin >> floatUserNum;
		}
		else {
			cout << "Please type your number: " << endl;
			cin >> userNum;
		}
		break;
	case 3:
		if (conversionType == 4) {
			cout << "Please type your number: " << endl;
			cin >> floatUserNum;
		}
		else {
			cout << "Please type your number: " << endl;
			cin >> backupUserNum;
		}
		break;
	}

	switch (typeNumber) {
	case 1:
		switch (conversionType) {
		case 1:
			cout << "Decimal to decimal? Really?" << endl;
			break;
		case 2:
			cout << "Heres your decimal in binary: " << endl;
			decimalToBinaryConversion(userNum, answerToSelection);
			break;
		case 3:
			cout << "Heres your decimal to hex: " << endl;
			decimalToHexadecimalConversion(userNum, answerToSelection);
			break;
		case 4:
			cout << "Heres your decimal to float: " << endl;
			decimalToFloatConversion(floatUserNum, answerToSelection);
			break;
		}
		break;
	case 2:
		switch (conversionType) {
		case 1:
			cout << "Heres your binary to decimal: " << endl;
			binaryToDecimalConversion(userNum, answerToSelection);
			break;
		case 2:
			cout << "Why are you doing binary to binary??" << endl;
			break;
		case 3:
			cout << "Heres your binary to hex: " << endl;
			//were going to do a big brain move by combining two functions (think mark think)
			binaryToHexadecimalConversion(userNum, answerToSelection);
			break;
		case 4:
			cout << "Heres your binary to float: " << endl;
		}
		break;
	case 3:
		switch (conversionType) {
		case 1:
			cout << "Heres your hex to decimal: " << endl;
			hexadecimalToDecimalConversion(backupUserNum, answerToSelection);
			break;
		case 2:
			cout << "Heres your hex to binary: " << endl;
			hexadecimalToBinary(backupUserNum, answerToSelection);
			break;
		case 3:
			cout << "Already in hex form!" << endl;
			break;
		case 4:
			cout << "Heres your hex to float: " << endl;
			break;
		}
		break;
	case 4:
		break;
	}

	return 0;
}