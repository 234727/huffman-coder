// main.cpp : Defines the entry point for the console application.
//

#include "Heap.h"
#include "HuffmanCode.h"

int main()
{
	HuffmanCode c;
	std::string fileName;
	std::cout << "Podaj nazwe pliku z wiadomoscia do zakodowania" << std::endl << "(bez rozszerzenia; program obs³uguje pliki .txt)" << std::endl;
	std::cin >> fileName;
	fileName += ".txt";

	c.code(fileName);
	char ch = std::getchar();
    return 0;
}

