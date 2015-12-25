/**
 * binaryTree_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 */
#include <iostream>
using std::cin;
using std::cout;

class binaryTree {
    public:
        binaryTree();
        ~binaryTree();
        bool isSearchTree();
        bool isHeap();
        void makeSearchTree();
        void makeHeap();
    private:
        struct treeNode {
            int data;
            treeNode* left;
            treeNode* right;
        };
        treeNode* _root;
};

//-----------------------------------------------------------------------------
binaryTree::binaryTree() {
    _root = NULL;
}

int main(int argc, char* argv[]) {
    
    return 0;
}
