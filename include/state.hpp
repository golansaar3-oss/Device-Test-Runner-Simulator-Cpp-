#pragma once

enum class State
{
    IDLE,
    RUNNING,
    PASSED,
    FAILED,
    ERROR

};

const char* to_string(State state);
