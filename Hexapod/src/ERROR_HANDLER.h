#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <Arduino.h>

class ERROR_HANDLER {
    public:
        static void HANDLE_ERROR(const char* ERROR_MESSAGE, bool HALT = false);
        static bool CHECK_CONDITION(bool CONDITION, const char* ERROR_MESSAGE, bool HALT = false);
};

#endif