/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

 #ifndef MAP_H
 #define MAP_H

#include <iostream>
#include <fstream>
#include <exception>
#include <math.h>
#include <unistd.h> //for the pause function

using namespace std;

class Map{
    public:
        Map(unsigned int rows, unsigned int cols, double popDensity); //overloaded with no file provided
        Map(unsigned int rows, unsigned int cols); //rows and cols
        Map(string fileName); //overloaded with fileName
        ~Map(); //destructor
        void populateBoard(unsigned int rows, unsigned int cols, double popDensity); //given a blank board populate accordingly
        bool validFile(string fileName); //validate if a file's given map obeys the constraints given
        bool validLine(string line); //validate if a grid's line is a valid line
        string printMap(); //print every row in the 2D array. Can print to console and/or print to a file.
        char **board; //will be set equal to a 2D array that will be populated with the necessary
        char boardPosition(int i, int j); //return the char at a specific position in the grid
        unsigned int getRow(); //get number of rows
        unsigned int getCol();//get number of cols
        void emptyMap(); //create an empty map (i.e filled with '-')
        void setRows(int r); //update the numRows var
        void setCols(int c); //update the numCols var
        

    private:
        int numRows; 
        int numCols;
        double density;
      

};
 #endif