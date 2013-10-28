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

int pgmRead (string somefile, string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024]);

int main ()
{
	string tag = "null";
	unsigned int pgmCols=0;
	unsigned int pgmRows=0;
	unsigned int pgmMaxval=0;
	unsigned int pixels[1024][1024];

	string defaultFile = "somepic.pgm";

	if (pgmRead (defaultFile, tag, pgmCols, pgmRows, pgmMaxval, pixels))
		cout << "Unexpected value in header. Please check source file.";

	else
	{
		//*----PASS CHECKS
		cout << tag << endl << pgmCols << endl << pgmRows << endl << pgmMaxval << endl << endl;

		for ( int j = 0; j < pgmRows; j++ )
		{
			for ( int i = 0; i < pgmCols; i++ )
				cout << pixels[j][i] << " ";
			cout << endl;
		}
		//---!PASS CHECKS
		//*/
	}

	return 0;


}


int pgmRead (string somefile, string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024])
{

	string thisLine;

	cout << "Please input the desired PGM filename: [somepic.pgm]";
	getline (cin, thisLine);

	if (thisLine != "") //input, set filename for read
		somefile = thisLine;

	ifstream inFile (somefile.c_str());

	if (!inFile.good()) //input file sanity check
		return 1;

	int row = 0; //row tracker

	while ( getline(inFile, thisLine) ) //pull line
	{
		//cout << "The line is: " << thisLine << endl;

		if (row == 0) //top line tag
		{
			stringstream ss(thisLine);
			ss >> tag;
		}

		else if (row == 1) //cols rows
		{
			istringstream is(thisLine);
			is >> pgmCols >> pgmRows;
		}

		else if (row == 2) //maxval
		{
			istringstream is(thisLine);
			is >> pgmMaxval;
		}

		else //outside header
		{
			istringstream is(thisLine);
			unsigned int col=0; //column tracker
			unsigned int x=0;
			while (is.good() && col < thisLine.length())
			{
				is >> x;
				//cout << x<<endl;
				pixels[row-3][col] = x;
				col++;
			}

		}
		row++;
	}

	/*----PARSE CHECKS
	cout << tag << endl << pgmCols << endl << pgmRows << endl << pgmMaxval << endl << endl;

	for ( int j = 0; j < pgmRows; j++ )
	{
		for ( int i = 0; i < pgmCols; i++ )
			cout << pixels[j][i] << " ";
		cout << endl;
	}
	*///---!PARSE CHECKS

	//Quick sanity check
	if ( tag == "null" || pgmRows == 0 || pgmCols == 0 || pgmMaxval == 0 )
		return 1;

	return 0;
}
