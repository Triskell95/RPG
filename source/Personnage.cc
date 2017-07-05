#include "Personnage.h"

Personnage::Personnage() : m_vie_initiale(15), m_mana_initial(10), m_armure(2)
{
    srand(time(0));
    m_arme = new Arme();
    m_vie             = m_vie_initiale;
    m_mana            = m_mana_initial;
    m_posture         = E_DEFENSIF;
    m_force           = 3;
    m_mental          = 3;
    m_social          = 3;
    m_agilite         = 3;
    m_resistanceFeu   = 1;
    m_resistanceFroid = 1;
}

//--------------------------------------------------------------------------

Personnage::Personnage(string nom) : m_nom(nom), m_vie_initiale(15), m_mana_initial(10), m_armure(2)
{
    srand(time(0));
    m_arme = new Arme();
    m_vie             = m_vie_initiale;
    m_mana            = m_mana_initial;
    m_posture         = E_DEFENSIF;
    m_force           = 3;
    m_mental          = 3;
    m_social          = 3;
    m_agilite         = 3;
    m_resistanceFeu   = 1;
    m_resistanceFroid = 1;
}

//--------------------------------------------------------------------------

Personnage::Personnage(string nom, string nomArme, int degatsArme) : m_nom(nom), m_vie_initiale(15), m_mana_initial(10), m_armure(2)
{
    srand(time(0));
    m_arme = new Arme(nomArme, degatsArme);
    m_vie             = m_vie_initiale;
    m_mana            = m_mana_initial;
    m_posture         = E_DEFENSIF;
    m_force           = 3;
    m_mental          = 3;
    m_social          = 3;
    m_agilite         = 3;
    m_resistanceFeu   = 1;
    m_resistanceFroid = 1;
}

//--------------------------------------------------------------------------

Personnage::Personnage( string nom,
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
                      ) : m_nom(nom), m_vie_initiale(vie_initiale), m_vie(vie_initiale), m_mana_initial(mana_initial), m_mana(mana_initial),
                              m_armure(armure), m_force(force), m_mental(mental), m_social(social), m_agilite(agilite), m_resistanceFeu(resistanceFeu), m_resistanceFroid(resistanceFroid)
{
    srand(time(0));
    m_arme = new Arme(nomArme, degatsArme);

    if(posture == "ATT")
    {
        m_posture = E_OFFENSIF;
    }
    else if(posture == "DEF")
    {
        m_posture = E_DEFENSIF;
    }
    else if(posture == "FOC")
    {
        m_posture = E_FOCUS;
    }
    else
    {
        m_posture = E_OFFENSIF;
    }

}

//--------------------------------------------------------------------------

Personnage::Personnage(Personnage* const& personnageACopier): m_vie_initiale(personnageACopier->m_vie), m_mana_initial(personnageACopier->m_mana), m_armure(personnageACopier->m_armure)
{
    srand(time(0));
    m_nom        = personnageACopier->m_nom;
    m_arme       = new Arme(*(personnageACopier->m_arme));
    m_vie        = personnageACopier->m_vie        ;
    m_mana       = personnageACopier->m_mana       ;
    m_posture    = personnageACopier->m_posture    ;
    m_force      = personnageACopier->m_force      ;
    m_mental     = personnageACopier->m_mental     ;
    m_social     = personnageACopier->m_social     ;
    m_agilite    = personnageACopier->m_agilite    ;
    m_resistanceFeu = personnageACopier->m_resistanceFeu;
    m_resistanceFroid = personnageACopier->m_resistanceFroid;

}

//--------------------------------------------------------------------------

Personnage* Personnage::Clone()
{
    return new Personnage(*this);
}

//--------------------------------------------------------------------------

Personnage::~Personnage()
{
    delete m_arme;
}

//--------------------------------------------------------------------------

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
    if(this != &personnageACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_nom        = personnageACopier.m_nom;
        m_vie_initiale = personnageACopier.m_vie_initiale;
        m_mana_initial = personnageACopier.m_mana_initial;
        m_vie        = personnageACopier.m_vie        ;
        m_mana       = personnageACopier.m_mana       ;
        m_posture    = personnageACopier.m_posture    ;
        m_force      = personnageACopier.m_force      ;
        m_mental     = personnageACopier.m_mental     ;
        m_social     = personnageACopier.m_social     ;
        m_agilite    = personnageACopier.m_agilite    ;
        m_resistanceFeu = personnageACopier.m_resistanceFeu;
        m_resistanceFroid = personnageACopier.m_resistanceFroid;
        delete m_arme;
        m_arme = new Arme(*(personnageACopier.m_arme));
    }
    return *this; //On renvoie l'objet lui-même
}

//--------------------------------------------------------------------------

//---------- ACTIONS ----------------------

void Personnage::agir(Personnage &cible)
{
    int choix = 0;

    cout << "Que doit faire " << CBOLD << m_nom << CDEFAULT << " ?" << endl;
    cout << "\t1 - Se servir de " << m_arme->getNom() << endl;
    cout << "\t2 - Coup de poing" << endl;
    cout << "\t3 - Changer de posture" << endl;
    cout << "\t4 - Boire une potion de soin" << endl;

    cin >> choix;

    switch(choix)
    {
        case 1:
            attaquer(cible);
            break;

        case 3:
            cout << "Quelle posture adopter ?" << endl;
            cout << "1-Offensif    2-Defensif    3-Focus" << endl;
            cin >> choix;
            if(choix < 1 and choix > 3)
                choix = 2;
            changerPosture(EPosture(choix-1));
            break;

        case 4:
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

void Personnage::recevoirDegats(int nbDegats, bool droitEsquiver)
{
    //Test de parade/esquive
    if(m_posture == E_DEFENSIF and droitEsquiver)
    {
        cout << "Tentative d'esquive de " << CBOLD << m_nom << CDEFAULT << ": ";
        ETest strTest = test(m_agilite, 10);

        if ( strTest == E_SUCCESCRITIQUE or strTest == E_SUCCES )
        {
            cout << CBOLD << m_nom << CDEFAULT << " esquive !" << endl;
            return;
        }
    }

    bool coupCritique = ( rand()%100 <= 10 );
    int multiplicateur = 1;

    if(coupCritique)
    {
        cout << CBOLD << CRED << "COUP CRITIQUE !" << CDEFAULT << endl;
        multiplicateur = 2;
    }

    int degatsReels = (nbDegats* multiplicateur) - m_armure;

    if(degatsReels < 1)
    {
        degatsReels = 1;
    }

    cout << CBOLD << m_nom << CDEFAULT << " prend " << CRED << degatsReels << CDEFAULT << " de dégats" << endl;
    m_vie -= degatsReels;

    if(m_vie < 0){
        m_vie = 0;
    }

    estVivant();
}

//--------------------------------------------------------------------------

void Personnage::attaquer(Personnage &cible)
{
    cout << endl << CBOLD << m_nom << CDEFAULT << " attaque " << CBOLD << cible.m_nom << CDEFAULT << " avec " << m_arme->getNom() << endl;

    ETest strTest;

    cout << "Ca va toucher ? ";
    strTest = test(m_force, 10);

    if( strTest == E_SUCCESCRITIQUE )
    {
        cible.recevoirDegats( 2 * (float)m_arme->getDegats() * float( 1.0 + (( m_force ) / 10.0 )), true );
    }
    else if( strTest == E_SUCCES)
    {
        cible.recevoirDegats( (float)m_arme->getDegats() * float( 1.0 + (( m_force ) / 10.0 )), true );
    }
    else if( strTest == E_ECHECCRITIQUE )
    {
        cout << CBOLD << m_nom << CDEFAULT << " se blesse en ratant..." << endl;
        recevoirDegats(2, false);
    }
}

//--------------------------------------------------------------------------

void Personnage::coupDePoing(Personnage &cible)
{
    cout << CBOLD << m_nom << CDEFAULT << " essaye de patater " << CBOLD << cible.getNom() << CDEFAULT << " dans la bouche"<< endl;
    cible.recevoirDegats(m_force, true);
}

//--------------------------------------------------------------------------

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if(m_vie > m_vie_initiale)
    {
        m_vie = m_vie_initiale;
    }
}

//--------------------------------------------------------------------------

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
}

//--------------------------------------------------------------------------

void Personnage::changerPosture(EPosture posture)
{
    m_posture = posture;
}

//--------------------------------------------------------------------------

bool Personnage::estVivant() const
{
    bool bRet = (m_vie > 0);

    if(bRet)
    {
        cout << CBOLD << m_nom << CDEFAULT << " est toujours debout, toujours vivant ! (" << m_vie << "/" << m_vie_initiale << ")" << endl;
    }
    else
    {
        cout << CBOLD << m_nom << CDEFAULT << " est " << CRED << " DECEDE !" << CDEFAULT << endl;
    }

    return bRet;
}

//--------------------------------------------------------------------------

bool Personnage::estVivantNoPrint() const
{
    return (m_vie > 0);
}

//--------------------------------------------------------------------------

void Personnage::utiliserMana(int mana)
{
    m_mana -= mana;

    if(m_mana < 0)
    {
        m_mana = 0;
    }
}

//--------------------------------------------------------------------------

void Personnage::recupererMana(int mana)
{
    m_mana += mana;

    if(m_mana > m_mana_initial)
    {
        m_mana = m_mana_initial;
    }
}

//--------------------------------------------------------------------------

void Personnage::afficherEtat() const
{
    cout << "====================================" << endl;
    cout << CBOLD << "\t\t" << m_nom << CDEFAULT << endl;
    cout << CRED <<  "Vie  : " << m_vie << CDEFAULT << endl;
    cout << CBLUE << "Mana : " << m_mana << CDEFAULT << endl;
    cout << CGREEN;
    m_arme->afficher();
    cout << CDEFAULT;
    cout << "====================================" << endl;

}

//--------------------------------------------------------------------------

void Personnage::sePresenter() const
{
    cout << "====================================" << endl;
    cout << "Bonjour, je m'appelle " << m_nom << "." << endl;
    cout << "J'ai encore " << m_vie << " points de vie." << endl;
    cout << "====================================" << endl;

}

//--------------------------------------------------------------------------

void Personnage::stats() const
{
    string arrPosture[3] = { "ATT", "DEF" ,"FOC" };
    string str = "==========================================================================================";
    string strClasse;

    cout << str << endl;

    //Premiere ligne:
    for(unsigned int i = 0; i < (str.length()-m_nom.length())/2; i++)
    {
        cout << " ";
    }
    cout << CBOLD << m_nom << CDEFAULT << endl;

    //Deuxieme ligne:
    strClasse = " (" + getClasse() + ")";
    for(unsigned int i = 0; i < (str.length()-strClasse.length())/2; i++)
    {
        cout << " ";
    }
    cout << strClasse << endl;

    //Troisieme ligne:
    cout << endl;
    cout << CRED <<  "   Vie:    " << setfill(' ') << setw(5) << m_vie << CDEFAULT << CBLUE << "\t      Mana:    " << setfill(' ') << setw(5) << m_mana << CDEFAULT << CGREEN << "\t       ";
    m_arme->afficher();
    cout << CDEFAULT;

    //Quatrieme ligne:
    cout << CRED << "   Force:  " << setfill(' ') << setw(5) << m_force << CBLUE << "\t      Mental:  " << setfill(' ') << setw(5) << m_mental << CGREEN << "\t       Social: " << m_social << CDEFAULT<< endl;

    //Cinquieme ligne:
    cout << CRED << "   Armure: " << setfill(' ') << setw(5) << m_armure << CBLUE << "\t      Posture: " << setfill(' ') << setw(5) << arrPosture[m_posture] << CDEFAULT << endl;

    //Sixieme ligne:
    cout << "   " << CRED << "Feu:      " << setfill(' ') << setw(3) << (float)(m_resistanceFeu-1.0)*100 << " %" << CBLUE << "\t      Froid:     " << setfill(' ') << setw(3) << (float)(m_resistanceFroid-1.0)*100.0 << " %" << CDEFAULT << endl;

    cout << endl;
    cout << str << endl;
}

//--------------------------------------------------------------------------

ETest Personnage::test(int caracteristique, int modulo) const
{
    int randomNb = rand()%modulo +1;

    if( randomNb <= modulo*0.05 or randomNb == 1 )
    {
        cout << CBOLD << CGREEN << "SUCCES CRITIQUE !" << CDEFAULT << " avec " << randomNb << " pour " << caracteristique << "/" << modulo << endl;
        return E_SUCCESCRITIQUE;
    }
    else if( randomNb >= modulo*0.95 or randomNb == modulo )
    {
        cout << CBOLD << CRED << "ECHEC CRITIQUE !" << CDEFAULT << " avec " << randomNb << " pour " << caracteristique << "/" << modulo  << endl;
        return E_ECHECCRITIQUE;
    }
    else if( randomNb <= caracteristique )
    {
        cout << CGREEN << "CA PASSE !" << CDEFAULT << " avec " << randomNb << " pour " << caracteristique << "/" << modulo << endl;
        return E_SUCCES;
    }
    else
    {
        cout << CRED << "C'EST UN ECHEC ! Dommage..." << CDEFAULT << " avec " << randomNb << " pour " << caracteristique << "/" << modulo << endl;
        return E_ECHEC;
    }

    return E_NONE;
}
