#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>

class BST{
private:

typedef struct BSTnode
{
	int data;
	BSTnode* R;
	BSTnode* L;
}* BSTnodePtr;

BSTnodePtr root;
BSTnodePtr curr;
BSTnodePtr temp;
BSTnodePtr delPtr;

void AddLeafP(int k,BSTnode* Ptr);
void PrintOrderP(BSTnode* Ptr);
BSTnode* ReturnNodeP(int k, BSTnode* Ptr);
int FindSmallestP(BSTnode* Ptr);
void DeleteNodeP(int k, BSTnode* Parent);
void RemoveRootMatch();
void RemoveMatch(BSTnode* Parent, BSTnode* match, bool L);
void BFS(BSTnode* Ptr);
void PreOrderP(BSTnode* Ptr);
void PostOrderP(BSTnode* Ptr);
int numberofnodesP(BSTnode* Ptr, int a);
int MaxDepthP(BSTnode* Ptr);
bool isBSTP(BSTnode* Ptr);

public:
	BST();
	BSTnode* CreateLeaf(int k);
	void AddLeaf(int k);
	void PrintOrder();
	BSTnode* ReturnNode(int k);
	int ReturnRootKey();
	void PrintChildren(int k);
	int FindSmallest();
	void DeleteNode(int k);
	void BFS();
	bool isempty();
	bool isBST();
	void PreOrder();
	void PostOrder();
	int numberofnodes();
	int max(int a, int b);
	int MaxDepth();
	int MaxDepthPublic(BSTnode* Ptr);
};
#endif