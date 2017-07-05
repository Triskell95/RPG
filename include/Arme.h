#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>

using namespace std;

#define CDEFAULT    "\033[0m"

class Arme
{
    public:
        Arme();
        Arme(string nom, int degats);
        ~Arme();
        void changer(string nom, int degats);
        void afficher() const;
        int getDegats() const;
        string getNom() const;

    private:
        string m_nom;
        int m_degats;
};

#endif
