#pragma once

#include "defs.h"
#include "CharCodes.h"

namespace Ops
{
	void Op(OpsExtensions op, DWRD * v1, DWRD * v2);
	void Cmp(CmpExtensions op, DWRD * v1, DWRD * v2);
}