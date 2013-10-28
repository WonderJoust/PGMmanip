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
#include "functions.h"

using namespace std;

//int pgmRead (string somefile, string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024]);

int main ()
{
	string tag = "null";
	unsigned int pgmCols=0;
	unsigned int pgmRows=0;
	unsigned int pgmMaxval=0;
	unsigned int pixels[1024][1024];

	string defaultInFile = "somepic.pgm";
	string defaultOutFile = "somepicMod.pgm";

	cout << 	"*********************************"<<endl
			<<	"*       Welcome to Hardy's      *"<<endl
			<< 	"*    MAGNIFICENT PGM EDITOR     *"<<endl
			<<	"* [and boring GIT presentation] *"<<endl
			<<	"*********************************"<<endl<<endl;

	if (pgmRead (defaultInFile, tag, pgmCols, pgmRows, pgmMaxval, pixels))
	{
		cout << "Unexpected value in header. Please check source file.";
		return 1;
	}

	unsigned int option = 5;

	while (true)
	{
		//Options list
		cout << "(1) Invert image"<<endl
				<< "(2) Rotate image" <<endl
				<< "(3) Output current image info to console"<<endl
				<< "(4) Save current image" <<endl
				<< "(5) Exit"<<endl;

		cout << "Please select an operation [exit]: ";
		cin >> option;

		switch (option)
		{
		case 1:
			pgmInvert(pgmCols, pgmRows, pgmMaxval, pixels);
			//cout << "pgmInvert"<<endl;
			break;
		case 2:
			//pgmRotate(pgmCols, pgmRows, pixels)
			cout << "pgmRotate not implimented"<<endl;
			break;
		case 3:
			pgmOut( tag, pgmCols, pgmRows, pgmMaxval, pixels );
			//cout << "pgmOut" <<endl;
			break;
		case 4:
			pgmSave( defaultOutFile, tag, pgmCols, pgmRows, pgmMaxval, pixels );
			//cout << "pgmSave" <<endl;
			break;
		default:
			cout << endl <<"Thanks and goodbye!";
			return 0;
			break;
		}
	}

	//else
	/*----PASS CHECKS
	{
		cout << tag << endl << pgmCols << endl << pgmRows << endl << pgmMaxval << endl << endl;

		for ( unsigned int j = 0; j < pgmRows; j++ )
		{
			for ( unsigned int i = 0; i < pgmCols; i++ )
				cout << pixels[j][i] << " ";
			cout << endl;
		}
	}
	//---!PASS CHECKS
	//*/

	return 0;


}


int pgmRead (string somefile, string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024])
{

	string thisLine;

	cout << "Please input the desired PGM filename [somepic.pgm] : ";
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
			while (is.good() && col < pgmCols)
			{
				is >> x;
				//cout << x<<endl;
				pixels[row-3][col] = x;
				col++;
			}

		}
		row++;
	}

	/*
	 //----PARSE CHECKS
	cout << tag << endl << pgmCols << endl << pgmRows << endl << pgmMaxval << endl << endl;

	for ( unsigned int j = 0; j < pgmRows; j++ )
	{
		for ( unsigned int i = 0; i < pgmCols; i++ )
			cout << pixels[j][i] << " ";
		cout << endl;
	}
	*///---!PARSE CHECKS

	//Quick sanity check
	if ( tag == "null" || pgmRows == 0 || pgmCols == 0 || pgmMaxval == 0 )
	{
		inFile.close();
		return 1;
	}

	inFile.close();
	return 0;
}
