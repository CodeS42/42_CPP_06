#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <limits>

# define PSEUDO_LITERALS 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE	4

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		~ScalarConverter();
		static void convert(std::string av1);
		static int whichType(std::string av1);
		static bool isChar(std::string av1);
		static bool isInt(std::string av1);
		static bool isFloat(std::string av1);
		static bool isDouble(std::string av1);
		static void convertChar(std::string av1);
		static void convertInt(std::string av1);
		static void convertFloat(std::string av1);
		static void convertDouble(std::string av1);
		static void convertPseudoLiterals(std::string av1);
};

#endif
