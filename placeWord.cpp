#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "headers.h"

using namespace std;
bool placed = true;

vector<vector<string>> placeWord(vector<string> word, vector<vector<string>> grid, int row, int col, int direction){
    switch(direction){
        case 1: //right
            if((grid[0].size() - col) < word.size()){ //not enough space towards right
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row][col+x] == ".") || (grid[row][col+x] == word[x]))
                        grid[row][col+x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 2: //left
            if((col+1) < word.size()){ //not enough space towards left
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row][col-x] == ".") || (grid[row][col-x] == word[x]))
                        grid[row][col-x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 3: //up
            if((row+1) < word.size()){ //not enough space towards up
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row-x][col] == ".") || (grid[row-x][col] == word[x]))
                        grid[row-x][col] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 4: //down
            if((grid.size() - row) < word.size()){ //not enough space towards down
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row+x][col] == ".") || (grid[row+x][col] == word[x]))
                        grid[row+x][col] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 5: //upright
            if((row+1) < word.size() || (grid[0].size() - col) < word.size()){ //not enough space upright
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row-x][col+x] == ".") || (grid[row-x][col+x] == word[x]))
                        grid[row-x][col+x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 6: //upleft
            if((row+1) < word.size() || (col+1) < word.size()){ //not enough space towards upleft
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row-x][col-x] == ".") || (grid[row-x][col-x] == word[x]))
                        grid[row-x][col-x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 7: //downright
            if((grid.size() - row) < word.size() || (grid[0].size() - col) < word.size()){ //not enough space towards downright
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row+x][col+x] == ".") || (grid[row+x][col+x] == word[x]))
                        grid[row+x][col+x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }
            break;

        case 8: //downleft
            if((grid.size() - row) < word.size() || (col+1) < word.size()){ //not enough space towards downleft
                placed = false;
                return grid;
            }
            else {                                      //check if positions are empty
                for(int x = 0; x < word.size(); x++){
                    if((grid[row-x][col-x] == ".") || (grid[row-x][col-x] == word[x]))
                        grid[row-x][col-x] = word[x];
                    else{
                        placed = false;
                        return grid;
                    }    
                }
            }  
            break;          
    }
    return grid;
}

vector<vector<string>> setWord(vector<string> word, vector<vector<string>> grid){
    while(true){
        placed = true;
        //generating a random position and direction
        int row = rand() % grid.size();
        int col = rand() % grid[0].size();
        int direction = 1 + (rand() % 8); //right,left,up,down,upright,upleft,downright,downleft

        //checking if position is free to place word
        grid = placeWord(word,grid,row,col,direction);

        //if allot word to location
        if(placed == true){
            break;
        }
    }
    cout << "moving to next word" << endl;
    return grid;
}