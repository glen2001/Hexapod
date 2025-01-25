#include <ERROR_HANDLER.h>
#include <Arduino.h>

void ERROR_HANDLER::HANDLE_ERROR(const char* ERROR_MESSAGE, bool HALT) {
    Serial.println(ERROR_MESSAGE);

    if (HALT) {
        Serial.println("SYSTEM HALTED.");
        while (true);
    }
}

bool ERROR_HANDLER::CHECK_CONDITION(bool CONDITION, const char* ERROR_MESSAGE, bool HALT) {
    if (!CONDITION) {
        HANDLE_ERROR(ERROR_MESSAGE, HALT);
        return false;
    }
    return true;
}