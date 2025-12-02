#ifndef DEF_DUREE
#define DEF_DUREE
 
class Duree
{
    public:
 
    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    int getHeures() const;
    int getMinutes() const;
    int getSecondes() const;
    void afficher() const;
    Duree operator+(const Duree& autre) const;
    bool operator==(const Duree& autre) const;
 
    private:
    int m_heures;
    int m_minutes;
    int m_secondes;
};
 
#endif