# include "../headers/child_classes.hpp"

Base* generate(void)
{
    std::srand(std::time(0));

    switch (std::rand() % 3)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }

    return (NULL);
}

void identify(Base* p)
{
    A* a_ptr = dynamic_cast<A*>(p);
    B* b_ptr = dynamic_cast<B*>(p);
    C* c_ptr = dynamic_cast<C*>(p);

    if (a_ptr)
        std::cout << "The real type of the object pointed to by p is : A" << std::endl;
    else if (b_ptr)
        std::cout << "The real type of the object pointed to by p is : B" << std::endl;
    else if (c_ptr)
        std::cout << "The real type of the object pointed to by p is : C" << std::endl;
    else
        std::cout << "The real type of the object pointed to by p, is not A, B, or C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a_ptr = dynamic_cast<A&>(p);
        (void)a_ptr;
        std::cout << "The real type of the object pointed to by p is : A" << std::endl;
        return;
    }
    catch(...) {}

    try
    {
        B& b_ptr = dynamic_cast<B&>(p);
        (void)b_ptr;
        std::cout << "The real type of the object pointed to by p is : B" << std::endl;
        return;
    }
    catch(...) {}

    try
    {
        C& c_ptr = dynamic_cast<C&>(p);
        (void)c_ptr;
        std::cout << "The real type of the object pointed to by p is : C" << std::endl;
        return;
    }
    catch(...) {}
    
    std::cout << "The real type of the object pointed to by p, is not A, B, or C" << std::endl;
}

int main(void)
{
    Base* tab_ptr[] = { new A,
                        new B,
                        new C };

    Base& a_ref = *tab_ptr[0];
    Base& b_ref = *tab_ptr[1];
    Base& c_ref = *tab_ptr[2];

    Base* rand_class;

    std::cout << "identify() with pointers :" << std::endl;
    for(int i = 0 ; i < 3 ; i++)
        identify(tab_ptr[i]);
    
    std::cout << "identify() with references :" << std::endl;
    identify(a_ref);
    identify(b_ref);
    identify(c_ref);

    std::cout << "identify() with generate :" << std::endl;
    rand_class = generate();
    identify(rand_class);

    for(int i = 0 ; i < 3 ; i++)
        delete tab_ptr[i];
    delete rand_class;
    
    return (0);
}
