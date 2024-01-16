 #include<iostream>
 #include "Queue.h"
 using namespace std;
 struct Node
 {
 	int data;
 	Node* left;
 	Node* right;
 }*root = NULL;//pointer of Node type declared globally
// T(n) = O(n*log n)   n = no of elements to be inserted.
void Insert(int data)
{
	Node* p;
	//if root is NULL then first create Root Node and return.
	if(root == NULL)
	{
		p = new Node();
		p->data = data;
		p->left = p->right = NULL;
		root = p; //update root pointer with new node.
		return;
	}
	//Create a new node to insert in BST
	p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	
	Node* focusnode = root;
	Node* parent;
	while(true)
	{
	parent = focusnode;	
	//if node already exist in BT then return
	if(data == root->data)
		return;
	//if data is less than parent node,s data
	else if (data < focusnode->data)
		{
			focusnode = focusnode->left;
			if (focusnode == NULL)
			{
				parent->left = p;
				return;
		}
		}
	//if data is less than parent node,s data
	else 
		{
			focusnode = focusnode->right;
			if (focusnode == NULL)
			{
				parent->right = p;
				return;
			}	
		}
	}
}

//preorder traversal
void preorder(Node* ptr)
{
	if(ptr == 0)
	{
		return;
	}
	cout<<ptr->data<<" ";
	preorder(ptr->left);
	preorder(ptr->right);
}
//postorder travesral
void postorder(Node* ptr)
{
	if(ptr == 0)
	{
		return;
	}
	
	postorder(ptr->left);
	postorder(ptr->right);
	cout<<ptr->data<<" ";
}
//inorder traversal (Gives Sorted data)
void inorder(Node* ptr)
{
	if(ptr == 0)
	{
		return;
	}
	
	inorder(ptr->left);
	cout<<ptr->data<<" ";
	inorder(ptr->right);
	
}
//level order traversal
/*void levelorder(Node* root)
{
	struct Queue q;
	create(&q,100);
	cout<<root->data;
	enqueue(&q,root);
	while(Queue::!isEmpty())
	{
		root = Queue::dequeue();
		if(root->left)
		{
			cout<<root->left->data<<endl;
			enqueue(&q,root->left);
		}
		
		if(root->right)
		{
			cout<<root->right<<endl;
			enqueue(&q,root->right);
		}
				
	}	
}
*/
//T(n) = O(log n) = height of tree
Node *Search(int key)
{
	Node* t = root;
	while(t != NULL)
		{
			if(key == t->data)
				return t;
			else if( key<t->data)
				t = t->left;
			else
				t = t->right;
		}
		return NULL;
}
Node* RInsert(Node* p, int key)
{
	Node* t;
	if (p == NULL)
	{
		t = new Node;
		t->data = key;
		t->left = t->right = NULL;
		return t;
	}
	if(key < p->data)
		p->left = RInsert(p->left, key);
	else if(key > p->data)
		p->right = RInsert(p->right, key);
	return p;
}
int height(Node* p)
{
	int x = 0, y = 0;
	if(p == 0)
		return 0;
	x = height(p->left);
	y = height(p->right);
	if(x > y)
		return x+1;
	else
		return y+1;	
}
Node* Inpre(Node* p)
{
	while(p!=NULL && p->right != NULL)
			p = p->right; //keep going right untill p->right became NULL.
		
	return p;
}



Node* Insucc(Node* p)
{
	while(p!=NULL && p->right != NULL)
			p = p->left; //keep going right untill p->right became NULL.
		
	return p;
}


Node* Delete(Node* p, int key)
{
	Node* q;
	//deletion of Node
	if(p == NULL)
		return 	NULL;
		//condition for leaf node
	if(p->left == NULL && p->right == NULL ) //delete leaf node
	{
		if(p == root)
			root = NULL;
		free(p);
		return NULL;
	}
	//search for key
	if(key < p->data)
		p->left= Delete(p->left, key);
	else if(key > p->data)
		p->right= Delete(p->right, key);
	 
	/*
	   		 50
	 		  /  
	  		10  
	    	 \
	     	 40
	    	/
			20
		 	\
		  	 30
	for above BST there is only inorder predecessor i.e. 40 for node 50 and no insuccessor existed for 50.
	deletion of 50 requires in order predecessor only, which is checked by condition if(height(LST) > height(RST).  
	 */
	 	//condition for non leaf node
	 else //when key = p->data we have reached at node to be deleted.  
	 {
	 	//Condition for Left skewed BST
	 	if(height(p->left) > height(p->right))
	 	{
	 		q = Inpre(p->left); //p->left is passed instead of p due to reason that inPredecessor is at left->right->right... of 
	 						   //given node so p->left is passed in advance p->right part will be traversed in Inpre() function. 
			p->data = q->data; //Replace 50 with 40 
			p->left = Delete(p->left , q->data); //Recursive call for 40.
		}
		//Condition for Right skewed BST
		if(height(p->left) < height(p->right))
	 	{
	 		q = Insucc(p->right); //p->right is passed instead of p due to reason that insuccessor is at right->leftt->left... of 
	 						     //given node so p->right is passed in advance p->left part will be traversed in Insucc() function. 
			p->data = q->data; //Replace  
			p->right = Delete(p->right , q->data); //Recursive 
		}
	 }
	 return p;
}
 int main()
 {
 	
    
	root = RInsert(root,10);
	RInsert(root,50);
	RInsert(root,10);
	RInsert(root,40);
	RInsert(root,20);
	RInsert(root,30);
	
	cout<<endl<<"preorder: ";
    preorder(root);
    cout<<endl<<"postorder: ";
    postorder(root);
    cout<<endl<<"Inorder: ";
    inorder(root);
    cout<<endl;
    Delete(root,30);
    cout<<endl<<"Inorder: ";
    inorder(root);

//Node *p = Search(400);
//if(p != NULL)
// 	cout<<"Element found: "<<endl;
//else
//cout<<"Element NOT found: "<<endl;
 //
    
 }