#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
/**
 * @brief Classe Video qui herite de Multimedia
 * on declare GestionMultimedia friend, afin que cette derniere puisse acceder a son constructeur desormais prive
 */
class  Video : public Multimedia{
    friend class GestionMultimedia;
public:
    Video() : Multimedia() {}
    /**
     * @brief Video
     * @param nom attibut herite de multimedia : nom de la photo
     * @param fichier attibut herite de multimedia : chemin vers la resource
     * @param duree duree de la video
     */
    Video(string nom,
        string fichier,
        int duree
        )
        : Multimedia(nom,fichier),duree(duree){}
    /**
     * @brief sortie : fonction d'affichage, appelle la fct Multimedia::sortie(s)
     * @param s : reference vers un stream de donnees
     */
    void sortie(ostream &s)  const override{
        Multimedia::sortie(s);
        s << "Duree : " << duree << endl;
    }

    /**
     * @brief jouer : run une commande pour jouer le fichier video
     */

    void jouer() const override {
        std::string command = "mpv \"" + this->getFichier() + "\" &";
        std::cout << "Running: " << command << std::endl;

        system(command.data());
    }

    string className() const override{
        return "Video";
    }

    void write(ostream &s) const override{
        Multimedia::write(s);
        s<<duree<<'\n';
    }

    void read(istream &s)  override{
        Multimedia::read(s);
        string d;
        getline(s,d);
        duree=stoi(d);
    }

private:
    int duree; /// duree de la video
};
#endif
