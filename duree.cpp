#include "duree.h"
#include <iostream>
 
Duree::Duree(int heures, int minutes, int secondes)
{
    if (secondes >= 60)
    {
        minutes += secondes / 60;
        secondes = secondes % 60;
    }
    if (minutes >= 60)
    {
        heures += minutes / 60;
        minutes = minutes % 60;
    }
    m_heures = heures;
    m_minutes = minutes;
    m_secondes = secondes;
}
int Duree::getHeures() const { return m_heures; }
int Duree::getMinutes() const { return m_minutes; }
int Duree::getSecondes() const { return m_secondes; }
void Duree::afficher() const{
    std::cout << m_heures << " heures, " << m_minutes << " minutes et " << m_secondes << " secondes." << std::endl;
}
Duree Duree::operator+(const Duree& autre) const{
    int totalSecondes = m_secondes + autre.m_secondes;
    int totalMinutes = m_minutes + autre.m_minutes;
    int totalHeures = m_heures + autre.m_heures;

    if (totalSecondes >= 60)
    {
        totalMinutes += totalSecondes / 60;
        totalSecondes = totalSecondes % 60;
    }
    if (totalMinutes >= 60)
    {
        totalHeures += totalMinutes / 60;
        totalMinutes = totalMinutes % 60;
    }
    return Duree(totalHeures, totalMinutes, totalSecondes);
}