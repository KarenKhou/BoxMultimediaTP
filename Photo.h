#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

class  Photo : public Multimedia {
public:
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
    void sortie(ostream &s)  const override{
        Multimedia::sortie(s);
        s << "Latitude : " << latitude <<  " Longitude: "<< longitude<<  endl;
    }


    void jouer() const override {
        std::string command = "imagej \"" + this->getFichier() + "\" &";
        std::cout << "Running: " << command << std::endl;
        system(command.data());
    }



private:
    float latitude{};
    float  longitude{};

};
#endif // PHOTO_H
