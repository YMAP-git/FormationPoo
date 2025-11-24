#include <iostream>
#include "personnage.h" //Ne pas oublier

using namespace std;

int main()
{
    Personnage david, goliath("Epée aiguisée",20);
    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath attaque david
    david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);

    return 0;
}