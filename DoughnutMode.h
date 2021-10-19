
/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "AbstractGame.h"
#include "Map.h"

class DoughnutMode : public AbstractGame{
    public:
        DoughnutMode(string fileName); //constructor given fileName
        DoughnutMode(unsigned int rows, unsigned int cols, double popDensity); //constructor given random inputs
        ~DoughnutMode(); //destructor
        void createNextGen(Map *one, Map *two); //create next generation
        void bufferedGrid(Map *m, Map *one); // create buffered grid adhering to DoughnutMode rules

};

 #endif