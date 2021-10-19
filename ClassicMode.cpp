
/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

//this file implements all the rules pertaining to classic mode and takes advantage of AbstractGame and its virtual methods


#include "ClassicMode.h"

using namespace std;

ClassicMode::ClassicMode(string fileName) : AbstractGame::AbstractGame(fileName){
    one = new Map(fileName);
    two = new Map(one->getRow(), one->getCol());
    three = new Map(one->getRow(), one->getCol());
    four = new Map(one->getRow(), one->getCol());
    createNextGen(one, two);
    createNextGen(two, three);
    createNextGen(three, four);
  
    
}

/** Constructor given random input
 * param: unsigned int rows and cols represent positive numbers for the rows and columns in the map
 * param: double popDensity represents the population density of the map
 */
ClassicMode::ClassicMode(unsigned int rows, unsigned int cols, double popDensity) : AbstractGame::AbstractGame(rows, cols, popDensity){
    one = new Map(rows, cols, popDensity);
    two = new Map(one->getRow(), one->getCol());
    three = new Map(one->getRow(), one->getCol());
    four = new Map(one->getRow(), one->getCol());

    //populate two, three and four with their respective maps
    createNextGen(one, two);
    createNextGen(two, three);
    createNextGen(three, four);
  
    
    
}

//destructor
ClassicMode::~ClassicMode(){
    delete one;
    delete two;
    delete three;
    delete four;
    delete bufferGrid;
}

/** Method populates a buffered grid such that we can count the neighbors in the future
 * param: Map pointer m representing the empty bufferGrid and Map pointer one representing the map needing to fill in the bufferGrid
 */
void ClassicMode::bufferedGrid(Map *m, Map *one){
    int rows = m->getRow();
    int cols = m->getCol();
   
    for(int i = 0; i < rows - 2; ++i){
        for(int j = 0; j < cols - 2; ++j){
            m->board[i+1][j+1] = one->board[i][j];
            
   
        }
        
    }    
    
}

/** This creates the next generation in the game 
 * Param: a pointer representing the old generation that will be read and update the second pointer that will hold the new map generation
 */
void ClassicMode::createNextGen(Map *one, Map *two){
    //create a buffered grid of the old map
    bufferGrid =  new Map(one->getRow() + 2, one->getCol() + 2);
    bufferedGrid(bufferGrid, one);

    //a row variable that starts from the inner part of the grid
    int currRow = 1;
    //a colum variable that starts from the inner part of the grid
    int currCol = 1;

    //nested for loops to count the neighbors in the bufferGrid and then update the new map as necessary
    for(int i = 0; i < two->getRow(); ++i){
        for(int j = 0; j < two->getCol(); ++j){
            //the character at the given position
            char c = bufferGrid->board[currRow][currCol];
            
            if(countNeighbors(currRow, currCol) <= 1){
                two->board[i][j] = '-';
            }
            
            if(countNeighbors(currRow, currCol) == 2){
                two->board[i][j] = c;
            }

            if(countNeighbors(currRow, currCol) == 3){
                
                two->board[i][j] = 'X';
            }

            if(countNeighbors(currRow, currCol) >= 4){
                two->board[i][j] = '-';
            }
            //increment column count
            ++currCol;
        }
        //increment row count
        ++currRow;;
        //reset column count to read from the beginning again
        currCol = 1;
    }
     
    
}