﻿// Created by Aleksandr Golovin on 1/25/2018.
// Project Name: ass2
// File Name: binarysearchTree.h
// Copyright � 2018 Aleksandr Golovin. All rights reserved.

// The following class and some function declarations were written by:
// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// Edit 20 Jan 2018. Added <ItemType> for all cases
// since it was complaining under some compilers but not g++


// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarynode.h"

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
	// constructor, empty tree
	BinarySearchTree<ItemType>();
	// constructor, tree with root
	explicit BinarySearchTree<ItemType>(const ItemType& rootItem);
	// copy constructor
	BinarySearchTree<ItemType>(const BinarySearchTree<ItemType>& bst);
	// destructor
	virtual ~BinarySearchTree<ItemType>();
	// true if no nodes
	bool isEmpty() const;
	// 0 if empty, 1 if only root, otherwise
	// max height of subtrees + 1
	int getHeight() const;
	// number of nodes and data in tree
	int getNumberOfNodes() const;
	// add a new item
	// return true if succesasfull
	// false if item already in tree or some other reason to fail
	bool add(const ItemType& item);
	// true if item is in tree
	bool contains(const ItemType& item) const;
	// dispaly a sideways ascii representation of tree
	void displaySideways() const;
	// inorder traversal: left-root-right
	// takes a function that takes a single parameter of ItemType
	// the function can modify the data in tree, but the
	// tree structure is not changed
	void inorderTraverse(void visit(ItemType&)) const;
	// create dynamic array, copy all the items to the array
	// and then read the array to re-create this tree
	void rebalance();
	// delete all nodes in tree and set root to nullptr
	void clear();
	// given an array of length n
	// create this tree to have all items in that array
	// with the minimum height
	bool readTree(ItemType arr[], int n);
	// trees are equal if they have the same structure
	// AND the same item values at all the nodes
	bool operator==(const BinarySearchTree<ItemType> &) const;
	// not == to each other
	bool operator!=(const BinarySearchTree<ItemType> &) const;
private:
	// root of the tree
	BinaryNode<ItemType>* rootPtr{ nullptr };
	// add a new node, helper function for add
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	// find the node with given vale, helper function for contains
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const;
	// helper function for displaySideways to work recursively
	void sideways(BinaryNode<ItemType>* current, int level) const;

	// The following function declaration are written by Aleksandr Golovin:

	// helper function for getNumberOfNodes 
	void preOrderCountNodes(BinaryNode<ItemType>* current, int & count) const;
	// helper function for clear
	void clearPostOrder(BinaryNode<ItemType>* current);
	// helper function for copy constructor
	BinaryNode<ItemType>* preOrderDeepCopy(BinaryNode<ItemType>* toCopy);
	// helper function for overloaded ==
	bool preOrderComparsion(const BinaryNode<ItemType>* root, const BinaryNode<ItemType>* rhs)const;
	// helper function for rebalance
	void fillArInOrder(const BinaryNode<ItemType>* root, ItemType ar[], int & index);
	// helper function for inorderTraverse
	void inOrderTrav(const BinaryNode<ItemType>* root, void visit(ItemType&)) const;
	// helper function for getHeight
	int heightCount(BinaryNode<ItemType>* root)const;
	// helper function for readTree
	BinaryNode<ItemType>* buildTree(ItemType ar[], int lbound, int ubound);

	// end of function declaration by Aleksandr Golovin
};

#include "binarysearchtree.cpp"

#endif // BINARYSEARCHTREE_H
