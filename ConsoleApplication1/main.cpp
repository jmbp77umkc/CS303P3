#include <iostream>
#include <fstream>

#include "MorseTree.h"

using namespace std;

int main() {
    cout << "Successful Compilation." << endl;

    ifstream m_file("morse.txt");
    MorseTree MTree(m_file);
    
    cout << MTree.encode_str("hello world") << endl;
    cout << MTree.decode_str(".... . ._.. ._.. ___    .__ ___ ._. ._.. _..");

    return 0;
}
