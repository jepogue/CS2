//Header file for Money.h. This is an interfae for the Money class
// Author: Jeremy Pogue
// Date: 10/2/2018 Version 1.0

#ifndef MONEY_H
#define MONEY_H

#include <iostream>

using namespace std; 


//Class to represent amounts of money in US curreny
class Money{
	public:
	
		//The following are the overloaded operators for thee ADT Money. They included adding, substracting, and comparing to money objects
		friend Money operator +(const Money& amount1, const Money& amount2);
		friend Money operator -(const Money& amount1, const Money& amount2);
		friend Money operator -(const Money& amount);
		friend bool operator ==(const Money& amount1, const Money& amount2);
		friend bool operator <(const Money& amount1, const Money& amount2);
		friend bool operator <=(const Money& amount1, const Money& amount2);
		friend bool operator >(const Money& amount1, const Money& amount2);
		friend bool operator >=(const Money& amount1, const Money& amount2);
		
		//The following are three seperate compilers for the money class. A two argument, one argument and default constructor
		Money(long dollars, int cents);		
		Money(long dollrs);
		Money();
		
		//The interface for a getter function for the money object
		double getValue() const; 
		
		//Will return the percentFigure percentage of the amount the object represents
		Money percent(int percentFigure) const; 
		
		//Overloaders for IO operations with the money object
		friend istream& operator >>(istream& ins, Money& amount);
		friend ostream& operator <<(ostream& outs, const Money& amount);
		
	private: 
		//Represents the amount of money as cents
		long allCents; 
		
		
	
	
};


#endif //MONEY_H