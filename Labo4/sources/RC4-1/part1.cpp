/* 
 * File:   part1.cpp
 * Author: patrick.mast
 *
 * Created on 30. avril 2013, 14:39
 * Adapted by Julien Biefer on 30. april 2019
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "laboCryptoUtils.h"

using namespace std;

int main(int argc, char** argv) {
    
    /* Compléter les parties marquées <TODO>. Il peut manquer une ou plusieurs instructions à chaque fois */

    // Noms des fichiers
    char* file1Plain    = "part1_01.bmp";
    char* file1Rc4      = "part1_01_rc4.bmp";
    char* file2Rc4      = "part1_02_rc4.bmp";
    char* file2Plain    = "part1_02.bmp";

    // Lecture des tailles des images
    long sizeFile1 = <TODO>;
    long sizeFile2 = <TODO>;
    
    // Vérification de la compatibilité des tailles
    <TODO>;
    
    // Lecture des images /!\ mémoire allouée
    char* image1Plain = readImage(file1Plain, sizeFile1);
    char* image1Rc4 = <TODO>;
    char* image2Rc4 = <TODO>;
    
    // Taille du contenu de l'image
    long contentSize = <TODO>;
    
    // Création des en-têtes
    char headers[HEADERS_SIZE];
    for (long i = 0; i < HEADERS_SIZE; ++i) {
        <TODO>;
    }

    // Création du contenu en effectuant un XOR avec le keystream
    <TODO>;
    
    // Création de l'image résultat
    storeImage(<TODO>);

    // Libération de l'espace mémoire alloué par readImage
    delete[] image1Plain;
    // ...

    return 0;
}
