#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;

class Film :  public Video{
public:

    Film() : Video() {}

    Film(
        string nom,
        string fichier,
        int duree,
        int* tableau,
        int nbrChapitres
        ) :
        Video(nom,fichier,duree)
    {
        copier(tableau,nbrChapitres);
    }

    ~Film(){
        delete[] tableauDuree;
    }

    Film(const Film& from) : Video(from){

        nbrChapitres = from.nbrChapitres;
        tableauDuree = new int[nbrChapitres];
        for (int i(0);i<nbrChapitres;i++){
            tableauDuree[i] = from.tableauDuree[i];
        }
    }

    Film& operator=(const Film& from){
        Video::operator=(from);
        if (tableauDuree && from.tableauDuree) *tableauDuree = *from.tableauDuree;
        return *this;
    }

    void sortie(ostream &s) const override{
        Video::sortie(s);
        s << "Tableau des Durees: ";
        for (int i = 0; i < nbrChapitres; i++) {
            s << tableauDuree[i] << " ";
        }
        s << endl;
    }

    const int* getTableauDuree() const{
        return tableauDuree;
    }
    int getnbrChapitres() const{
        return nbrChapitres;
    }

    void setTableau(int* tab, int taille) {
        delete[] tableauDuree;
        copier(tab, taille);
    }

private:

    int* tableauDuree = nullptr;
    int nbrChapitres = 0;

    void copier(const int * tab, int taille) {
        if (taille>0 && tab!=nullptr){
            tableauDuree = new int[taille];
            for (int i(0); i<taille; i++){
                tableauDuree[i]=tab[i];
            }
            nbrChapitres = taille;
        } else {
            int* tableauDuree = nullptr;
            int nbrChapitres = 0;
        }

    }
};

#endif // FILM_H
