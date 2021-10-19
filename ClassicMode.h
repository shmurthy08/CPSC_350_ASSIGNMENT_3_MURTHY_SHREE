/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

 #ifndef CLASSICMODE_H
 #define CLASSICMODE_H

#include "AbstractGame.h"
#include "Map.h"

class ClassicMode : public AbstractGame{
    public:
        ClassicMode(string fileName); //constructor given file
        ClassicMode(unsigned int rows, unsigned int cols, double popDensity); //construtor given random values
        ~ClassicMode(); //destructor
        void createNextGen(Map *one, Map *two); //create the next generation
        void bufferedGrid(Map *m, Map *one); //create a bufferedGrid
};

#endif