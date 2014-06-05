/* 
 * File:   Produkt_liste.h
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#ifndef PRODUKT_LISTE_H
#define	PRODUKT_LISTE_H
#include "Produkt.h"

using namespace std;

class ProduktListe
{
  private:
    vector<Produkt> liste;
    
  public:
    ProduktListe(vector<Produkt> angabe_produktliste);
    ProduktListe();
    
    vector<Produkt> liefereProduktListe() const;
    void schreibeProdukte() const;
};

#endif	/* PRODUKT_LISTE_H */

