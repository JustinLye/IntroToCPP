#pragma once
#if !defined(__JL__EXCEPTION_RECORD_HEADER_INCLUDED__)
#define __JL__EXCEPTION_RECORD_HEADER_INCLUDED__
#include<cstdint>
#include<string>
namespace jl {
    class exception_record {
    private:
        std::string exception_msg;
        uint32_t record_number;
    public:
        exception_record(const std::string& _init_msg, const uint32_t _init_record = 0) :
            exception_msg(_init_msg), record_number(_init_record)
        {}
        inline void output(std::ostream& s) const {
            if(!record_number)
                s << exception_msg;
            else
                s << "Record Number: " << record_number << '\t' << exception_msg;
        }
        inline friend std::ostream& operator<<(std::ostream& s, const exception_record& er) {
            er.output(s);
            return s;
        }
    };
}

#endif