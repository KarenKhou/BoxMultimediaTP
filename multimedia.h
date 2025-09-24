#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
using namespace std;


class Multimedia
{
public:
    Multimedia();
    Multimedia(string nom, string fichier);
    virtual ~Multimedia() = default;

    string getNom() const;
    void setNom(string name);
    string getFichier()const;
    void setFichier(string fichier);

    virtual void sortie(ostream &s) const=0;
    virtual void jouer() const = 0;


private:
    string nom{};
    string fichier{};
};

#endif // MULTIMEDIA_H
