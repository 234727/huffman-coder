#include "Tree.h"
#include <iostream>

//*********************************************************************
void Tree::push(Node &n)
{
	this->root = &n;
	this->root->leftChild = NULL;
	this->root->rightChild = NULL;
	this->root->parent = NULL;
}
//*********************************************************************
void Tree::push(Tree &t)
{
	int o = this->root->getOccurrences() + t.root->getOccurrences();
	std::string s = this->root->getCharacter() + t.root->getCharacter();

	Symbol *symbol = new Symbol(s, o);
	Node *node = new Node(*symbol);

	node->parent = NULL;
	node->leftChild = root;
	node->rightChild = t.root;
	this->root->parent = node;
	t.root->parent = node;

	this->root = node;
}
//*********************************************************************
std::string Tree::getPath(std::string s)
{
	std::string finalPath = "";
	Node *route = new Node(*(this->root));
	while (1)
	{
		if (route->leftChild != NULL)
		{
			if (route->leftChild->getCharacter().find(s) != -1)
			{
				finalPath += "0";
				route = route->leftChild;
			}
			else
			{
				if (route->rightChild != NULL)
				{
					if (route->rightChild->getCharacter().find(s) != -1)
					{
						finalPath += "1";
						route = route->rightChild;
					}
				}
			}
		}
		if (route->getCharacter().length() == 1)
			return finalPath;
	}
	std::string value= "";
	return value;
}
//*********************************************************************

Tree::Tree()
{

}


Tree::~Tree()
{
}

Tree::Tree(Node *n)
{
	this->root = n;
}