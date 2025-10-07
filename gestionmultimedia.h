#ifndef GESTIONMULTIMEDIA_H
#define GESTIONMULTIMEDIA_H
#include <map>
#include "multimedia.h"
#include "groupe.h"
#include "Photo.h"
#include "Video.h"
#include "film.h"
#include <memory>

using namespace std;
using ptrPhoto = shared_ptr<Photo>;
using ptrVideo = shared_ptr<Video>;
using ptrFilm = shared_ptr<Film>;
using ptrMulti = shared_ptr<Multimedia>;
using ptrGroup = shared_ptr<Groupe>;

class GestionMultimedia
{
public:
    //je dois mettre les constrcuteur des autre classe private?
    GestionMultimedia();

    ptrPhoto newPhoto(string nom,
                      string fichier,
                      float latitude,
                      float longitude);

    ptrVideo newVideo(string nom,
                      string fichier,
                      float duree);

    ptrFilm newFilm(string nom,
                     string fichier,
                     int duree,
                     int* tableau,
                     int nbrChapitres);

    ptrGroup newGroup(string nom);

    ptrMulti rechercherMultimedia(string nom);
    ptrGroup rechercherGroup(string nom);

    void afficher(string nom,ostream& s);

    bool jouer(string nom);

    bool supprimerMultimedia(const std::string& nom);
    bool supprimerGroup(const std::string& nom);


private:
    map<string,ptrMulti> dictMultimedia;
    map<string,ptrGroup> dictGroup;

};

#endif // GESTIONMULTIMEDIA_H
