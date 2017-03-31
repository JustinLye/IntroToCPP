#include"account.h"
#include<sstream>
#include<iomanip>

jl::account::account(const std::string& _init_account_code, const std::string& _init_first_name, const std::string& _init_last_name, double _init_balance) try : 
    account_code(_init_account_code), first_name(_init_first_name), last_name(_init_last_name), balance(_init_balance)
{
    if(account_code.empty())
        throw jl::jlexcept("Account code cannot be an empty string");
    if(first_name.empty())
        throw jl::jlexcept("First name cannot be an empty string");
    if(last_name.empty())
        throw jl::jlexcept("Last name cannot be an empty string");
} catch(jl::jlexcept& e) {
    throw e;
} catch(std::exception& e) {
    throw jl::jlexcept(e.what());
} catch(...) {
    throw jl::jlexcept(construct_excpt_msg) + jl::jlexcept("Unknown error");
}

std::string jl::account::to_string() const {
    std::string rtn_string;
    rtn_string = account_code;
    rtn_string += first_name;
    std::fill_n(std::back_inserter(rtn_string), 15 - first_name.size(), ' ');
    rtn_string += last_name;
    std::fill_n(std::back_inserter(rtn_string), 25 - last_name.size(), ' ');
    rtn_string += type();
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(11) << std::fixed << std::setprecision(2) << balance;
    rtn_string += ss.str();
    return rtn_string;
}

