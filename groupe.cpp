#include "groupe.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
using ptrMulti = shared_ptr<Multimedia>;


Groupe::Groupe(string nom) : nom(nom) {}

Groupe::Groupe(const std::string& nom, std::initializer_list<ptrMulti> elems):
 std::list<ptrMulti>(elems), nom(nom) {}

string Groupe::getNom() const{
    return nom;
}
void Groupe::afficher(std::ostream & o) const{
    o<<"Groupe: "<<nom<< " ";
    for ( ptrMulti elt : *this){
        elt->sortie(o);
    }
}
