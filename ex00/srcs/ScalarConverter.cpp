#include "../headers/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(std::string av1)
{
	if (av1.size() > 1 || isdigit(av1[0]))
		return (false);
	return (true);
}

bool ScalarConverter::isInt(std::string av1)
{
	size_t i = 0;

	if (!isdigit(av1[0]) && av1[0] != '-' && av1[0] != '+')
		return (false);
	if (av1[0] != '-' || av1[0] != '+')
		i++;
	while (i < av1.size())
	{
		if (!isdigit(av1[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isFloat(std::string av1)
{
	int string_size = av1.size();
	int i = 0;

	if (!isdigit(av1[0]) && av1[0] != '-' && av1[0] != '+')
		return (false);
	if (av1[0] != '-' || av1[0] != '+')
		i++;
	while (i < string_size)
	{
		if (av1[i] == '.' || av1[i] == 'f')
			break;
		else if (!isdigit(av1[i]))
			return (false);
		i++;
	}
	if ((av1[i] != '.' && av1[i] != 'f') 
		|| (av1[i] == 'f' && (i + 1) < string_size) 
		|| (av1[i] == '.' && (i + 1) == string_size))
		return (false);
	if (av1[i] == '.' && av1[i + 1] == 'f')
		return (false);
	while(++i < string_size)
	{
		if (!isdigit(av1[i]) && av1[i] != 'f')
			return (false);
	}
	if (av1[i - 1] != 'f')
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(std::string av1)
{
	int string_size = av1.size();
	int i = 0;

	if (!isdigit(av1[0]) && av1[0] != '-' && av1[0] != '+')
		return (false);
	if (av1[0] != '-' || av1[0] != '+')
		i++;
	while (i < string_size)
	{
		if (av1[i] == '.')
			break;
		else if (!isdigit(av1[i]))
			return (false);
		i++;
	}
	if ((av1[i] != '.') || (av1[i] == '.' && (i + 1) == string_size))
		return (false);
	while(++i < string_size)
	{
		if (!isdigit(av1[i]))
			return (false);
	}
	return (true);
}

void ScalarConverter::convertChar(std::string av1)
{
	if (av1[0] >= 32 && av1[0] <= 126)
		std::cout << "char: '" << av1[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(av1[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(av1[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(av1[0]) << std::endl;
}

void ScalarConverter::convertInt(std::string av1)
{
	long nb = strtol(av1.c_str(), NULL, 10);

	if (nb >= 32 && nb <= 126)
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (nb >= std::numeric_limits<int>::min() && nb <= std::numeric_limits<int>::max())
	{
		int n = static_cast<int>(nb);
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
	}
	else
	{
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
}

void ScalarConverter::convertFloat(std::string av1)
{
	float nb = strtof(av1.c_str(), NULL);
	long nb_long = static_cast<long>(nb);
	
	if (nb >= 32 && nb <= 126)
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (nb_long >= std::numeric_limits<int>::min() && nb_long <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

void ScalarConverter::convertDouble(std::string av1)
{
	double nb = strtod(av1.c_str(), NULL);
	long nb_long = static_cast<long>(nb);
	
	if (nb >= 32 && nb <= 126)
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (nb_long >= std::numeric_limits<int>::min() && nb_long <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
}

void ScalarConverter::convertPseudoLiterals(std::string av1)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;

	if (av1 == "nan" || av1 == "nanf")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
	else if (av1 == "+inf" || av1 == "+inff")
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
}

int ScalarConverter::whichType(std::string av1)
{
	if (av1 == "nan" || av1 == "nanf" 
		|| av1 == "+inf" || av1 == "+inff"
		|| av1 == "-inf" || av1 == "-inff")
		return (0);
	else if (isChar(av1))
		return (1);
	else if (isInt(av1))
		return (2);
	else if (isFloat(av1))
		return (3);
	else if (isDouble(av1))
		return (4);

	return (-1);
}

void ScalarConverter::convert(std::string av1)
{
	switch (whichType(av1))
	{
		case PSEUDO_LITERALS:
			convertPseudoLiterals(av1);
			break;
		case CHAR:
			convertChar(av1);
			break;
		case INT:
			convertInt(av1);
			break;
		case FLOAT:
			convertFloat(av1);
			break;
		case DOUBLE:
			convertDouble(av1);
			break;
		default:
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
			break;
	}
}
