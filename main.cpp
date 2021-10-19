/*
 * Shree Murthy
 * 2374658
 * shmurthy@chapman.edu
 * CPSC 350-03
 * Assignment 3
 **/

#include <iostream>
#include "Map.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"
#include "AbstractGame.h"
#include "Run.h"

using namespace std;

int main(int argc, char** argv){
    Run *r = new Run();
    r->run();
    delete r;


    return 0;


}