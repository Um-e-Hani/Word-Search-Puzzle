#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "headers.h"

using namespace std;

int main(){
    srand((unsigned) time(0));
    vector<vector<string>> wordList;            //list of words to place in puzzle
    vector<vector<string>> grid;        //word search puzzle

    cout << "Welcome to the puzzle generator!" << endl;

    //generating empty grid
    grid = generateGrid();

    //reading words from csv file
    wordList = generateWordsList();

    for(int x=0;x<wordList.size();x++){
        for(int y =0;y<wordList[x].size();y++){
            cout << wordList[x][y] << " ";
        }
        cout << endl;
    }


    //generating puzzle
    grid = createPuzzle(wordList,grid);

    //generate file
    generateFile(grid);
    return 0;
}