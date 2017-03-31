#include"account_manager.h"

void jl::account_manager::main() {
    std::ifstream is;
    uint32_t _records_processed = 0;
    try {
        open_input_file(is);
    } catch(jl::jlexcept& e) {
        _log.add_exception(e);
        _log.dump();
        throw e;
    }
    std::string line_input;
    while(!is.eof()) {
        char _buffer = is.peek();
        while(_buffer == '\n' && _buffer != EOF) {
            is.ignore(1);
            _buffer = is.peek();
        }
        if(_buffer != EOF) {
            ++_records_processed;
            std::getline(is, line_input, '\n');
            try {
                jl::acct_data* a_data = parse_line_input(line_input);
                add_account(a_data->_type, a_data->_account_code, a_data->_first_name,
                    a_data->_last_name, a_data->_balance);
                delete a_data;
            } catch(jl::jlexcept& e) {
                _log.add_exception(e, _records_processed);
            }
        } else {
            break;
        }
    }
    update_accounts();
    std::vector<std::string> u_vec;
    u_vec = to_string();
    std::ofstream os;
    os.open("update.dat");
    if(os.bad() || os.fail()) {
        _log.add_exception("Output file for updated accounts could not be opened");
    } else {
        for(auto s : u_vec)
            os << s << '\n';
        os.close();
        if(os.bad() || os.fail()) {
            _log.add_exception("Output file for updated accounts could not be closed");
        }
        try {
            print_report("Report.txt");
        } catch(jl::jlexcept& e) {
            _log.add_exception(e);
        }
    }
    _log.dump();
}

jl::acct_data* jl::account_manager::parse_line_input(const std::string& _input) const {
    if(_input.size() != 62)
        throw jl::jlexcept("Line input is not formatted correctly. "
        "Fields are delimited by fixed widths:\n\tAccount = 10\n\tFirst Name = 15\n\tLast Name = 25"
        "\n\tType = 1\n\tBalance = 11 - Balance should be filled with 0's and two decimal places");
    jl::acct_data* a_data_ptr = new jl::acct_data;
    a_data_ptr->_account_code = _input.substr(0, 10);
    a_data_ptr->_first_name = generic::trim_right(_input.substr(10, 15));
    a_data_ptr->_last_name = generic::trim_right(_input.substr(25, 25));
    a_data_ptr->_type = _input.substr(50, 1).c_str()[0];
    a_data_ptr->_balance = std::stod(_input.substr(51, 11));
    return a_data_ptr;
}

void jl::account_manager::print_report(const std::string& _output) const {
    std::ofstream os;
    os.open(_output);
    if(os.bad() || os.fail())
        throw jl::jlexcept(_output + " could not be opened");
    os << "Type" << "    " << std::setw(12) << std::left << "Account Code" << "    "
        << std::setw(35) << std::left << "Last Name, First Name"
        << std::setw(12) << std::right << "Balance\n";
    for(jl::account* a : accounts) {
        os << a->type() << "       " << std::setw(12) << std::left << a->get_account_code()
            << "    " << std::setw(35) << std::left << a->get_last_name() + ", " + a->get_first_name()
            << std::setw(11) << std::fixed << std::setprecision(2) << std::right << a->get_balance() << '\n';
    }
    os.close();
    if(os.bad() || os.fail())
        throw jl::jlexcept(_output + " could not be closed");
        
}