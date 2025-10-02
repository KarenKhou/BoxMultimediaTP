#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

class  Video : public Multimedia{
    friend class GestionMultimedia;
public:
    Video() : Multimedia() {}

    Video(string nom,
        string fichier,
        int duree
        )
        : Multimedia(nom,fichier),duree(duree){}

    void sortie(ostream &s)  const override{
        Multimedia::sortie(s);
        s << "Duree : " << duree << endl;
    }

    void jouer() const override {
        std::string command = "mpv \"" + this->getFichier() + "\" &";
        std::cout << "Running: " << command << std::endl;

        system(command.data());
    }

private:
    int duree;


};
#endif
