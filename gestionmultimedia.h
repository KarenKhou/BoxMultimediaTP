#ifndef GESTIONMULTIMEDIA_H
#define GESTIONMULTIMEDIA_H
#include <map>
#include "multimedia.h"
#include "groupe.h"
#include "Photo.h"
#include "Video.h"
#include "film.h"
#include <memory>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
using ptrPhoto = shared_ptr<Photo>;
using ptrVideo = shared_ptr<Video>;
using ptrFilm = shared_ptr<Film>;
using ptrMulti = shared_ptr<Multimedia>;
using ptrGroup = shared_ptr<Groupe>;

/**
 * @brief Classe GestionMultimedia: cette classe sert a instancier de nouveaux multimedia et
 * les ajoutes a un dictionaire de multimedia dictMulti, et instancier de nouveaux groupes et les
 * ajouter a dictGroup. On utilise des pointeurs intelligents pour ne pas avoir a gerer les fyites de memoires.
 */
class GestionMultimedia
{
public:
    //je dois mettre les constrcuteur des autre classe private?
    GestionMultimedia();

    /// instancie de nouvelles Photos et ajoute au dictionaire
    ptrPhoto newPhoto(string nom,
                      string fichier,
                      float latitude,
                      float longitude);

    /// instancie de nouvelles Videos et ajoute au dictionaire
    ptrVideo newVideo(string nom,
                      string fichier,
                      float duree);

    /// instancie de nouveaux Films et ajoute au dictionaire
    ptrFilm newFilm(string nom,
                     string fichier,
                     int duree,
                     int* tableau,
                     int nbrChapitres);

    ptrGroup newGroup(string nom);

    ptrMulti rechercherMultimedia(string nom);
    ptrGroup rechercherGroup(string nom);

    bool afficher(string nom,ostream& s);


    bool jouer(string nom);


    /**
     * @brief supprimerMultimedia supprime un objet multimedia du dictionnaire dictMulti,
     * et de tout les groupes. L'objet est detruit automatiquement car on utilise les smarts pointers.
     * on decide de gerer la suppression d'un multimedia non existant
     * de maniere raisonnable : on renvoie un bool false si le dictionnaire n'existe pas.
     * @param nom du multimedia a supprimer
     * @return flag de succes
     */
    bool supprimerMultimedia(const std::string& nom);

    /**
     * @brief supprimerGroup supprime un groupe du dictionnaire dictGoup
     * @param nom Nom du groupe a supprimer
     * @return flag de succes
     */
    bool supprimerGroup(const std::string& nom);

    /**
     * @brief createMultimedia est une factory method qui va creer elle meme les nouveaux objects
     * @param className
     * @return
     */
    ptrMulti createMultimedia(const std::string& className);

    /**
     * @brief saveAll Fonction qui serialise tout les object contenu dans dictMulti dans le fichier "filename"
     * @param filename
     * @param objects
     * @return
     */
    bool saveAll(const std::string &filename);



    /**
     * @brief readAll Fonction qui lit les objects du fichier, et les met dans dictMulti
     * @param filename
     * @return
     */
    bool readAll(const std::string &filename);




private:
    map<string,ptrMulti> dictMultimedia; /// dictionnaire contenant l'integralite des multimedias
    map<string,ptrGroup> dictGroup; ///dictionnaire contenant l'integralite des groupes.

};


#endif // GESTIONMULTIMEDIA_H
