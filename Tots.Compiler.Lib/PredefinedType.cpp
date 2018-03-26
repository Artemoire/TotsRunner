#include "PredefinedType.h"

PredefinedType::PredefinedType(Tots::Language::PredefTypes type)
{
	kind = SyntaxKind::kPredefinedType;
	ptype = type;
}
