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
    long sizeFile1 = readImageSize(file1Plain);
    long sizeFile2 = readImageSize(file1Rc4);
    
    // Vérification de la compatibilité des tailles
    if (sizeFile1 != sizeFile2) {
        cerr << "Error: Image sizes are not compatible." << endl;
        return 1;
    }
    
    // Lecture des images /!\ mémoire allouée
    char* image1Plain = readImage(file1Plain, sizeFile1);
    char* image1Rc4 = readImage(file1Rc4, sizeFile1);
    char* image2Rc4 = readImage(file2Rc4, sizeFile1);
    
    // Taille du contenu de l'image
    long contentSize = sizeFile1 - HEADERS_SIZE;
    
    // Création des en-têtes
    char headers[HEADERS_SIZE];
    for (long i = 0; i < HEADERS_SIZE; ++i) {
        headers[i] = image1Plain[i];
    }

    // Création du contenu en effectuant un XOR avec le keystream
    char* contentResult = new char[contentSize];    
    for (long i = 0; i < contentSize; ++i) {
        contentResult[i] = image1Rc4[i] ^ image2Rc4[i];
    }
    
    // Création de l'image résultat
    storeImage(file2Plain, headers, contentResult, HEADERS_SIZE, sizeFile1);

    // Libération de l'espace mémoire alloué par readImage
    delete[] image1Plain;
    delete[] image1Rc4;
    delete[] contentResult;

    return 0;
}
