#ifndef MORSETREE_H
#define MORSETREE_H

#include "BinTree.h"
#include <string>
#include <fstream>
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
	MorseTree(fstream morse_file);

	//for decoding a string of periods '.' and underscores '_'
	//both return zero "0" if they fail
	char decode_char(string code_char);
	//assumes string is NOT terminated by a space
	string	decode_str(string code_str);

	//for encoding a string to morse
	string encode_char(char character);
	string encode_str(string str);

	//inserts a character based on a string of periods '.' and underscores '_'
	bool insert(char character, string code);
};

#endif
