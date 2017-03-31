#pragma once
#if !defined(__JL__ACCOUNT_FACTORY_HEADER_INCLUDED__)
#define __JL__ACCOUNT_FACTORY_HEADER_INCLUDED__
#include"simple_account.h"
#include"bonus_account.h"
#include"balanced_account.h"
#include"service_account.h"

namespace jl {
    class account_factory {
    public:
        jl::account* operator()(const char, const std::string&, const std::string&, const std::string&, double);
    };
}

#endif