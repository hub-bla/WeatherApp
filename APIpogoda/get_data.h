#pragma once
#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <cmath>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

json get_data(string city_name);
