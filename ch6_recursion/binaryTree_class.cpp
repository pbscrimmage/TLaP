/**
 * binaryTree_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 */
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

class binaryTree {
    public:
        binaryTree();
        binaryTree(vector<int> numbers);
        ~binaryTree();
        int countNodes();
        void addNode(int n); // Public wrapper for insertNode
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
        void insertNode(int n, treeNode* treePtr);
};

//-----------------------------------------------------------------------------
binaryTree::binaryTree() {
    _root = NULL;
}

//-----------------------------------------------------------------------------
binaryTree::binaryTree(vector<int> numbers) {
    for (int n : numbers) {
        insertNode(n, _root);
    }
}

//-----------------------------------------------------------------------------
void binaryTree::insertNode(int n, treeNode* treePtr) {
    if (treePtr == NULL) {
        treePtr = new treeNode{n,NULL,NULL};
    } else {
        if (n <= treePtr->data) {
            insertNode(n, treePtr->left);
        } else {
            insertNode(n, treePtr->right);
        }
    }
}

//-----------------------------------------------------------------------------
binaryTree::~binaryTree() {

}

int main(int argc, char* argv[]) {
    
    vector<int> testvals{0,1,2,3,4,5,6,7,8,9,10};
    binaryTree bt{testvals};

    return 0;
}
