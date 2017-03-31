#pragma once
#if !defined(__JL__BONUS_ACCOUNT_HEADER_INCLUDED__)
#define __JL__BONUS_ACCOUNT_HEADER_INCLUDED__
#include"account.h"
#include"jlexcept.h"
#include<string>
namespace jl {
    class bonus_account : public account {
    public:
        bonus_account(const std::string& _init_account_code, const std::string& _init_first_name, const std::string& _init_last_name, double _init_balance) try :
            jl::account(_init_account_code, _init_first_name, _init_last_name, _init_balance)
        {
        } catch(jl::jlexcept& e) {
            throw e;
        } catch(std::exception& e) {
            throw e;
        } catch(...) {
            throw jl::jlexcept("Unknown error");
        }
        inline void monthly_update() { set_balance(get_balance() * (get_balance() > 5000 ? 1.06 : 1.04)); }
        inline char type() const { return 'B'; }
    };
}
#endif