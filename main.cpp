#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "introduction.h"
#include "list.h"

using namespace std;

enum class Letter {
	correct,
	wrong_pos,//wrong position
	wrong
};

string getColor(const string& word, vector<Letter> colors)
{
	const string green = "\x1b[42m";//color for correct letter 
	const string yellow = "\x1b[43m";//color for correct letter but at the wrong position
	const string grey = "\x1b[0m";//default color

	string output = "";//output word which is the word that would be on screen

	for (int i = 0; i < word.length(); i++)
	{
		switch (colors[i]) {
			case Letter::correct:
				output += green + word[i] + grey;
				break;
			case Letter::wrong_pos:
				output += yellow + word[i] + grey;
				break;
			case Letter::wrong:
				output += word[i];
				break;
		}
	}

	return output;
}
vector<Letter> Guess(const string& correctWord, const string& guessedWord)
{
	vector<Letter> guess;
	vector<bool> lettersUsed(5, false);

	for (int i = 0; i < guessedWord.length(); i++)
	{
		//if it matched 
		if (guessedWord[i] == correctWord[i]) {
			guess.push_back(Letter::correct);
			lettersUsed[i] = true;//used letter is correct
		} else {
			guess.push_back(Letter::wrong);
		}
	}

	for (int i = 0; i < guessedWord.length(); i++)
	{
		if (guess[i] == Letter::wrong) {
			for (int j = 0; j < guessedWord.length(); j++)
			{
				if (guessedWord[i] == correctWord[j] && !lettersUsed[j]) {
					guess[i] = Letter::wrong_pos;
					lettersUsed[j] = true;//used letter is correct but at the wrong position
					break;
				}
			}
		}
	}

	return guess;//the guess word
}



//check the status of game 
bool CheckGame(vector<Letter> guess)
{
	for (auto& letter : guess) {
		if (letter != Letter::correct) {
			return false;//the word is not correct, keep guessing till you ran out of chances
		}
	}

	return true;//the word is correct
}

int main(){

	introduction in;
	in.intro();//brief intro to the Wordle game


	list li;
	auto words=li.pickWord("word.txt");//access the word list for the game

	//generate random word from the list
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<mt19937::result_type> group(0,(int)words.size()-1);

	string correctWord=words[group(rng)];//the target word

	int count=0;//counting the play times. The total times(chances) is six

	do{


		string guessWord;
		cout<<"Enter a five letter word, please: "<<'\n';
		cin>> guessWord;

		auto guess=Guess(correctWord,guessWord);

		//check if guess is correct

		bool guessResult=false;//default value
		for(auto& word:words){
			if(word==guessWord){

				guessResult = true;
				break;
			}


		} 

		//if guess result stay false
		if(!guessResult){


			for(auto& word:words){
				//if words are matched
				if(word==guessWord){
					guessWord=true;
					break;
				}



			}
			//else the word is not in the list
			if(!guessResult){

				cout<<"Your word is not in the list,please type again. "<<endl;
				continue;




			}


		}



		//print the guessed word on the screen with color
		cout<<"\033[A\r"<<getColor(guessWord,guess)<<'\n';

		//if count reaches 5 which is the sixth chance for the game, Game over
		if(count==5){
			//reveal the correct answer
			cout<<'\n';
			cout<<"correct word is "<<correctWord<<endl;


		}	
		//if the guess word perfectly match with target word
		if(CheckGame(guess)){
			cout<<"Congratulations! You won!"<<endl;
			break;


		}
		count++;//update play times

	}while(count<6);









}
