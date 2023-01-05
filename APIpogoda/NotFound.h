#pragma once
#include "Error.h"
class NotFound :
    public Error
{
private:
    string city_name;
public:
    NotFound(string ct);
    string show_error_message() { return "Couldn't find city: " + city_name; }
};

