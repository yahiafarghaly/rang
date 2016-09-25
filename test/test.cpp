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
		rang::init();

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

TEST_CASE("Rang printing to standard output", "[terminal]")
{
	std::string s = "Rang works with ";

	SECTION("output is to terminal")
	{

		std::cout << rang::fg::green << s << "std::cout" << rang::style::reset
		          << std::endl;

		std::clog << rang::fg::blue << s << "std::clog" << rang::style::reset
		          << std::endl;

		std::cerr << rang::fg::red << s << "std::cerr" << rang::style::reset
		          << std::endl;
		REQUIRE(1 == 1);
	}
}
