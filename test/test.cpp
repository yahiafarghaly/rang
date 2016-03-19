#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "rang.hpp"
#include <fstream>
#include <string>

TEST_CASE("Rang printing to non-terminals", "[file]")
{
	std::string s = "Hello World";

	SECTION("output is to a file")
	{
		std::ofstream out("out.txt");
		std::streambuf *coutbuf = std::cout.rdbuf();
		std::cout.rdbuf(out.rdbuf());

		std::cout << rang::fg::blue << s << rang::style::reset;

		std::cout.rdbuf(coutbuf);
		out.close();

		std::ifstream in("out.txt");
		std::string output;
		std::getline(in, output);

		REQUIRE(s == output);
	}
}
