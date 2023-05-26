#include "fetch_data.h"

json fetch_data(string link) {

    cpr::AsyncResponse fr = cpr::GetAsync(cpr::Url{ link });
    fr.wait();

    cpr::Response r = fr.get();
    if (r.error) {
        Error* wskazniczek = new NoConnection();
        throw wskazniczek;
    }
    json data = json::parse(r.text);
    return data;
}

