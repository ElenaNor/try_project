#include<iostream>
#include<queue>
#include<amp.h>
using namespace std;

template<class T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	explicit BinaryTreeNode(T val){
		this->data = val;
		left = nullptr;
		right = nullptr;
	}
};


template<class T>
BinaryTreeNode<T>* takeInputLevelOrder(){   

	T data;
	cout<<"Enter the root data"<<endl;
	cin>>data;
	
	if(data == -1)return nullptr;              

	BinaryTreeNode<T> *root = new BinaryTreeNode<T>(data);
	queue<BinaryTreeNode<T>*> *totakeInput = new queue<BinaryTreeNode<T>*>();
	totakeInput->push(root);

	while(!totakeInput->empty()){
		BinaryTreeNode<T> *temp = totakeInput->front();     
		totakeInput->pop();                                        

		cout<<"Enter the left node of "<<temp->data<<endl;  
		cin>>data;
		
		if(data != -1){
		BinaryTreeNode<T> *leftnode = new BinaryTreeNode<T>(data);   
		temp->left = leftnode;           
		totakeInput->push(leftnode);     
		}

		cout<<"Enter the right node of "<<temp->data<<endl;       
		cin>>data;
		if(data != -1){
		BinaryTreeNode<T> *rightnode = new BinaryTreeNode<T>(data);
		temp->right = rightnode;
		totakeInput->push(rightnode);
		}
	}
	return root;
}

template<typename T>
void printLevelOrder(BinaryTreeNode<T> *root){   
	
	if(root == nullptr)return;                      
	
  queue<BinaryTreeNode<T>*> *qu = new queue<BinaryTreeNode<T>*>();    
  qu->push(root);

  while(!qu->empty()){
	  
    BinaryTreeNode<T> *node = qu->front();                 
    qu->pop();                                               
    
    if(node != nullptr)cout<<node->data<<" "; 
    
    if(node->left != nullptr)qu->push(node->left);
    
    if(node->right != nullptr)qu->push(node->right);
    }
}



template<class T>
void PreOrder_Traversal(BinaryTreeNode<T> *root){
	  if(root == nullptr)return;
	  
	  cout<<root->data<<" ";
	  PreOrder_Traversal(root->left);
	  PreOrder_Traversal(root->right);
}

template<class T>
void PostOrder_Traversal(BinaryTreeNode<T> *root){
	if(root == nullptr)return;
	
	PostOrder_Traversal(root->left);
	PostOrder_Traversal(root->right);
	cout<<root->data<<" ";
}
	
template<class T>
void InOrder_Traversal(BinaryTreeNode<T> *root){
	if(root == nullptr)return;
	
	InOrder_Traversal(root->left);
	cout<<root->data<<" ";
	InOrder_Traversal(root->right);
}
	
int main(){
	 BinaryTreeNode<int> *root = takeInputLevelOrder<int>();
	 
	 cout<<"Level Order : "; printLevelOrder(root); cout<<endl;	  
	 cout<<" PreOrder : "; PreOrder_Traversal(root); cout<<endl;
	 cout<<" PostOrder : "; PostOrder_Traversal(root); cout<<endl;
	 cout<<" InOrder : "; InOrder_Traversal(root);
}
