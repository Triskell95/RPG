#include "Guerrier.h"


Guerrier::Guerrier() : Personnage()
{
    setVie(25);
    setMana(10);
    changerPosture(E_OFFENSIF);
    setArmure(6);
    setForce(6);
    setMental(3);
    setSocial(3);
    setAgilite(2);
    setResistanceFeu(1.2);
    setResistanceFroid(0.9);
}

//--------------------------------------------------------------------------

Guerrier::Guerrier(string nom) : Personnage(nom)
{
    setVie(25);
    setMana(10);
    changerPosture(E_OFFENSIF);
    setArmure(6);
    setForce(6);
    setMental(3);
    setSocial(3);
    setAgilite(2);
    setResistanceFeu(1.2);
    setResistanceFroid(0.9);
}

//--------------------------------------------------------------------------

Guerrier::Guerrier(string nom, string nomArme, int degats) : Personnage(nom, nomArme, degats)
{
    setVie(25);
    setMana(10);
    changerPosture(E_OFFENSIF);
    setArmure(6);
    setForce(6);
    setMental(3);
    setSocial(3);
    setAgilite(2);
    setResistanceFeu(1.2);
    setResistanceFroid(0.9);
}

//--------------------------------------------------------------------------

Guerrier::Guerrier(             string nom,
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
                      ) : Personnage(nom, nomArme, degatsArme, vie_initiale, mana_initial, armure, posture, force, mental, social, agilite, resistanceFeu, resistanceFroid)
{
}

//--------------------------------------------------------------------------

Guerrier* Guerrier::Clone()
{
    return new Guerrier(*this);
}

//--------------------------------------------------------------------------

Guerrier::~Guerrier()
{

}

//--------------------------------------------------------------------------

void Guerrier::agir(Personnage &cible)
{
    int choix = 0;

    cout << "Que doit faire " << CBOLD << getNom() << CDEFAULT << " ?" << endl;
    cout << "\t1 - Se servir de " << getArme()->getNom() << endl;
    cout << "\t2 - Coup de poing" << endl;
    cout << "\t3 - Frapper comme un sourd au marteau de guerre" << endl;
    cout << "\t4 - Changer de posture" << endl;
    cout << "\t5 - Boire une potion de soin" << endl;

    cin >> choix;

    switch(choix)
    {
        case 1:
            attaquer(cible);
            break;

        case 3:
            frapperCommeUnSourdAvecUnMarteau(cible);
            break;

        case 4:
            cout << "Quelle posture adopter ?" << endl;
            cout << "1-Offensif    2-Defensif    3-Focus" << endl;
            cin >> choix;
            if(choix < 1 and choix > 3)
                choix = 2;
            changerPosture(EPosture(choix-1));
            break;

        case 5:
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

void Guerrier::frapperCommeUnSourdAvecUnMarteau(Personnage &cible) const
{
    cout << endl << CBOLD << getNom() << CDEFAULT << " frappe " << CBOLD << cible.getNom() << CDEFAULT << " comme un sourd avec un marteau" << endl;

    cout << "Ca va toucher ? ";
    ETest strTest = test(getForce(), 10);

    if( strTest == E_SUCCESCRITIQUE or strTest == E_SUCCES )
    {
        cible.recevoirDegats( 3 * getForce(), true );
    }
}

//--------------------------------------------------------------------------

void Guerrier::sePresenter() const
{
    Personnage::sePresenter();
    cout << "Je suis " << getNom() << ", un Guerrier redoutable." << endl;
}
