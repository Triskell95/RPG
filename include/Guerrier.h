#ifndef DEF_GUERRIER
#define DEF_GUERRIER

#include <iostream>
#include <string>
#include "Personnage.h"
//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !

class Guerrier : public Personnage
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{

    public:
        Guerrier();
        Guerrier(string nom);
        Guerrier(string nom, string nomArme, int degats);
        Guerrier(                       string nom,
                                        string nomArme,
                                        int degatsArme,
                                        int vie_initiale,
                                        int mana_initial,
                                        int armure,
                                        string posture,
                                        int force,
                                        int mental,
                                        int social,
                                        int agilite,
                                        float resistanceFeu,
                                        float resistanceFroid
                              );
        Guerrier* Clone();
        ~Guerrier();

        virtual void agir(Personnage &cible);
        void frapperCommeUnSourdAvecUnMarteau(Personnage &cible) const;
        void sePresenter() const;

        string getClasse() const {
            return "Guerrier";
        }

    private:

};

#endif
