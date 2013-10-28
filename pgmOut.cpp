/*
 * pgmOut.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: majuk
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "functions.h"
//#include <iostream>
//#include <string>

using namespace std;

void pgmOut (string tag, unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024])
{
	cout << tag << endl << pgmCols << " " << pgmRows << endl << pgmMaxval << endl << endl;

	for ( unsigned int j = 0; j < pgmRows; j++ )
	{
		for ( unsigned int i = 0; i < pgmCols; i++ )
			cout << pixels[j][i] << " ";
		cout << endl;
	}
	return;
}
