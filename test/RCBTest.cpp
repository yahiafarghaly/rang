#include <fstream>
#include "rang.hpp"

int main()
{
	std::cout << rang::fg::blue << "\nShould be blue";
	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	std::string word = "not blue";
	std::cout << "START " << rang::fg::blue << word << " END";

	std::cout.rdbuf(coutbuf);
	std::cout << "\nShould again be blue" << rang::style::reset << std::endl;
	return 0;
}
