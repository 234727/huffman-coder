#pragma once
#include "Symbol.h"
class Node
{
	Symbol symbol;
public:
	Node *parent;
	Node *leftChild;
	Node *rightChild;
public:
	int getOccurrences() { return symbol.getOccurrences(); }
	std::string getCharacter() { return symbol.getSign(); }
	void setSymbol(Symbol &s) { this->symbol = symbol; }
	Symbol& getSymbol() { return symbol; }
	Node();
	Node(const Node &n);
	Node(Symbol &s) { this->symbol = s; }
	~Node();

	Node &operator = (const Node & n);
};

