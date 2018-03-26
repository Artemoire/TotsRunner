#include "QualifiedNameSyntax.h"

QualifiedNameSyntax::QualifiedNameSyntax(NameSyntax * l, SimpleNameSyntax * r)
{
	kind = kQualifiedNameSyntax;
	left = l;
	right = r;
}
