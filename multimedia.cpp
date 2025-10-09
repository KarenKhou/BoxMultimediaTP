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

void Multimedia::write(ostream &s) const{
    s<<nom<<'\n'<<fichier<<'\n';
}

void Multimedia::read(istream &s) {
    getline(s,nom);
    getline(s,fichier);
}
Multimedia* createMultimedia(const std::string& className) {
    if (className == "Photo")
        return new Photo();
    else if (className == "Video")
        return new Video();
    else
        return nullptr;
}
