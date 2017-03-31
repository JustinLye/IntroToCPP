
#include"employee.h"
#include"jlexcept.h"
#include<iostream>
#include<vector>

namespace jl {
    const char* no_selection {"No employee has been selected. You must first select an employee using the select_employee method."};
    class employee_list {
    private:
        unsigned int _size;
        jl::employee* _current_emp;
        std::vector<jl::employee> _list;
    public:
        //constructors
        employee_list() : _size(0), _current_emp(nullptr){}
        //modifiers

        //Reads data from input stream. Assumes data is comma-delimited.
        inline void read_data(std::istream& s) {
            if(!s)
                throw jl::jlexcept("Input file not valid");
            if(s.bad() || s.fail())
                throw jl::jlexcept("Input file state not vaild for data read");
            std::string first_name, last_name;
            float mthly_pay = 0.0;
            while(!s.eof()) {
                char _buffer = s.peek();
                while(_buffer == '\n' && _buffer != EOF) {
                    s.ignore(1);
                    _buffer = s.peek();
                }
                if(!getline(s, first_name, ','))
                    throw jl::jlexcept("Could not read first name");
                if(!getline(s, last_name, ','))
                    throw jl::jlexcept("Could not read last name");
                s >> mthly_pay;
                if(s.bad() || s.fail())
                    throw jl::jlexcept("Error occurred while reading data file");
                _list.push_back(jl::employee(first_name, last_name, mthly_pay));
                _size++;
            }
        }
        inline void clear_list() { _list.clear(); _size = 0; }
        //Gives increase/decrease to all employees in std::vector<employee> _list
        inline void mass_mod_mthly_pay(const float pay_change) {
            try {
                for(jl::employee& emp : _list)
                    emp.set_monthly_pay(emp.get_monthly_pay() + pay_change);
            } catch(const jl::jlexcept& e) {
                throw e;
            }
        }
        inline void push_back(const jl::employee& emp) {
            _list.push_back(emp);
            _size++;
        }
        inline void push_back(const std::string& init_first_name,
            const std::string& init_last_name,
            float init_monthly_pay) try
        {
            push_back(jl::employee(init_first_name,
                init_last_name,
                init_monthly_pay));
        } catch(const jl::jlexcept& e) {
            throw e;
        }
        inline void select_employee(const unsigned int index) {
            if(index >= _size)
                throw jl::jlexcept("Index out of range");
            _current_emp = &_list[index];
        }
        inline void clear_selection() { _current_emp = nullptr; }
        inline void set_first_name(const std::string& new_first_name) try {
            if(!_current_emp)
                throw jl::jlexcept(no_selection);
            _current_emp->set_first_name(new_first_name);
        } catch(const jl::jlexcept& e) {
            throw jl::jlexcept("Failed to set employee first name") += e;
        }
        inline void set_first_name(const char* new_first_name) try {
            if(!_current_emp)
                throw jl::jlexcept(no_selection);
            _current_emp->set_first_name(new_first_name);
        } catch(const jl::jlexcept& e) {
            throw jl::jlexcept("Failed to set employee first name") += e;
        }
        inline void set_last_name(const std::string& new_last_name) try {
            if(!_current_emp)
                throw jl::jlexcept(no_selection);
            _current_emp->set_last_name(new_last_name);
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept("Failed to set employee last name") += e;
        }
        inline void set_last_name(const char* new_last_name) try {
            if(!_current_emp)
                throw jl::jlexcept(no_selection);
            _current_emp->set_last_name(new_last_name);
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept("Failed to set employee last name") += e;
        }
        //output and operators
        inline void output(std::ostream& s) const {
            for(const jl::employee& emp : _list)
                s << emp << '\n';
        }
        friend inline std::ostream& operator<<(std::ostream& s, const jl::employee_list l) {
            l.output(s);
            return s;
        }
        inline const jl::employee& operator[](const unsigned int index) const {
            if(index >= _size)
                throw jl::jlexcept("Index out of range");
            return _list[index];
        }
    };       
}
