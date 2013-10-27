/*
 * pgmManip.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Arthur Bousquet
 */

#include <iostream>
#include <string>

using namespace std;

int pgmRead (string somefile, int pixels[]);


int main ()
{
	int pixels[1024*1024]={0};

	string thisFile;

	pgmRead (thisFile, pixels);
	return 0;
}


int pgmRead (string somefile, int pixels[])
{
	return 0;
}
