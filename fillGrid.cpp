#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "headers.h"

using namespace std;

vector<vector<string>> fillGrid(vector<vector<string>> grid){
    //string alphabet[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" }; 
    string alphabet[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" }; 
    for(int x = 0; x < grid.size(); x++){
        for(int y = 0; y < grid[0].size(); y++){
            if(grid[x][y] == "."){
                grid[x][y] = alphabet[rand() % 26];
            }
        }
    }
    return grid;
}
