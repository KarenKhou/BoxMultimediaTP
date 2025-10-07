#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <iostream>
#include <string>
#include <memory>

#include "multimedia.h"

using namespace std;
using ptrMulti = shared_ptr<Multimedia>;
/**
 * @brief Classe groupe qui represente un groupe d'objet multimedia.
 * Herite de std::list  (template  class)
 */
class Groupe : public std::list<ptrMulti>
{
public:
    using std::list<ptrMulti>::list;
    /**
     * @brief Constructeur Groupe qui permet l'initialisation de la forme suivante:
     *     Groupe g1("Photo Paris",{p1,p2,p3});

     * @param nom
     * @param elems
     */
    Groupe(const std::string& nom, std::initializer_list<ptrMulti> elems);

    Groupe(string nom);
    /// fonction d'affichage d'un groupe
    void afficher(std::ostream & o) const;
    string getNom() const;


private:
    string nom{}; /// nom du groupe
};

#endif // GROUPE_H
