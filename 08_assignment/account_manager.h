#pragma once
#if !defined(__JL__ACCOUNT_MANAGER_HEADER_INCLUDED__)
#define __JL__ACCOUNT_MANAGER_HEADER_INCLUDED__
#include"account_factory.h"
#include"exception_log.h"
#include"trim.h"
#include<vector>
#include<fstream>
#include<string>
namespace jl {
    struct acct_data {
        char _type;
        std::string _account_code;
        std::string _first_name;
        std::string _last_name;
        double _balance;
    };
    class account_manager {
    private:
        const std::string input_file_name;
        std::vector<jl::account*> accounts;
        jl::exception_log _log;
        inline void open_input_file(std::ifstream& is) {
            is.open(input_file_name);
            if(is.bad() || is.fail())
                throw jl::jlexcept("Input file could not be opened or does not exist");
        }
    public:
        account_manager(const std::string& _init_input_file_name) try : input_file_name(_init_input_file_name), _log("account.log", std::ios_base::out) {
            if(input_file_name.empty())
                throw jl::jlexcept("Input file name cannot be empty string");
        } catch(std::exception& e) {
            throw e;
        } catch(...) {
            throw jl::jlexcept("Unknow error occurred while constructing jl::account_manager");
        }
        ~account_manager() { for(jl::account* a : accounts) delete a; }
        void main();
        acct_data* parse_line_input(const std::string&) const;
        void print_report(const std::string&) const;
        inline void update_accounts() { for(jl::account* a : accounts) a->monthly_update(); }
        inline void output(std::ostream& s) const { for(jl::account* a : accounts) s << *a << '\n'; }
        inline void add_account(const char, const std::string&,
            const std::string&, const std::string&, double);
        inline std::vector<std::string> to_string() const {
            std::vector<std::string> s_vec;
            for(jl::account* a : accounts)
                s_vec.push_back(a->to_string());
            return s_vec;
        }
        inline friend std::ostream& operator<<(std::ostream& s, const jl::account_manager& a_mgr) {
            a_mgr.output(s);
            return s;
        }
    };

    inline void jl::account_manager::add_account(const char _type, const std::string& _account_code,
        const std::string& _first_name, const std::string& _last_name, double _balance) {
        jl::account_factory __factory;
        jl::account* acct_ptr = __factory(_type, _account_code, _first_name, _last_name, _balance);
        if(acct_ptr)
            accounts.push_back(acct_ptr);
    }
}

#endif