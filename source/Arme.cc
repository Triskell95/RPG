#include "Arme.h"

Arme::Arme() : m_nom("Epée rouillée"), m_degats(3)
{

}

//--------------------------------------------------------------------------

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

//--------------------------------------------------------------------------

Arme::~Arme()
{

}

//--------------------------------------------------------------------------

void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
}

//--------------------------------------------------------------------------

void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl;
}

//--------------------------------------------------------------------------

int Arme::getDegats() const
{
    return m_degats;
}

//--------------------------------------------------------------------------

string Arme::getNom() const
{
    return m_nom;
}
