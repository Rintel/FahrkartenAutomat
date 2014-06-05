/* 
 * File:   Geldeinheit.h
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#ifndef GELDEINHEIT_H
#define	GELDEINHEIT_H
using namespace std;

class Geldeinheit
{
private:
    double wert;
    int anzahl;
    
public:
    Geldeinheit();
    Geldeinheit(double angabe_wert);
    Geldeinheit(double angabe_wert, int angabe_anzahl);
    
    double liefereGeldwert() const;
    int liefereGeldeinheiten() const;
    void aendereGeldeinheiten(int neue_anzahl);
    void schreibe_wert_mal_anzahl() const;
    double liefere_wert_mal_anzahl() const;
};


#endif	/* GELDEINHEIT_H */

