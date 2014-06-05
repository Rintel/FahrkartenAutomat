/* 
 * File:   Produkt.h
 * Author: Cedric Laier
 *
 * Created on 09. Dezember 2013, 14:12
 */
#ifndef PRODUKT_H
#define	PRODUKT_H
#include <string>
#include <cstring>


class Produkt
{
  private:
    std::string name;
    double preis;
    
  public:
    Produkt();
    Produkt(std::string angabe_name, double angabe_preis);
    
    void aenderePreis(double neuer_preis);
    void aendereProduktname(std::string neuer_name);
    std::string liefereProduktname() const;
    double lieferePreis() const;
};


#endif	/* PRODUKT_H */

