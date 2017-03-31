#pragma once
#if !defined(__JL__SERVICE_ACCOUNT_HEADER_INCLUDED)
#define __JL__SERVICE_ACCOUNT_HEADER_INCLUDED
#include"account.h"
#include"jlexcept.h"
#include<string>
namespace jl {
    class service_account : public account {
    public:
        service_account(const std::string& _init_account_code, const std::string& _init_first_name, const std::string& _init_last_name, double _init_balance) try :
            jl::account(_init_account_code, _init_first_name, _init_last_name, _init_balance)
        {
        } catch(jl::jlexcept& e) {
            throw e;
        } catch(std::exception& e) {
            throw e;
        } catch(...) {
            throw jl::jlexcept("Unkown error");
        }
        inline void monthly_update() { set_balance((get_balance() - 5.0) * 1.04); }
        inline char type() const { return 'C'; }
    };
}
#endif