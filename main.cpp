#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;
bool placed = true;
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

vector<vector<string>> generateWordsList(){

    string filename;
    ifstream file;
    string temp,temp1 = "";
    vector<vector<string>> wordList;

   //cout << "Please enter the name of csv file to read word list from: ";
    //cin >> filename;
    //filename += ".csv";

    file.open("file1.csv", ios::in);
    if(!file){
        cout << "Error opening file for read.";
        exit;
    }

    while(getline(file,temp)){
        vector<string> tempp;
        stringstream str(temp);
        while(getline(str,temp1,'.'))
            tempp.push_back(temp1);

        wordList.push_back(tempp);
    }

    return wordList;
}

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