// APIpogoda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <nlohmann/json.hpp>
#include "Error.h"
#include "CityWeather.h"
#include "Coordinates.h"
#include "NoConnection.h"
using namespace std;
using json = nlohmann::json;




ostream& operator<<(ostream& os, Error* err) {
    os << err->show_error_message();
    return os;
}
int main()
{
    while (true) {
        try {
            string city;
            cout << "Enter city name: ";
            cin >> city;
            Coordinates* corr = new Coordinates(city);
            CityWeather weather(corr);
            weather.display_weather();
        }
        catch (Error* err) {

        }
    }
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
