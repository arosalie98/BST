/*
Student Name: <student name>
Student NetID: <student NetID>
Compiler Used: <Visual Studio, GCC, etc.>
Program Description:
This file exports the simple BST structure and methods used in the chapter
*/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
class BST{
private:

typedef struct BSTnode
{
	int data;
	int subtreenodes;
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
int numberofnodesP(BSTnode* Ptr);
int MaxDepthP(BSTnode* Ptr);
bool isBSTP(BSTnode* Ptr);
int FindLCAP(BSTnode* Ptr, int a, int b);
int FindShortestDistanceP(BSTnode* Ptr, int a , int b);
void MirrorImageP(BSTnode* Ptr);
void RangeOfNumbersP(BSTnode* Ptr, int K1, int K2);
bool isnotbalancedP(BSTnode* Ptr);
void balanceP(BSTnode* Ptr);
void subtreenodesP(int k);
void closestkeyP(BSTnode* Ptr, int k);
void DSWalgorithmP(BSTnode* Ptr);
void CreateBackbone(BSTnode* Ptr);
void CreateBalanced();


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
	int min(int a, int b);
	int MaxDepth();
	int MaxDepthPublic(BSTnode* Ptr);
	int FindLCA(int a, int b);
	int FindShortestDistance(int a, int b);
	void MirrorImage();
	void RangeOfNumbers(int K1, int K2);
	bool isnotbalanced();
	void balance();
	void subtreenodes(int k);
	void closestkey(int k);
	void DSWalgorithm();
	void rotatePhase1(BSTnode* temp, BSTnode* curr);
	void rotatePhase2(int a);
};
#endif
