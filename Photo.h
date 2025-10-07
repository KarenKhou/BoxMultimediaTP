#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

/**
 * @brief Classe Photo qui herite de Multimedia,
 * on declare GestionMultimedia friend, afin que cette derniere puisse acceder a son constructeur desormais prive
 */

class  Photo : public Multimedia {
    friend class GestionMultimedia;
public:
    /**
     * @brief Constructeur de Photo
     * @param nom attibut herite de multimedia : nom de la photo
     * @param fichier attibut herite de multimedia : chemin vers la resource
     * @param latitude latitude de la photo
     * @param longitude longitude de la photo
     */
    Photo(
        string nom,
        string fichier,
        float latitude,
        float longitude
        ) :
        Multimedia(nom,fichier),
        latitude(latitude),
        longitude(longitude)
    {}
    float getLongitude() const {
        return longitude;
    }
    float getLatitude() const {
        return latitude;
    }

    void setLatitude(float latitude) {
        this->latitude = latitude;
    }

    void setLongitude (float longitude) {
        this->longitude = longitude;
    }
    /**
     * @brief sortie : fonction d'affichage, appelle la fct Multimedia::sortie(s)
     * @param s : reference vers un stream de donnees
     */
    void sortie(ostream &s)  const override{
        Multimedia::sortie(s);
        s << "Latitude : " << latitude <<  " Longitude: "<< longitude<<  endl;
    }

    /**
     * @brief jouer : run une commande pour jouer le fichier photo
     */
    void jouer() const override {
        std::string command = "imagej \"" + this->getFichier() + "\" &";
        std::cout << "Running: " << command << std::endl;
        system(command.data());
    }



private:
    float latitude{}; /// latitude de la photo
    float  longitude{}; /// longitude de la photo

};
#endif // PHOTO_H
