#include <iostream>
#include <cstdlib>
#include "BST.h"
#include <queue>
#include <stack>
using namespace std;


BST::BST(){root=NULL;}

BST::BSTnode* BST::CreateLeaf(int k){

 BSTnodePtr n=new BSTnode;
 	n->data=k;
 	n->L=NULL;
 	n->R=NULL;

 	return n;
}
int BST::max(int a, int b){
	return a>b?a:b;
}
int BST::MaxDepth(){
	return MaxDepthP(root);
}
int BST::MaxDepthP(BSTnode* Ptr){

	if (!isempty())
	{
		if (Ptr->L!=NULL&&Ptr->R!=NULL)
		{
			return max(MaxDepthP(Ptr->L),MaxDepthP(Ptr->R))+1;
		}
		else if (Ptr->L==NULL&&Ptr->R!=NULL)
		{
			return max(0,MaxDepthP(Ptr->R))+1;
		}
		else if (Ptr->R==NULL&&Ptr->L!=NULL)
		{
			return max(0,MaxDepthP(Ptr->L))+1;
		}
		else if (Ptr->L==NULL&&Ptr->R==NULL)
		{
			return 1;
		}
	}


else{
	cout<<"The tree is empty";
}

}

int BST::MaxDepthPublic(BSTnode* Ptr){

if (!isempty())
	{
		if (Ptr->L!=NULL&&Ptr->R!=NULL)
		{
			return max(MaxDepthP(Ptr->L),MaxDepthP(Ptr->R))+1;
		}
		else if (Ptr->L==NULL&&Ptr->R!=NULL)
		{
			return max(0,MaxDepthP(Ptr->R))+1;
		}
		else if (Ptr->R==NULL&&Ptr->L!=NULL)
		{
			return max(0,MaxDepthP(Ptr->L))+1;
		}
		else if (Ptr->L==NULL&&Ptr->R==NULL)
		{
			return 1;
		}
	}


else{
	cout<<"The tree is empty";
}
}

void BST::AddLeaf(int k){
AddLeafP(k,root);
}

void BST::AddLeafP(int k,BSTnode* Ptr){

if (root==NULL)
{
	root=CreateLeaf(k);
}
else if (k<Ptr->data)
{
	if (Ptr->L!=NULL)
	{
		AddLeafP(k,Ptr->L);
	}
	else{
		Ptr->L=CreateLeaf(k);
	}
}
else if (k>Ptr->data)
{
	if (Ptr->R!=NULL)
	{
		AddLeafP(k,Ptr->R);
	}
	else{
		Ptr->R=CreateLeaf(k);
	}
}

else{
	cout<<"Key"<<k<<"has already been added to the tree"<<"\n";
}
}

void BST::PrintOrder(){
	PrintOrderP(root);
}

void BST::PrintOrderP(BSTnode* Ptr){

	if (!isempty())
	{
		if (Ptr->L!=NULL)
		{
			PrintOrderP(Ptr->L);
		}
		cout<<Ptr->data<<" ";
		if (Ptr->R!=NULL)
		{
			PrintOrderP(Ptr->R);
		}
	}
else{
	cout<<"Tree is empty"<<"\n";
}
}
 int BST::numberofnodes(){
int count =0;
queue <BSTnode*> Q;
if (!isempty())
{
	Q.push(root);
	while(!Q.empty()){

		
		count++;
		if (Q.front()->L!=NULL)
		{
			Q.push(Q.front()->L);
		}
		if (Q.front()->R!=NULL)
		{
			Q.push(Q.front()->R);
		}
			Q.pop();
	}
}
else{
	cout<<"The tree is empty"<<"\n";
}
	return count;

}
// }

void BST::PreOrder(){
	PreOrderP(root);
}

void BST::PreOrderP(BSTnode* Ptr){

	if (!isempty())
	{
		cout<<Ptr->data<<" ";
		if (Ptr->L!=NULL)
		{
			PreOrderP(Ptr->L);
		}
		if (Ptr->R!=NULL)
		{
			PreOrderP(Ptr->R);
		}
	}

	else{
		cout<<"The Tree is empty"<<"\n";
	}
}

void BST::PostOrder(){
	PostOrderP(root);
}

void BST::PostOrderP(BSTnode* Ptr){

	if (!isempty())
	{
		if (Ptr->L!=NULL)
		{
			PostOrderP(Ptr->L);
		}
		if (Ptr->R!=NULL)
		{
			PostOrderP(Ptr->R);
		}
		cout<<Ptr->data<<" ";
	}

	else{
		cout<<"The Tree is empty"<<"\n";
	}

}



void BST::BFS(){
	BFS(root);
}
void BST::BFS(BSTnode* Ptr){
	int count =0;
queue <BSTnode*> Q;
if (!isempty())
{
	Q.push(root);
	while(!Q.empty()){

		cout<<Q.front()->data<<" ";
		count++;
		if (Q.front()->L!=NULL)
		{
			Q.push(Q.front()->L);
		}
		if (Q.front()->R!=NULL)
		{
			Q.push(Q.front()->R);
		}
			Q.pop();
	}
}
else{
	cout<<"The tree is empty"<<"\n";
}
		cout<<"\n"<<count;

}

BST::BSTnode* BST::ReturnNode(int k){

	return ReturnNodeP(k, root);
}

BST::BSTnode* BST::ReturnNodeP(int k, BSTnode* Ptr){

	if (Ptr!=NULL)
	{
		

		if (Ptr->data==k){
			return Ptr;
		}
		
		else{
					if (Ptr->data>k){
						ReturnNodeP(k,Ptr->L);
					}

					else{
						ReturnNodeP(k,Ptr->R);
					}
			}


}
	
	else{
		return NULL;
	}

}

int BST::ReturnRootKey(){

	if (!isempty())
	{
		return root->data;
	}

	else{return -1000;}
}

	void BST::PrintChildren(int k){

		curr=ReturnNode(k);
		if (curr!=NULL)
		{
			cout<<"Parent Node ="<<curr->data<<"\n";
			curr->L==NULL?
			cout<<"Left Child is null"<<"\n":
			cout<<"Left Child="<<curr->L->data<<"\n";

			curr->R==NULL?
			cout<<"Right Child is null"<<"\n":
			cout<<"Right Child="<<curr->R->data<<"\n";
		}
		else{
			cout<<"key"<<k<<"is not in the tree"<<"\n";
		}
}

	int BST::FindSmallest(){
		return FindSmallestP(root);

	}


int BST::FindSmallestP(BSTnode* Ptr){

	if (root==NULL)
	{
		cout<<"tree is empty"<<"\n";
		return -1000;
	}
	else{
		if (Ptr->L!=NULL)
		{
			return FindSmallestP(Ptr->L);
		}
else{

	return Ptr->data;
}
	
	}
}


void BST::DeleteNode(int k){

	DeleteNodeP(k, root);
}


void BST::DeleteNodeP(int k, BSTnode* Parent){

if (!isempty())
{
	if (root->data==k)
	{
		RemoveRootMatch();
	}
	else{

		if (k<Parent->data && Parent->L!=NULL)
		{
			Parent->L->data==k?
			RemoveMatch(Parent,Parent->L,true):
			DeleteNodeP(k, Parent->L);
		}

		else if (k>Parent->data && Parent->R!=NULL)
		{
			Parent->R->data==k?
			RemoveMatch(Parent,Parent->R,false):
			DeleteNodeP(k, Parent->R);
		}
		else{
			cout<<"Key"<<k<<" was not found in the tree"<<"\n";
		}




	}
}
else{
	cout<<"Tree is empty"<<"\n";
}

}

void BST::RemoveRootMatch(){

if (!isempty())
{
	delPtr=root;
	int rootkey=root->data;
	int smallestinrightsubtree;

	//case0 0 children
	if (root->L==NULL && root->R==NULL)
	{
		root==NULL;
		delete delPtr;
	}
	//case 1 1 Child
	else if (root->L==NULL && root->R !=NULL)
	{
		root=root->R;
		delPtr->R=NULL;
		delete delPtr;
		cout<<"Root node with k "<<rootkey<<" was deleted"<<"The new root contains key"<<root->data<<"\n";
	}

	else if (root->L!=NULL && root->R ==NULL)
	{
		root=root->L;
		delPtr->L=NULL;
		delete delPtr;
		cout<<"Root node with k "<<rootkey<<" was deleted"<<"The new root contains key"<<root->data<<"\n";
	}

	//case 2 2 children
	else{
		smallestinrightsubtree=FindSmallestP(root->R);
		DeleteNodeP(smallestinrightsubtree,root);
		root->data=smallestinrightsubtree;
		cout<<"Root key containing"<<rootkey<<" was overwritten with key"<<root->data<<"\n";
	}
}
else{
	cout<<"Cannot remove root. Tree is empty"<<"\n";
}

}

void BST::RemoveMatch(BSTnode* Parent, BSTnode* match, bool L){
	if (!isempty())
	{
	int matchkey=match->data;
	int smallestinrightsubtree;


//case 0 0 children
if (match->L==NULL&&match->R==NULL)
{
	delPtr=match;
	L==true? Parent->L=NULL:Parent->R=NULL;
	delete delPtr;
	cout<<"Node containing key "<<matchkey<<" was removed"<<"\n";
}
//case 1 1 child
else if (match->L==NULL&&match->R!=NULL)
{
	L==true?Parent->L=match->R:Parent->R=match->R;
	match->R=NULL;
	//delPtr=match;
	delete match;
	cout<<"Node containing key "<<matchkey<<" was removed"<<"\n";
}
else if (match->L!=NULL&&match->R==NULL)
{
	L==true?Parent->L=match->L:Parent->R=match->L;
	match->L=NULL;
	delPtr=match;
	delete delPtr;
	cout<<"Node containing key "<<matchkey<<" was removed"<<"\n";
}

//case 2 2children
else{

smallestinrightsubtree=FindSmallestP(match->R);
DeleteNodeP(smallestinrightsubtree,match);
match->data=smallestinrightsubtree;
}
 	}
	else{
		cout<<"Cannot remove match. Tree is empty"<<"\n";
	}
}

bool BST::isempty(){

return root==NULL;
}

bool BST::isBST(){

	if(isBSTP(root)){
		cout<<"Its a BST"<<"\n";
		return isBSTP(root);
	}
}

bool BST::isBSTP(BSTnode* Ptr){

	int flag=0;
	if (!isempty())
	{
		if (Ptr->L!=NULL&&Ptr->R!=NULL)
		{
			if (Ptr->L->data>=Ptr->data || Ptr->R->data<=Ptr->data )
		{
			flag=1;
		}
		
		if(Ptr->L!=NULL){ isBSTP(Ptr->L);}
		if(Ptr->R!=NULL){isBSTP(Ptr->R);}
		}
	}

	else{
		cout<<"The tree is empty"<<"\n";
	}

return flag==0;
}

