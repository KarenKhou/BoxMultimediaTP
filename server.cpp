//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "gestionmultimedia.h"
#include "tcpserver.h"

const int PORT = 3331;


int main(int argc, char* argv[])
{
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
}

