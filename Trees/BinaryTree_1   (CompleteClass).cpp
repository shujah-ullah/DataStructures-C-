
/* CPP Program To Create Binary Tree Using Queue it takes user input and store in BT
	Functions included are:
		Create Tree
		Preorder Traversal
		Postorder Traversal
		Inorder Traversal
		Levelorder Traversal
		Height of Tree
 
	Created on 21/2/2023 @ 1:35 am
	Created by:© Shujah Ullah.
*/

#include<iostream>
using namespace std;
class Node{
	public:
		Node *lchild;
		Node *rchild;
		int data;
};

class Queue{
	private:
		int front;
		int rear;
		int size;
		Node **Q; //for creating array of pointers
	public:
		Queue(){
			front = rear = -1;
			size = 10;
			Q = new Node*[size];
		}
		Queue(int size){
			front = rear = -1;
			this->size = size;
			Q = new Node*[size];
		}
		void Enqueue(Node* p);
		Node* dequeue();
		bool isEmpty(){ 
			if(front == rear)
				return true;
			else
				return false;
		}
};
void Queue::Enqueue(Node* p){
	if( rear == size-1)
		cout<<"Queue is full:"<<endl;
	else 
	{
		rear++;
		Q[rear] = p;
	}
}
Node *Queue::dequeue()
{
	Node *x = NULL;
	if(front == -1 && rear == -1)
		cout<<"Queue is Empty:"<<endl;
	else{
		x = Q[front+1];
		front++;
	}
	return x;
}

class Tree{
	private:
		Node *root;
	public:
		Tree(){root = NULL;}
		void CreateTree();
		void preorder(){ preorder(root); }
		void preorder(Node* p);
		void Inorder(){ Inorder(root); }
		void Inorder(Node* p);
		void postorder(){ postorder(root); }
		void postorder(Node* p);
		void levelorder(){ levelorder(root); }
		void levelorder(Node* p);
		int Height(){ return Height(root); }
		int Height(Node *root);
};
void Tree::CreateTree()
{
	int x;
	Node *p,*t = NULL;
	Queue q(100);
	cout<<"Enter root value:"<<endl;
	cin>>x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.Enqueue(root);
	while(!q.isEmpty())
	{
		p = q.dequeue();
		//For Left Child,
		cout<<"Enter left child  of: "<<p->data<<"  (-1 for NULL)"<<endl;
		cin>>x;
		if(x!=-1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.Enqueue(t);
		}
		//For Right CHILD,
		cout<<"Enter right child  of: "<<p->data<<"  (-1 for NULL)"<<endl;
		cin>>x;
		if(x!=-1)
		{
			t = new Node;
			t->data = x;
			t->lchild= t->rchild = NULL;
			p->rchild = t;
			q.Enqueue(t);
		}
		
	}	
}
void Tree::preorder(struct Node *p)
{
	if(p != 0)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void Tree::Inorder(struct Node *p)
{
	if(p != 0)
	{
		Inorder(p->lchild);
		cout<<p->data<<" ";
		Inorder(p->rchild);
	}
}
void Tree::postorder(struct Node *p)
{
	if(p != 0)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}
void Tree::levelorder(Node *p)
{
	Queue q(100);
	cout<<p->data<<" ";
	q.Enqueue(root);
	while(!q.isEmpty())
	{
		p = q.dequeue();
		if(p->lchild != NULL)
		{
			cout<<p->lchild->data<<" ";
			q.Enqueue(p->lchild);
		}
		if(p->rchild != NULL)
		{
			cout<<p->rchild->data<<" ";
			q.Enqueue(p->rchild);
		}
	}
}
int Tree::Height(Node *root)
{
	int x = 0, y = 0;
	if(root == 0)
		return 0;
	x = Height(root->lchild);
	y = Height(root->rchild);
	if(x > y)
		return x+1;
	else
		return y+1;	
}

int main()
{
	Tree t;
	t.CreateTree();
	cout<<"Preorder for given tree is: "<<endl;
	t.preorder();
	cout<<endl;
	
	cout<<"Inorder for given tree is: "<<endl;
	t.Inorder();
	cout<<endl;
	
	cout<<"postorder for given tree is: "<<endl;
	t.postorder();
	cout<<endl;
	
	cout<<"levelorder for given tree is: "<<endl;
	t.levelorder();
	cout<<endl;
	
	int x = 0;
	x = t.Height();
	cout<<"height of given tree is: "<<x<<endl;
	
	
	
	
	
	
}