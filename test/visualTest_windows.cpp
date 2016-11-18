#include "C:\Users\Yahia\Desktop\github_repos\rang_for_windows\rang_repo\rang\include\rang.hpp"
#include <iostream>

int main()
{	
	rang::rangWindowsConsoleInit();
	std::cout << rang::style::reset << rang::fg::blue		<< "This is a blue color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::green		<< "This is a green color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::cyan		<< "This is a cyan color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::red		<< "This is a red color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::magenta	<< "This is a magenta color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::yellow		<< "This is a yellow color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::white		<< "This is a white color " << rang::style::reset << std::endl;
	std::cout << rang::style::reset << rang::fg::gray		<< "This is a gray color " << rang::style::reset << std::endl;
	system("pause");
	return 0;
}
