/*
Student Name: <student name>
Student NetID: <student NetID>
Compiler Used: <Visual Studio, GCC, etc.>
Program Description:
Given a binary tree, print its nodes an order
*/

#include <cstdlib>
#include <iostream>
 #include "BST.h"
// #include "BST.cpp"
#include <queue>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int TreeKeys[6]={1,2,3,4,5,6};
	// int TreeKeys[3]={50,76,21};

	//int TreeKeys[4]={2,1,3,4};
	int input=0;
	BST BSTObject;

	for (int i = 0; i <6; i++)
	{
		BSTObject.AddLeaf(TreeKeys[i]);
	}
	//BSTObject.PrintOrder();
	cout<<"\n";

	//BSTObject.PrintChildren(BSTObject.ReturnRootKey());

	//cout<<"smallest value in the tree ="<<BSTObject.FindSmallest()<<"\n";

// 	cout<<"Enter key value to delete. Enter -1 to stop the process"<<"\n";
// 	while(input!=-1){
// cout<<"delete node:"<<"\n";
// 	cin>>input;
// 	{
// 	if (input!=-1)
// 	{
// 		cout<<"\n";
// 		BSTObject.DeleteNode(input);
//   		BSTObject.PrintOrder();
//   		cout<<"\n";

// 	}
// }

// 	}
	BSTObject.BFS();
	cout<<"\n";
	// BSTObject.PreOrder();
	// cout<<"\n";
	// BSTObject.PostOrder();
	//  cout<<"\n";
	//cout<<BSTObject.numberofnodes();
	//cout<<BSTObject.MaxDepth();
// //	BSTObject.ReturnNode(100);
// 	cout<<BSTObject.MaxDepthPublic(BSTObject.ReturnNode(52));
 	// BSTObject.isBST();
 	// if (!BSTObject.isnotbalanced())
 	// {
 	// 	cout<<"its balanced"<<"\n";
 	// }
// 	cout<<BSTObject.FindLCA(3,80)<<"\n";
// 	cout<<BSTObject.FindShortestDistance(2,76);

// BSTObject.MirrorImage();
// 	BSTObject.PrintOrder();
// BSTObject.RangeOfNumbers(10,70);
//  	BSTObject.subtreenodes(50);
//  	BSTObject.closestkey(15);

//BSTObject.closestkey(2);
	 BSTObject.DSWalgorithm();
	 	BSTObject.BFS();

		return 0;
}
