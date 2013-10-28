/*
 * pgmInvert.cpp
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

void pgmInvert (unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024])
{
	for ( unsigned int j = 0; j < pgmRows; j++ )
	{
		for ( unsigned int i = 0; i < pgmCols; i++ )
		{
			double percent = 1 - ( (static_cast<double>(pixels[j][i])) / (static_cast<double>(pgmMaxval)) );
			//cout << percent <<endl;

			pixels[j][i] = pgmMaxval*percent;
		}
	}

	return;
}
