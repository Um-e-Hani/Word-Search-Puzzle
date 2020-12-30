#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "headers.h"

using namespace std;

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
        std::cout << "Error opening file for read.";
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