#include <cctype>
#include <fstream>
#include <cassert>

#include "TotsParserDriver.h"

using namespace Tots::Language::Syntax::Parser;

TotsParserDriver::~TotsParserDriver()
{
	delete(scanner);
	scanner = nullptr;
	delete(parser);
	parser = nullptr;
}

void TotsParserDriver::parse(const char * const filename)
{
	assert(filename != nullptr);
	std::ifstream in_file(filename);
	if (!in_file.good())
	{
		exit(EXIT_FAILURE);
	}
	parse_helper(in_file);
	return;
}

void TotsParserDriver::parse(std::istream &stream)
{
	if (!stream.good() && stream.eof())
	{
		return;
	}
	//else
	parse_helper(stream);
	return;
}


void TotsParserDriver::parse_helper(std::istream &stream)
{

	delete(scanner);
	try
	{
		scanner = new TotsScanner(&stream);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate scanner: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}

	delete(parser);
	try
	{
		parser = new TotsParser((*scanner) /* scanner */,
			(*this) /* driver */);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate parser: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}
	const int accept(0);
	if (parser->parse() != accept)
	{
		std::cerr << "Parse failed!!\n";
	}
	return;
}
