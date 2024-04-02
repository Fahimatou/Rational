#include <string>
using namespace std;
#ifndef RATIONNEL_H
#define RATIONNEL_H

// Définition de la classe
class Rationnel
{
    // Déclaration surcharche flux entrée  >> (cin)
    friend std::istream& operator>>(std::istream&,  Rationnel&);     

    // Déclaration surcharche flux sortie  << (cout)
    friend std::ostream& operator<<(std::ostream&, const Rationnel&);  

    // Surcharge des opérateurs arithmétiques
    friend const Rationnel operator+(const int, const Rationnel&);      // Number + Rationnek 
    friend const Rationnel operator-(const int, const Rationnel&);
    friend const Rationnel operator*(const int, const Rationnel&);
    friend const Rationnel operator/(const int, const Rationnel&);


    // Surcharge des opérateurs relationnels
    friend bool operator==(const int, const Rationnel&);				// Number == Rationnel
    friend bool operator!=(const int, const Rationnel&);				// int != Rationnel

    friend bool operator<(const int, const Rationnel&);
    friend bool operator>(const int, const Rationnel&);
    friend bool operator<=(const int, const Rationnel&);
    friend bool operator>=(const int, const Rationnel&);


public:
    Rationnel();
    Rationnel(int, int);
    Rationnel( int n);
    /* destructeur:
     ~Rationnel();  */

     // Surcharge des opérateurs d'affectation
    const Rationnel& operator=(const Rationnel&);					// Rationnel = Rationnel
    const Rationnel& operator=(const int);							// Rationnel = int
    const Rationnel& operator+=(const Rationnel&);					// Rationnel += Rationnel
    const Rationnel& operator+=(const int);							// Rationnel += int
    const Rationnel& operator-=(const Rationnel&);					// Rationnel -= Rationnel
    const Rationnel& operator-=(const int);							// Rationnel -= int
    const Rationnel& operator*=(const Rationnel&);					// Rationnel *= Rationnel
    const Rationnel& operator*=(const int);					        // Rationnel *= Rationnel
    const Rationnel& operator/=(const Rationnel&);					// Rationnel /= Rationnel
    const Rationnel& operator/=(const int);							// Rationnel /= int
    const Rationnel& operator++();                                  // Pré-incrémentation (++var)
    const Rationnel  operator++(const int);                         // Post-incrémentation (var++)
    const Rationnel& operator--();                                  // Pré-décrémentation (++var)
    const Rationnel  operator--(const int);                         // Post-décrémentation (var++)




    //Surcharge des opérateurs arithmétiques
    const Rationnel operator+(const Rationnel&) const;              //Object + object	
    const Rationnel operator+(const int) const;                     //Obect + number 
    const Rationnel operator- (const Rationnel&) const;
    const Rationnel operator-(const int) const;
    const Rationnel operator* (const Rationnel&) const;
    const Rationnel operator*(const int) const;
    const Rationnel operator/( const Rationnel&) const;
    const Rationnel operator/(const int) const;


    // Surcharge des opérateurs relationnels
    bool operator==(const Rationnel&) const;					    // Rationnel == Rationnel
    bool operator==(const int) const;							    // Rationnel == int
    bool operator!=(const Rationnel&) const;						// Rationnel != Rationnel
    bool operator!=(const int) const;                               // Rationnel != int
    
    bool operator<(const Rationnel&) const;					        // Rationnel < Rationnel
    bool operator<(const int) const;							    // Rationnel < int

    bool operator<=(const Rationnel&) const;					    // Rationnel <= Rationnel
    bool operator<=(const int) const;							    // Rationnel <= int

    bool operator>(const Rationnel&) const;					        // Rationnel > Rationnel
    bool operator>(const int) const;							    // Rationnel > int

    bool operator>=(const Rationnel&) const;					    // Rationnel >= Rationnel
    bool operator>=(const int) const;							    // Rationnel >= int

    //INSERER PROTOTYPES DES FONCTIONS MEMBRES ICI
public:
    
    void simplification();
    void afficherRationnel(const char* chaine, Rationnel& r);
    int pgcd(int a, int b);
    void additionner(const Rationnel& r);
    void soustraire(const Rationnel& r);
    void multiplier(const Rationnel& r);
    void diviser(const Rationnel& r);
    void affichageFraction();
    void affichageFlottant();
   // int getNumerateur() const;
   // int getDenominateur() const;
  

    			


    





    //Attributs membres
private:
    int denominateur;
    int numerateur;
};



#endif // !Rationnel.h

