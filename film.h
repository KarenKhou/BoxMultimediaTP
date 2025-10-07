#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;
/**
 * @brief Classe Film qui herite de Video
 * on declare GestionMultimedia friend, afin que cette derniere puisse acceder a son constructeur desormais prive
 */
class Film :  public Video{
    friend class GestionMultimedia;
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
    /**
     * @brief constructeur Film qui accepte un Film comme argument
     * @param from Film dont on veut creer faire une copier dans le nouvel objet
     */

    Film(const Film& from) : Video(from){

        nbrChapitres = from.nbrChapitres;
        tableauDuree = new int[nbrChapitres];
        for (int i(0);i<nbrChapitres;i++){
            tableauDuree[i] = from.tableauDuree[i];
        }
    }

    /**
     * @brief operator = redefinition de l'operateur d'affectation
     * @param from Film qu'on veut copier
     */
    Film& operator=(const Film& from){
        Video::operator=(from);
        if (tableauDuree && from.tableauDuree) *tableauDuree = *from.tableauDuree;
        return *this;
    }
    /// fonction d'affichage d'un film sur un stream passer en argument
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
//karen docu
    void setTableau(int* tab, int taille) {
        delete[] tableauDuree;
        copier(tab, taille);
    }

private:

    int* tableauDuree = nullptr; ///tableau C contenant la duree de chaque chapitre du film
    int nbrChapitres = 0; /// nombre de chapitres dans le film

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
