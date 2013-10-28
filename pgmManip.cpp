/*
 * pgmManip.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Arthur Bousquet
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int pgmRead (string somefile, string &tag, string header[], int pixels[][1024]);

int main ()
{
	string tag;
	string header[3]={"0"};
	int pixels[1024][1024];

	string thisFile = "somepic.pgm";

	pgmRead (thisFile, tag, header, pixels);
	return 0;
}


int pgmRead (string somefile, string &tag, string header[], int pixels[][1024])
{
	string thisLine;

	ifstream inFile (somefile.c_str());

	int j = 0;

	while ( getline(inFile, thisLine) ) //pull line
	{
		cout << "The line is: " << thisLine << endl;

		istringstream ss(thisLine);
		//load in string parser
		unsigned int i=0;
		int x=0;
		while (ss.good() && i < thisLine.length())
		{
			ss >> x;
			cout << x<<endl;
			i++;
		}
	}

	return 0;
}
