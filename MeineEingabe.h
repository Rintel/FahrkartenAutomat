/* 
 * File:   Meine_eingabe.h
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#ifndef MEINE_EINGABE_H
#define	MEINE_EINGABE_H

double erfasseDouble(double min, double max);
void erfasse_zeichenkette(std::string& eingabe);
long erfasse_long(long min, long max);
int erfasse_int(int min, int max);
double erfasseGeldeinheit();

#endif	/* MEINE_EINGABE_H */

