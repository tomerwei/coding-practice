#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

Node* newNode(int k) {
  Node *temp = new Node;
  temp->key = k;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

bool isBST(Node* root, int maxn, int minn) {
  if (root == NULL) {
    return true;
  } 
  bool left = isBST(root->left, root->key, minn);
  bool right = isBST(root->right, maxn, root->key);
  if (left && right && root->key < maxn && root->key > minn) {
    return true; 
  }
  return false;
}


int main() {

  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6); 
  root->right->right = newNode(7);

  Node* root2 = newNode(6);
  root2->left = newNode(4);
  root2->left->left = newNode(3);
  root2->left->right = newNode(5);
  
  cout<<isBST(root, 1000, -1000)<<endl;
  cout<<isBST(root2, 1000, -1000)<<endl;

  cout<<isBST2(root,)<<endl;
  cout<<isBST2(root2,-1)<<endl;

  return 0;
}
