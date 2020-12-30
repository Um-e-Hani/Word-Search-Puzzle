#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "headers.h"

using namespace std;

void generateFile(vector<vector<string>> grid){
    fstream file;
    file.open("puzzle.csv", fstream::out);

    for(int x = 0; x < grid.size(); x++){
            for(int y = 0; y < grid[0].size(); y++){
                file << grid[x][y] << ",";
            }
            file << endl;
        }
    file.close();
    return;
}