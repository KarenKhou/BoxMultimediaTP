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

    void afficher(string nom,ostream& s);

    bool jouer(string nom);
    /**
     * @brief supprimerMultimedia supprime un objet multimedia du dictionnaire dictMulti,
     * et de tout les groupes. L'objet est detruit automatiquement car on utilise les smarts pointers.
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




private:
    map<string,ptrMulti> dictMultimedia; /// dictionnaire contenant l'integralite des multimedias
    map<string,ptrGroup> dictGroup; ///dictionnaire contenant l'integralite des groupes.

};

/**
 * @brief saveAll
 * @param filename
 * @param objects
 * @return
 */
bool saveAll(const std::string &filename, const std::vector<Multimedia *> &objects) {
    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }

    for (auto it : objects) {
        f << it->className();
        it->write(f);
        if (f.fail()) {
            std::cerr << "Write error in " << filename << std::endl;
            return false;
        }
    }
    return true;
}



bool readAll(const std::string &filename, std::vector<Multimedia *> &objects) {
    std::ifstream f(filename);
    if (!f) {
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }

    while (f) {
        std::string className;
        std::getline(f, className);
        if (className.empty()) break;

        Multimedia *obj = createMultimedia(className);
        if (!obj) {
            std::cerr << "Unknown class name: " << className << std::endl;
            return false;
        }

        obj->read(f);
        if (f.fail()) {
            std::cerr << "Read error in " << filename << std::endl;
            delete obj;
            return false;
        } else {
            objects.push_back(obj);
        }
    }
    return true;
}


#endif // GESTIONMULTIMEDIA_H
