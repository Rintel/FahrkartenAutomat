/* 
 * File:   ProduktListe.cpp
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#include <iostream>
#include <vector>
#include "ProduktListe.h"
#include "Produkt.h"

using namespace std;

/** Konstruiert ein Objekt ProduktListe.
 * 
 */
ProduktListe::ProduktListe()
{
  Produkt n = Produkt();
  liste.push_back(n);
}

/** Konstruiert ein Objekt Produktliste mit 
 * 
 * @param angabe_produktliste Ein uebergebener Vektor des Types Produkt
 */
ProduktListe::ProduktListe(vector<Produkt> angabe_produktliste)
{
  if (angabe_produktliste.size() < 1)
    cout << "\nDie Produktliste ist zu klein.\n";
  else
    liste = angabe_produktliste;
}

/** Die Funktion liefert die Produktliste.
 * 
 * @return Die Produktliste.
 */
vector<Produkt> ProduktListe::liefereProduktListe() const
{
  return liste;
}

/** Die Funktion 'schreibeProdukte' gibt den Inhalt einer Produktliste auf dem Bildschirm aus.
 * 
 */
void ProduktListe::schreibeProdukte() const
{
  cout << "\n\n";
  for(unsigned int i = 0; i < liste.size(); i++)
  {
    cout << "[" << i << "] " << liste[i].liefereProduktname() << "\n";
    if ((i + 1) % 2 == 0)
      cout << "------------------------------------\n";
  }
  cout << "\n";
}