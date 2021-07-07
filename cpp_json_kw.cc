#include <iostream>
#include <optional>
#include <string>
#include <json.hpp>
#include <stdexcept>
#include <complex>

#include <iostream>

using nlohmann::json;

template <typename T>
struct mapped_json_value {bool success ; std::optional<T> value;};

template <typename T>
auto kws_get(const json &j, const std::string & key) -> mapped_json_value<T>
{
   if (auto iter = j.find(key); iter != j.end()) {
       try {
           return { true, iter->get<T>() };
       }
       catch (std::exception & e) {
           std::cerr << "bad conversion: " << e.what() << std::endl;
           throw;
       }
   }
   return {};
}

int main (int argc, char** argv)
{ 
    json J {
        {"hello", 3.3 },
    };

    if (const auto [_bool, _optional] = kws_get<std::string>(J,"hello"); _bool && _optional)
    {
        std::cout << "yes " << *_optional << std::endl;    
    } 
    else {
        std::cout << "no  " << std::endl;    
        //_optional;
    }

}
