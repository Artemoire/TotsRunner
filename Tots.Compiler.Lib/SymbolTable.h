#pragma once

#include <vector>

class LocalSymbol
{
public:
	int loc;
	char * id;

	LocalSymbol(int, char*);
};

class SymbolTable
{
	int ptr;
	std::vector<LocalSymbol> symbols;
	std::vector<int> scopes;

public:	

	SymbolTable();

	bool is_valid_loc(int);
	int loc_of(char*);
	int add(char*);

	void clear();
	void push_scope();
	void pop_scope();
};