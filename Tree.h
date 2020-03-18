#pragma once
#include <vector>
#include "Symbol.h"
#include "Node.h"

class Tree
{
	Node *root;
public:
	void push(Node &n);
	void push(Tree &t);
	std::string getPath(std::string s);
	Node getRoot() { return *root; }

	Tree();
	Tree(Node *n);
	~Tree();
};

