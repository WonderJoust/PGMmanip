/*
 * pgmSave.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Arthur Bousquet
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "functions.h"

using namespace std;

void pgmSave (string outFile, string tag, unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024])
{

	string line;

	cout << "Please input the filename to write to [somepicMod.pgm]: ";
	getline( cin, line );

	if ( line != "" )
		outFile = line;

	ofstream someFile (outFile.c_str());

	if (!someFile.good())
	{
		cout << "Error accessing output file."<<endl;
		return;
	}

	someFile << tag << '\n' << pgmCols << " " << pgmRows << '\n' << pgmMaxval << '\n';

	for ( unsigned int j = 0; j < pgmRows; j++ )
	{
		for ( unsigned int i = 0; i < pgmCols; i++ )
			someFile << pixels[j][i] << " ";
		someFile << '\n';
	}

	someFile.close();
	return;
}
