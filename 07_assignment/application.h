#if !defined(__application__header_included__)
#define __application__header_included__

#include"account.h"
#include"jlexcept.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stdexcept>
namespace jl {
    class application {
    private:
        std::vector<jl::account> __accounts;
        std::string __input_file_path;
        double __total_balance;
        inline void read_file(std::ifstream& s) try {
            if(!s)
                throw jl::jlexcept("Input file invalid");
            if(!s.is_open())
                s.open(__input_file_path);
            if(!s)
                throw jl::jlexcept("Input file could not be opened");
            while(!s.eof()) {
                char __buffer = s.peek();
                while(__buffer == '\n' && __buffer != EOF) {
                   s.ignore(1);
                   __buffer = s.peek();
                }
                if(__buffer != EOF) {
                   char __account[10];
                   char __first_name[15];
                   char __last_name[25];
                   double __balance = 0;
                   s.read(__account, sizeof(__account));
                   if(s.bad()||s.fail())
                       throw jl::jlexcept("Error reading account code from data file");
                   s.read(__first_name, sizeof(__first_name));
                   if(s.bad()||s.fail())
                       throw jl::jlexcept("Error reading first name from data file");
                   s.read(__last_name, sizeof(__last_name));
                   if(s.bad()||s.fail())
                       throw jl::jlexcept("Error reading last name from data file");
                   s >> __balance;
                   if(s.bad()||s.fail())
                       throw jl::jlexcept("Error reading balance from data file");

                   __accounts.push_back(jl::account(
                       std::string(__account, sizeof(__account)),
                       std::string(__first_name, sizeof(__first_name)),
                       std::string(__last_name, sizeof(__last_name)),
                       __balance));
                   __total_balance += __balance;
                }
            }
            s.close();
            if(s.fail()||s.bad())
                throw jl::jlexcept("Error closing input file");
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept("Error occurred while attempting to read the input file") + e;
        } catch(std::exception& e) {
            throw jl::jlexcept("Error occurred while attempting to read the input file") + jl::jlexcept(e.what());
        } catch(...) {
            throw jl::jlexcept("Error occurred while attempting to read the input file") + jl::jlexcept("Unknown error");
        }
        inline void output(std::ostream& s) const {
            s << std::left << std::setw(10) << "Account" << '\t'
                << std::setw(42) << "Last Name, First Name" << '\t'
                << std::right << std::setw(15) << "Balance" << '\n';
            for(const jl::account& acct : __accounts)
                s << acct << '\n';
            s << "Total Balance\t" << std::setw(63) << std::setprecision(2)
                << std::fixed << std::right << __total_balance << '\n';
        }
    public:
        application(const std::string& fp) try : __input_file_path(fp), __total_balance(0) {
            if(fp.empty())
                throw jl::jlexcept("Input file path cannot be empty string");
            std::ifstream __input_file(__input_file_path);
            read_file(__input_file);
            std::sort(__accounts.begin(), __accounts.end());
            std::ofstream __output_file;
            __output_file.open("Report.txt");
            if(!__output_file)
                throw jl::jlexcept("Output file could not be opened");
            output(__output_file);
            __output_file.close();

        } catch(jl::jlexcept& e) {
            throw jl::jlexcept("Error occurred constructing application object") + e;
        } catch(std::exception& e) {
            throw jl::jlexcept("Error occurred while attempting to construct application object") + jl::jlexcept(e.what());
        } catch(...) {
            throw jl::jlexcept("Unknown error occurred while attempting to construct application object");
        }
        application(const char* fp) try : __input_file_path(fp), __total_balance(0) {
            std::ifstream __input_file(__input_file_path);
            if(!fp)
                throw jl::jlexcept("Input file path cannot be null");
            read_file(__input_file);
            std::sort(__accounts.begin(), __accounts.end());
            std::ofstream __output_file;
            __output_file.open("Report.txt");
            if(!__output_file)
                throw jl::jlexcept("Output file could not be opened");
            output(__output_file);
        } catch(jl::jlexcept& e) {
            throw jl::jlexcept("Error occurred constructing applcation object") + e;
        } catch(std::exception e) {
            throw jl::jlexcept("Error occurred while attempting to construct application object") + jl::jlexcept(e.what());
        } catch(...) {
            throw jl::jlexcept("Unknown error occurred while attempting to construct application object");
        }

    };
}
#endif