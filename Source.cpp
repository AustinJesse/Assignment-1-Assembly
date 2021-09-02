#include<iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

//#include "Header.h"

using namespace std;

void decimalToBinaryConversion(unsigned numberInserted, vector<unsigned>& answerToSelection) {
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

void decimalToHexadecimalConversion(unsigned numberInserted, vector<unsigned>& answerToSelection) {
	double carryThis;
	while (numberInserted > 0) {
		carryThis = remainder(numberInserted, 16); //should get the remainder
		numberInserted = numberInserted / 16; //lowers the number down
		answerToSelection.push_back(carryThis);
	}

	for (int j = answerToSelection.size() - 1; j >= 0; j--) {
		cout << answerToSelection[j] << endl;
	}
}



int main() {
	int typeNumber;
	int conversionType;
	unsigned userNum;
	vector<unsigned> answerToSelection;

	cout << "Hi! Please select, using the numbers, format of your number:" << endl;
	cout << "1. DECIMAL" << endl << "2. BINARY" <<
		endl << "3. HEX" << endl << "4. FLOAT" << endl;
	cin >> typeNumber;
	cout << "Hi! Please select, using the numbers, which conversion you wish to perform:" << endl;
	cout << "1. DECIMAL" << endl << "2. BINARY" <<
		endl << "3. HEX" << endl << "4. FLOAT" << endl;
	cin >> conversionType;
	
	cout << "Please type your number!" << endl;
	cin >> userNum;

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
			break;
		}
		break;
	case 2:
		switch (conversionType) {
		case 1: 
			cout << "Heres your binary to decimal: " << endl;
			break;
		case 2:
			cout << "Why are you doing binary to binary??" << endl;
			break;
		case 3:
			cout << "Heres your binary to hex: " << endl;
			break;
		case 4:
			cout << "Heres your binary to float: " << endl;
		}
		break;
	case 3:
		break;
	case 4:
		break;
	}

	return 0;
}