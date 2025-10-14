#ifndef ERREURKAREN_H
#define ERREURKAREN_H

#include <iostream>
using namespace std;


class nomInvalide : public std::runtime_error{
public:
    nomInvalide(string s) : std::runtime_error(s){}
};



class tailleInvalide : public std::runtime_error{
public:
    tailleInvalide(string s) : std::runtime_error(s){}
};

#endif // ERREURKAREN_H
