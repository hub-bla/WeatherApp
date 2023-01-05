#pragma once
#include "Error.h"
class NoConnection :
    public Error
{
public:
    string show_error_message();
};

