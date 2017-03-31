#include"application.h"
#include"jlexcept.h"
#include <iostream>
#include <fstream>

int main() try {
    jl::application app("account.dat");
    return 0;
} catch(jl::jlexcept& e) {
    std::cerr << e.what();
} catch(std::exception& e) {
    std::cerr << e.what() << '\n';
} catch(...) {
    std::cerr << "Unknown error occurred";
}
