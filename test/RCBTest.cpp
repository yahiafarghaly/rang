#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "rang.hpp"

#include <fstream>
#include <string>

std::string RCB(std::string input)
{
	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	std::cout << rang::fg::blue << input << rang::style::reset;

	std::cout.rdbuf(coutbuf);
	out.close();
	
	std::ifstream in("out.txt");
	std::string output;
	std::getline(in,output);
	return output;

}

TEST_CASE("Redirected cout buffer", "RCB")
{
	REQUIRE(RCB("HelloWorld") == "HelloWorld");
}

