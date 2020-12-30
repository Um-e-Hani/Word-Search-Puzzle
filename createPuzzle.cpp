#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "headers.h"

using namespace std;

vector<vector<string>> createPuzzle(vector<vector<string>>wordList,vector<vector<string>> grid){

    //set words
    for(int x = 0; x < wordList.size(); x++){
        grid = setWord(wordList[x],grid);
    }

    cout << "All words set." << endl;
    //fill the rest of the grid
    grid = fillGrid(grid);

    return grid;
}