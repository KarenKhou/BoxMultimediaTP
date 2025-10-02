#include "gestionmultimedia.h"

GestionMultimedia::GestionMultimedia() {}
ptrPhoto GestionMultimedia::newPhoto(string nom,
                  string fichier,
                  float latitude,
                  float longitude){
    ptrPhoto k(new Photo(nom,fichier,latitude,longitude));
    dictMultimedia[nom] = k;
    return k;
}

ptrVideo GestionMultimedia::newVideo(string nom,
                  string fichier,
                 float duree){
    ptrVideo k(new Video(nom,fichier,duree));
    dictMultimedia[nom] = k;
    return k;

}

ptrFilm GestionMultimedia::newFilm(string nom,
                 string fichier,
                 int duree,
                 int* tableau,
                int nbrChapitres){
    ptrFilm k(new Film(nom,fichier,duree,tableau,nbrChapitres));
    dictMultimedia[nom] = k;
    return k;
}

ptrGroup GestionMultimedia::newGroup(string nom) {
    ptrGroup k = ptrGroup(new Groupe(nom));
    dictGroup[nom] = k;
    return k;
}


ptrMulti GestionMultimedia::rechercherMultimedia(string nom){
    auto it = dictMultimedia.find(nom);
    if (it == dictMultimedia.end()) {
        std::cout << "pas trouvé dans MULTIMEDIA DICT" << std::endl;
        return nullptr;
    } else {
        return it->second;
    }
}
ptrGroup GestionMultimedia::rechercherGroup(string nom){
    auto it = dictGroup.find(nom);
    if (it == dictGroup.end()) {
        std::cout << "pas trouvé dans GROUP DICT" << std::endl;
        return nullptr;
    } else {
        return it->second;
    }
}

void GestionMultimedia::afficher(string nom, ostream& s){
    ptrGroup group = GestionMultimedia::rechercherGroup(nom);
    if (group != nullptr) {
        group->afficher(s);
        return;
    }
    ptrMulti multi = GestionMultimedia::rechercherMultimedia(nom);
    if (multi != nullptr) {
        multi->sortie(s);
        return;
    }

}

bool GestionMultimedia::jouer(string nom){
    ptrGroup group = GestionMultimedia::rechercherGroup(nom);
    if (group != nullptr) {
        for (auto& multi : *group) {
            multi->jouer();
        }

        return true;
    }
    ptrMulti multi = GestionMultimedia::rechercherMultimedia(nom);
    if (multi != nullptr) {
        multi->jouer();
        return true;
    }
    return false;
}
