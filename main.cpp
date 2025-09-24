//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "film.h"

using namespace std;

int main(int argc, const char* argv[])
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


    return 0;
}


// g++ main.cpp Multimedia.cpp -o programme
// .\programme.exe
