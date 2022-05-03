# WordleGame
A C++ project for wordle game

Wordle is a web-based word game created and developed by Welsh software engineer Josh Wardle.
Players have six attempts to guess a five-letter word, with feedback given for each guess in the form of colored tiles indicating when letters match or 
occupy the correct position. The letter with grey background color is not part of the word you need to guess for. 
The letter with yellow color is the letter that is actually part of word not at the correct position. The letter with green color is part of the word and is in the
correct position. The goal for this game is basically make sure word with green background color apear five times within six attempts.

The game is not easy to win. So cherish every tries you have. 

The program is composed of one cpp file,a few headers and one text file contains all the possible words for the game. In the cpp file, there is more than one class.
The only one cpp file is the main.cpp. It runs the main operation for the game. It will check the if the guessed word is matched with targeted word, game status and fill the proper color for letters. It will check the tries is limit within 6 times and print the proper message with different circumstances.
There are two headers created for helping the main.cpp. One is called list.h which contain a method to access a word from word list. Another one is called introduction.h which contains a method that will give a brief introduction to the game.

The whole program will generate as a text-based wordle game which is everything like an online wordle game but without the panel.
