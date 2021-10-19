/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/


//this file implements all the necessary information needed to run the game (i.e taking in user inputs and calling the right methods to complete the game)

#include "Run.h"




//constructor
Run::Run(){

}

//destructor
Run::~Run(){

}

// /** Method runs the actual program
//  * The goal is to take all user inputs needed to run the program and then proceed
//  */
void Run::run(){ //update later with while loop to check until valid inputs are provided
    string config;
    string output; // sets if the user wants pause or enter or output to a file
    cout << "WELCOME TO GAME OF LIFE!" << endl;
    while(1){
       if(config == "random" || config == "flat-file"){
           break;
       }
       else{
           
            cout << "Would you like a \"random\" configuration or a \"flat-file\" configuration?" << endl;
            cin >> config;
    
    
       }
    }
    while(1){
        if(output == "pause" || output == "enter" || output == "file")
            break;
        else{
            cout << "Would you like to \"pause\" inbetween generations or use the \"enter\" key or output to a \"file\" to create the next generation?" << endl;
            cin >> output;
        }
    }

    //ask user for game mode
    string gameMode;
    while(1){
        if(gameMode == "Classic" || gameMode == "Mirror" || gameMode == "Doughnut"){
            break;
        }
        else{
            cout << "Select Game Mode: \"Classic\", \"Mirror\", \"Doughnut\"" << endl;
            cin >> gameMode;
        }
    }

    //ask user for random config inputs
    int rows;
    int cols;
    float popDensity;
    if(config == "random"){
        while(1){
            cout << "ROWS?" << endl;
            cin >> rows;
            if(rows > 0){
                break;
            }
            else if(rows == 0){
                cout << "Invalid Input: CANNOT TAKE 0 AS INPUT" << endl;
            }
            else{
                cout << "input a positive number" << endl;
            }
        }
        
        while(1){
            cout << "COLUMNS?" << endl;
            cin >> cols;
            if(cols > 0){
                break;
            }
            else if(cols == 0){
                cout << "INVALID INPUT: CANNOT TAKE ZERO AS INPUT" << endl;
            }
            else{
                cout << "input a positive number" << endl;
            }
        }
        while(1){
            cout << "POPULATION DENSITY?" << endl;
            cin >> popDensity;
            if(popDensity >= 0 && popDensity <= 1){
                break;
            }
            else{
                cout << "INVALID INPUT: enter number between 0 and 1" << endl;
            }   

        }
        if(gameMode == "Classic"){
            ClassicMode *c = new ClassicMode(rows, cols, popDensity);
            if(output == "pause"){
                c->consolePause();
                delete c;
            }
            if(output == "enter"){
                c->consoleEnter();
                delete c;
            }
            if(output == "file"){
                string name;
                cout << "Name of file to create?" << endl;
                cin >> name;
                c->createFileOutput(name);
                delete c;
            }
            
        }
        if(gameMode == "Mirror"){
            MirrorMode *m = new MirrorMode(rows, cols, popDensity);
            if(output == "pause"){
                m->consolePause();
                delete m;
            }
            if(output == "enter"){
                m->consoleEnter();
                delete m;
            }
            if(output == "file"){
                string name;
                cout << "Name of file to create?" << endl;
                cin >> name;
                m->createFileOutput(name);
                delete m;
            }
            
           
        }
        if(gameMode == "Doughnut"){
            DoughnutMode *d = new DoughnutMode(rows, cols, popDensity);
            if(output == "pause"){
                d->consolePause();
                delete d;
            }
            if(output == "enter"){
                d->consoleEnter();
                delete d;
            }
            if(output == "file"){
                string name;
                cout << "Name of file to create?" << endl;
                cin >> name;
                d->createFileOutput(name);
                delete d;
            }
        
        }
    }

    //if user gives file input
    string input;
    if(config == "flat-file"){

        cout << "Input Name of the file" << endl;
        cin >> input;
        ifstream inFile(input);
        
        
        
    
        //Check if the input file is open to be read
        if(inFile.is_open()){
            if(gameMode == "Classic"){
                ClassicMode *c = new ClassicMode(input);
                if(output == "pause"){
                    c->consolePause();
                    delete c;
                }
                if(output == "enter"){
                    c->consoleEnter();
                    delete c;
                }
                if(output == "file"){
                    string name;
                    cout << "Name of file to create?" << endl;
                    cin >> name;
                    c->createFileOutput(name);
                    delete c;
                }
                
            }
            if(gameMode == "Doughnut"){
                DoughnutMode *c = new DoughnutMode(input);
                if(output == "pause"){
                    c->consolePause();
                    delete c;
                }
                if(output == "enter"){
                    c->consoleEnter();
                    delete c;
                }
                if(output == "file"){
                    string name;
                    cout << "Name of file to create?" << endl;
                    cin >> name;
                    c->createFileOutput(name);
                    delete c;
                }
                
            }
            if(gameMode == "Mirror"){
                MirrorMode *c = new MirrorMode(input);
                if(output == "pause"){
                    c->consolePause();
                    delete c;
                }
                if(output == "enter"){
                    c->consoleEnter();
                    delete c;
                }
                if(output == "file"){
                    string name;
                    cout << "Name of file to create?" << endl;
                    cin >> name;
                    c->createFileOutput(name);
                    delete c;
                }
                
            }
        }
        //if the file cannot be opened output this error
        else{
            cout << "Unable to open file" << endl;
        }

    }
}