#if !defined(_JL_EMPLOYEE_HEADER_INCLUDED_)
#define _JL_EMPLOYEE_HEADER_INCLUDED_
#pragma once

#include "jlexcept.h"
#include <string>

namespace jl {
    class employee {
    private:
        std::string first_name;
        std::string last_name;
        float monthly_pay;
        inline bool is_empty(const char* c) {
            if (!c)
                return false;
            else 
                return c[0] == '\0';
        }
    public:
        //constructors
        employee(const std::string& init_first_name,
            const std::string& init_last_name,
            const float init_monthly_pay) :
            first_name(init_first_name),
            last_name(init_last_name),
            monthly_pay(init_monthly_pay) {
            if(init_first_name.empty() || init_last_name.empty())
                throw jl::jlexcept("First and last name cannot be blank.");
            if(init_monthly_pay <= 0)
                throw jl::jlexcept("Monthly pay must be greater than zero.");
        }
        employee(const char* init_first_name,
            const char* init_last_name,
            const float init_monthly_pay) :
            first_name(init_first_name),
            last_name(init_last_name),
            monthly_pay(init_monthly_pay) {
            if(is_empty(init_first_name) || is_empty(init_last_name))
                throw jl::jlexcept("First and last name cannot be blank.");
            if(init_monthly_pay <= 0)
                throw jl::jlexcept("Monthly pay must be greater than zero.");
        }
        //accessors

		//Returns the first name
        inline std::string get_first_name() const throw() { return first_name; }
		//Returns the last name
        inline std::string get_last_name() const throw() { return last_name; }
		//Returns monthly pay
        inline float get_monthly_pay() const throw() { return monthly_pay; }

        //modifiers

		//Sets the value of the first name
        inline void set_first_name(const std::string& new_first_name) {
            if(new_first_name.empty())
                throw jl::jlexcept("First name cannot be blank");
            first_name = new_first_name;
        }
		//Sets the value of the first name
        inline void set_first_name(const char* new_first_name) {
            if(is_empty(new_first_name))
                throw jl::jlexcept("First name cannot be blank");
            first_name = new_first_name;
        }

		//Sets the value of the last name
        inline void set_last_name(const std::string& new_last_name) {
            if(new_last_name.empty())
                throw jl::jlexcept("Last name cannot be blank");
            last_name = new_last_name;
        }

		//Sets the value of the last name
        inline void set_last_name(const char* new_last_name) {
            if(is_empty(new_last_name))
                throw jl::jlexcept("Last name cannot be blank");
            last_name = new_last_name;
        }

		//Sets the value of monthly pay
        inline void set_monthly_pay(const float new_monthly_pay) {
            if(new_monthly_pay <= 0)
                throw jl::jlexcept("Monthly pay must be greater than zero");
            monthly_pay = new_monthly_pay;
        }
        
		//Outputs first_name, last_name, monthly_pay
        inline void output(std::ostream& s) const {
            s << first_name << ',' << last_name << ',' << monthly_pay;
        }
        friend inline std::ostream& operator<<(std::ostream& s, const jl::employee& emp) {
            emp.output(s);
            return s;
        }
    };
}
#endif