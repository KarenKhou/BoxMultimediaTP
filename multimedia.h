#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>

using namespace std;

/**
 * @mainpage TP - Gestion Multimédia et TCP
 *
 * @section  Introduction
 *
 * Ce projet a été réalisé dans le cadre du cours **INF224**.
 * Il implémente une application orientée objet permettant de :
 * - Gérer des objets multimédia (photos, vidéos, films)
 * - Les regrouper dans des collections (groupes)
 * - Communiquer avec un client distant via un serveur TCP
 *
 * Le code est intégralement en **C++**
 *
 * @section archi_sec Architecture
 *
 * Le projet est structuré autour des classes principales :
 *
 *
 * @section authors_sec Auteurs
 * - Karen El Khoury
 *
 * @section date_sec Date
 * septembre-octobre 2025
 */


/**
 * @brief Classe multimedia abstraite, elle implemente getters et setters des attibus, et la fct sortie d'affichage,
 * la fct jouer est virtuelle pour appliquer le polymorphisme
 */
class Multimedia
{
public:
    Multimedia();
    /**
     * @brief constructeur Multimedia, throws une exception de type nomInvalide si le nom contient autre chose que des lettres, chiffres, _ et -
     * @param nom Nom de l'objet
     * @param fichier Chemin vers la resource
     */
    Multimedia(string nom, string fichier);
    virtual ~Multimedia() = default;

    string getNom() const;
    void setNom(string name);
    string getFichier()const;
    void setFichier(string fichier);

    virtual void sortie(ostream &s) const;
    virtual void jouer() const = 0;
    ///fct pour serialiser les objects
    virtual void write(ostream &s) const ;
    ///fct pour deserealiser les objects
    virtual void read(istream &s)  ;
    ///fct qui specifie le type de la classe
    virtual string className() const =0;

    ///overload de l'operateur << et >> pour effectuer la serialisation
    friend std::ostream& operator<<(std::ostream& os, const Multimedia& obj);
    friend std::istream& operator>>(std::istream& is, Multimedia& obj);





private:
    string nom{};
    string fichier{};
};

#endif // MULTIMEDIA_H
