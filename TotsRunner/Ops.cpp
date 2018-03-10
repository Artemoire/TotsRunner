#include "Ops.h"

#define ERR_ABORT(...) ERR(__VA_ARGS__, "Aborting...")

#define ERR_DIV_ZERO() ERR_ABORT("Division By Zero. Oops")


void Ops::Op(OpsExtensions op, DWRD * v1, DWRD * v2)
{
	switch (op)
	{
		case OpsExtensions::kADD_I32:
		{
			DLOG("+=");
			*(WRD*)v1 += *(WRD*)v2;
			DLOG(*v1);
			break;
		}
		case OpsExtensions::kSUB_I32:
		{
			DLOG("-=");
			*(WRD*)v1 -= *(WRD*)v2;
			break;
		}
		case OpsExtensions::kMUL_I32:
		{
			DLOG("*=");
			*(WRD*)v1 *= *(WRD*)v2;
			DLOG(*(WRD*)v1);
			break;
		}
		case OpsExtensions::kDIV_I32:
		{
			DLOG("/=");
			if (*(WRD*)v2 == 0)
			{
				ERR_DIV_ZERO(); // TODO: EH
			}				

			*(WRD*)v1 /= *(WRD*)v2;
			break;
		}		
		case OpsExtensions::kADD_F32:
		{
			DLOG("+=");
			*(Float*)v1 += *(Float*)v2;
			DLOG(*(Float*)v1);
			break;
		}
		case OpsExtensions::kSUB_F32:
		{
			DLOG("-=");
			*(Float*)v1 -= *(Float*)v2;
			DLOG(*(Float*)v1);
			break;
		}
		case OpsExtensions::kMUL_F32:
		{
			DLOG("*=");
			*(Float*)v1 *= *(Float*)v2;
			DLOG(*(Float*)v1);
			break;
		}
		case OpsExtensions::kDIV_F32:
		{
			DLOG("/=");
			*(Float*)v1 /= *(Float*)v2;
			DLOG(*(Float*)v1);
			break;
		}
		case OpsExtensions::kAND:
		{
			DLOG("&=");
			*v1 &= *v2;
			DLOG(*v1);
			break;
		}
		case OpsExtensions::kOR:
		{
			DLOG("|=");
			*v1 |= *v2;
			DLOG(*v1);
			break;
		}
		case OpsExtensions::kXOR:
		{
			DLOG("^=");
			*v1 ^= *v2;
			DLOG(*v1);
			break;
		}
		case OpsExtensions::kSHR32:
		{
			DLOG(">>=");
			*(WRD*)v1 >>= *(WRD*)v2;
			DLOG(*v1);
			break;
		}
		case OpsExtensions::kSHL32:
		{
			DLOG("<<=");
			*(WRD*)v1 <<= *(WRD*)v2;
			DLOG(*v1);
			break;
		}
	}
}

#define I32_COMPARE(CMPRTR) I32 w1 = *(I32*)v1; I32 w2 = *(I32*)v2; if(w1 CMPRTR w2) { *(WRD*)v1 = 1; DLOG("True"); } else { *(WRD*)v1 = 0; DLOG("False"); }

#define WRD_COMPARE(CMPRTR) WRD w1 = *(WRD*)v1; WRD w2 = *(WRD*)v2; if(w1 CMPRTR w2) { *(WRD*)v1 = 1; DLOG("True"); } else { *(WRD*)v1 = 0; DLOG("False"); }

void Ops::Cmp(CmpExtensions op, DWRD * v1, DWRD * v2)
{
	switch (op)
	{	
		case(CmpExtensions::kCEQ32):
		{
			DLOG("==");
			WRD_COMPARE(== )
			break;
		}
		case(CmpExtensions::kCNE32):
		{
			DLOG("!=");
			WRD_COMPARE(!= )
			break;
		}
		case (CmpExtensions::kCGEI32):
		{
			DLOG(">=");
			I32_COMPARE(>= )
			break;
		}
		case (CmpExtensions::kCGEUI32):
		{
			DLOG(">=");
			WRD_COMPARE(>= )
			break;
		}
		case (CmpExtensions::kCGTI32):
		{
			DLOG(">");
			I32_COMPARE(> )
			break;
		}
		case (CmpExtensions::kCGTUI32):
		{
			DLOG(">");
			WRD_COMPARE(> )
			break;
		}
		case (CmpExtensions::kCLEI32):
		{
			DLOG("<=");
			I32_COMPARE(<= )
			break;
		}
		case (CmpExtensions::kCLEUI32):
		{
			DLOG("<=");
			WRD_COMPARE(<= )
			break;
		}
		case (CmpExtensions::kCLTI32):
		{
			DLOG("<");
			I32_COMPARE(< )
			break;
		}
		case (CmpExtensions::kCLTUI32):
		{
			DLOG("<");
			WRD_COMPARE(< )
			break;
		}
	}
}

#undef I32_COMPARE
#undef WRD_COMPARE
#undef ERR_DIV_ZERO