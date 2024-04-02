#include "Rationnel.h" 
using namespace std;
#include <iostream>
#include <string>


//Surcharge >>
std::istream& operator>>(std::istream& in, Rationnel& rationnel) {
    char separateur;
    in >> rationnel.numerateur >> separateur >> rationnel.denominateur;

    rationnel.simplification();
    return in;
}

//surcharge <<
std::ostream& operator<<(std::ostream& out, const Rationnel& rationnel) {

    out << rationnel.numerateur << "/"<< rationnel.denominateur;
   
    return out;
    }



// Post-incr�mentation (var--)
const Rationnel Rationnel::operator--(const int)
{
    Rationnel temp(*this); //cr�er une copie 
    this->numerateur -= this->denominateur; //additionner 1 � une fraction revient � additionner son d�nominateur
    //� son num�rateur;
    return temp;

}


// Pr�-d�cr�mentation (--var)
const Rationnel& Rationnel::operator--() {
    this->numerateur -= this->denominateur; //additionner 1 � une fraction revient � additionner son d�nominateur
    //� son num�rateur;
    return *this;
    
}


// Post-d�cr�mentation (var++)
const Rationnel Rationnel::operator++(const int)
{
    Rationnel temp(*this); //cr�er une copie 
    this->numerateur += this->denominateur; //additionner 1 � une fraction revient � additionner son d�nominateur
    //� son num�rateur;
    return temp;

}


// Pr�-incr�mentation (++var)
const Rationnel& Rationnel::operator++() {
    this->numerateur += this->denominateur; //additionner 1 � une fraction revient � additionner son d�nominateur
    //� son num�rateur;
    return *this;

}








// Rationnel + Rationnel
const Rationnel Rationnel::operator+(const Rationnel& droite) const {
    // Cr�er une nouvelle instance pour h�berger le r�sultat
    Rationnel resultat(this->numerateur, this->denominateur);

    // Effectuer l'addition (la r�duction est effectu�e par la fonction auxiliaire)
    resultat.additionner(droite);

    return resultat;
}


// Rationnel + Number
const Rationnel Rationnel::operator+(const int droite) const {
    // Cr�er une nouvelle instance initialis�e � droite convertie en fraction
    Rationnel resultat(droite);

    // Invoquer Rationnel::operator+( Rationnel )
    return *this + resultat;
}

//Number + Rationnel
const Rationnel operator+(const int gauche, const Rationnel& droite) {
    // Invoquer Rationnel::operator+( Rationnel )
    return Rationnel(gauche) + droite;
}

// Rationnel - Rationnel
const Rationnel Rationnel::operator-(const Rationnel& droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);

    // Effectuer l'addition (la r�duction est effectu�e par la fonction auxiliaire)
    resultat.soustraire(droite);

    return resultat;
}

// Rationnel - Number
const Rationnel Rationnel::operator-(const int droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);
    Rationnel nombre(droite);
    
    return resultat - nombre;
   
}


// Number - Rationnel
const Rationnel operator-(const int gauche , const Rationnel& droite)
{
   
    return Rationnel(gauche) - droite;
}



//Rationnel * Rationnel
const Rationnel Rationnel::operator*(const Rationnel& droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);
    resultat.multiplier(droite);

    return resultat;
}

//Rationnel * Number
const Rationnel Rationnel::operator*(const int droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);

    return resultat * Rationnel(droite);
}

//Number * Rationnel
const Rationnel operator*(const int gauche , const Rationnel& droite)
{

    return droite * gauche;
}


//Rationnel / Rationnel
const Rationnel Rationnel::operator/(const Rationnel& droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);

    resultat.diviser(droite);

    return resultat ;
}

//Rationnel / number
const Rationnel Rationnel::operator/(const int droite) const
{
    Rationnel resultat(this->numerateur, this->denominateur);

    return resultat / Rationnel(droite);
}
//Number / Rationnel
const Rationnel operator/(const int gauche, const Rationnel& droite)
{
    return Rationnel(gauche) / droite;
}


// Rationnel = Rationnel
const Rationnel& Rationnel::operator=(const Rationnel& droite) {
    
    this->numerateur = droite.numerateur;
    this->denominateur = droite.denominateur;

    return *this;
} 

// Rationnel = Number
const Rationnel& Rationnel::operator=(const int droite) {
    
    *this = Rationnel(droite);
    return *this;
}



// Rationnel += Rationnel
const Rationnel& Rationnel::operator+=(const Rationnel& droite) {
    
    *this = *this + droite;
    return *this;
}
// Rationnel += Number
const Rationnel& Rationnel::operator+=(const int droite) {

    *this = *this + droite;
    return *this;
}

// Rationnel *= Rationnel
const Rationnel& Rationnel::operator*=(const Rationnel& droite)
{
    *this = *this * droite;
    return *this;
}

// Rationnel *= Number
const Rationnel& Rationnel::operator*=(const int droite)
{
    *this = *this * droite;
    return *this;
}

// Rationnel /= Rationnel
const Rationnel& Rationnel::operator/=(const Rationnel& droite)
{
    *this = *this / droite;
    return *this;
}

// Rationnel /= Number
const Rationnel& Rationnel::operator/=(const int droite)
{
    *this = *this / droite;
    return *this;
}

// Rationnel -= Rationnel
const Rationnel& Rationnel::operator-=(const Rationnel& droite)
{
    *this = *this - droite;
    return *this;

}
// Rationnel -= Number
const Rationnel& Rationnel::operator-=(const int droite)
{
    *this = *this - droite;
    return *this;

}


// Rationnel == Rationnel
//Transformer en nombre d�cimal afin de les comparer
bool Rationnel::operator==(const Rationnel& droite) const {
    // Convertir en flottants et comparer les r�sultats
    double valeurGauche = this->numerateur * 1.0 / this->denominateur;
    double valeurDroite = droite.numerateur * 1.0 / droite.denominateur;

    return (valeurGauche == valeurDroite);
}
// Rationnel == Number
bool Rationnel::operator==(const int droite) const {
    // Invoquer Rationnel::operator==( Rationnel )
    return (*this == Rationnel(droite));
} 

// Number == Rationnel
bool operator==(const int gauche, const Rationnel& droite)
{
    // Invoquer Rationnel::operator==( int )
    return ( Rationnel(gauche) == droite);
}



// Rationnel != Rationnel
bool Rationnel::operator!=(const Rationnel& droite) const {
    // Invoquer Rationnel::operator==( Rationnel )
    return !(*this == droite);
}

// Rationnel != Number
bool Rationnel::operator!=(const int droite) const {
    // Invoquer Rationnel::operator==( int )
    return !(*this == droite);
}
// Number != Rationnel
bool operator!=(const int gauche, const Rationnel& droite) {
    // Invoquer Rationnel::operator==( int, Rationnel )
    return !(gauche == droite);
}



// Rationnel < Rationnel
//si a/b < c/d, alors a*d < c*b.
bool Rationnel::operator<(const Rationnel& droite) const
{
    return (this->numerateur * droite.denominateur < droite.numerateur * this->denominateur);
}

// Rationnel < Number
bool Rationnel::operator<(const int droite) const
{
    return (*this < Rationnel(droite));;
}

// Number < Rationnel
bool operator<( const int gauche,const Rationnel& droite)
{
    return (Rationnel(gauche) < droite);
}


// Rationnel <= Rationnel
//si a/b <= c/d, alors a*d <= c*b.
bool Rationnel::operator<=(const Rationnel& droite) const
{
    return (this->numerateur * droite.denominateur <= droite.numerateur * this->denominateur);
}
// Rationnel <= Number
bool Rationnel::operator<=(const int droite) const
{
    return (*this <= Rationnel(droite));
}
bool operator<=(const int gauche, const Rationnel& droite)
{
    return (Rationnel(gauche) <= droite);
}



// Rationnel > Rationnel
//si a/b > c/d, alors a*d > c*b.
bool Rationnel::operator>(const Rationnel& droite) const
{
    return (this->numerateur * droite.denominateur > droite.numerateur * this->denominateur);
}
// Rationnel > Number
bool Rationnel::operator>(const int droite) const
{
    return (*this > Rationnel(droite));
}
bool operator>(const int gauche, const Rationnel& droite)
{
    return (Rationnel(gauche) > droite);
}


// Rationnel >= Rationnel
//si a/b >= c/d, alors a*d >= c*b.
bool Rationnel::operator>=(const Rationnel& droite) const
{
    return (this->numerateur * droite.denominateur >= droite.numerateur * this->denominateur);
}
// Rationnel >= Number
bool Rationnel::operator>=(const int droite) const
{
    return (*this >= Rationnel(droite));
}
bool operator>=(const int gauche, const Rationnel& droite)
{
    return (Rationnel(gauche) >= droite);;
}


//constructeur par d�faut
Rationnel::Rationnel() {
    denominateur = 1;
    numerateur = 1;
}


//constructeur avec param�tres
Rationnel::Rationnel(int n, int d) {
    numerateur = n;
    denominateur = d;

    simplification();

}

Rationnel::Rationnel(int n) {
    numerateur = n;
    denominateur = 1;
}


int Rationnel::pgcd(int a, int b) {
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a  = t;
   }
    return a;

}

//sert � rendre la fraction irr�ductible
void Rationnel::simplification() {
    int resultat = pgcd(numerateur, denominateur);
    numerateur /= resultat;
    denominateur /= resultat;

    if (denominateur < 0) { // Si le d�nominateur est n�gatif, ajuster le num�rateur
        numerateur *=  -1;
        denominateur *= -1;
    }

}



void Rationnel::additionner(const Rationnel& r) {
    numerateur = (numerateur * r.denominateur) +  r.numerateur * denominateur;
    denominateur = denominateur * r.denominateur;

    simplification();
}

void Rationnel::soustraire(const Rationnel& r) {
    numerateur = (numerateur * r.denominateur) - r.numerateur * denominateur;
    denominateur = denominateur * r.denominateur;
    simplification();
}
void Rationnel::multiplier(const Rationnel& r) {
    numerateur = numerateur * r.numerateur;
    denominateur = denominateur * r.denominateur;
    simplification();

}
void Rationnel::diviser(const Rationnel& r) {
    numerateur = numerateur * r.denominateur;
    denominateur = denominateur * r.numerateur;
    simplification();

}
void Rationnel::afficherRationnel(const char* chaine, Rationnel& r) {
    cout << chaine << '\t';
    r.affichageFraction();
    cout << ", \t";
    r.affichageFlottant();
    cout << std::endl;
}

void Rationnel::affichageFraction() {
cout << numerateur << " / " << denominateur;

 }

 void Rationnel::affichageFlottant() {
      cout << static_cast<float>(numerateur) / denominateur;
      }





   



