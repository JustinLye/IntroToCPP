#include"account_factory.h"
#include<sstream>
jl::account* jl::account_factory::operator()(const char _type, const std::string& _account_code, const std::string& _first_name, const std::string& _last_name, double _balance) {
    jl::account* a_ptr = nullptr;
    switch(_type) {
    case 'A':
        a_ptr = new jl::simple_account(_account_code, _first_name, _last_name, _balance);
        break;
    case 'B':
        a_ptr = new jl::bonus_account(_account_code, _first_name, _last_name, _balance);
        break;
    case 'C':
        a_ptr = new jl::service_account(_account_code, _first_name, _last_name, _balance);
        break;
    case 'D':
        a_ptr = new jl::service_account(_account_code, _first_name, _last_name, _balance);
        break;
    case 'X':
        break;
    default:
        std::stringstream ss;
        ss << _type << " is not a recognized account type";
        throw jl::jlexcept(ss.str());
        break;
    }
    return a_ptr;
}