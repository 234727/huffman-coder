#include "Node.h"


Node::Node()
{
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}


Node::~Node()
{
}

Node::Node(const Node &n)
{
	this->symbol = n.symbol;
	this->parent = n.parent;
	this->leftChild = n.leftChild;
	this->rightChild = n.rightChild;
}

Node & Node::operator=(const Node &n)
{
	if (&n != this)
	{
		this->symbol = n.symbol;
		this->parent = n.parent;
		this->leftChild = n.leftChild;
		this->rightChild = n.rightChild;
	}
	return *this;
}