#include <iostream>
#include <vector>

using namespace std;

// Node structure
struct Node {
	int data;
	Node* left;
	Node* right;
};

class BinaryTree {
public:
	BinaryTree();
	Node* Insert(Node* root, int data);
	void Display(Node* root);

private:
	Node* NewNode(int data){
		Node* temp = new Node();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;

		return temp;  
	}
};

BinaryTree:: BinaryTree(){

}

Node* BinaryTree:: Insert(Node* root, int data){
	// If its an empty tree
	if(!root){
		return this->NewNode(data);
	}

	if(data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);

	return root;
}

void BinaryTree:: Display(Node* root){
	if(!root)
		return;

	cout << root->data << "\t";
	Display(root->left);
	Display(root->right);
}

int main(){
	BinaryTree bt;
	Node* root = bt.Insert(NULL, 5);
	bt.Insert(root, 4);
	bt.Insert(root, 8);
	bt.Insert(root, 11);
	bt.Insert(root, 13);
	bt.Insert(root, 4);
	bt.Insert(root, 7);
	bt.Insert(root, 2);
	bt.Insert(root, 1);

	bt.Display(root);
	cout <<endl;
	return 0;
}
