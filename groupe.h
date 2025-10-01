#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <iostream>
#include <string>
#include <memory>

#include "multimedia.h"

using namespace std;
using ptrMulti = shared_ptr<Multimedia>;

class Groupe : public std::list<ptrMulti>
{
public:
    using std::list<ptrMulti>::list; //question
    Groupe(const std::string& nom, std::initializer_list<ptrMulti> elems);

    Groupe(string nom);
    void afficher(std::ostream & o) const;

    string getNom() const;


private:
    string nom{};
};

#endif // GROUPE_H
