#pragma once
#include <string>
#include <cstddef>
#include <istream>

#include "TotsScanner.h"
#include "TotsParser.tab.hh"
#include "SyntaxRoot.h"

namespace Tots
{
	namespace Language
	{
		namespace Syntax
		{
			namespace Parser
			{
				class TotsParserDriver {
				public:
					SyntaxRoot * root = nullptr;

					TotsParserDriver() = default;

					virtual ~TotsParserDriver();

					/**
					* parse - parse from a file
					* @param filename - valid string with input file
					*/
					void parse(const char * const filename);
					/**
					* parse - parse from a c++ input stream
					* @param is - std::istream&, valid input stream
					*/
					void parse(std::istream &iss);
				private:

					void parse_helper(std::istream &stream);					
					TotsParser *parser = nullptr;
					TotsScanner *scanner = nullptr;
				};
			}
		}
	}
}
