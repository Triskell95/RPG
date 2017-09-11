#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN

#include <iostream>
#include <string>
#include "Personnage.h"

class Magicien : public Personnage
{
    public:
        Magicien();
        Magicien(string nom);
        Magicien(string nom, string nomArme, int degats);
        Magicien(                       string nom,
                                        string nomArme,
                                        int degatsArme,
                                        int vie_initiale,
                                        int mana_initial,
                                        int endurance_initiale,
                                        int armure,
                                        string posture,
                                        int force,
                                        int mental,
                                        int social,
                                        int agilite,
                                        float resistanceFeu,
                                        float resistanceFroid
                              );
        Magicien *Clone();
        ~Magicien();

        virtual void agir(Personnage &cible);
        void bouleDeFeu(Personnage &cible);
        void bouleDeGlace(Personnage &cible);
        void delugeDeFeu(Personnage &cible);
        void sePresenter() const;

        string getClasse() const {
            return "Magicien";
        }

    private:
};

#endif
