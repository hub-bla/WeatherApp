#pragma once
#include <cmath>
#include <iomanip>
#include <fstream>
#include "Coordinates.h"

class CityWeather
{

private:
    float temperature_in_celsius;
    float temperature_in_fahrenheit;
    float latitude;
    float longitude;
    float wind_speed;
    string name_of_city;
    string weather_condition;
    void get_weather_condition(int condition_code);
public:
    friend void to_fahrenheit(CityWeather& weather);
    CityWeather(Coordinates& cor);
    ~CityWeather();
    void display_weather();
};

