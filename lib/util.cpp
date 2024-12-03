#include "util.hpp"

//std
#include <fstream>
#include <set>

namespace util {
	std::string util::read_string(std::istream& is) {
		static const std::set whitespace = { ' ', '\t', '\n' };
		std::string result;
		while (whitespace.contains(is.peek()))
			is.ignore();
		if (is.get() != '\"')
			throw std::runtime_error("util.hpp, read_string: string doesn't have \" at start");

		char c = is.get();
		do {
			result += c;
			c = is.get();
		} while (c != '\"');

		return result;
	}

	void read_tests(size_t test_id, const std::function<void(std::istream& is)>& test_maker) {
		std::string filename = "tests/p" + std::to_string(test_id) + ".txt";
		std::fstream file(filename);
		while(!file.eof())
			test_maker(file);
		file.close();
	}
}
