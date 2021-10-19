/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

 #ifndef MIRRORMODE_H
 #define MIRRORMODE_H


#include "AbstractGame.h"
#include "Map.h"

class MirrorMode : public AbstractGame{
    public:
        MirrorMode(string fileName); //constructor to handle file input
        MirrorMode(unsigned int rows, unsigned int cols, double popDensity); //constructor to handle random user inputs
        ~MirrorMode(); //destructor
        void createNextGen(Map *one, Map *two); //create the next gen
        void bufferedGrid(Map *m, Map *one); //create buffered grid adhereing to the mirror mod rules

};
 #endif