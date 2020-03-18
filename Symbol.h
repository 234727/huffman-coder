#pragma once
#include <string>
class Symbol
{
	std::string sign;
	int  occurrences;
public:
	std::string getSign() { return sign; }
	void setSign(std::string s) { this->sign = s; }
	int getOccurrences() { return occurrences; }
	void setOccurrences(int o) { this->occurrences = o; }
	Symbol();
	Symbol(std::string s, int o) { this->sign = s; this->occurrences = o; }
	~Symbol();

	Symbol &operator = (const Symbol & s);
	bool operator < (const Symbol &s);
};

