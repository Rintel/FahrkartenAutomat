/* 
 * File:   GeldeinheitListe.cpp
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#include <iostream>
#include <string>
#include <iomanip> //Header providing parametric manipulators!
#include <vector>
#include "Geldeinheit.h"
#include "GeldeinheitenListe.h"

using namespace std;

/** Konstruiert ein Objekt GeldeinheitenListe und schreibt die erste Geldeinheit
 *  in einen Vektor.
 */
GeldeinheitenListe::GeldeinheitenListe()
{
  Geldeinheit x = Geldeinheit();
  geldeinheit.push_back(x);
}

/** Konstruiert ein Objekt GeldeinheitenListe und schreibt eine erste Geldeinheit
 *  in einen Vektor.
 * 
 * @param neueGeldeinheit Eine uebergebene Geldeinheit.
 */
GeldeinheitenListe::GeldeinheitenListe(Geldeinheit neueGeldeinheit)
{
  geldeinheit.push_back(neueGeldeinheit);
}

/** Konstruiert ein Objekt GeldeinheitenListe 
 * 
 * @param liste
 */
GeldeinheitenListe::GeldeinheitenListe(vector<Geldeinheit> liste)
{
  if (liste.size() < 1)
    cout << "\nIhre Produktliste ist zu klein!!\n";
  else
    geldeinheit = liste;
}

/** Diese Funktion liefert die Geldeinheit eines Objektes.
 * 
 * @return Die Geldeinheit.
 */
vector<Geldeinheit> GeldeinheitenListe::liefereGeldeinheit() const
{
  return geldeinheit;
}

/** Diese Funktion ermittelt den Gesamtbetrag aller in der Liste enthaltenden Werte. 
 * 
 * @return Den Gesamtbetrag aller Werte.
 */
double GeldeinheitenListe::liefereGesamtbetrag() const
{
  double bank = 0;
  for (unsigned int i = 0; i < geldeinheit.size(); i++)
  {
    bank += geldeinheit[i].liefere_wert_mal_anzahl();
  }
  return bank;
}

/** Diese Funktion fuegt 
 * 
 * @param eine_Geldeinheit
 */
void GeldeinheitenListe::addiereGeldeinheit(Geldeinheit eine_Geldeinheit)
{
  if (eine_Geldeinheit.liefereGeldwert() > 0)
  {
    bool ok = false;
    for (unsigned int i = 0; i < geldeinheit.size(); i++)
    {
      if (geldeinheit[i].liefereGeldwert() == eine_Geldeinheit.liefereGeldwert())
      {
        geldeinheit[i].aendereGeldeinheiten(geldeinheit[i].liefereGeldeinheiten() + 1);
        ok = true;
      }
    }
    if (!ok)
      geldeinheit.push_back(eine_Geldeinheit);
  }
}

/** Diese Funktion teilt den gezahlten Ueberbetrag in die zulaessigen Geldeinheiten ein.
 * 
 * @param wert Der gezahlte Ueberbetrag.
 */
void GeldeinheitenListe::liefereZulaessigesWechselgeld(double wert)
{
  double temp = wert;
  if (temp < 0)
    temp *= -1;
  int tempZwo = (int)(temp * 100);
  for(unsigned int i = 0; i < geldeinheit.size(); i++)
  {
    int tempDrei = (int)(geldeinheit[i].liefereGeldwert() * 100);
    while((tempZwo - tempDrei) >= 0)
    {
      geldeinheit[i].aendereGeldeinheiten(geldeinheit[i].liefereGeldeinheiten() + 1);
      tempZwo -= tempDrei;
    }
  }
}
/** Diese Funktion gibt die Anzahl der Geldeinheiten auf dem Bildschirm aus.
 * 
 */
void GeldeinheitenListe::liefereGeldeinheit()
{
  geldeinheit = sortiere_nach_wert();
  for (unsigned int i = 0; i < geldeinheit.size(); i++)
  {
    if (geldeinheit[i].liefereGeldeinheiten() > 0)
    {
      cout << "\n";
      geldeinheit[i].schreibe_wert_mal_anzahl();
      cout << " Euro";
    }
  }
}

/** Diese Funktion sortiert einen Vektor aufsteigendend nach seinem Geldwert.
 * 
 * @return Der sortierte Vektor.
 */
vector<Geldeinheit> GeldeinheitenListe::sortiere_nach_wert()
{
  Geldeinheit tmp;
  vector<Geldeinheit> neu = geldeinheit; 
  for (unsigned int i = 0; i < neu.size() - 1; ++i) 
  { 
    for (unsigned int j = 0; j < neu.size() - i - 1; ++j) 
    {
      if (neu[j].liefereGeldwert() < neu[j + 1].liefereGeldwert()) 
      {
        tmp = neu[j];
        neu[j] = neu[j + 1];
        neu[j + 1] = tmp;
      }
    }
  }
  return neu;
}



