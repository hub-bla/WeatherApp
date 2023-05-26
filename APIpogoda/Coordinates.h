#pragma once
#include "fetch_data.h"
#include <cmath>
#include <iomanip>
#include <cpr/cpr.h>
#include <string>
#include <nlohmann/json.hpp>
#include "NotFound.h"
#include <vector>
#include <sstream>
using namespace std;
using json = nlohmann::json;
class Coordinates
{
public:
	float latitude;
	float longitude;
	string city;
	Coordinates(string u_city);
	~Coordinates();

};

