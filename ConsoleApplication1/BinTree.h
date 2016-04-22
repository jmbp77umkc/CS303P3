#ifndef BINTREE_H
#define BINTREE_H

    //no included standard libs so may be necessary on some compilers
    #ifndef NULL
    #define NULL 0
    #endif


struct CBTNode {
    char data;
    CBTNode* left;
    CBTNode* right;
    
    CBTNode() {
        data = 0; //null character '\0'
        left = right = NULL;
    }
};

class CharBinTree {
private:
    CBTNode* root;
    CBTNode* cursor;
    
    void growTree(CBTNode* n, int h); //recursive makes a tree of height h from this node
    void copyTree(CBTNode* orig, CBTNode* copy); //recursive for copy constructor
    void delTree(CBTNode* n); //recursively delete children then self
public:
    CharBinTree();
    CharBinTree(int height);
    CharBinTree(const CharBinTree& orig); //copy constructor
    ~CharBinTree();
    void initTreeHeight(int height); //make a full, complete tree of this height (zero is just a root)
    void wipeTree(); //no memory leaks, please
    
    CBTNode* getRoot();
    char getRootData();
    
    //built in cursor for your convenience!
    CBTNode* getCursor();
    void setCursorToRoot();
    void setCursor(CBTNode* c);
    char getCursorData();
    bool goLeft(); //true if there is a node to the left
    bool goRight(); //true if there is a node to the right
};

#endif
