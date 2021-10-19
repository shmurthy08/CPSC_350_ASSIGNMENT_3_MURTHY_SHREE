/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include "Map.h"

#include <sstream>

using namespace std;

class AbstractGame{

    public:
        AbstractGame(string fileName); // constructor given fileName
        AbstractGame(unsigned int rows, unsigned int cols, double popDensity); //constructor given random inputs
        void run(); //sets up everything for the user (i.e do they want pause, enter, file output)
        bool compare(string genOne, string genTwo, string genThree, string genFour); //compare two generations to see if they are the same
        int countNeighbors(int i, int j); //count the number of neighbors such that the next gneeration can be updated properly
        void createFileOutput(string input); //output the maps onto this file...still need to create
        void consolePause(); //control what should happen if the pause option is selected
        void consoleEnter(); //control what should happen if the enter option is selected
        

    protected:
        virtual void createNextGen(Map *one, Map *two) = 0; //create the next generation of the game
        void createFileOutputHelper(Map *m, string input, int genNumber);
        //four map objects to hold their respective Map generation and one bufferedGrid map 
        Map *bufferGrid; 
        Map *one;
        Map *two;
        Map *three;
        Map *four;
        





};

 #endif