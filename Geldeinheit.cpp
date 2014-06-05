/* 
 * File:   Geldeinheit.cpp
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "Geldeinheit.h"

using namespace std;

/** Konstruiert ein Objekt Geldeinheit und initalisiert es mit jeweils mit 0 */
Geldeinheit::Geldeinheit()
{
  wert = 0;
  anzahl = 0;
}

/** Konstruiert ein Objekt Geldeinheit mit einem uebergebenen Geldwert.
 * 
 * @param geldbetrag Der uebergebene Geldwert.
 */
Geldeinheit::Geldeinheit(double geldWert)
{
  if (geldWert < 0.00)
    wert = 1;
  else
    wert = geldWert;
  anzahl = 1;
}

/** Konstruiert ein Objekt Geldeinheit mit einem uebergebenen Geldwert.
 * 
 * @param geldbetrag Der uebergebene Geldwert.
 * @param anzahlGeldeinheiten Die uebergebene Anzahl von Geldeinheiten.
 */
Geldeinheit::Geldeinheit(double geldbetrag, int anzahlGeldeinheiten)
{
  if (geldbetrag < 0.00)
    wert = 1;
  else
    wert = geldbetrag;
  if (anzahlGeldeinheiten < 0)
    anzahl = 1;
  else
    anzahl = anzahlGeldeinheiten;
}

/** Diese Funktion aendert die Anzahl der Waehrungseinheiten.
 * 
 * @param neue_anzahl Die zu aendernde Anzahl von Waehrungseinheiten.
 */
void Geldeinheit::aendereGeldeinheiten(int neue_anzahl)
{
    anzahl = neue_anzahl;
}

/** Diese Funktion liefert den Geldwert.
 * 
 * @return Der Geldwert.
 */
double Geldeinheit::liefereGeldwert() const
{
  return wert;
}

/** Diese Funktion liefert die Anzahl der Waehrungseinheiten.
 * 
 * @return Die Anzahl der Waehrungseinheiten.
 */
int Geldeinheit::liefereGeldeinheiten() const
{
  return anzahl;
}

/** Diese Funktion gibt die Anzahl der Geldeinheiten sowie den dazu passenden Geldwert
 *  auf dem Bildschirm aus. 
 */
void Geldeinheit::schreibe_wert_mal_anzahl() const
{
  cout << setw(1) << anzahl;
  cout << " * ";
  cout << setw(5) << setprecision(2) << fixed << wert;
}

/** Diese Funktion multipliziert den Geldwert mit der Anzahl von Geldeinheiten.
 * 
 *  @return Das Produkt aus Wert und Anzahl.
 */
double Geldeinheit::liefere_wert_mal_anzahl() const
{
  return (wert * anzahl);
}
