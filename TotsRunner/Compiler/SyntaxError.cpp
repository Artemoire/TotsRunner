#include "SyntaxError.h"

std::vector<SyntaxError*> * SyntaxError::errors = new std::vector<SyntaxError*>();

SyntaxError::SyntaxError(const char * m)
{
	msg = m;
}

AssingmentSyntaxError::AssingmentSyntaxError() : SyntaxError("Left of assignment must be an identifier")
{
}
