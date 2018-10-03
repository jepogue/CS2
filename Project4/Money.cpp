//This is the implementation for the Money adt.
//The interface is Money.h
//Author Jeremy Pogue
//Date 10/2/2018 Version 1.0

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "Money.h"
using namespace std;


//Function to conver a character to an int '1' through '9'
int digitToInt(char c);

//default constructor for Money
Money :: Money() : allCents(0) {}

//single argument constructor for Money uses a dollar amount
Money :: Money(long dollars) : allCents(dollars * 100){}

//two argument constructor for Money has both dollars and cents  
Money :: Money(long dollars, int cents){
	if(dollars * cents < 0){ //Dollars and Cents must be both either pos or neg 
		cout << "Invalid values for dollars and cents \n";
		exit(1);
	}
	
	allCents = cents + dollars*100;
}

//Getter function for money returns dollars and cents DD.CC
double Money :: getValue() const{
	return allCents * 0.01;
}

//Returns a percent of the Money if percentFigure = 10 it will return 10% of the money amount
Money Money :: percent(int percentFigure) const {
	double decimalPercent = percentFigure * .01;
	return allCents;
}


//Overriden '+' operator returns the total amount of money 
Money operator +(const Money& amount1, const Money& amount2){
	Money temp;
	temp.allCents = amount1.allCents + amount2.allCents; 
	return temp; 
}

//Overriden '-' operator returns the amount of the first money minus the second
Money operator -(const Money& amount1, const Money& amount2){
	Money temp;
	temp.allCents = amount1.allCents - amount2.allCents;
	return temp;
	
}

//Overriden '-' operator for negation

Money operator -(const Money& amount){
	Money temp;
	temp.allCents = -amount.allCents;
	return temp; 
}


//Overriden == operator
bool operator ==(const Money& amount1, const Money& amount2){
	return (amount1.allCents == amount2.allCents);
}

//Overriden < operator
bool operator <(const Money& amount1, const Money& amount2){
	return (amount1.allCents < amount2.allCents);
}

//Overriden <= operator
bool operator <=(const Money& amount1, const Money& amount2){
	return (amount1.allCents <= amount2.allCents);
}

//Overriden > operator
bool operator >(const Money& amount1, const Money& amount2){
	return (amount1.allCents > amount2.allCents);
}

//Overriden >= operator
bool operator >=(const Money& amount1, const Money& amount2){
	return (amount1.allCents >= amount2.allCents);
}

//overloaded input
istream& operator >>(istream& ins, Money& amount){
	char oneChar, decimalPoint, digit1, digit2; 
	long dollars;
	int cents;
	bool negative; // sets to true if input is negative
	
	ins >> oneChar; 
	if (oneChar == '-'){
		negative = true;
		ins >> oneChar; 
	}
	else
		negative = false;
	
	ins >> dollars >> decimalPoint >> digit1 >> digit2; 
	
	if(oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)){
		cout << "Error illegal form for money input \n"; 
		exit(1);
	}
	
	cents = digitToInt(digit1) * 10 + digitToInt(digit2);
	amount.allCents = dollars * 100 + cents;
	if(negative){
		amount.allCents = -amount.allCents;
	}
	
	cout << "Successful pull " << amount.allCents << endl; 
	return ins; 	
}

//overloaded output
ostream& operator<< (ostream& outs, const Money& amount){
	long positiveCents, dollars, cents;
	positiveCents = labs(amount.allCents);
	dollars = positiveCents/100; 
	cents = positiveCents%100;
	
	if (amount.allCents < 0){
		outs << "- $" << dollars << '.';		
	}
	else
		outs << "$" << dollars << '.';
	
	if (cents < 10){
		outs << '0';
	}
	outs << cents;
	
	return outs; 
}

int digitToInt(char c){
	return ( static_cast<int>(c) - static_cast<int>('0'));
}





