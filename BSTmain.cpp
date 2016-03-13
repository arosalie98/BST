#include <cstdlib>
#include <iostream>
 #include "BST.h"
// #include "BST.cpp"
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int TreeKeys[16]={50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
	//int TreeKeys[4]={2,1,3,4};
	int input=0;
	BST BSTObject;

	for (int i = 0; i < 16; i++)
	{
		BSTObject.AddLeaf(TreeKeys[i]);
	}
	BSTObject.PrintOrder();
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
	//BSTObject.BFS();
	// cout<<"\n";
	// BSTObject.PreOrder();
	// cout<<"\n";
	// BSTObject.PostOrder();
	// cout<<"\n";
	//cout<<BSTObject.numberofnodes();
	//cout<<BSTObject.MaxDepth();
//	BSTObject.ReturnNode(100);
	cout<<BSTObject.MaxDepthPublic(BSTObject.ReturnNode(21));
	BSTObject.isBST();

		return 0;
}