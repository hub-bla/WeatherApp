#pragma once
#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <cmath>
#include <nlohmann/json.hpp>
#include "NoConnection.h"
using namespace std;
using json = nlohmann::json;

json get_data(string city_name);
