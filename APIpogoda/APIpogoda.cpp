// APIpogoda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Error.h"
#include "CityWeather.h"
#include "Coordinates.h"
#include "NoConnection.h"
using namespace std;




ostream& operator<<(ostream& os, Error* err) {
    os << err->show_error_message() << endl << endl;
    return os;
}



int main()
{
    ifstream File("last_city.txt");
    string city_from_file;
    getline(File, city_from_file);
    File.close();
    while (true) {
        try {
            string city;

            if (city_from_file != "") {
                city = city_from_file;
                city_from_file = "";
            }
            else {
                cout << "Enter city name: ";
                getline(cin, city);
            }
            system("CLS");
            Coordinates corr1 = Coordinates(city);
            CityWeather weather(corr1);
            weather.display_weather();
        }
        catch (Error* err) {
            cout << err;
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
