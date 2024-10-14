#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        
        //chacking that the tree is empty or not
        if(root == NULL) {
                return new Node(data);
            } else {
                
                //define a variable called current to keep the temperary value
                Node* current;
                
                //checking the given data is larger than root-> data
                if(data < root->data) {
                    
                    //if it is fullfilled assign current to root -> left
                    current = insert(root->left, data);
                    root->left = current;
                } else {
                    
                    //if it is not fullfilled assign current to root -> right 
                    current = insert(root->right, data);
                    root->right = current;
                }

               return root;
           }
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}