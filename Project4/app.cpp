//Application file for Project 4
//Author Jeremy Pogue
// Date 10/3/2018 Version 1.0

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Money.h"
using namespace std;


int main(){
	
	Money amount; 
	ifstream inStream;
	ofstream outStream;
	
	inStream.open("infile.dat");
	if(inStream.fail()){
		cout << "Input file opening failed \n";
		exit(1);
	}
	
	outStream.open("outfile.dat");
	if(outStream.fail ()){
		cout << "Output file opening failed \n";
		exit(1);
	}
	
	inStream >> amount;
	outStream << amount << " copied from the file infile.dat \n";
	cout << amount << " copied from the file infile.dat \n";
	
	inStream.close();
	outStream.close();	
	
	return 0; 
}
/**
OUTPUT: 

C:\Users\Jeremy\Desktop\CS2\Project4>a
Successful pull 111
$1.11 copied from the file infile.dat

**/