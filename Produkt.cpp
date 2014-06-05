/* 
 * File:   Produkt.cpp
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */

#include <iostream>
#include <string>
#include "Produkt.h"

using namespace std;

/** Konstruiert ein Objekt Produkt mit einem Namen und einem Preis. */
Produkt::Produkt()
{
  name = "*";
  preis = 1.00;
}

/** Konstruiert ein Objekt Produkt mit einem uebergebenen Produktnamen sowie einem Produktpreis.
 * 
 * @param angabe_name Der Produktname
 * @param angabe_preis Der Produktpreis.
 */
Produkt::Produkt(string produktName, double produktPreis)
{
  name = produktName;
  if (produktPreis <= 0)
    preis = 1;
  else
    preis = produktPreis;
}

/** Diese Funktion aendert den Produktpreis des Objektes.
 * 
 * @param neuerPreis Der neue Produktpreis.
 */
void Produkt::aenderePreis(double neuerPreis)
{
  if (neuerPreis <= 0)
    preis = 1;
  else
    preis = neuerPreis;
}

/** Diese Funktion aendert den Produktnamen des Objektes. 
 */
void Produkt::aendereProduktname(string nameNeu)
{
  name = nameNeu;
}

/** Diese Funktion liefert den Produktnamen.
 *  
 *  @return Einen String mit dem Produktnamen. 
 */
string Produkt::liefereProduktname() const
{
  return name;
}

/** Diese Funktion liefert den Produktpreis.
 * 
 * @return Den Produktpreis.
 */
double Produkt::lieferePreis() const
{
  return preis;
}