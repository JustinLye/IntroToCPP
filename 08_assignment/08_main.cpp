#include"account_manager.h"
#include"jlexcept.h"
#include<iostream>

int main() try {
    jl::account_manager a_mgr("account2.dat");
    a_mgr.main();
} catch(jl::jlexcept& e) {
    std::cerr << e.what() << '\n';
} catch(std::exception& e) {
    std::cerr << e.what() << '\n';
} catch(...) {
    std::cerr << "Unknown error occurred\n";
}