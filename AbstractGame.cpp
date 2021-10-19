/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

/** This file is designed to handle a generic game...specific game modes can leverge its methods to figure out how they want to
 * build their maps
 */

#include "AbstractGame.h"


/** Constructor that takes a file input and then updates all the variables
 * 
 */
AbstractGame::AbstractGame(string fileName){
    //Attempt to update the member variables and catch any error that occur
    try{
        one = new Map(fileName);
        bufferGrid = new Map(one->getRow() + 2, one->getCol() + 2);
        two = new Map(one->getRow(), one->getCol());
        three = new Map(one->getRow(), one->getCol());
        four = new Map(one->getRow(), one->getCol());
    }
    catch(runtime_error &except){
        cerr << except.what() << endl;
    }
    

}

/** Overloaded constructor given random values for rows, cols, and population density
 * 
 */
AbstractGame::AbstractGame(unsigned int rows, unsigned int cols, double popDensity){
    try{
        one = new Map(rows, cols, popDensity);
    }
    catch(runtime_error &except){
        cerr << except.what() << endl;
    }
    bufferGrid = new Map(one->getRow() + 2, one->getCol() + 2);
    two = new Map(one->getRow(), one->getCol());
    three = new Map(one->getRow(), one->getCol());
    four = new Map(one->getRow(), one->getCol());
}





/** Method counts a position's neighbors
 * Return an int representing number of valid neighbors
 */
int AbstractGame::countNeighbors(int i, int j){
    int count = 0; 

    
    //check top left
    if(bufferGrid->boardPosition(i - 1, j - 1) == 'X'){
        ++count;
    }
    //check top
    if(bufferGrid->boardPosition(i - 1, j) == 'X'){
        ++count;
    }
    //check top right
    if(bufferGrid->boardPosition(i - 1, j + 1) == 'X'){
        ++count;
    }
    //check bottom left
    if(bufferGrid->boardPosition(i + 1, j - 1) == 'X'){
        ++count;
    }
    //check bottom
    if(bufferGrid->boardPosition(i + 1, j) == 'X'){
        ++count;
    }
    //check bottom right
    if(bufferGrid->boardPosition(i + 1, j + 1) == 'X'){
        ++count;
    }
    //check left
    if(bufferGrid->boardPosition(i, j - 1) == 'X'){
        ++count;
    }
    //check right
    if(bufferGrid->boardPosition(i, j + 1) == 'X'){
        ++count;
    }

    return count;

} 


/** Compare the last four generations to check for stablization
 * return a boolean value (true if the current gen matches any of the three previous generations and false if otherwise)
 */
bool AbstractGame::compare(string genOne, string genTwo, string genThree, string genFour){
    //check to see if map is empty
    Map *m = new Map(four->getRow(), four->getCol());
    if(genFour == m->printMap()){
        delete m;
        return true;
    }
    else if(genFour == genOne){
        return true;
    }
    else if(genFour == genTwo){
        return true;
    }
    else if(genFour == genThree){
        return true;
    }
    else{
        return false;
    }
}


/** If the user wants a pause after every generation then run this method
 * 
 */
void AbstractGame::consolePause(){
    float time = 0.1;
    int currGen = 4;
    Map *tempFirst;
    Map *tempLast;

    //Print first gen 
    cout << "Generation 0" << endl;
    cout << one->printMap();
    usleep((long) (time*10000000));


    //print second gen
    cout << "Generation 1" << endl;
    cout << two->printMap();
    usleep((long) (time*10000000));

    //print third gen
    cout << "Generation 2" << endl;
    cout << three->printMap();
    usleep((long) (time*10000000));

    //print fourth gen
    cout << "Generation 3" << endl;
    cout << four->printMap();
    usleep((long) (time*10000000));

    //while it is not stable create a new generation and update maps 
    while(!compare(one->printMap(), two->printMap(), three->printMap(), four->printMap())){
        cout << "Generation " << currGen << endl;

        one = two; 
        two = three;
        three = four;
        four = new Map(one->getRow(), one->getCol());
        createNextGen(three, four);
        cout << four->printMap();
        usleep((long) (time*10000000));
        ++currGen;
    }

}

/** If the user wants a pause after every generation then run this method
 * 
 */
void AbstractGame::consoleEnter(){
    int currGen = 4;
    Map *tempFirst; //stores the old Map one and then deletes it at the end
    Map *tempLast;
    
    cin.ignore();

    //manually print out the first four generations
    cout << "Generation 0" << endl;
    cout << one->printMap();
    cin.ignore();

    cout << "Generation 1" << endl;
    cout << two->printMap();
    cin.ignore();

    cout << "Generation 2" << endl;
    cout << three->printMap();
    cin.ignore();

    cout << "Generation 3" << endl;
    cout << four->printMap();
    cin.ignore();


    //while the game hasn't stablized create new generations
    while(!compare(one->printMap(), two->printMap(), three->printMap(), four->printMap())){
        cout << "Generation " << currGen << endl;

        one = two; 
        two = three;
        three = four;
        four = new Map(one->getRow(), one->getCol());
        createNextGen(three, four);
        cout << four->printMap();
        cin.ignore();
        ++currGen; //increment to keep track of what generation you are on
    }
}

/** if the user wants a file output of the generations then run this method
 * param: take a string input of the fileName
 */
void AbstractGame::createFileOutput(string input){
    
   
    int currGen = 4;//set curr gen to 4 since we already have the first four
    int currRow = 0;
    
    //manually append the first four generations
    createFileOutputHelper(one, input, 0);
    createFileOutputHelper(two, input, 1);
    createFileOutputHelper(three, input, 2);
    createFileOutputHelper(four, input, 3);

    //while it is not stable create new generations
    while(!compare(one->printMap(), two->printMap(), three->printMap(), four->printMap())){
        cout << "Generation " << currGen << endl;

        one = two;
        two = three;
        three = four;
        four = new Map(one->getRow(), one->getCol());
        createNextGen(three, four);
        createFileOutputHelper(four, input, currGen);

        ++currGen;
        
    }
}

/** A helper method designed to do the actually appending to the file. should be a void method
 * param: Map *m represents the map to be appended, string input represents the file to append to, int genNumber represents which generation we are on
 */
void AbstractGame::createFileOutputHelper(Map *m, string input, int genNumber){
    string words;
    ofstream outFile;
    //open the file and make sure to append
    outFile.open(input, std::ios_base::app);

    //Check if the input/output file are open to be read
        if(outFile.is_open()){
            //String map: holds map
            string map = m->printMap();
            //this lets you read every line in a string (similar to how we create ifstreams to read every line of an input file)
            istringstream istr(map);
            //read the map and then append to file
            outFile << "Generation " << genNumber << endl;
            while(getline(istr, words)){
                
                outFile << words << "\n";
            }
            
            //close the output file to avoid memory issues
            outFile.close();
        }
        //if the file cannot be opened output this error
        else{
            cout << "Unable to open files" << endl;
        }
}


