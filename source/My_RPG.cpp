//============================================================================
// Name        : My_RPG.cpp
// Author      : Thibaut DA SILVA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>

#include "Personnage.h"
#include "Guerrier.h"
#include "Magicien.h"

string G_NOM_RPG = "ARENA-RPG OF DOOM";

//string strJ1 = CBLUE << "J1" << CDEFAULT;
//string strJ2 = CRED  << "J2" << CDEFAULT;

using namespace std;

Personnage* choixPersonnage(vector<Personnage*> list, string strJoueur)
{
    unsigned int choix = 0;
    Personnage* perso;

    cout << strJoueur << " - Choisissez un personnage:" << endl;
    for(unsigned int i = 0; i < list.size(); i++)
    {
        cout << "\t" << i+1 << " - " << list[i]->getNom() << endl;
    }
    cout << "\t" << list.size()+1 << " - Détails sur les personnages" << endl;

    //Choix de l'utilisateur
    cin >> choix;

    //Si le choix est dans la liste
    if(choix-1 >= 0 and choix-1 < list.size())
    {
        //Copie du personnage pour l'associer au joueur
        perso = list[choix-1]->Clone();
    }
    else if(choix-1 == list.size())
    {
        for(unsigned int i = 0; i < list.size(); i++)
        {
            list[i]->stats();
        }
        cout << endl;
        perso = choixPersonnage(list, strJoueur);
    }
    else
    {
        //Choix par défaut: random
        cout << "Choix non valide ! (" << choix << ")" << endl;
        srand(time(0));
        int randomNb = rand()%(list.size());
        cout << CBOLD << list[randomNb]->getNom() << CDEFAULT << " (" << randomNb+1 << ") pris par defaut" << endl;
        perso = list[randomNb];
    }
    return perso;
}

void fnNouveauTour(vector<Personnage*> listPerso)
{
    Personnage* persoJ1;
    Personnage* persoJ2;

    persoJ1 = choixPersonnage(listPerso, "J1");
    persoJ2 = choixPersonnage(listPerso, "J2");

    system("clear");

    string dumb;

    while( persoJ1->estVivantNoPrint() and persoJ2->estVivantNoPrint() )
    {
        system("clear");

        persoJ1->afficherEtat();
        persoJ2->afficherEtat();

        persoJ1->agir(*persoJ2);

        if(persoJ2->estVivantNoPrint())
        {
            persoJ2->agir(*persoJ1);
        }

        persoJ1->recupererMana(5);
        persoJ1->recupererMana(5);

        cout << endl;
        persoJ1->afficherEtat();
        persoJ2->afficherEtat();


        cin >> dumb;
    }
}

int main() {

    system("clear");

    string strBanniere = "==========================================================================================";
    cout << strBanniere << endl;
    cout << endl;
    string strTitre = "Bienvenue dans " + G_NOM_RPG + "!";
    for(unsigned int i = 0; i < (strBanniere.length() - strTitre.length())/2 ; i++)
    {
        cout << " ";
    }
    cout << CBOLD << strTitre << CDEFAULT << endl;
    cout << endl;
    cout << strBanniere << endl;
    cout << endl;

    string filename = "../data/personnages.txt";
    ifstream myfile(filename.c_str(), ifstream::in);
    istringstream iss;

    vector<Personnage*> listPerso;
    bool bRet = false;

    if(!myfile)
    {
        cout << "Impossible d'ouvrir le fichier !\n";

        Guerrier   *dovahkhin = new Guerrier("Dovahkhin", "Dragon Slayer", 8);
        Magicien   *gandalf = new Magicien("Gandalf", "Baton Magique", 6);
        Personnage *clampin = new Personnage("Clampin Lambda");

        listPerso.push_back(dovahkhin);
        listPerso.push_back(gandalf);
        listPerso.push_back(clampin);
    }
    else
    {
        while(not bRet)
        {
            string line;
            getline(myfile, line);
            if(line[0] == '#')
            {
                continue;
            }
            else
            {
                iss.str(line);

                string nom;
                string classe         ;
                string nomArme        ;
                string degatsArme     ;
                string vie_initiale   ;
                string mana_initial   ;
                string armure         ;
                string posture        ;
                string force          ;
                string mental         ;
                string social         ;
                string agilite        ;
                string resistanceFeu  ;
                string resistanceFroid;

                //Récupération des attributs
                if(iss >> nom >> classe >> nomArme >> degatsArme >> vie_initiale >> mana_initial
                        >> armure >> posture >> force >> mental >> social >> agilite >>
                        resistanceFeu >> resistanceFroid)
                {
                    //On crée des personnages en fonction de la classe qui leur est attribuée
                    Personnage *perso;
                    if(classe == "Personnage")
                    {
                        perso = new Personnage( nom, nomArme, atoi(degatsArme.c_str()), atoi(vie_initiale.c_str()),
                                atoi(mana_initial.c_str()), atoi(armure.c_str()), posture.c_str(),
                                atoi(force.c_str()), atoi(mental.c_str()), atoi(social.c_str()), atoi(agilite.c_str()),
                                atof(resistanceFeu.c_str()), atof(resistanceFroid.c_str()) );
                    }
                    else if(classe == "Guerrier")
                    {
                        perso = new Guerrier( nom, nomArme, atoi(degatsArme.c_str()), atoi(vie_initiale.c_str()),
                                atoi(mana_initial.c_str()), atoi(armure.c_str()), posture.c_str(),
                                atoi(force.c_str()), atoi(mental.c_str()), atoi(social.c_str()), atoi(agilite.c_str()),
                                atof(resistanceFeu.c_str()), atof(resistanceFroid.c_str()) );
                    }
                    else if(classe == "Magicien")
                    {
                        perso = new Magicien( nom, nomArme, atoi(degatsArme.c_str()), atoi(vie_initiale.c_str()),
                                atoi(mana_initial.c_str()), atoi(armure.c_str()), posture.c_str(),
                                atoi(force.c_str()), atoi(mental.c_str()), atoi(social.c_str()), atoi(agilite.c_str()),
                                atof(resistanceFeu.c_str()), atof(resistanceFroid.c_str()) );
                    }
                    else
                    {
                        cout << "Erreur: classe \"" << classe << "\" invalide !" << endl;
                        continue;
                    }

                    listPerso.push_back(perso);
                    iss.clear();
                }
                else
                {
                    bRet = true;
                }
            }
        }
    }

    char c;

    do
    {
        fnNouveauTour(listPerso);

        cout << "Voulez-vous continuer ? 1:Oui   2:Non" << endl;

        cin >> c;

        if(c == '1')
        {
            system("clear");
            continue;

        }
        else if(c == '2')
        {
            break;
        }
        else
        {
            cout << "Choix non reconnu entre '1' et '2': par défaut -> Non !" << endl;
            break;
        }

    } while(1);

    for(vector<Personnage*>::iterator i = listPerso.begin(); i != listPerso.end(); i++ )
    {
        delete *i;
    }

    cout << endl;
    cout << strBanniere << endl;
    cout << endl;

    string strMerci = "Encore merci d'avoir joué à " + G_NOM_RPG + " ! :D";
    for(unsigned int i = 0; i < (strBanniere.length() - strMerci.length())/2 ; i++)
    {
        cout << " ";
    }

    cout << CBOLD << strMerci << CDEFAULT << endl;
    cout << endl;
    cout << strBanniere << endl;

    return 0;
}
