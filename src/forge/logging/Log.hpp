#ifndef __HG__FIR__LOGGING__LOG_H__
#define __HG__FIR__LOGGING__LOG_H__

#include <cstdio>
#include <cstdarg>
#include <ctime>


namespace forge {
namespace logging {

    void init(FILE *outStream, FILE *errStream);
    void deInit();

    namespace out {
        void print(const char *format, ...);
    }

    namespace err {
        void print(const char *format, ...);
    }


    // Definition:
    static
    FILE *_OutStream = nullptr;

    static
    FILE *_ErrStream = nullptr;


    static
    void printTimeStamp(FILE *stream) {
        time_t timeNow;
        time(&timeNow);

        tm *timeInfo = localtime(&timeNow);

        char str_months[12][4] = {
            "Jan",
            "Feb",
            "Mar",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
        };

        char str_days[7][4] = {
            "Sun",
            "Mon",
            "Tue",
            "Wed",
            "Thu",
            "Fri",
            "Sat"
        };

        fprintf(stream,
                "[%s|%d %s %d][%d:%d:%d]| ",
                str_days[timeInfo->tm_wday],
                timeInfo->tm_mday,
                str_months[timeInfo->tm_mon],
                timeInfo->tm_year + 1900,
                timeInfo->tm_hour,
                timeInfo->tm_min,
                timeInfo->tm_sec);
    }


    void init(FILE *outStream, FILE *errStream) {
        _OutStream = outStream;
        _ErrStream = errStream;
    }


    void deInit() {
        _OutStream = nullptr;
        _ErrStream = nullptr;
    }


    void out::print(char const *format, ...) {
        va_list args;
        va_start(args, format);

        printTimeStamp(_OutStream);
        vfprintf(_OutStream, format, args);
        fprintf(_OutStream, "\n");

        va_end(args);
    }


    void err::print(char const *format, ...) {
        va_list args;
        va_start(args, format);

        printTimeStamp(_ErrStream);
        vfprintf(_ErrStream, format, args);
        fprintf(_OutStream, "\n");

        va_end(args);
    }

}   // namespace logging
}   // namespace forge


#endif // __HG__FIR__LOGGING__LOG_H__
