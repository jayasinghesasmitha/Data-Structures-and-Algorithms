#include <iostream>

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
        Node * insert(Node * root, int data) {
    
  		    //chacking that the tree is empty or not
            if(root == NULL) {
                    return new Node(data);
                } else {
                
                    //define a variable called current to keep the temperary value
                    Node* current;
                
                    //checking the given data is larger than root-> data
                    if(data <= root->data) {
                        current = insert(root->left, data);
                        root->left = current;
                    } else {
                        current = insert(root->right, data);
                        root->right = current;
                    }

                    return root;
                }
            }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        
        //define two integers named max and min to clarify the large one and small one
        int max=0;
        int min=0;
        
        //piu them into correct varable
        if(v1<v2){
            max=v2;
            min=v1;
        }else{
            max=v2;
            min=v1;
        }
        
        //checking the tree is empty or not
        if (!root) {
            return NULL;
        }

        //generating a loop till root becomes true
        while (root) {
            
            //checking that the given v1 and v2 larger than root-> data.
            if (root->data > max && root->data > min) {
                
                //if it is okay then the new root equals root->left
                root = root->left;
                
            //checking that the given v1 and v2 slower than root-> data
            } else if (root->data < max && root->data < min) {
                
                //if it is okay then the new root equals root->right
                root = root->right;
            } else {
                return root;
            }
        }

        return NULL; // If no common ancestor is found
    }

}; //End of Solution

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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
