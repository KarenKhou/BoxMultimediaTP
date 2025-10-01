#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <iostream>
#include <string>
#include "multimedia.h"

using namespace std;

class Groupe : public std::list<Multimedia*>
{
public:
    Groupe(const std::string& nom, std::initializer_list<Multimedia*> elems);

    Groupe(string nom);
    void afficher(std::ostream & o) const;

    string getNom() const;


private:
    string nom{};
};

#endif // GROUPE_H
