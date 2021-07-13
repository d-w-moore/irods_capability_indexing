#ifndef __es_detail_hpp
#define __es_detail_hpp

#include <fmt/format.h>
#include <utility>
#include <map>
#include <list>
#include <string>

namespace irods {
namespace indexing {
namespace detail {

    using std::string;

    std::string url_path() { return {}; }
    std::string url_path(const std::string & s) { return s; }

    template<class...T>
    std::string url_path (const std::string & s, T...t)
    {
        return  s + "/" + url_path(t...);
    }

    // define URL 

    class Url {
        string path_;
        std::map<string,string> params_;
    public:
        template<class...String> Url(String... s): path_(url_path(s...)) {}
        void append_to_path(const string &elem) { path_ += ( path_.size()?"/":"" ) + elem; }
        void set_param(const string& s, const  string & v="" ) { params_[s]=v; }
        void clear_param(const string& s) { params_.erase(s); }
        void clear_all_params() { params_.clear(); }
        string params_to_string() const {
            string s; 
            for(const auto & [k,v]: params_) { 
              const auto & x = fmt::format("{}={}",k,v);
              s += (s.size()?"&":"?") + x;
            }
            return s; 
        }
        string format () const { return path_ + params_to_string(); }
    };


} //namespace detail
} //namespace indexing
} //namespace irods

#endif //es_detail_hpp
