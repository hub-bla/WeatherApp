// APIpogoda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;



class Weather {
private:
    float temperature_in_celsius;
    float latitude;
    float longitude;
    float wind_speed;
    string name_of_city;
    string weather_condition;
    void get_weather_condition(int condition_code);
    public:
        Weather(float lat, float lon, float wind_s, float temp, int condition);
        void to_fahrenheit();
        void display_weather();
};

int main()
{
    string  city_name;
    cout << "Enter name of city: ";
    cin >> city_name;
    string full_link = "https://geocoding-api.open-meteo.com/v1/search?name=" + city_name + "&count=1";
    cpr::AsyncResponse fr = cpr::GetAsync(cpr::Url{ full_link });
    fr.wait(); // This waits until the request is complete
    cpr::Response r = fr.get(); // Since the request is complete, this returns immediately
    json data = json::parse(r.text);
    float latitude = data["results"][0]["latitude"];
    float longitude = data["results"][0]["longitude"];
    float converted_latitude = floor(latitude * 100.0) / 100.0;
    float converted_longitude = floor(longitude * 100.0) / 100.0;

    string weather_link = "https://api.open-meteo.com/v1/forecast?latitude=" + to_string(converted_latitude) + "&longitude=" + to_string(converted_longitude) + "&current_weather=true";

    cpr::AsyncResponse fwr = cpr::GetAsync(cpr::Url{ weather_link });
    fwr.wait(); // This waits until the request is complete
    cpr::Response wr = fwr.get(); // Since the request is complete, this returns immediately
    json weather_data = json::parse(wr.text);
    float temperature = weather_data["current_weather"]["temperature"];
    float wind_s = weather_data["current_weather"]["windspeed"];
    int condition = weather_data["current_weather"]["weathercode"];
    Weather weather1(converted_latitude, converted_longitude, wind_s, temperature, condition );

    weather1.display_weather();
}



Weather::Weather(float lat, float lon, float wind_s, float temp, int condition) {
    latitude = lat;
    longitude = lon;
    wind_speed = wind_s;
    temperature_in_celsius = temp;
    get_weather_condition(condition);
};


void Weather::get_weather_condition(int condition_code) {
    map<int, std::string> condition_codes{ {0, "clear sky"}, {1, "mainly clear"}, {2, "partly cloudy"},
        {3, "overcast"}, {45, "fog"}, {48, "despositing rime fog"}, {51, "light drizzle"},
        {53, "moderate drizzle"}, {55, "dense drizzle"}, {56, "light freezing drizzle"}, {57, "dense freezing drizzle"},
        {61, "slight rain"}, {63, "moderate rain"}, {65, "heavy rain"}, {66, "light freezing rain"}, {67, "heavy frezzing rain"},
        {71, "slight snow fall"}, {73, "moderate snowfall"}, {75, "heavy snow fall"}, {77, "snow grains"},
        {80, "slight rain shower"}, {81, "moderate rain shower"}, {82, "violent rain shower"}, {85, "slight snow shower"},
        {86, "heavy snow shower"}, {95, "thunderstorm"}, {96, "thunderstorm with slight hail"}, {99, "thunderstorm with heavy hail"}};

    weather_condition = condition_codes[condition_code];
}

void Weather::display_weather() {
    cout << "City: " << name_of_city << endl;
    cout << "Temperature (in Celsius): " << temperature_in_celsius << endl;
    cout << "Wind Speed: " << wind_speed << endl;
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "Weather Condition: " << weather_condition << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
