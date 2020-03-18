#include "Symbol.h"


Symbol::Symbol()
{
}

Symbol::~Symbol()
{
}

Symbol & Symbol::operator=(const Symbol &s)
{
	if (&s != this)
	{
		this->sign = s.sign;
		this->occurrences = s.occurrences;
	}
	return *this;
}

bool Symbol::operator<(const Symbol &s)
{
	return this->occurrences < s.occurrences;
}