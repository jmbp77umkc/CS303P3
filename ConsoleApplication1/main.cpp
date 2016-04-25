#include <iostream>

#include "BinTree.h" //shouldn't be needed in final version
#include "MorseTree.h"
#include <sstream>
#include <list>

using namespace std;

list<string> readMorseWord(string code);

int main() {
    cout << "Successful Compilation." << endl;
    
    //test da tree
    CharBinTree t(8);
    
    t.setCursorToRoot();
    cout << "Went root." << endl;
    for (int i=0; i<9; ++i) {
        if (t.goLeft()) cout << "Went left." << endl;
        else cout << "Failed left." << endl;
    }
    
    t.setCursorToRoot();
    cout << "Went root." << endl;
    for (int i=0; i<9; ++i) {
        if (t.goRight()) cout << "Went right." << endl;
        else cout << "Failed right." << endl;
    }
    cout << "See ya." << endl;
    

    //Kenton
    string line;
    string word;
    list<string> MorseWord; //Each entry is a (string) letter
    list<char> RealWord; //Each entry is a (char) letter
    MorseTree MTree;

    cin >> line; 

    MorseWord = readMorseWord(line);
    for (list<string>::iterator itr = MorseWord.begin(); itr != MorseWord.end(); itr++){
        word += MTree.decode(*itr); //Sends MTree a string in morse code (a Morse Code letter)
    }

    //or

    RealWord = readRealWord(line);
    for (list<char>::iterator itr = RealWord.begin(); itr != RealWord.end(); itr++){
        word += MTree.enccode(*itr) + " "; //Sends MTree a character
    }


    //EndKenton
    return 0;
}

list<string> readMorseWord(string code){
    std::stringstream ss;
    ss << code;

    list<string> MorseWord;
    string MorseLetter= " ";

    char next;

    while (ss >> next){
        if (next == ' ') {
            MorseWord.push_back(MorseLetter);
            MorseLetter = "";
            continue;
        }
        MorseLetter += next;
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