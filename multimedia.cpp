#include "multimedia.h"
#include <iostream>
using namespace std;


Multimedia::Multimedia() {}

Multimedia::Multimedia(string nom, string fichier){
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

