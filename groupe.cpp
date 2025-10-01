#include "groupe.h"
#include <iostream>
#include <string>
using namespace std;

Groupe::Groupe(string nom) : nom(nom) {}

Groupe::Groupe(const std::string& nom, std::initializer_list<Multimedia*> elems):
 std::list<Multimedia*>(elems), nom(nom) {}

string Groupe::getNom() const{
    return nom;
}
void Groupe::afficher(std::ostream & o) const{
    o<<"Groupe: "<<nom<< " ";
    for ( auto *elt : *this){
        elt->sortie(o);
    }
}
