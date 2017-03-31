#pragma once
#if !defined(__JL__SIMPLE_ACCOUNT_HEADER_INCLUDED__)
#define __JL__SIMPLE_ACCOUNT_HEADER_INCLUDED__
#include"account.h"
#include"jlexcept.h"
#include<string>
namespace jl {
    class simple_account : public jl::account {
    public:
        simple_account(const std::string& _init_account_code, const std::string& _init_first_name, const std::string& _init_last_name, double _init_balance) try :
            jl::account(_init_account_code, _init_first_name, _init_last_name, _init_balance)
        {
        } catch(jl::jlexcept& e) {
            throw e;
        } catch(std::exception& e) {
            throw e;
        } catch(...) {
            throw jl::jlexcept("Error occurred while constructing simple account");
        }
        inline void monthly_update() { set_balance(get_balance() * 1.05); }
        inline char type() const { return 'A'; }
    };
}
#endif