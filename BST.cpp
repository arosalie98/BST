/*
Student Name: <student name>
Student NetID: <student NetID>
Compiler Used: <Visual Studio, GCC, etc.>
Program Description:
<Write a short description of the program.>
*/

#include <iostream>
#include <cstdlib>
#include "BST.h"
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
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

	int BST::min(int a, int b){
	return a<b?a:b;
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
		cout<<Ptr->data<<" "<<Ptr->subtreenodes<<" "<<"\n";
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

	return numberofnodesP(root);
}

 int BST::numberofnodesP(BSTnode* Ptr){
int count =0;
queue <BSTnode*> Q;
if (!isempty())
{
	Q.push(Ptr);
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
		//cout<<"\n"<<count;

}

// void BST::subtreenodes(){
// 	subtreenodesP(root);
// }

void BST::subtreenodes(int k){
 BSTnodePtr Ptr= ReturnNode(k);
int count =0;
queue <BSTnode*> Q;
if (!isempty())
{
	Q.push(Ptr);
	while(!Q.empty()){
		//BSTnodePtr n=ReturnNode(Q.front());
		Q.front()->subtreenodes=numberofnodesP(Q.front())-1;
		
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
		//cout<<"\n"<<count;

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

bool BST::isnotbalanced(){
	return isnotbalancedP(root);
}

bool BST::isnotbalancedP(BSTnode* Ptr){
return abs(MaxDepthPublic(Ptr->R)-MaxDepthPublic(Ptr->L)>=2);

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

int BST::FindLCA(int a, int b){

return FindLCAP(root,a,b);
}

int BST::FindLCAP(BSTnode* Ptr, int a, int b){

if (!isempty())
{
	if (Ptr->data<a && Ptr->data>b || Ptr->data>a && Ptr->data<b)
	{
		return Ptr->data;
	}
	else if (Ptr->data<a && Ptr-> data<b)
	{
		FindLCAP(Ptr->R,a,b);
	}
	else if (Ptr->data>a && Ptr-> data>b)
	{
		FindLCAP(Ptr->L,a,b);
	}
}



else{
	cout<<"Tree is empty"<<"\n";
}
}

int BST::FindShortestDistance(int a, int b){

	return FindShortestDistanceP(root, a,b);
}

int BST::FindShortestDistanceP(BSTnode* Ptr, int a, int b){
 BSTnodePtr n=ReturnNode(FindLCA(a,b));
 BSTnodePtr m=n;
int count1=0;
int count2=0;
	if (!isempty())
	{
	while(n->data!=a)
		{
			if (a>n->data)
			{
				n=n->R;
				count1++;
			}
			else if (a<n->data)
			{
				n=n->L;
				count1++;
			}
		}
	while(m->data!=b)
		{
			if (b>m->data)
			{
				m=m->R;
				count2++;
			}
			else if (b<m->data)
			{
				m=m->L;
				count2++;
			}
		}


			
return count1+count2;
}
else{
		cout<<"Tree is empty"<<"\n";
}
}

void BST::MirrorImage(){
	 MirrorImageP(root);
}

void BST::MirrorImageP(BSTnode* Ptr){

if (!isempty())
{
	

	if(MaxDepthPublic(Ptr)!=1){

	BSTnodePtr n =Ptr->R;
	Ptr->R=Ptr->L;
	Ptr->L=n;

	if(Ptr->R!=NULL){MirrorImageP(Ptr->R);}
	if(Ptr->L!=NULL){MirrorImageP(Ptr->L);}
}


}

else{
	cout<<"The tree is empty"<<"\n";
}

}

void BST::RangeOfNumbers(int K1, int K2){

	RangeOfNumbersP(root, K1, K2);
}

void BST::RangeOfNumbersP(BSTnode* Ptr, int K1, int K2){
stack<int> S;
if (!isempty())
	{
		if (Ptr->L!=NULL)
		{
			RangeOfNumbersP(Ptr->L,K1, K2);
		}
if (Ptr->data>K1 && Ptr->data<K2)
		{
			

			S.push(Ptr->data);
		}	



			if (Ptr->R!=NULL)
		{
			RangeOfNumbersP(Ptr->R,K1,K2);
		}
	}
else{
	cout<<"Tree is empty"<<"\n";
}
for (int i = 0; i < S.size(); ++i)
{
	cout<<S.top()<<" "<<"\n";
	S.pop();
}
}

void BST::balance(){
	balanceP(root);
}


void BST::balanceP(BSTnode* Ptr){

if (isnotbalanced())
{
	
}



else{
	cout<<"Tree is already balanced"<<"\n";
}
}

void BST::closestkey(int k){
	closestkeyP(root, k);
}

void BST::closestkeyP(BSTnode* Ptr, int k){

queue <BSTnode*> Q;
vector <int> V;
vector <int> V1;
if (!isempty())
{
	Q.push(Ptr);
	while(!Q.empty()){

		if(k<Q.front()->data){
			V.push_back(Q.front()->data);
			//cout<<V.front();
		}
		if (k>Q.front()->data)
		{
		V1.push_back(Q.front()->data);	
		}
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
		cout<<"The Tree is empty"<<"\n";
	}
	
sort(V.begin(), V.end());
sort(V1.begin(), V1.end());
// cout<<V1.back()<<"\n";
// 		cout<<V.front()<<"\n";

	// if(!(V.empty() && V1.empty())){
	// 	abs(V.front()-k)>abs(k-V1.back())?
	// 	cout<<V1.back()<<"\n":
	// 	cout<<V.front()<<"\n";
	// }

 if (V.empty() || !V1.empty())
	{
	cout<<V1.back()<<"\n";
	}
else if (!V.empty() || V1.empty())
	{
	cout<<V.front()<<"\n";
	}
else if(!(V.empty() && V1.empty())){
		abs(V.front()-k)>abs(k-V1.back())?
		cout<<V1.back()<<"\n":
		cout<<V.front()<<"\n";
	}
}

void BST::DSWalgorithm(){
	DSWalgorithmP(root);
}

void BST::DSWalgorithmP(BSTnode* Ptr){

	if (!isempty())
	{
	
		CreateBackbone(Ptr);
		CreateBalanced();


	}


else{
	cout<<"The tree is empty";
}

}

void BST::CreateBackbone(BSTnode* Ptr){
curr=Ptr;
temp=Ptr;

while(Ptr->L!=NULL)
{
	Ptr=temp->L;
	if(Ptr->R){temp->L=Ptr->R;}
	Ptr->R=temp;
	root=Ptr;
	curr=root;
	temp=root;
	}
//cout<<"\n"<<root->data<<curr->data<<temp->data;

curr=temp;
temp=temp->R;


while(temp!=NULL){

	if (temp->L!=NULL)
	{
		rotatePhase1(temp,curr);
		temp=curr->R;
	}

else{
	curr=temp;
	temp=temp->R;
}
}
}

void BST::CreateBalanced(){

// int a=numberofnodes();
// cout<<pow(floor(log(numberofnodes()+1)),2)-1;
int a= numberofnodes();
int b= 3;
int c=a-b;
//cout<<a<<b<<c;
vector <BSTnode*> PtrV;
if (c>0)
{
rotatePhase2(c);
}
while(b>1){

	b=b/2;

rotatePhase2(b);
}
}



void BST::rotatePhase1(BSTnode* temp, BSTnode* curr){
curr->R=temp->L;
		if(temp->L->R!=NULL){temp->L=temp->L->R;}
		else{temp->L=NULL;}
		curr->R->R=temp;
}


void BST::rotatePhase2(int a){

		curr=root;
		temp=curr->R;
		delPtr=temp;
	for (int i = 0; i < a ; ++i)
	{
	
		if (temp->L!=NULL)
		{
			curr->R=temp->L;
		}
		else{
			curr->R=NULL;
		}
		temp->L=curr;
		if(temp->R!=NULL && temp->R->R!=NULL && i!=a-1)
		{
		curr=temp->R;
		temp->R=curr->R;
		temp=curr->R;
	    }
	}
	root=delPtr;
}

