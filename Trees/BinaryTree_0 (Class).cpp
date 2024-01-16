#include<iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node  *left , *right;
		
	public:
		Node* create(int x);
		void setLeft(Node* left);
		
		void setRight(Node* Right);
		
		
		
};
Node* Node::create(int x)
{
	Node *root = new Node;
	root->data = x;
	root->left = NULL;
	root->right = NULL;
	
	return root;	
}
void Node::setLeft(Node* left)
{
	this->left = left;	
	
}

void Node::setRight(Node* Right)
{
	this->right = Right;
		
}
int main()
{

Node TreeNode;


Node *ptr = TreeNode.create(5);

Node *left = TreeNode.create(7);
TreeNode.setLeft(left);

Node *right = TreeNode.create(2);
TreeNode.setRight(right);

return 1;










	
}