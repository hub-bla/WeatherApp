#pragma once
#include <cmath>
#include <iomanip>

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
    void get_weather_condition(int condition_code);
public:
    CityWeather(Coordinates* cor);
    friend json get_data(string city_name);
    void display_weather();
};

