#include "get_data.h"

json get_data(string link) {
    
    cpr::AsyncResponse fr = cpr::GetAsync(cpr::Url{ link });
    fr.wait(); 
    cpr::Response r = fr.get(); 
    json data = json::parse(r.text);
    return data;
}

