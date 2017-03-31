#if !defined(__JL_ACCOUNT_HEADER_INCLUDED__)
#define __JL_ACCOUNT_HEADER_INCLUDED__
#include"trim.h"
#include"jlexcept.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>

namespace {
    const char construction_exception[] = {"Error occurred while attempting to construct account object"};
}

namespace jl {
    class account {
    private:
        std::string account_number;
        std::string first_name;
        std::string last_name;
        double balance;
    public:
        account(std::string& init_account_number, std::string& init_first_name, std::string& init_last_name, double init_balance) try :
            account_number(init_account_number),
            first_name(generic::trim_right(init_first_name)),
            last_name(generic::trim_right(init_last_name)),
            balance(init_balance)
        {
            if (init_account_number.empty())
                throw jl::jlexcept("Account number cannot be empty string");
            if (init_first_name.empty())
                throw jl::jlexcept("First name cannot be empty string");
            if (init_last_name.empty())
                throw jl::jlexcept("Last name cannot be empty string");
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept(construction_exception) + e;
        } catch(std::exception& e) {
            throw jl::jlexcept(construction_exception) + jl::jlexcept(e.what());
        } catch(...) {
            throw jl::jlexcept(construction_exception) + jl::jlexcept("Unknown error");
        }
        account(const char* init_account_number,
            const char* init_first_name,
            const char* init_last_name,
            double init_balance) try :
            account_number(std::string(init_account_number)),
            first_name(generic::trim_right(std::string(init_first_name))),
            last_name(generic::trim_right(std::string(init_last_name))),
            balance(init_balance)
        {
            if(account_number.empty())
                throw jl::jlexcept("Account number cannot be empty string");
            if(first_name.empty())
                throw jl::jlexcept("First name cannot be empty string");
            if(last_name.empty())
                throw jl::jlexcept("Last name cannot be empty string");
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept(construction_exception) + e;
        } catch(std::exception& e) {
            throw jl::jlexcept(construction_exception) + jl::jlexcept(e.what());
        } catch(...) {
            throw jl::jlexcept(construction_exception) + jl::jlexcept("Unknown error");
        }

        inline std::string get_account_number() const throw() { return account_number; }
        inline std::string get_first_name() const throw() { return first_name; }
        inline std::string get_last_name() const throw() { return last_name; }
        inline double get_balance() const throw() { return balance; }

        inline friend bool operator<(const jl::account& l, const jl::account& r) {
            return strcmp(l.get_account_number().c_str(), r.get_account_number().c_str()) < 0;
        }

        inline void output(std::ostream& s) const {
            s << std::left << std::setw(10) << account_number
                << '\t' << std::setw(42) << first_name + ", " + last_name
                << '\t' << std::right << std::setw(15) << std::fixed
                << std::setprecision(2) << balance;
        }
        friend inline std::ostream& operator<<(std::ostream& s, const jl::account& a) {
            a.output(s);
            return s;
        }
    };
}
#endif