/**
 * binaryTree_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 */
#include <iostream>
#include <vector>
#include <exception>
#include <string>
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
        bool checkNodes(treeNode* treePtr); // Helper function for isSearchTree
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
    treeNode* newNode = new treeNode{n,NULL,NULL};
    newNode->left = _root; 
    _root = newNode;
}

//-----------------------------------------------------------------------------
bool binaryTree::isSearchTree() {
    if (_root == NULL) {
        return false;
    } else {
        return checkNodes(_root);
    }
}

//-----------------------------------------------------------------------------
bool binaryTree::checkNodes(treeNode* treePtr) {
    bool checkLeft = false;
    bool checkRight = false;

    if (treePtr == NULL) { // Empty tree
        return false;
    }
    treeNode* left = treePtr->left;
    treeNode* right = treePtr->right;

    if (left == NULL && right == NULL) { // Made it to end node
        return true;
    }
    if (left != NULL && left->data > treePtr->data) {
        return false; 
    } else if (right != NULL && right->data <= treePtr->data) {
        return false;
    }
    if (left != NULL) {
        checkLeft = checkNodes(treePtr->left);
    }
    if (right != NULL) {
        checkRight = checkNodes(treePtr->right);
    }
    return checkLeft && checkRight;
}
    
//-----------------------------------------------------------------------------
binaryTree::~binaryTree() {

}

int main(int argc, char* argv[]) {
    
    
    try {
        vector<int> testvals{0,1,2,3,4,5,6,7,8,9,10};
        binaryTree bt{testvals};

        bool dididoitrite = bt.isSearchTree();
        cout << dididoitrite << '\n';
    }
    catch (const std::exception& e) {
        cout << e.what();
    }

    return 0;
}
