#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stack>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *root=NULL,*temp,*curr;
class tree{
	private:
	public:
		void create(int x){
			 temp=new node;
			 temp->data=x;
			 temp->left=NULL;
			 temp->right=NULL;
		}
		void insert(node *dRoot, int x){
			if(root==NULL){
				create(x);
				root=temp;
			}
			else if(x>=dRoot->data && dRoot->right==NULL){
				cout<<"\nDR="<<dRoot->data<<endl;
				create(x);
				dRoot->right=temp;
			}
			else if(x<dRoot->data && dRoot->left==NULL){
				cout<<"\nDR="<<dRoot->data<<endl; 
				create(x);
				dRoot->left=temp;
			}
			else if(x>=dRoot->data && dRoot->right!=NULL){
				insert(dRoot->right,x);
			}
			else if(x<dRoot->data && dRoot->left!=NULL){
				insert(dRoot->left,x);
			}
		}
		void inOrderIterative(node *dRoot) 
		{ 
		    stack<node *> s; 
		    curr = dRoot; 
		  
		    while (curr != NULL || s.empty() == false) 
		    { 
		        while (curr !=  NULL) 
		        {
		            s.push(curr); 
		            curr = curr->left;
		        } 
		        curr = s.top(); 
		        s.pop(); 
		        cout << curr->data << " "; 
		        curr = curr->right;
		  
		    }
		}
		    
		void preOrderIteration(node *dRoot) 
		{
			stack<node *> s;
			s.push(dRoot);
			while(curr!=NULL || s.empty()==false)
			{
				curr=s.top();
				s.pop();
				cout<<curr->data;
				s.push(curr->right);
				s.push(curr->left);
			}
				
		}
};
main(){
	tree obj;
	int op,x;
	while(true){
		system("cls");
		cout<<"\n\t1.Insert Data\n\n\t2. Display inOrder\n\n\t3. Display in PreOrder\n\nSelect Option : ";
		cin>>op;
		switch(op){
			case 1:{
				cout<<"\nEnter data : ";
				cin>>x;
				obj.insert(root,x);
				break;
			}
			case 2:{
				obj.inOrderIterative(root);
				getch();
				break;
			}
			case 3:{
				obj.preOrderIteration(root);
				getch();
				break;
			}
		}
	}
	return 0;
}


