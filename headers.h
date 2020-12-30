#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<string>> generateWordsList();
vector<vector<string>> generateGrid();
vector<vector<string>> fillGrid(vector<vector<string>> grid);
void generateFile(vector<vector<string>> grid);
vector<vector<string>> placeWord(vector<string> word, vector<vector<string>> grid, int row, int col, int direction);
vector<vector<string>> setWord(vector<string> word, vector<vector<string>> grid);
vector<vector<string>> createPuzzle(vector<vector<string>>wordList,vector<vector<string>> grid);