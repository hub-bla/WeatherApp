#pragma once
#include "get_data.h"
#include <cmath>
#include <iomanip>
#include <cpr/cpr.h>
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
class Coordinates
{
private:
	float latitude;
	float longitude;
	string city;
public:
	friend json get_data(string city_name);
	Coordinates(string u_city);
	float get_longitude();
	float get_latitude();
	string get_city_name();
	~Coordinates();

};

