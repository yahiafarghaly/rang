#ifndef RANG_DOT_HPP
#define RANG_DOT_HPP

#if defined(__unix__) || defined(__unix) || defined(__linux__)
#define OS_LINUX
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define OS_WIN
#elif defined(__APPLE__) || defined(__MACH__)
#define OS_MAC
#else
#error Unknown Platform
#endif

#if defined(OS_LINUX) || defined(OS_MAC)
#include <unistd.h>
#elif defined(OS_WIN)
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <Windows.h>
#endif

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <type_traits>

namespace rang {

namespace {
	std::streambuf const *RANG_coutbuf = std::cout.rdbuf();
	std::streambuf const *RANG_cerrbuf = std::cerr.rdbuf();
	std::streambuf const *RANG_clogbuf = std::clog.rdbuf();
}

enum class style {
#if defined(OS_LINUX) || defined(OS_MAC)
	reset     = 0,
	bold      = 1,
	dim       = 2,
	italic    = 3,
	underline = 4,
	blink     = 5,
	reversed  = 6,
	conceal   = 7,
	crossed   = 8
#elif defined(OS_WIN)
	reset	  = 255		//Different value to remove the collision of comparsion between the color code 0 with the <Value T> in << overload operator
#endif
};

enum class fg {
#if defined(OS_LINUX) || defined(OS_MAC)
	black   = 30,
	red     = 31,
	green   = 32,
	yellow  = 33,
	blue    = 34,
	magenta = 35,
	cyan    = 36,
	gray    = 37
#elif defined(OS_WIN)
	black	= 0,
	blue	= 1,
	green	= 2,
	cyan	= 3,
	red		= 4,
	magenta = 5,
	yellow	= 6,
	white	= 7,
	gray	= 8
#endif
};

enum class bg {
	black   = 40,
	red     = 41,
	green   = 42,
	yellow  = 43,
	blue    = 44,
	magenta = 45,
	cyan    = 46,
	gray    = 47
};

enum class fgB {
	black   = 90,
	red     = 91,
	green   = 92,
	yellow  = 93,
	blue    = 94,
	magenta = 95,
	cyan    = 96,
	gray    = 97
};

enum class bgB {
	black   = 100,
	red     = 101,
	green   = 102,
	yellow  = 103,
	blue    = 104,
	magenta = 105,
	cyan    = 106,
	gray    = 107
};

#if defined(OS_WIN)
struct windowsConsoleInfo
{
	HANDLE hstdout;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};

static windowsConsoleInfo wci;

#endif

inline bool supportsColor()
{

#if defined(OS_LINUX) || defined(OS_MAC)
	const std::string Terms[] =
		{
			"ansi", "color", "console", "cygwin", "gnome", "konsole", "kterm",
			"linux", "msys", "putty", "rxvt", "screen", "vt100", "xterm"
		};

	const char *env_p = std::getenv("TERM");
	if (env_p == nullptr) {
		return false;
	}

	std::string env_string(env_p);
	static const bool result = std::any_of(std::begin(Terms), std::end(Terms),
		[&](std::string term) {
			return env_string.find(term) != std::string::npos;
		});
	return result;

#elif defined(OS_WIN)
	const char *env_p = std::getenv("COMSPEC"); //cmd path
	if (env_p == nullptr) {
		return false;
	}
	else
		return true;
#endif
}

inline bool isTerminal(const std::streambuf *osbuf)
{
	if (osbuf == RANG_coutbuf) {
#if defined(OS_LINUX) || defined(OS_MAC)
		return isatty(fileno(stdout)) ? true : false;
#elif defined(OS_WIN)
		return _isatty(_fileno(stdout)) ? true : false;
#endif
	}

	if (osbuf == RANG_cerrbuf || osbuf == RANG_clogbuf) {
#if defined(OS_LINUX) || defined(OS_MAC)
		return isatty(fileno(stderr)) ? true : false;
#elif defined(OS_WIN)
		return _isatty(_fileno(stderr)) ? true : false;
#endif
	}
	return false;
}

#if defined(OS_WIN)
//Must be called before using rang
inline void rangWindowsConsoleInit()
{
	wci.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	// Remember the initial settings for current console
	GetConsoleScreenBufferInfo(wci.hstdout, &(wci.csbi));
}
static inline void rangWindowsConsoleReset()
{
	SetConsoleTextAttribute(wci.hstdout, wci.csbi.wAttributes);
}
#endif

template <typename T>
using enable = typename std::enable_if
	<
		std::is_same<T, rang::style>::value ||
		std::is_same<T, rang::fg>::value ||
		std::is_same<T, rang::bg>::value ||
		std::is_same<T, rang::fgB>::value ||
		std::is_same<T, rang::bgB>::value,
		std::ostream&
	>::type;

template <typename T>
inline enable<T> operator<<(std::ostream &os, T const value)
{
	std::streambuf const *osbuf = os.rdbuf();
#if defined(OS_LINUX) || defined(OS_MAC)
	return ((supportsColor()) && (isTerminal(osbuf)))
	  ? os << "\033[" << static_cast<int>(value) << "m"
	  : os;
#elif defined(OS_WIN)
	int value_i = static_cast<int>(value);
	if ((supportsColor()) && (isTerminal(osbuf)))
	{
		if (value_i == static_cast<int>(rang::style::reset))
			rangWindowsConsoleReset();
		else
			SetConsoleTextAttribute(wci.hstdout, value_i);
		return os;
	}
	else
		return os;
#endif
}
}

#undef OS_LINUX
#undef OS_WIN
#undef OS_MAC

#endif /* ifndef RANG_DOT_HPP */
