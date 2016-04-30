#include <iostream>
#include <fstream>
#include "MorseTree.h"
#include <sstream>
#include <list>

using namespace std;

list<string> readMorseWord(string code);
list<char> readRealWord(string word);


int main() {

    string line;
    string word = "";
    list<string> MorseWord; //Each entry is a (string) letter
    list<char> RealWord; //Each entry is a (char) letter
    ifstream m_file("morse.txt");
    MorseTree MTree(m_file);

    //decode morse
    line = "... ___ ...";
    MorseWord = readMorseWord(line);
    for (list<string>::iterator itr = MorseWord.begin(); itr != MorseWord.end(); itr++){
        word += MTree.decode_char(*itr); //Sends MTree a string in morse code (a Morse Code letter)
    }
    cout << line << " = " << word << endl;

    //encode morse
    line = "hello";
    word = "";
    RealWord = readRealWord(line);
    for (list<char>::iterator itr = RealWord.begin(); itr != RealWord.end(); itr++){
        word += MTree.encode_char(*itr) + " "; //Sends MTree a character
    }
    cout << line << " = " << word << endl;
    
    //quit
    cout << "Type crap to quit." << endl;
    cin >> line;

    return 0;
}

list<string> readMorseWord(string code){
	std::stringstream ss;
	ss << code;

	list<string> MorseWord;
	string MorseLetter = " ";

	while (ss >> MorseLetter){
		MorseWord.push_back(MorseLetter);
	}

	return MorseWord;
}

list<char> readRealWord(string word){
	std::stringstream ss;
	ss << word;
	list<char> RealWord;

	char next;

	while (ss >> next){
		RealWord.push_back(next);
	}

	return RealWord;
}