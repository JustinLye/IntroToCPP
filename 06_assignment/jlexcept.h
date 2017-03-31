#if !defined(_JL_EXCEPT_HEADER_INCLUDED_)
#define _JL_EXCEPT_HEADER_INCLUDED_
#pragma once

#include<sstream>
#include<string>

namespace  jl {
    class jlexcept : public std::exception {
    private:
        std::string file;
        int line;
        std::string description;
        std::string what_string;
    public:
        //constructors
        jlexcept(std::string init_file,int init_line,std::string init_desc) :
            file(init_file),
            line(init_line),
            description(init_desc)
        {
            std::ostringstream s;
            s << file << "(" << line << "):\nERROR - " << description << '\n';
            what_string = s.str();
        }
        jlexcept(std::string init_desc) : file(__FILE__), line(__LINE__), description(init_desc) {
            std::ostringstream s;
            s << description;
            what_string = s.str();
        }
        //accessors
        inline std::string get_file() const throw() { return file; }
        inline int get_line() const throw() { return line; }
        inline std::string get_description() const throw() { return description; }
        const char* what() const throw() { return what_string.c_str(); }

        //modifiers
        inline static void combine_exception_info(jlexcept& e_left, const jlexcept& e_right) {
            std::ostringstream s;
            s << e_left.get_file() << "(" << e_left.get_line() << "):\n\tERROR - " << e_left.get_description() << '\n';
            s << e_right.get_file() << "(" << e_right.get_line() << "):\n\tERROR - " << e_right.get_description() << '\n';
            e_left.what_string = s.str();
        }
        //operators
        inline friend jlexcept& operator+=(jlexcept& e_left, const jlexcept& e_right) {
            combine_exception_info(e_left, e_right);
            return e_left;
        }
        inline friend jlexcept& operator+(const jlexcept& e_left, const jlexcept& e_right) {
            return jlexcept(e_left) += e_right;
        }
    };
}
#endif