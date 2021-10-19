/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

//this file implements all the rules pertaining to creating a map


#include "Map.h"

using namespace std;

/** Constructor given random input
 * param: unsigned int rows and cols represent positive numbers for the rows and columns in the map
 * param: double popDensity represents the population density of the map
 */
Map::Map(unsigned int rows, unsigned int cols, double popDensity){
    numRows = rows;
    numCols = cols;
    density = popDensity;
    board = new char* [numRows];
    for(int i = 0; i < numRows; ++i){
        board[i] = new char[numCols];
    }
    emptyMap();
    populateBoard(numRows, numCols, density);
} 

/** Constructor that creates a board given only rows and cols
 * param: unsigned int rows and cols represent positive numbers for the rows and columns in the map
 */
Map::Map(unsigned int rows, unsigned int cols){
    numRows = rows;
    numCols = cols;
    board = new char* [numRows];
    for(int i = 0; i < numRows; ++i){   
        board[i] = new char[numCols];
    }
    emptyMap();
}

/** Constructor given a file
 * param: string fileName representing file input
 */
Map::Map(string fileName){
    ifstream inFile(fileName);
    string row;
    string col;
    string words;
   

    //get the first line and check if it is a valid input
    getline(inFile, row);
    for(int i = 0; i < row.length() - 1; ++i){
        if(isdigit(row[i]) == false){
            throw runtime_error("INVALID ROW PROVIDED");
        }
    }
  

    //get the second line and check if it is a valid input
    getline(inFile, col);
    for(int i = 0; i < col.length() - 1; ++i){
       
        if(!isdigit(col[i])){
            throw runtime_error("INVALID COLUMN PROVIDED");

        }
    }

    //use temp variables for row and col to be used to iterate
    int rows = stoi(row);
    int cols = stoi(col);
    //keep track of currRow to populate the board
    int currRow = 0;
    //a temp map of the rows and cols given and then populate its board
    Map *m = new Map(rows, cols);

    //while loop to populate board
    while(getline(inFile, words)){
        if(validLine(words)){
            for(int i = 0; i < cols; ++i){
                m->board[currRow][i] = words[i];
            }
            ++currRow;
        }
        else{
            throw runtime_error("INVALID CHARACTER IN GIVEN GRID");
        }
    }

    //update member variables (numRows, numCols, board)
    setRows(rows);
    setCols(cols);
    board = m->board;
        
       

   
} 

/** Destructor 
*/
Map::~Map(){
    for(int i = 0; i < numRows; ++i){
        delete [] board[i];
    }
    delete [] board;
}

/** A boolean method that checks every line in the map provided to check if everything is an X or -
 * param: string line representing map
 */
bool Map::validLine(string line){ 
    for(int i = 0; i < line.length() - 1; ++i){
        if(!(line[i] == '-' || line[i] == 'X' || line[i] == 'x')){
            return false;
        }
        
    }
    return true; 
}

/** update the numRows member variable
 * param: int r representing the row 
 */
void Map::setRows(int r){
    numRows = r;
}

/** update the numCols member variable
 * param: int c representing the column 
 */
void Map::setCols(int c){
    numCols = c;
}

/** method to populate the board given the users random inputs
 * param: unsigned int rows and cols representing the rows and cols of the grid
 * param: double popDensity representing the density
 */
void Map::populateBoard(unsigned int rows, unsigned int cols, double popDensity){
    
    //target number of cells needed to be filled with X
    int target = (int) (popDensity * (rows * cols));
    int counter = 0;
    int randRow;
    int randCol;

    //loop through and randomly select positions to be updated with X
    while(counter < target){
        randRow = rand() % rows;
        randCol = rand() % cols;
        if(board[randRow][randCol] == '-'){
            board[randRow][randCol] = 'X';
            ++counter;
        }
        
    }
}

/** create an empty map filled with -
 *
 */
void Map::emptyMap(){
    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < numCols; ++j){
            board[i][j] = '-';
        }
    }
}

/** return the number of rows in the grid
 * return: int value
 */
unsigned int Map::getRow(){
    return numRows;
}


/** return the number of cols in the grid
 * return: int value
 */
unsigned int Map::getCol(){
    return numCols;
}


/** print out the board
 * return string of the board
 */
string Map::printMap(){
    int currRow = 0;
    string s = "";

    while(currRow != numRows){
        for(int i = 0; i < numCols; ++i){
            s += board[currRow][i];
        }
        s += "\n";
        ++currRow;
    }
    return s;

}

/** a method designed to return the character at a specific position
 * return char value at the specified position
 * param: int i and j reprsenting the coord position
 */
char Map::boardPosition(int i, int j){
    return board[i][j];
}