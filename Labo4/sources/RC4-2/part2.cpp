/* 
 * File:   part2.cpp
 * Author: patrick.mast
 *
 * Created on 30. avril 2013, 15:29
 * Adapted by Julien Biefer on 30. april 2019
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "laboCryptoUtils.h"

using namespace std;

int main(int argc, char** argv) {
    
    /* Compléter les parties marquées <TODO>. Il peut manquer une ou plusieurs instructions à chaque fois */

    char* file1Rc4 = "part2_01_rc4.bmp";
    char* file2Rc4 = "part2_02_rc4.bmp";
    char* fileMix = "part2_mix.bmp";
        
    // Lecture des tailles des images
	 long sizeFile1 = readImageSize(file1Rc4);
	 long sizeFile2 = readImageSize(file2Rc4);
    
    // Vérification de la compatibilité des tailles
    if (sizeFile1 != sizeFile2) {
		cerr << "Error: Image sizes are not compatible." << endl;
		return 1;
	 }
    
    // Lecture des images /!\ mémoire allouée
    char* image1 = readImage(file1Rc4, sizeFile1);
    char* image2 = readImage(file2Rc4, sizeFile2);

    // Taille du contenu de l'image
    long contentSize = sizeFile1 - HEADERS_SIZE;
    
    // Création des en-têtes
    char headers[HEADERS_SIZE];
    for (long i = 0; i < HEADERS_SIZE; ++i) {
        headers[i] = image1[i];
    }
    
    // Création du contenu en effectuant un XOR entre les 2 images
    char content[contentSize];
	 for (long i = 0; i < contentSize; ++i) {
		 content[i] = image1[i + HEADERS_SIZE] ^ image2[i + HEADERS_SIZE];
	 }

    // Création de l'image résultat
	 storeImage(fileMix, headers, content, HEADERS_SIZE, sizeFile1);

    // Libération de l'espace mémoire alloué par readImage
    delete[] image1;
	 delete[] image2;

	 return 0;
}