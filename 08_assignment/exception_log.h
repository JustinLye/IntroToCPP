#pragma once
#if !defined(__JL__EXCEPTION_LOG_HEADER_INCLUDED__)
#define __JL__EXCEPTION_LOG_HEADER_INCLUDED__
#include"exception_record.h"
#include"jlexcept.h"
#include<vector>
#include<fstream>
namespace jl {
    class exception_log {
    private:
        std::string _log_file_name;
        std::ios_base::open_mode _open_mode;
        uint32_t _exception_count;
        std::vector<jl::exception_record> _exceptions;
    public:
        exception_log(const std::string& _init_log_file_name, const std::ios_base::openmode& _init_open_mode) :
            _log_file_name(_init_log_file_name), _open_mode(_init_open_mode), _exception_count(0) {
            if(_log_file_name.empty())
                throw jl::jlexcept("jl::exception_log member '_log_file_name' cannot be an empty string");
        }
        ~exception_log() { if(_exception_count > 0) dump(); }
        inline void add_exception(const jl::exception_record& er) { _exceptions.push_back(er); ++_exception_count; }
        inline void add_exception(const std::string& s, const uint32_t r = 0) { _exceptions.push_back(jl::exception_record(s, r)); ++_exception_count; }
        inline void add_exception(const char* s, const uint32_t r = 0) { _exceptions.push_back(jl::exception_record(s, r)); ++_exception_count; }
        template<typename T>
        inline void add_exception(const T& e, const uint32_t r = 0) { _exceptions.push_back(jl::exception_record(e.what(), r)); ++_exception_count; }
        inline void dump() {
            if(_exception_count > 0) {
                std::ofstream _log;
                _log.open(_log_file_name.c_str(), _open_mode);
                if(_log.bad() || _log.fail())
                    throw jl::jlexcept(_log_file_name + " could not be opened");
                for(jl::exception_record er : _exceptions)
                    _log << er << '\n';
                _log.close();
                _exceptions.clear();
                _exception_count = 0;
            }
        }
    };
}

#endif