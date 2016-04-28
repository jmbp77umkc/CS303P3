#ifndef MORSETREE_H
#define MORSETREE_H

#include "BinTree.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//this class is for making a tree for morse coded characters
//where going left is encoded as a period '.' and going right is encoded as an underscore '_'

class MorseTree{
private:
	CharBinTree morse;
public:
	//makes an empty tree of the correct size for morse code
	MorseTree();
	//can read a file and build from there
	//closes the file when done
	MorseTree(ifstream& morse_file);

	//for decoding a string of periods '.' and underscores '_'
	//all encode/decode methods return zero "0" if they fail
	char decode_char(string code_char);
	//assumes string is NOT terminated by a space
	string	decode_str(string code_str);

	//for encoding a string to morse
	//wrapper function for search function
	string encode_char(char character);
	string search_m_tree(char& ch, string& code, bool& found, CBTNode* n);
	string encode_str(string str);

	//inserts a character based on a string of periods '.' and underscores '_'
	bool insert(char character, string code);
};

#endif
