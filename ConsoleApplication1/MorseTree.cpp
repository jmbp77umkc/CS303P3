#include "MorseTree.h"

MorseTree::MorseTree()
{
	//makes tree of apropriate size
	morse.initTreeHeight(4);
}
MorseTree::MorseTree(ifstream& morse_file)
{
	//if file is not yet open it returns with no tree created
	if (!morse_file.is_open())
	{
		return;
	}

	//makes tree of apropriate size
	morse.initTreeHeight(4);
	string line;
	char character;
	string code;

	//reads in next character
	while (morse_file >> line)
	{
		//splits the input apart into sections
		character = line[0];
		line.erase(0,1);
		code = line;

		//inserts the line into the tree
		if (!insert(character, code))
		{
			cout << "Could not insert " << character << " continuing anyway." << endl;
		}
	}

	//closes file when done
	morse_file.close();

	return;
}

//for decoding a string of '.' and '-'
//Bothe return zero "0" if they fail
char MorseTree::decode_char(string code_char)
{
	//weeds out characters that can't exist in morse code
	if (code_char == "._._" || code_char == "___." || code_char == "____" || code_char == "__..")
		return '0';

	string::iterator sit;
	morse.setCursorToRoot();

	for (sit = code_char.begin(); sit != code_char.begin(); sit++)
	{
		if (*sit == '.')
		{
			if (morse.goLeft())
				continue;
			//if the position exists then it goes back to the top
			else
				return '0';
			//position dosen't exist and you are stupid
		}
		else if (*sit == '_')
		{
			if (morse.goRight())
				continue;
			//if the position exists then it goes back to top
			else
				return '0';
			//position dosen't exist and you are stupid
		}
		else
			return '0';
	}

	return morse.getCursorData();
}
string	MorseTree::decode_str(string code_str)
{
	if (code_str == "")
		return "0";

	string character = "";
	string decoded_str = "";
	string::iterator sit;

	for (sit = code_str.begin(); sit != code_str.end(); sit++)
	{
		if (*sit == ' ')
		{
			decoded_str += decode_char(character);
			character.clear();
		}
		else if (*sit == '.' || *sit == '_')
		{
			character += *sit;
		}
		else
			return "0";
	}
	decoded_str += decode_char(character);

	return decoded_str;
}

//for encoding a string to morse
//wrapper function for search function
string MorseTree::encode_char(char character)
{
	morse.setCursorToRoot();
	string code = "";

	bool found = false;

	search_m_tree(character, code, found);

	if (found == false)
	{
		cout << "could not find " << character << " in the tree.";
	}

	return code;
}
string MorseTree::search_m_tree(char& ch, string& code, bool& found)
{
	CBTNode* current = morse.getCursor();


	if (morse.getCursorData() == ch)
	{
		found = true;
		return code;
	}

	if (morse.goLeft())
	{
		search_m_tree(ch, code, found);
		if (found)
		{
			code += ".";
			return code;
		}
		else
			morse.setCursor(current);
	}
	else if (morse.goRight())
	{
		search_m_tree(ch, code, found);
		if (found)
		{
			code += "_";
			return code;
		}
		else
			morse.setCursor(current);
	}
	else
		return code;
}

string MorseTree::encode_str(string str)
{
	if (str == "")
		return "0";

	string::iterator sit;
	string code = "";

	for (sit = str.begin(); sit != str.end(); sit++)
	{
		if (*sit == ' ')
			code += " ";
		else
			code += encode_char(*sit);
	}

	return code;
}

//inserts a character based on a string of '.' and '-'
bool MorseTree::insert(char character, string code)
{
	if (code == "") //checks for bad input
	{
		return false;
	}

	//weeds out characters that can't exist in morse code
	if (code == "._._" || code == "___." || code == "____")
		return false;

	morse.setCursorToRoot(); //loads root of tree
	string::iterator sit;	//starts iterator for code string

	//ther are 2 possible characters
	//this loop searches for the location of the insert using joshes built in cursor
	for (sit = code.begin(); sit != code.end(); sit++)
	{
		if (*sit == '.')
		{
			if (morse.goLeft())
				continue;
			//if the position exists then it goes back to the top
			else
				return false;
			//position dosen't exist and you are stupid
		}
		else if (*sit == '_')
		{
			if (morse.goRight())
				continue;
			//if the position exists then it goes back to top
			else
				return false;
			//position dosen't exist and you are stupid
		}
		else
			return false;
	}

	if (morse.getCursorData() == 0)
	{
		morse.setCursotData(character);
		return true;
	}
	else
		return false;
}