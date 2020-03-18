#include "HuffmanCode.h"


void HuffmanCode::code(std::string fileName)
{
	// ALGORYTM KROK PO KROKU

	// 1. wczytanie do string ca³ego pliku
	std::string text = readFromFile(fileName);
	eraseNnnecessarySigns(text);
	std::string textCopy = text;
	
	// 2. utworzenie symboli
	std::vector<Symbol> symbols;
	while(textCopy.length() != 0)
		addSymbol(textCopy, symbols);

	// 3. posortowanie symboli
	std::sort(symbols.begin(), symbols.end());

	// 4. utoworzenie wêz³ów 
	std::vector<Node> nodes;
	for (int i = 0; i < symbols.size(); ++i)
	{
		Node *n = new Node(symbols[i]);
		nodes.push_back(*n);
	}

	// 5. utworzenie drzew
	std::vector<Tree> trees;
	for (int i = 0; i < nodes.size(); ++i)
	{
		Tree *t = new Tree(&nodes[i]);
		trees.push_back(*t);
	}

	// 6. budowanie drzewa
	this->tree.push(nodes[0]);
	for (int i = 1; i < trees.size(); ++i)
		this->tree.push(trees[i]);

	// 7. kodowanie i zapis do pliku 
	std::fstream file;
	std::string line;
	file.open("zakodowana.txt", std::ios::out);
	if (file.good())
	{
		for (int i = 0; i < text.length(); ++i)
		{
			char ch = text[i];
			std::string character(1, ch);
			file << this->tree.getPath(character);
		}
		file.close();
	}
}
//******************************************************
std::string HuffmanCode::readFromFile(std::string fileName)
{
	std::ifstream t(fileName);
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}
//***************************************************************
void HuffmanCode::addSymbol(std::string &text, std::vector<Symbol> &symbols)
{
	char ch = text[0];
	int occurennces = 0;
	unsigned int position = 0;

	while (position != -1)
	{
		position = text.find(ch);
		if (position != -1)
		{
			++occurennces;
			text.erase(position, 1);
		}
	}

	std::string character(1, ch);
	Symbol *s = new Symbol(character, occurennces);
	symbols.push_back(*s);
}
//*******************************************************
void HuffmanCode::eraseNnnecessarySigns(std::string &text)
{
	for (int i = 0; i < text.length(); ++i)
	{
		char ch = text[i];
		if (ch < 97 || ch > 122)
			text.erase(i, 1);

	}
}
HuffmanCode::HuffmanCode()
{
}


HuffmanCode::~HuffmanCode()
{
}
