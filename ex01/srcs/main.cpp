#include "../headers/Serializer.hpp"

int main(void)
{
    Data* ptr = new Data;

    ptr->name = "Anna";
    ptr->age = 6;

    std::cout << ptr << std::endl;
    std::cout << ptr->name << std::endl;
    std::cout << ptr->age << std::endl;

    std::cout << std::endl;

    std::cout << Serializer::deserialize(Serializer::serialize(ptr)) << std::endl;
    std::cout << ptr->name << std::endl;
    std::cout << ptr->age << std::endl;

    delete ptr;
    return (0);
}
