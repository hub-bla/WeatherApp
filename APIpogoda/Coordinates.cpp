#include "Coordinates.h"


vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}


string join(const vector<string>& v, const string& delimiter = "%20") {
    string out;
    auto i = v.begin();
    auto e = v.end();
    if (i != e) {
        out += *i++;
        for (; i != e; ++i) out.append(delimiter).append(*i);
    }
    return out;
}

Coordinates::Coordinates(string us_city) {
    vector<string> v = split(us_city, ' ');
    if (v.size() >= 2) {
        city = join(v);

    }
    else {
        city = us_city;
    }
    string full_link = "https://geocoding-api.open-meteo.com/v1/search?name=" + city + "&count=1";
    json data = fetch_data(full_link);
    if (data["results"].is_null()) {
        Error* err_ptr = new NotFound(us_city);
        throw err_ptr;
    }
    float lati = data["results"][0]["latitude"];
    float longi = data["results"][0]["longitude"];
    city = data["results"][0]["name"];
    latitude = floor(lati * 100.0) / 100.0;
    longitude = floor(longi * 100.0) / 100.0;
}

Coordinates::~Coordinates() {}


