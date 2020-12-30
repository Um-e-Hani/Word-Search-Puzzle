#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "headers.h"

using namespace std;

vector<vector<string>> generateGrid(){
    int rows,cols;          //dimensions of the grid
    vector<vector<string>> grid;

    cout << "Please enter the rows of the grid: ";
    cin >> rows;
    cout << "Please enter the cols of the grid: ";
    cin >> cols;

    for (int x = 0; x < rows ; x++){
        vector<string> temp;
        for(int y = 0; y < cols ; y++){
            temp.push_back(".");
        }
        grid.push_back(temp);
    }

    return grid;
}