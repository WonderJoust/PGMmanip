/*
 * pgmManip2.h
 *
 *  Created on: Oct 28, 2013
 *      Author: Arthur Bousquet
 */

#ifndef PGMMANIP2_H_
#define PGMMANIP2_H_

void pgmOut (std::string tag, unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024]);

void pgmInvert (unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024]);

int pgmRead (std::string somefile, std::string &tag, unsigned int &pgmCols, unsigned int &pgmRows, unsigned int &pgmMaxval, unsigned int pixels[][1024]);

void pgmSave (std::string defaultOutFile, std::string tag, unsigned int pgmCols, unsigned int pgmRows, unsigned int pgmMaxval, unsigned int pixels[][1024]);

#endif /* PGMMANIP2_H_ */
