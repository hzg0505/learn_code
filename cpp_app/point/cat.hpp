#ifndef CAT_H
#define CAT_H
#include <string>
#include <iostream>

class CAT
{
private:
    std::string _name;

public:
    CAT(std::string name);
    CAT();
    ~CAT();
    void Display();
    void SetName(std::string name);
};

#endif