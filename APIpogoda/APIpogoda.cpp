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
    public:
        void to_fahrenheit();
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
    cout << converted_latitude << endl;
    cout << converted_longitude << endl;

    string weather_link = "https://api.open-meteo.com/v1/forecast?latitude=" + to_string(converted_latitude) + "&longitude=" + to_string(converted_longitude) + "&current_weather=true";

    cpr::AsyncResponse fwr = cpr::GetAsync(cpr::Url{ weather_link });
    fwr.wait(); // This waits until the request is complete
    cpr::Response wr = fwr.get(); // Since the request is complete, this returns immediately
    json weather_data = json::parse(wr.text);
    float temperature = weather_data["current_weather"]["temperature"];
    cout << weather_data << endl;
    cout << temperature << "°C" << endl;
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
