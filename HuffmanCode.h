#pragma once
#include "Tree.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <algorithm> 
#include <fstream>

class HuffmanCode
{
	Tree tree;
	std::string readFromFile(std::string fileName);
	void addSymbol(std::string &text, std::vector<Symbol> &s);
	void eraseNnnecessarySigns(std::string &text);

public:
	void code(std::string fileName);

	HuffmanCode();
	~HuffmanCode();
};

