#pragma once
#include "Error.h"
#include <iostream>
using namespace std;
class NoConnection :
    public Error
{
public:
    string show_error_message() { return "test"; }
};

