#include "cat.hpp"
#include <string>
#include <iostream>

CAT::CAT() : _name("default_name")
{
    std::cout << "Default Constructor of Cat: " << _name << std::endl;
}

CAT::CAT(std::string name):_name(name)
{
    std::cout<<" Constructor of Cat : " << _name << std::endl;
}

CAT::~CAT()
{
    std::cout<<" Destructor of Cat : " << _name << std::endl;
}

void CAT::Display()
{
    std::cout<<" CAT name: " << _name << std::endl;
}

void CAT::SetName(std::string name)
{
    _name = name;
}