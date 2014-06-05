/* 
 * File:   FahrkartenautomatMain.cpp
 * Author: Cedric Laier
 *
 * Created on 10. Dezember 2013, 13:38
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include "Produkt.h"
#include "ProduktListe.h"
#include "MeineEingabe.h"
#include "Geldeinheit.h"
#include "GeldeinheitenListe.h"

using namespace std;

vector<Produkt> erstelleFahrkarten();
vector<Geldeinheit> zulaessigeGeldeinheiten();
void schreibePreise(ProduktListe liste);
Produkt liefereProduktauswahl(ProduktListe liste, int wahl);

/** Programm 6 - Fahrkartenautomat
 *  Das Programm simuliert einen Fahrkartenautomaten. Dem Benutzer des Automaten werden verschiedene Tarife
 *  angeboten. Der Anwender hat anschliessend die Moeglichkeit, sich fuer den passenden Tarif zu entscheiden.
 *  Dieses geschieht ueber die Eingabe des gewuenschten Menuepunktes. Sobald dieses geschehen ist, wird dem Anwender 
 *  der Tarifpreis angezeigt und er wird aufgefordert den Ticketpreis zu bezahlen.
 *  Bei diesem Programm zahlt der Nutzer ueber die Eingabe der eingeworfenen Geldbetraege.
 *  Er kann mit 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 00.10, 00.00 Geldeinheiten bezahlen.
 *  Bezahlt der Nutzer durch korrekten Einwurf, wird anschliessend die Fahrtkarte gedruckt und er aufgefordert
 *  seine Karte zu entnehmen.
 *  Bezahlt der Nutzer nicht passend und wirft mehr ein als noetig waere, wird die Fahrkarte gedruckt und das entsprechende
 *  Wechselgeld ausgegeben. Der Anwender soll nun sein Wechselgeld, sowie die Fahrkarte entnehmen und kehrt
 *  zur Tarifauswahl zurueck.
 *  Falls der Anwender das Programm nicht mehr benutzen moechte, so kann er durch die Eingabe des Wertes '-1' 
 *  das Programm beenden.
 */

int main(void) 
{
  int inputEins = 0;
  while (inputEins != -1)
  {
    GeldeinheitenListe einwurf = GeldeinheitenListe();
    ProduktListe meinePreise = ProduktListe(erstelleFahrkarten());
    schreibePreise(meinePreise);
    inputEins = erfasse_int(-1, 9);
    if (inputEins != -1)
    {
      Produkt produktAuswahl = liefereProduktauswahl(meinePreise, inputEins);
      double inputZwo = 1;
      while (inputZwo != 0 && (produktAuswahl.lieferePreis() - einwurf.liefereGesamtbetrag()) > 0)
      {
        cout << produktAuswahl.lieferePreis() - einwurf.liefereGesamtbetrag() << " Euro";
        cout << "\nBitte Geld einwerfen: ";
        inputZwo = erfasseGeldeinheit();
        Geldeinheit betrag = Geldeinheit(inputZwo);
        einwurf.addiereGeldeinheit(betrag);
      }
      if ((produktAuswahl.lieferePreis() - einwurf.liefereGesamtbetrag()) == 0)
        cout << "\n\nBitte entnehmen Sie Ihre Fahrkarte.\n\n";
      else if (inputZwo == 0 && einwurf.liefereGesamtbetrag() > 0)
      {
        cout << "\n\nBitte entnehmen Sie Ihr bereits eingeworfenes Geld:\n";
        einwurf.liefereGeldeinheit();
      }
      else if ((produktAuswahl.lieferePreis() - einwurf.liefereGesamtbetrag()) < 0)
      {
        cout << "\n\nBitte entnehmen Sie Ihre Fahrkarte und Ihr Wechselgeld: \n";
        vector<Geldeinheit> betragZwo = zulaessigeGeldeinheiten();
        GeldeinheitenListe rueckgabe = GeldeinheitenListe(betragZwo);
        rueckgabe.liefereGeldeinheit();
        rueckgabe.liefereZulaessigesWechselgeld(produktAuswahl.lieferePreis() - einwurf.liefereGesamtbetrag());
        rueckgabe.liefereGeldeinheit();
      }
    }
  }
}

/** Diese Funktion erstellt einen Vektor mit den einzelnen Tarifen und den dazugehoerigen Preisen.
 * 
 * @return Der Vektor mit den Tarifnamen und Preisen.
 */
vector<Produkt> erstelleFahrkarten()
{
  vector<Produkt> tarife;
  string namen[] = {"Kurzstrecke", "Ermaessigungstarif", "Einzelfahrschein", "Ermaessigungstarif", 
  "4-Fahrten-Karte Einzelfahrschein", "Ermaessigungstarif", "Tageskarte", "Ermaessigungstarif", "Monatskarte", "Ermaessigungstarif"};
  double preise[] = {1.3, 0.8, 2.6, 2.1, 9.0, 6.4, 8.2, 5.4, 88.0, 56.5};
  for(int i = 0; i < 10; i++)
  {
    Produkt n = Produkt(namen[i], preise[i]);
    tarife.push_back(n);
  }
  return tarife;
}

/** Diese Funktion erstellt einen Vektor mit den zulaessigen Geldeinheiten.
 * 
 * @return Der Vektor mit den zulaessigen Geldeinheiten.
 */
vector<Geldeinheit> zulaessigeGeldeinheiten()
{
  vector<Geldeinheit> geldeinheiten;
  double werte[] = {50, 20, 10, 5, 2, 1, 0.5, 0.1};
  for (int i = 0; i < 8; i++)
  {
    Geldeinheit meineGeldeinheit = Geldeinheit(werte[i], 0);
    geldeinheiten.push_back(meineGeldeinheit);
  }
  return geldeinheiten;
}

/** Diese Funktion gibt das Menue dem Benutzer auf dem Bildschirm aus.
 * 
 * @param preise Eine Produktliste mit den dazugehoerigen Preisen.
 */
void schreibePreise(ProduktListe preise)
{
  cout << "\n\nFahrkarten-Automat";
  preise.schreibeProdukte();
  cout << "Ihre Auswahl: ";
}

/** Diese Funktion liefert den gewaehlen Tarif/Menuepunkt.
 * 
 * @param liste Die ProduktListe
 * @param wahl Der ausgewaehlte Tarif/Menuepunkt
 * @return Das gewaehte Produkt.
 */
Produkt liefereProduktauswahl(ProduktListe liste, int wahl)
{
  vector<Produkt> auswahl = liste.liefereProduktListe();
  Produkt menu = auswahl[wahl];
  return menu;
}

