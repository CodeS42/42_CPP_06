#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct  Data
{
    std::string name;
    int         age;
}               Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& other);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif