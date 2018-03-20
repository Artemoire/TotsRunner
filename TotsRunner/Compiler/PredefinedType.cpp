#include "PredefinedType.h"

char *predefIdentifier(Tots::Language::PredefTypes type)
{
	switch (type)
	{		
		case Tots::Language::PredefTypes::_VOID:
		{
			return (char*)Tots::Language::Keywords::void_keyword;
		}
		case Tots::Language::PredefTypes::_INT:
		{
			return (char*)Tots::Language::Keywords::int_keyword;
		}
		case Tots::Language::PredefTypes::_FLOAT:
		{
			return (char*)Tots::Language::Keywords::float_keyword;
		}
		case Tots::Language::PredefTypes::_BOOL:
		{
			return (char*)Tots::Language::Keywords::bool_keyword;
		}
		case Tots::Language::PredefTypes::_CHAR:
		{
			return (char*)Tots::Language::Keywords::char_keyword;
		}
	}
}

PredefinedType::PredefinedType(Tots::Language::PredefTypes type) : TypeSyntax(predefIdentifier(type))
{
	kind = SyntaxKind::kPredefinedType;
	ptype = type;
}
