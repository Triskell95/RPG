#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Arme.h"

#define CRED     "\033[31m"
#define CREDBG   "\033[41m"
#define CGREEN   "\033[32m"
#define CGREENBG "\033[42m"
#define CBLUE    "\033[34m"
#define CBLUEBG  "\033[44m"
#define CDEFAULT "\033[0m"
#define CBOLD    "\033[1m"

enum ETest { E_NONE = 0, E_SUCCESCRITIQUE = 1, E_SUCCES = 2, E_ECHEC = 3, E_ECHECCRITIQUE = 4 };
enum EPosture { E_OFFENSIF = 0, E_DEFENSIF = 1, E_FOCUS = 2};

using namespace std;

class Personnage
{
    public:

        //--- CSTR / DSTR ---
        Personnage();
        Personnage(string nom);
        Personnage(string nom, std::string nomArme, int degatsArme);
        Personnage(         string nom,
                            string nomArme,
                            int degatsArme,
                            int vie_initiale,
                            int mana_initial,
                            int endurance_initiale,
                            int armure,
                            string posture,
                            int m_force,
                            int m_mental,
                            int m_social,
                            int m_agilite,
                            float m_resistanceFeu,
                            float m_resistanceFroid
                  );
        Personnage(Personnage* const& autre);
        virtual Personnage* Clone();
        virtual ~Personnage();
        Personnage& operator=(Personnage const& personnageACopier);

        //--- ACTIONS ---
        virtual void agir(Personnage &cible);

        void recevoirDegats(int nbDegats, bool droitEsquiver);
        void attaquer(Personnage &cible);
        void coupDePoing(Personnage &cible);

        void changerArme(string nomNouvelleArme, int degatsNouvelleArme);
        void changerPosture(EPosture posture);

        void recupererMana(int mana);
        bool utiliserMana(int mana);

        void recupererEndurance(int endurance);
        bool utiliserEndurance(int endurance);

        void boirePotionDeVie(int quantitePotion);


        //--- AFFICHAGE ---
        void statsBarre(int nbCarres, string couleur) const;
        void afficherEtat() const;
        void sePresenter() const;
        void stats() const;

        //--- TESTS ---
        ETest test(int caracteristique, int modulo) const;
        bool estVivant() const;
        bool estVivantNoPrint() const;

        //--- GETTERS / SETTERS ---
        string getNom() const {
            return m_nom;
        }
        void setNom(string nom) {
            m_nom = nom;
        }
        virtual string getClasse() const {
            return "Personnage";
        }
        EPosture getPosture() const {
            return m_posture;
        }
        int getVie() const {
            return m_vie;
        }
        void setVie(int vie) {
            m_vie = vie;
        }
        int getMana() const {
            return m_mana;
        }
        void setMana(int mana) {
            m_mana = mana;
        }
        int getEndurance() const {
            return m_endurance;
        }
        void setEndurance(int endurance) {
            m_endurance = endurance;
        }
        int getArmure() const {
            return m_armure;
        }
        void setArmure(int armure) {
            m_armure = armure;
        }
        int getForce() const {
            return m_force;
        }
        void setForce(int force) {
            m_force = force;
        }
        int getMental() const {
            return m_mental;
        }
        void setMental(int mental) {
            m_mental = mental;
        }
        int getSocial() const {
            return m_social;
        }
        void setSocial(int social) {
            m_social = social;
        }
        int getAgilite() const {
            return m_agilite;
        }
        void setAgilite(int agilite) {
            m_agilite = agilite;
        }
        float getResistanceFeu() const {
            return m_resistanceFeu;
        }
        void setResistanceFeu(int resistanceFeu) {
            m_resistanceFeu = resistanceFeu;
        }
        float getResistanceFroid() const {
            return m_resistanceFroid;
        }
        void setResistanceFroid(int resistanceFroid) {
            m_resistanceFroid = resistanceFroid;
        }
        Arme* getArme() const {
            return m_arme;
        }
    private:

        //caracteristiques
        string m_nom;
        int m_vie_initiale;
        int m_vie;
        int m_mana_initial;
        int m_mana;
        int m_endurance_initiale;
        int m_endurance;
        int m_armure;
        Arme *m_arme;
        EPosture m_posture;

        //stats
        int m_force;
        int m_mental;
        int m_social;
        int m_agilite;
        float m_resistanceFeu;
        float m_resistanceFroid;
};

#endif
