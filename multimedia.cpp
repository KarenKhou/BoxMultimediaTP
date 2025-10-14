#include "multimedia.h"

#include <iostream>
#include <cctype>
#include "ErreurKaren.h"

using namespace std;


Multimedia::Multimedia() {}

Multimedia::Multimedia(string nom, string fichier){
    for (char c : nom) {
        if (!(std::isalnum(c) || c == ' ' || c == '-' || c == '_'))
            throw nomInvalide("Seule les chiffres, lettre, - et _ sont autorises");
    }
    this->nom =  nom;
    this->fichier = fichier;
}

string Multimedia::getNom() const {
    return nom;
}

void Multimedia::setNom(string s) {
    this->nom = s;
}
string Multimedia::getFichier() const {
    return fichier;
}

void Multimedia::setFichier(string s) {
    this->fichier = s;
}

void Multimedia::sortie(ostream &s ) const{
    s <<"Nom: "<< nom << " - Fichier: "<< fichier << endl;
}

void Multimedia::write(ostream &s) const{
    s<<nom<<'\n'<<fichier<<'\n';
}

void Multimedia::read(istream &s) {
    getline(s,nom);
    getline(s,fichier);
}

std::ostream& operator<<(std::ostream& os, const Multimedia& obj) {
    obj.write(os);
    return os;
}

std::istream& operator>>(std::istream& is, Multimedia& obj){
    obj.read(is);
    return is;
}



