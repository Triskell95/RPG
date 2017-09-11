#include "Magicien.h"

Magicien::Magicien() : Personnage()
{
    setVie(15);
    setMana(15);
    setEndurance(10);
    changerPosture(E_DEFENSIF);
    setArmure(4);
    setForce(2);
    setMental(6);
    setSocial(5);
    setAgilite(3);
    setResistanceFeu(1.2);
    setResistanceFroid(0.8);
}

//--------------------------------------------------------------------------

Magicien::Magicien(string nom) : Magicien()
{
    this->setNom(nom);
}

//--------------------------------------------------------------------------

Magicien::Magicien(string nom, string nomArme, int degats) : Magicien(nom)
{
    this->changerArme(nomArme, degats);
}

//--------------------------------------------------------------------------

Magicien::Magicien(             string nom,
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
                      ) : Personnage(nom, nomArme, degatsArme, vie_initiale, mana_initial, endurance_initiale, armure, posture, force, mental, social, agilite, resistanceFeu, resistanceFroid)
{
}

//--------------------------------------------------------------------------

Magicien* Magicien::Clone()
{
    return new Magicien(*this);
}

//--------------------------------------------------------------------------

Magicien::~Magicien()
{

}

//--------------------------------------------------------------------------

void Magicien::agir(Personnage &cible)
{
    int choix = 0;

    cout << "Que doit faire " << CBOLD << getNom() << CDEFAULT << " ?" << endl;
    cout << "\t1 - Se servir de " << getArme()->getNom() << " (-" << ((getForce()+getAgilite())/2) << " endu)" << endl;
    cout << "\t2 - Coup de poing  (-2 endu)" << endl;
    cout << "\t3 - Boule de feu   (-4 mana)" << endl;
    cout << "\t4 - Boule de glace (-4 mana)" << endl;
    cout << "\t5 - Déluge de feu  (-8 mana)" << endl;
    cout << "\t6 - Changer de posture" << endl;
    cout << "\t7 - Boire une potion de soin" << endl;

    cin >> choix;

    switch(choix)
    {
        case 1:
            attaquer(cible);
            break;

        case 3:
            bouleDeFeu(cible);
            break;

        case 4:
            bouleDeGlace(cible);
            break;

        case 5:
            delugeDeFeu(cible);
            break;

        case 6:
            cout << "Quelle posture adopter ?" << endl;
            cout << "1-Offensif    2-Defensif    3-Focus" << endl;
            cin >> choix;
            if(choix < 1 and choix > 3)
                choix = 2;
            changerPosture(EPosture(choix-1));
            break;

        case 7:
            boirePotionDeVie(5 + rand()%8);
            break;

        case 2:
        default:
            coupDePoing(cible);
            break;
    }
    cout << endl;
}

//--------------------------------------------------------------------------

void Magicien::bouleDeFeu(Personnage &cible)
{
    if(getMana() > 0)
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " envoie une boule de feu dans la face de " << CBOLD << cible.getNom() << CDEFAULT << endl;

        ETest strTest;

        if( not this->utiliserMana(4))
        {
            return;
        }

        cout << "Ca va toucher ? ";
        strTest = test(getMental(), 10);

        if(strTest == E_SUCCESCRITIQUE or strTest == E_SUCCES )
        {
            cible.recevoirDegats((int)( 2.0 * cible.getResistanceFeu() * ( (float)getMental() ) ), true);
        }
        else if(strTest == E_ECHECCRITIQUE)
        {
            recevoirDegats(2, false);
        }
    }
    else
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " n'a pas assez de mana !" << CDEFAULT << endl;
    }
}

//--------------------------------------------------------------------------

void Magicien::bouleDeGlace(Personnage &cible)
{
    if(getMana() > 0)
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " envoie une boule de glace dans la face de " << CBOLD << cible.getNom() << CDEFAULT << endl;

        ETest strTest;

        if( not this->utiliserMana(4))
        {
            return;
        }

        cout << "Ca va toucher ? ";
        strTest = test(getMental(), 10);

        if(strTest == E_SUCCESCRITIQUE or strTest == E_SUCCES )
        {
            cible.recevoirDegats((int)( 2.0 * cible.getResistanceFroid() * ( (float)getMental() ) ), true);
            cible.utiliserEndurance(1);
        }
        else if(strTest == E_ECHECCRITIQUE)
        {
            recevoirDegats(2, false);
        }
    }
    else
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " n'a pas assez de mana !" << CDEFAULT << endl;
    }
}

//--------------------------------------------------------------------------

void Magicien::delugeDeFeu(Personnage &cible)
{
    if(getMana() > 0)
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " provoque un déluge de feu sur " << CBOLD << cible.getNom() << CDEFAULT << endl;

        ETest strTest;

        if( not this->utiliserMana(8))
        {
            return;
        }

        cout << "Ca va toucher ? ";
        strTest = test(getMental(), 10);

        if(strTest == E_SUCCESCRITIQUE or strTest == E_SUCCES )
        {
            cible.recevoirDegats((int)( 3.0 * cible.getResistanceFeu() * ( (float)getMental() ) ), false);
        }
        else if(strTest == E_ECHECCRITIQUE)
        {
            recevoirDegats(4, false);
        }

    }
    else
    {
        cout << endl << CBOLD << getNom() << CDEFAULT << " n'a pas assez de mana !" << CDEFAULT << endl;
    }
}

//--------------------------------------------------------------------------

void Magicien::sePresenter() const
{
    Personnage::sePresenter();
    cout << "Je suis " << getNom() << ", un Magicien formidable." << endl;
}
