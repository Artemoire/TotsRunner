#pragma once

#include <vector>

class SyntaxError
{
public:
	static std::vector<SyntaxError*> * errors;

	const char * msg;
	SyntaxError(const char *);
};

class AssingmentSyntaxError : public SyntaxError
{
public:	
	AssingmentSyntaxError();
};