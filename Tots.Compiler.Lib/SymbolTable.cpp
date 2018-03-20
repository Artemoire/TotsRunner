#include "SymbolTable.h"
#include <string>

LocalSymbol::LocalSymbol(int l, char * i)
{
	loc = l;
	id = i;
}

SymbolTable::SymbolTable()
{
	ptr = 0;
}

bool SymbolTable::is_valid_loc(int loc)
{
	for (int i = 0; i < ptr; ++i)
		if (symbols[i].loc == loc)
			return true;
	return false;
}

int SymbolTable::loc_of(char * id)
{
	for (int i = 0; i < symbols.size(); ++i)
		if (strcmp(symbols[i].id, id) == 0)
			return symbols[i].loc;
	return -1;
}

int SymbolTable::add(char * id)
{
	if (loc_of(id) != -1)
		return -1;

	int loc = symbols.size();
	symbols.insert(symbols.begin() + ptr, LocalSymbol(loc, id));
	ptr++;
	return loc;
}

void SymbolTable::clear()
{
	ptr = 0;
	symbols.clear();
	scopes.clear();
}

void SymbolTable::push_scope()
{
	scopes.push_back(ptr);
}

void SymbolTable::pop_scope()
{
	if (scopes.size() == 0)
		return;

	ptr = scopes.back();
	scopes.pop_back();
}
