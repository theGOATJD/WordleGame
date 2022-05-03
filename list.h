#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

class list
{
	//access the word from word list
	public:
		vector<string> pickWord(const char* path){

			ifstream file("word.txt");
			vector<string> word;
			string line;
			while(getline(file,line)){
				word.push_back(line);
			}
			return word;
		}










};
#endif
