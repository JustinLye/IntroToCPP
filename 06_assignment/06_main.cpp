#include"employee_list.h"
#include"jlexcept.h"
#include<iostream>
#include<fstream>
#include<stdexcept>
const char* file_name {"employee.dat"};
const char* output_file_name {"ouput.dat"};
int main() try {
    std::ifstream data_file;
    std::ofstream out_file;
    jl::employee_list my_list;
    data_file.open(file_name);
    if(!data_file)
        throw jl::jlexcept("Input file could not be opened");
    if(!data_file.is_open())
        data_file.open(file_name);
    my_list.read_data(data_file);
    my_list.mass_mod_mthly_pay(50.0);
    out_file.open(output_file_name);
    if(!out_file)
        throw jl::jlexcept("Output file could not be opened");
    out_file << my_list << '\n';
} catch(const jl::jlexcept& e) {
    std::cerr << e.what() << '\n';
} catch(const std::exception e) {
    std::cerr << e.what() << '\n';
}
