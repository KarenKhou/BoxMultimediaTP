//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "film.h"
#include "groupe.h"
#include "gestionmultimedia.h"

#include <memory>

using ptrVid = std::shared_ptr<Video>;
using ptrPhoto = std::shared_ptr<Photo>;


using namespace std;


int main() {
    GestionMultimedia gestion;

    auto photo1 = gestion.newPhoto("plage", "plage.jpg", 43, 23);
    auto photo2 = gestion.newPhoto("montagne", "montagne.jpg", 23, 2);

    auto video1 = gestion.newVideo("clip", "clip.mp4", 33);

    int chapitres[] = {10, 20, 30};
    auto film1 = gestion.newFilm("film", "film.mp4", 60, chapitres, 3);

    auto groupe1 = gestion.newGroup("vacances");
    groupe1->push_back(photo1);
    groupe1->push_back(video1);

    std::cout << "\n=== Affichage des multimédias ===" << std::endl;
    gestion.afficher("plage",cout);
    gestion.afficher("montagne",cout);
    gestion.afficher("clip",cout);
    gestion.afficher("film",cout);

    std::cout << "\n=== Affichage du groupe ===" << std::endl;
    gestion.afficher("vacances",cout);

    std::cout << "\n=== Lecture multimédias ===" << std::endl;
    gestion.jouer("clip");
    gestion.jouer("film");

    std::cout << "\n=== Recherche inexistante ===" << std::endl;
    gestion.afficher("inconnu",cout);
    gestion.jouer("inconnu");

    return 0;
}


/*int main(int argc, const char* argv[])
{
   // main partie Polymorphisme
   // attention repondre au questions

    Multimedia** unif =  new Multimedia*[10];
    unsigned int i = 0;
    unif[i++]=  new Video("Video","./vid.mp4",  200);
    unif[i++]=  new Photo("Images","./photomami.png",10,10);

    for  (unsigned int k = 0;  k<i;  ++k ){
        unif[k]->jouer();
        cout<<"jouer"<<endl;
    }
    cout<<"test"<<endl;



    int tab1[] = {345,23, 43};

    Film f("Rita", "C:/Users/User/Videos/Screen Recordings/Screen Recording 2025-04-09 184047.mp4", 90, tab1, 3);
    f.sortie(cout);

    //modif le tableau passé en argument
    tab1[0] = 999;
    tab1[1] = 888;
    tab1[2] = 777;

    cout << "apres modif" << endl;
    f.sortie(cout);

    // reutilisation de memoire
    int chap2[3] = {1, 2, 3};

    f.sortie(cout);

    int chap3[] = {42, 43, 44, 45};
    f.setTableau(chap3, 4);


    f.sortie(cout);

    chap3[0] = -1;
    chap3[1] = -2;

    f.sortie(cout);

    //test partie 7

    cout<<"Test partie 7"<<endl;
    Film film1("Rita",
     "C:/Users/User/Videos/Screen Recordings/Screen Recording 2025-04-09 184047.mp4",
     90,
     tab1,
     3);
    film1.sortie(cout);

    Film film2(film1);
    film2.sortie(cout);
    Film film3;
    film3 = film2;
    film2.sortie(cout);

    //test partie 8

    ptrPhoto p1(new Photo("nom photo1", "fichier 1", 10,20));
    ptrPhoto p2(new Photo("nom photo2", "fichier 2", 130,202));
    ptrPhoto p3(new Photo("nom photo3", "fichier 3", 102,203));

    ptrVid v1(new Video("nom vid1","fichier vid1",30));
    ptrVid v2(new Video ("nom vid2","fichier vid2",59));
    ptrVid v3(new Video("nom vid3","fichier vid3",23));

    Groupe g1("Photo Paris",{p1,p2,p3});

    Groupe g2("Video Beirut");
    g2.push_back(v1);
    g2.push_back(v2);
    g2.push_back(v3);

    g1.afficher(cout);
    g2.afficher(cout);





    return 0;
}*/


// g++ main.cpp Multimedia.cpp -o programme
// .\programme.exe
