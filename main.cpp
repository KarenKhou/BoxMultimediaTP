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
#include <sstream>
#include "tcpserver.h"
#include <memory>

using ptrVid = std::shared_ptr<Video>;
using ptrPhoto = std::shared_ptr<Photo>;


using namespace std;

#define VERSION_SERIALISATION

int main() {
#ifdef VERSION1
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
#endif
#ifdef VERSION2
    GestionMultimedia gestion;

    auto photo1 = gestion.newPhoto("plage", "plage.jpg", 43, 23);
    auto photo2 = gestion.newPhoto("montagne", "montagne.jpg", 23, 2);

    auto video1 = gestion.newVideo("clip", "clip.mp4", 33);

    int chapitres[] = {10, 20, 30};
    auto film1 = gestion.newFilm("film", "film.mp4", 60, chapitres, 3);

    auto groupe1 = gestion.newGroup("vacances");
    groupe1->push_back(photo1);
    groupe1->push_back(video1);

    cout << "Affichage des multimédias" <<endl;
    gestion.afficher("plage",cout);
    gestion.afficher("montagne",cout);
    gestion.afficher("clip",cout);
    gestion.afficher("film",cout);

    cout << "Affichage du groupe" << endl;
    gestion.afficher("vacances",cout);

    cout << " Lecture multimédias" << endl;
    gestion.jouer("clip");
    gestion.jouer("film");

    cout << "Recherche inexistante" << endl;
    gestion.afficher("inconnu",cout);
    gestion.jouer("inconnu");

    cout << "Suppression  multimédia plage" << endl;
    gestion.supprimerMultimedia("plage");

    cout << "affichage du groupe après suppression de plage" << endl;
    gestion.afficher("vacances", cout);

    cout << "Suppression du groupe 'vacances'" << endl;
    gestion.supprimerGroup("vacances");

    cout << "Tentative d'affichage d'un groupe supprimé" << endl;
    gestion.afficher("vacances", cout);

    return 0;
#endif
#ifdef VERSION_CLIENTSERVEUR



    const int PORT = 3331;
        GestionMultimedia gestion;

        auto photo1 = gestion.newPhoto("plage", "plage.jpg", 43, 23);
        auto photo2 = gestion.newPhoto("montagne", "montagne.jpg", 23, 2);

        auto video1 = gestion.newVideo("clip", "clip.mp4", 33);

        int chapitres[] = {10, 20, 30};
        auto film1 = gestion.newFilm("film", "film.mp4", 60, chapitres, 3);

        auto groupe1 = gestion.newGroup("vacances");
        groupe1->push_back(photo1);
        groupe1->push_back(video1);
        // cree le TCPServer
        auto* server =
            new TCPServer( [&](std::string const& request, std::string& response) {

                // the request sent by the client to the server
                std::cout << "request: " << request << std::endl;
                std::stringstream ss(request);
                std::string commande, nom;
                ss >> commande >> nom;

                // the response that the server sends back to the client
                if(commande == "RECHERCHER"){

                    auto grp = gestion.rechercherGroup(nom);
                    if(grp){
                        response="Groupe : "+nom+" trouve ";
                    }else if (gestion.rechercherMultimedia(nom)) {
                        response = "Multimedia : " + nom + "  trouve";
                    } else {
                        response = "Objet : " + nom + " non trouve";
                    }


                }else if(commande == "AFFICHER"){
                    std::ostringstream oss;

                    gestion.afficher(nom, oss);
                    response = oss.str();


                }else if(commande=="JOUER"){
                    if (gestion.jouer(nom)){
                        response = "Multimedia jouer";
                    }else{
                        response = "Echec";
                    }
                }

                // return false would close the connecytion with the client
                return true;
            });


        // lance la boucle infinie du serveur
        std::cout << "Starting Server on port " << PORT << std::endl;

        int status = server->run(PORT);

        // en cas d'erreur
        if (status < 0) {
            std::cerr << "Could not start Server on port " << PORT << std::endl;
            return 1;
        }

        return 0;

#endif

#ifdef VERSION_SERIALISATION

        GestionMultimedia gestion;



        auto photo1 = gestion.newPhoto("plage", "plage.jpg", 43, 23);
        auto photo2 = gestion.newPhoto("montagne", "montagne.jpg", 23, 2);

        auto video1 = gestion.newVideo("clip", "clip.mp4", 33);
        int chapitres[] = {10, 20, 30};
        auto film1 = gestion.newFilm("film", "film.mp4", 60, chapitres, 3);

        // std::ofstream out("save.txt");
        // out << gestion;   // Sauvegarde complète

        std::ifstream in("save.txt");
        in >> gestion;    // Lecture complète


        // gestion.saveAll("serFile.txt");


        // //gestion.readAll("serFile.txt");


        cout << "Affichage des multimédias" <<endl;
        gestion.afficher("plage",cout);
        gestion.afficher("montagne",cout);
        gestion.afficher("clip",cout);
        gestion.afficher("film",cout);



        return 0;
#endif
#ifdef  VERSION_GESTIONERREUR
        //test throwing error

        try{
            GestionMultimedia gestion;
            int chapitres[] = {10, 20, 30};

            //gestion raisonnable des erreurs
            if(gestion.afficher("inconnu",cout)){
                cout<<"affichage reussit"<<endl;
            }else{
                cout<<"Affchage non aboutit"<<endl;
            }


            auto p1 = gestion.newPhoto("karen","/k",10,10);
            auto p2 = gestion.newPhoto("karen","/k",10,10);//Nom Invalide: Nom Multimedia deja existant
            auto p3 = gestion.newPhoto("ka/ren","/k",10,10);//Nom Invalide: Seule les chiffres, lettre, - et _ sont autorises

            auto film5 = gestion.newFilm("testfilm","/ll",-9,chapitres,3);//Taille Invalide : Duree d'une video ne peut pas etre <=0
            auto film6 = gestion.newFilm("hi","/ll",90,chapitres,-9);//Taille Invalide : Le nombre de chapitre d'un film ne peux pas etre <=0
            return  0;
        }
        catch(nomInvalide &e ){
            cerr<<"Nom Invalide: "<<e.what()<<endl;
        }
        catch(tailleInvalide &e ){
            cerr<<"Taille Invalide : "<< e.what()<< endl;
        }
        catch(...){
            cerr<<"Autre erreur : "<<endl;
        }





#endif
}
