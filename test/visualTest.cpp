#include "rang.hpp"

int main()
{
	std::cout << std::endl
	          << rang::style::reset << rang::bg::green << rang::fg::gray
	          << "If you're seeing green bg, then rang works!"
	          << rang::style::reset << std::endl;
	return 0;
}
