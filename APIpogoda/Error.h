#pragma once
#include <iostream>
using namespace std;
class Error
{
private:
	string error_message;
public:
	virtual string show_error_message()=0;
	friend ostream& operator<<(ostream& os, Error* err);
};

