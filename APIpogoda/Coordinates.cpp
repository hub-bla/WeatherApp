#include "Coordinates.h"


Coordinates::Coordinates(string us_city) {
    string full_link = "https://geocoding-api.open-meteo.com/v1/search?name=" + us_city + "&count=1";
	json data = get_data(full_link);
    
    float lati = data["results"][0]["latitude"];
    float longi = data["results"][0]["longitude"];
    city = data["results"][0]["name"];
    latitude = floor(lati * 100.0) / 100.0;
    longitude = floor(longi * 100.0) / 100.0;
}

Coordinates::~Coordinates(){}


float Coordinates::get_latitude() {
    return latitude;
}

float Coordinates::get_longitude() {
    return longitude;
}

string Coordinates::get_city_name() {
    return city;
}