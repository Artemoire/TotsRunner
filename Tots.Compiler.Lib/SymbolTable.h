#pragma once

#include <vector>
#include "PredefTypes.h"

class TypeSymbol
{
public:
	bool predefined;
	Tots::Language::PredefTypes ptype;
	// TYPEDEF

	TypeSymbol();
	TypeSymbol(Tots::Language::PredefTypes);
};

class LocalSymbol
{
public:
	int loc;
	char * id;
	TypeSymbol type;

	LocalSymbol(int, char*, TypeSymbol);
};

class SymbolTable
{
	int ptr;
	std::vector<LocalSymbol> symbols;
	std::vector<int> scopes;
	
	char * building;

public:	

	SymbolTable();

	void curr(char*);
	bool is_curr(char*);

	bool is_valid_loc(int);
	int loc_of(char*);
	LocalSymbol get(int);
	int add(char*, TypeSymbol);

	void clear();
	void push_scope();
	void pop_scope();
};