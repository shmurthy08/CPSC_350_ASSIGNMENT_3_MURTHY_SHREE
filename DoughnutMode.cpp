/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/


//this file implements all the rules pertaining to doughnut mode and takes advantage of AbstractGame and its virtual methods



#include "DoughnutMode.h"


using namespace std;


/** Constructor given a file name 
 * param: string fileName representing file input
 */
DoughnutMode::DoughnutMode(string fileName) : AbstractGame::AbstractGame(fileName){
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
DoughnutMode::DoughnutMode(unsigned int rows, unsigned int cols, double popDensity) : AbstractGame::AbstractGame(rows, cols, popDensity){
    one = new Map(rows, cols, popDensity);
    two = new Map(one->getRow(), one->getCol());
    three = new Map(one->getRow(), one->getCol());
    four = new Map(one->getRow(), one->getCol());
    bufferGrid = new Map(one->getRow() + 2, one->getCol() + 2);
    bufferedGrid(bufferGrid, one);
    cout << bufferGrid->printMap() << endl;
    //populate two, three and four with their respective maps
    createNextGen(one, two);
    createNextGen(two, three);
    createNextGen(three, four);
   
}

/** Destructor
*/
DoughnutMode::~DoughnutMode(){

    delete one;
    delete two;
    delete three;
    delete four;
    delete bufferGrid;
}

/** Creates a buffered grid of a given map that will be used to efficently count neighbors
 * parameters: Map *m represents an empty buffer grid, Map *one represents the map that will help populate the buffer
 */
void DoughnutMode::bufferedGrid(Map *m, Map *one){
    int rows = m->getRow();
    int cols = m->getCol();

    //check top left of original grid and then change buffered as needed
    if(one->board[0][0] == 'X'){
        m->board[rows-1][cols - 1] = 'X';
    }

    //check top right of original grid and then change buffered as needed
    if(one->board[0][one->getCol()-1] == 'X'){
        m->board[rows-1][0] = 'X';
    }

    //Check if bottom left of original grid is occupied...thus make sure top right of buffered grid is occupied
    if(one->board[one->getRow()-1][0] == 'X'){
        m->board[0][cols - 1] = 'X';
    }

    //Check bottom right if its occupied change buffered as needed
    if(one->board[one->getRow() - 1][one->getCol() - 1] == 'X'){
        m->board[0][0] = 'X';
    }

    int currRow = 0;
    int currCol = 0;

    //copy top row of original grid to bottom row of the buffered grid
    currRow = rows - 1;
    currCol = 1;
    for(int i = 0; i < one->getCol(); ++i){
        m->board[currRow][currCol] = one->board[0][i];
        ++currCol;
    }

    //copy bottom row of original grid to top row of the buffered grid
    currRow = 0;
    currCol = 1;
    for(int i = 0; i < one->getCol(); ++i){
        m->board[currRow][currCol] = one->board[one->getRow()-1][i];
        ++currCol;
    }

    //copy right column of original grid to the left column (aka the first column) of the buffered grid
    currRow = 1;
    currCol = 0;
    for(int i = 0; i < one->getRow(); ++i){
        m->board[currRow][currCol] = one->board[i][one->getCol() - 1];
        ++currRow;
    }
    
    //left column to right column
    currRow = 1;
    currCol = cols - 1;
    for(int i = 0; i < one->getRow(); ++i){
        m->board[currRow][currCol] = one->board[i][0];
        ++currRow;
    }

    //populate inside
    for(int i = 0; i < rows - 2; ++i){
        for(int j = 0; j < cols - 2; ++j){
            m->board[i+1][j+1] = one->board[i][j];
            
   
        }
        
    } 
}


/** This creates the next generation in the game 
 * Param: a pointer representing the old generation that will be read and update the second pointer that will hold the new map generation
 */
void DoughnutMode::createNextGen(Map *one, Map *two){
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