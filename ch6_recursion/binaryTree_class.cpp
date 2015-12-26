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
        bool checkNodes(int n, treeNode* treePtr); // Helper function for isSearchTree
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
        return checkNodes(_root->data, _root);
    }
}

//-----------------------------------------------------------------------------
bool binaryTree::checkNodes(int n, treeNode* treePtr) {
    bool passTest = false;
    bool checkLeft = false;
    bool checkRight = false;

    if (treePtr == NULL) {
        passTest = false;
    }
    treeNode* left = NULL;
    treeNode* right = NULL;

    if (left == NULL && right == NULL) {
        passTest = true;
        
    }
    if (left != NULL ) {
        left = treePtr->left;
        if (left->data > n) {
            passTest = false; 
        }
    } else if (right != NULL ) {
        right = treePtr->right;
        if (right->data <= n) {
            passTest  = false;
        }
    }
    if (passTest) {
        if (left != NULL) {
            checkLeft = checkNodes(treePtr->data, treePtr->left);
        }
        if (right != NULL) {
            checkRight = checkNodes(treePtr->data, treePtr->right);
        }
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
