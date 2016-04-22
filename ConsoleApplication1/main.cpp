#include <iostream>

#include "BinTree.h" //shouldn't be needed in final version
#include "MorseTree.h"

using namespace std;

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
        if (t.goLeft()) cout << "Went right." << endl;
        else cout << "Failed right." << endl;
    }
    cout << "See ya." << endl;
    
    return 0;
}