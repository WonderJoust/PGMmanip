/*
 * pgmRead.h
 *
 *  Created on: Oct 28, 2013
 *      Author: majuk
 */

#ifndef PGMREAD_H_
#define PGMREAD_H_

#include <string>

int pgmRead (string somefile, string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024]);


#endif /* PGMREAD_H_ */
