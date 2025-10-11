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
        return nullptr;
    } else {
        return it->second;
    }
}

ptrGroup GestionMultimedia::rechercherGroup(string nom){
    auto it = dictGroup.find(nom);
    if (it == dictGroup.end()) {
        return nullptr;
    } else {
        return it->second;
    }
}

void GestionMultimedia::afficher(string nom, ostream& s){
    if (auto group =rechercherGroup(nom)){
        group->afficher(s);
        return;
    }
    if (auto multi = rechercherMultimedia(nom)){
        multi->sortie(s);
        return;
    }

}

bool GestionMultimedia::jouer(string nom){
    if (auto group = rechercherGroup(nom)){
        for (auto& multi : *group) {
            multi->jouer();
        }
        return true;
    }
    if(auto multi = rechercherMultimedia(nom)){
        multi->jouer();
        return true;
    }
    return false;
}

bool GestionMultimedia::supprimerGroup(const std::string& nom){
    auto it = dictGroup.find(nom);
    if(it != dictGroup.end()){
        (it->second)->clear();
        dictGroup.erase(it);
        return true;
    }
    return false;
}

bool GestionMultimedia::supprimerMultimedia(const std::string& nom){
    auto it = dictMultimedia.find(nom);
    if(it != dictMultimedia.end()){
        ptrMulti multiasupprimer = it->second;
        for (auto &it2 : dictGroup){
            ptrGroup grp = it2.second;
            grp->remove(multiasupprimer);
        }
        dictMultimedia.erase(it);
        return true;
    }
    return false;
}

ptrMulti GestionMultimedia::createMultimedia(const std::string& className) {
    if (className == "Photo")
        return shared_ptr<Photo>(new Photo());
    else if (className == "Video")
        return shared_ptr<Video>(new Video());
    else if (className == "Film")
        return shared_ptr<Film>(new Film());
    else
        return nullptr;
}

bool GestionMultimedia::saveAll(const std::string &filename) {
    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }

    for (const auto & [nom, obj] : dictMultimedia) {
        f << obj->className() <<'\n';
        obj->write(f);
        if (f.fail()) {
            std::cerr << "Write error in " << filename << std::endl;
            return false;
        }
    }
    std::cout<<"Write done"<<std::endl;
    return true;
}
bool GestionMultimedia::readAll(const std::string &filename) {
    std::ifstream f(filename);
    if (!f) {
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }

    while (f) {
        std::string className;
        std::getline(f, className);
        if (className.empty()) break;

        ptrMulti obj = createMultimedia(className);
        if (!obj) {
            std::cerr << "Unknown class name: " << className << std::endl;
            return false;
        }
        obj->read(f);
        dictMultimedia[obj->getNom()] = obj;
    }
    return true;
}

