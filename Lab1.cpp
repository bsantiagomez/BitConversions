/*
              Created by Bryan S. Gomez 2/11/2020, Copyright @ 2020. All rights reserved.
  =================================================================================================
  Converts string inputs of 16-bit Binary to its integer value(1), same with 32-bit Hexadecimal(2).
  Converts integer input to it's string Binary representation(3), same with it's Hexadecimal(4).
  Adds two integer values(5). Hexadecimal addition of two Hexadecimal string inputs(6).
  Hexadecimal multiplication of two Hexadecimal string inputs(7).
*/
// NOTE: DID NOT IMPLEMENT INPUT VALIDATION, IMPLEMENT ON FREE TIME SOON.
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

void bin16BitToDecimalDisplay();  // Display for (1)
long int bin16BitToDecimal(const string &bin);     // Function for (1)
void hex32BitToDecimalDisplay();  // Display for (2)
long int hex32BitToDecimal(const string &hex);          // Function for (2)
void decToBinaryDisplay();        // Display for (3)
string decToBinary(int dec);             // Function for (3)
void decToHexDisplay();           // Display for (4)
string decToHex(int dec);                // Function for (4)
void additionWithBasesDisplay();  // Display for (5)
string additionWithBases(string num1, string num2, int base);       // Function for (5)
void hexAdditionDisplay();        // Display for (6)
string hexAddition(string hex1, string hex2);             // Function for (6)
void hexMultiplicationDisplay();  // Display for (7)
string hexMultiplication(string hex1, string hex2);       // Function for (7)
void allTypeExpressionDisplay();  // Display for (8) Unable to finish
template<class anyType>
anyType allTypeExpression();				  // Function for (8) Unable to finish

int main() {
	bin16BitToDecimalDisplay();
	hex32BitToDecimalDisplay();
	decToBinaryDisplay();
	decToHexDisplay();
	additionWithBasesDisplay();
	hexAdditionDisplay();
  hexMultiplicationDisplay();
  cout << endl;
	return 0;
}
void bin16BitToDecimalDisplay(){
  string bin;             
  cout << "Please enter a 16-bit binary integer: ";
  cin >> bin;
  cin.ignore();
  cout << "\nYour input: " << bin << "\t\tConverted into integer value: " << bin16BitToDecimal(bin);
}
long int bin16BitToDecimal(const string &bin) {
	long int decimal = 0, index = bin.size() - 1;
	for (int i = 0; i < bin.size(); ++i){
		if (bin[i] == '1') { decimal += pow(2, index--); }
    else{--index;}
  }
	return decimal;
}
void hex32BitToDecimalDisplay(){
  string hex;             //Variable for user's input
  cout << "\nPlease enter a 32-bit hexadecimal integer: "; //0x19ABCDEF
  cin >> hex;
  cin.ignore();
    cout << "\nYour input: " << hex << "\t\tConverted into integer value: " << hex32BitToDecimal(hex);
}
long int hex32BitToDecimal(const string &hex) {
	char hexValues[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; //Possible hexvalues
  long int decimal = 0;
  int index = hex.size() - 1;
	for (int i = 0; i < hex.size(); ++i)
		for (int j = 0; j < sizeof(hexValues); ++j)
			if (hex[i] == hexValues[j]) { decimal += (j * pow(16, index--)); }
	return decimal;
}
void decToBinaryDisplay(){
  int input;             //Variable for user's input
  cout << "\nPlease enter a decimal value: "; //122
  cin >> input;
  cin.ignore();
  cout << "\nYour input: " << input << "\t\tConverted into binary value: " << decToBinary(input);
}
string decToBinary(int dec) {
	string binary = "";
	while (dec != 0) {
		if ((dec % 2) == 1) { binary = "1" + binary; }
		else { binary = "0" + binary; }
		dec /= 2;
	}
	return binary;
}
void decToHexDisplay(){
  int input;             //Variable for user's input
  cout << "\nPlease enter a decimal value: "; //122
  cin >> input;
  cin.ignore();
  cout << "\nYour input: " << input << "\t\tConverted into hexadecimal value: " << decToHex(input);
}
string decToHex(int dec) {
	string binary = "";
	string hexValues[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };                 
	while (dec != 0) {
		int i = dec % 16;
		binary = hexValues[i] + binary;
		dec /= 16;
	}
	return binary;
}
void additionWithBasesDisplay(){
  string num1, num2;             //Variable for user's input
  int base;
  cout << "\nPlease enter two integers separate by a space(up to 1,000 digits): ";
  cin >> num1 >> num2;
  cout << "Please enter a base: ";
  cin >> base;
  cin.ignore();                 //Used to remove newline character.
  cout << "\nYour input: " << num1 << " + " << num2 << "\t\tIn base " << base << " is: " << additionWithBases(num1, num2, base);
}
string additionWithBases(string num1, string num2, int base) {
	string total, sum;
	int dCarry = 0, dSum = 0;
	for (int i = num1.size() - 1; i >= 0; --i) {
		dSum = ((int)num1[i] - 48) + ((int)num2[i] - 48) + dCarry;
		if (dSum < base) {
			sum = to_string(dSum);
			total = sum + total;
		}
		else {
			dCarry = dSum / base;
			dSum %= base;
			sum = to_string(dSum);
			total = sum + total;
		}
	}
	total = to_string(dCarry) + total;
	return total;
}
void hexAdditionDisplay(){
  string hex1, hex2;
  cout << "\nPlease enter hex value 1: ";
	cin >> hex1;
	cin.ignore();
	cout << "Please enter hex value 2: ";
	cin >> hex2;
	cin.ignore();
  cout << "Hex values: " << hex1 << " + " << hex2 << " = " << hexAddition(hex1, hex2) << endl;
}
string hexAddition(string hex1, string hex2) {
	int carry = 0, dSum = 0;
	size_t num1, num2, zeros;
	string total, sum, tempHex;
	string hexValues("0123456789ABCDEF");
  if(hex1.size() > hex2.size()){
    zeros = hex1.size() - hex2.size();
    tempHex.append(zeros, '0');
    tempHex.append(hex2);
    hex2 = tempHex;
  }else if (hex2.size() > hex1.size()){
    zeros = hex2.size() - hex1.size();
    tempHex.append(zeros, '0');
    tempHex.append(hex1);
    hex1 = tempHex;
  }
  for(int i = hex1.size() -1; i >= 0; --i){
    num1 = hexValues.find(hex1[i]);
    num2 = hexValues.find(hex2[i]);
    dSum = num1 + num2 + carry;
    if(dSum < 16){
      sum = hexValues[dSum];
      total = sum + total;
      carry = 0;
    }else{
      carry = dSum/16;
      dSum %= 16;
      sum = hexValues[dSum];
      total = sum + total;
    }
  }
  total = hexValues[carry] + total;
	return total;
}
void hexMultiplicationDisplay(){
  string hex1, hex2;
  cout << "\nPlease enter hex value 1: ";
  cin >> hex1;
  cin.ignore();
  cout << "Please enter hex value 2: ";
  cin >> hex2;
  cin.ignore();
  cout << "Hex values: " << hex1 << " * " << hex2 << " = " << hexMultiplication(hex1, hex2);
}
string hexMultiplication(string hex1, string hex2){
  size_t num1, num2, dProduct;
  string totalProduct;
  num1 = hex32BitToDecimal(hex1);
  num2 = hex32BitToDecimal(hex2);
  dProduct = num1 * num2;
  totalProduct = decToHex(dProduct);
  return totalProduct;
}
