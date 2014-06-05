/* 
 * File:   Geldeinheit_liste.h
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#ifndef GELDEINHEIT_LISTE_H
#define	GELDEINHEIT_LISTE_H

#include "Geldeinheit.h"

using namespace std;

class GeldeinheitenListe
{
  private:
    vector<Geldeinheit> geldeinheit;
    
  public:
    GeldeinheitenListe();
    GeldeinheitenListe(Geldeinheit eine_Geldeinheit);
    GeldeinheitenListe(vector<Geldeinheit> liste);
    
    vector<Geldeinheit> liefereGeldeinheit() const;
    void addiereGeldeinheit(Geldeinheit eine_Geldeinheit);
    void liefereZulaessigesWechselgeld(double wert);
    void liefereGeldeinheit();
    double liefereGesamtbetrag() const;
    
  private:
    vector<Geldeinheit> sortiere_nach_wert();
};


#endif	/* GELDEINHEIT_LISTE_H */

