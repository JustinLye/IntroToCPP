#pragma once

#if !defined(__JL__ACCOUNT_HEADER_INCLUDED__)
#define __JL__ACCOUNT_HEADER_INCLUDED__
#include"jlexcept.h"
#include<cstdlib>
#include<iomanip>
#include<string>

namespace jl {
    const char construct_excpt_msg[] = { "Error occurred while attempting to construct account object" };
    const char invalid_mbr_excpt_msg[] = {"An error occurred while attempting to change to value of a data member"};
    class account {
    private:
        std::string account_code;
        std::string first_name;
        std::string last_name;
        double balance;
    public:
        account(const std::string&, const std::string&, const std::string&, double);
        virtual void monthly_update() = 0;
        virtual char type() const = 0;

        inline const std::string& get_account_code() const throw() { return account_code; };
        inline const std::string& get_first_name() const throw() { return first_name; };
        inline const std::string& get_last_name() const throw() { return last_name; };
        inline const double get_balance() const throw() { return balance; };

        inline void set_account_code(const std::string&);  //defined below
        inline void set_first_name(const std::string&);    //defined below
        inline void set_last_name(const std::string&);     //defined below
        inline void set_balance(double b) { balance = b; }
        std::string to_string() const;
        inline void output(std::ostream& s) const {
            s << this->type() << ',' << account_code << ',' << first_name << ',' << last_name << ',' << std::fixed << std::setprecision(2) << balance;
        }
        
        inline bool operator<(const std::string& s) const { return account_code < s; }
        inline bool operator<=(const std::string& s) const { return account_code <= s; }
        inline bool operator==(const std::string& s) const { return account_code == s; }
        inline bool operator>(const std::string& s) const { return account_code > s; }
        inline bool operator>=(const std::string& s) const { return account_code >= s; }
        inline bool operator<(const char* s) const { return account_code < s; }
        inline bool operator<=(const char* s) const { return account_code <= s; }
        inline bool operator==(const char* s) const { return account_code == s; }
        inline bool operator>(const char* s) const { return account_code > s; }
        inline bool operator>=(const char* s) const { return account_code >= s; }

        template<typename T>
        inline bool operator<(const T a) const { return account_code < a.account_code; }
        template<typename T>
        inline bool operator<=(const T a) const { return account_code <= a.account_code; }
        template<typename T>
        inline bool operator==(const T a) const { return account_code == a.account_code; }
        template<typename T>
        inline bool operator>(const T a) const { return account_code > a.account_code; }
        template<typename T>
        inline bool operator>=(const T a) const { return account_code >= a.account_code; }
        friend inline std::ostream& operator<<(std::ostream& s, const jl::account& a) {
            a.output(s);
            return s;
        }
    };

    inline void jl::account::set_account_code(const std::string& s) try {
        if(s.empty())
            throw jl::jlexcept("Account code cannot be an empty string");
        account_code = s;
    } catch(jl::jlexcept& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + e;
    } catch(std::exception& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept(e.what());
    } catch(...) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept("Unknown error");
    }

    inline void jl::account::set_first_name(const std::string& s) try {
        if(s.empty())
            throw jl::jlexcept("First name cannot be an empty string");
        first_name = s;
    } catch(jl::jlexcept& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + e;
    } catch(std::exception& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept(e.what());
    } catch(...) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept("Unknown error");
    }

    inline void jl::account::set_last_name(const std::string& s) try {
        if(s.empty())
            throw jl::jlexcept("Last name cannot be an empty string");
        last_name = s;
    } catch(jl::jlexcept& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + e;
    } catch(std::exception& e) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept(e.what());
    } catch(...) {
        throw jl::jlexcept(invalid_mbr_excpt_msg) + jl::jlexcept("Unknown error");
    }
}
#endif