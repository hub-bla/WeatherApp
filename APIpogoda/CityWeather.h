#pragma once
#include <cmath>
#include <iomanip>
#include <fstream>
#include "Coordinates.h"

class CityWeather
{

private:
    float temperature_in_celsius;
    float latitude;
    float longitude;
    float wind_speed;
    string name_of_city;
    string weather_condition;
    void str_weather_condition(int condition_code);
public:
    CityWeather(Coordinates& cor);
    ~CityWeather();
    void display_weather();
};

