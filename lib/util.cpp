#include "util.hpp"

namespace util {
	std::string read_string(std::istream& is) {
		static const std::set whitespace = { ' ', '\t', '\n' };
		std::string result;
		while (whitespace.contains(is.peek()))
			is.ignore();
		if (is.get() != '\"')
			throw std::runtime_error("util.hpp, read_string: string doesn't have \" at start");

		char c = is.get();
		if (c != '\"') {
			do {
				result += c;
				c = is.get();
			} while (c != '\"');
		}
		is.get();

		//std::cout << result << ' ';
		return result;
	}
}
