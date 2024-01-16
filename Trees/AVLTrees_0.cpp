#include<iostream>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
	int bf;
}*root = NULL;
int NodeHeight(Node* p)
{
	int hl, hr;
	
	if(p == 0)
		return 0;
	hl = NodeHeight(p->left);
	hr = NodeHeight(p->right);
	if(hl > hr)
		return hl+1;
	else
		return hr+1;	
}

void Insert(int key)
{
 struct Node *t=root;
 struct Node *r=NULL,*p;
 
 if(root==NULL)
 {
 p= new Node;
 p->data=key;
 p->bf=0;
 p->left=p->right=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->left;
 else if(key>t->data)
 t=t->right;
 else
 return;
 }
 p=new Node;
 p->data=key;
 p->left=p->right=NULL;
 
 if(key<r->data) r->left=p;
 else r->right=p;
}

Node *LLRotation(Node* p)
{
	/* 
			P
		   /  \
		 pL    Node
		/  \
	 LST    RST
	 
	*/
	
	Node* pL = p->left;
	pL->bf=0;
	int lbf, rbf;
	//make Assignments for LLrotation
	
	p->left = pL->right;
	
	/*After new Assignment
	
			   P
		      / \
		 pL  /   Node
		/  \/
	 LST   RST	
	 	
   */
   
	pL->right = p;
	/*
			pL
		   /  \ 
		LST	   P
		      / \
			 /   \
		  RST     Node			
   */
   
   //Calcuate new Balance Factor of P.
	lbf = NodeHeight(p->left)+1;
	rbf = NodeHeight(p->right)+1;
	p->bf = lbf - rbf;
	
	if(p == root)
		root = pL;
	/*     Root
	        |
			pL
		   / \
		  /   P
	    LST  / \
		    RST	Node	
   */
	return pL;
	
	
}

struct Node *LRRotation(struct Node *p)
{
 int lbf,rbf;
 struct Node *pl=p->left;
 struct Node *plr=pl->right;
 plr->bf=0;
 
 p->left=plr->right;
 pl->right=plr->left;
 plr->left=pl;
 plr->right=p;
 lbf=NodeHeight(p->left)+1;
 rbf=NodeHeight(p->right)+1;
 p->bf=lbf-rbf;
 
 lbf=NodeHeight(pl->left)+1;
 rbf=NodeHeight(pl->right)+1;
 pl->bf=lbf-rbf;
 if(p==root)root=plr;
 return plr;
}
struct Node *RRRotation(struct Node *p)
{
 int lbf,rbf;
 struct Node *pr=p->right;
 pr->bf=0;
 p->right=pr->left;
 pr->left=p;
 lbf=NodeHeight(p->left)+1;
 rbf=NodeHeight(p->right)+1;
 p->bf=lbf-rbf;
 if(p==root)root=pr;
 return pr;
}
struct Node *RLRotation(struct Node *p)
{
 int lbf,rbf;
 struct Node *pr=p->right;
 struct Node *prl=pr->left;
 prl->bf=0;
 
 p->right=prl->left;
 pr->left=prl->right;
 prl->right=pr;
 prl->left=p;
 lbf=NodeHeight(p->left)+1;
 rbf=NodeHeight(p->right)+1;
 p->bf=lbf-rbf;
 
 lbf=NodeHeight(pr->left)+1;
 rbf=NodeHeight(pr->right)+1;
 pr->bf=lbf-rbf;
 if(p==root)root=prl;
 return prl;
}

Node* RInsert(Node* p, int key)
{
	Node* t;
	int lbf, rbf;
	if (p == NULL)
	{
		t = new Node;
		t->data = key;
		t->bf = 0;
		t->left = t->right = NULL;
		return t;
	}
	if(key < p->data)
		p->left = RInsert(p->left, key);
	else if(key > p->data)
		p->right = RInsert(p->right, key);
		
	lbf = NodeHeight(p->left)+1;
	rbf = NodeHeight(p->right)+1;
	p->bf = lbf - rbf;
	if(p->bf==2 && p->left->bf == 1)
		return LLRotation(p);
		
	
	else if(p->bf==2 && p->left->bf == -1)
		return LRRotation(p);
	
	else if(p->bf==-2 && p->right->bf == -1)
		return RRRotation(p);
		
	else if (p->bf ==-2 && p->right->bf == 1)
		return RLRotation(p);
	
return p;
}

void Inorder(Node *p)
{
	if(p != NULL)
	{
	 Inorder(p->left);
	 cout<<p->data<<" ";
	 Inorder(p->right);
	}
	
}
int main()
{
 Insert(30);
 RInsert(root,50);
 RInsert(root,40);
 RInsert(root,20);
 RInsert(root,10);
 RInsert(root,42);
 RInsert(root,46);
 
 Inorder(root);
	
	int h = NodeHeight(root);
	cout<<endl;
	cout<<"height: "<<h;
	
	
}