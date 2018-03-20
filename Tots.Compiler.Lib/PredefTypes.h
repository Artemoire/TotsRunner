#pragma once

#define PTYPES(V)	\
V(_VOID)	        \
V(_INT)				\
V(_FLOAT)			\
V(_BOOL)			\
V(_CHAR)			\

#define DECLARE_ENUM(Name) Name,

namespace Tots
{
	namespace Language
	{
		enum PredefTypes
		{
			PTYPES(DECLARE_ENUM)
		};
	}
}