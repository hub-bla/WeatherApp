#include "CityWeather.h"


CityWeather::CityWeather(Coordinates* cor) {
	string weather_link = "https://api.open-meteo.com/v1/forecast?latitude=" + to_string(cor->get_latitude()) + "&longitude=" + to_string(cor->get_longitude()) + "&current_weather=true";
	json weather_data = get_data(weather_link);
    name_of_city = cor->get_city_name();
    longitude = cor->get_longitude();
    latitude = cor->get_latitude();
    temperature_in_celsius = weather_data["current_weather"]["temperature"];
    wind_speed = weather_data["current_weather"]["windspeed"];
	int condition = weather_data["current_weather"]["weathercode"];
    get_weather_condition(condition);
}



void CityWeather::get_weather_condition(int condition_code) {
    map<int, std::string> condition_codes{ {0, "clear sky"}, {1, "mainly clear"}, {2, "partly cloudy"},
        {3, "overcast"}, {45, "fog"}, {48, "despositing rime fog"}, {51, "light drizzle"},
        {53, "moderate drizzle"}, {55, "dense drizzle"}, {56, "light freezing drizzle"}, {57, "dense freezing drizzle"},
        {61, "slight rain"}, {63, "moderate rain"}, {65, "heavy rain"}, {66, "light freezing rain"}, {67, "heavy frezzing rain"},
        {71, "slight snow fall"}, {73, "moderate snowfall"}, {75, "heavy snow fall"}, {77, "snow grains"},
        {80, "slight rain shower"}, {81, "moderate rain shower"}, {82, "violent rain shower"}, {85, "slight snow shower"},
        {86, "heavy snow shower"}, {95, "thunderstorm"}, {96, "thunderstorm with slight hail"}, {99, "thunderstorm with heavy hail"} };

    weather_condition = condition_codes[condition_code];
}


void CityWeather::display_weather() {
    cout << "City: " << name_of_city << endl;
    cout << "Temperature (in Celsius): " << temperature_in_celsius << endl;
    cout << "Wind Speed: " << wind_speed << endl;
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "Weather Condition: " << weather_condition << endl;
}
