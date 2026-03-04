#include "state.hpp"


const char* to_string(State state)
{
    switch (state)
    {
    case State::IDLE:
        return "IDLE";       
    case State::RUNNING:
        return "RUNNING";  
    case State::PASSED:
        return "PASSED"; 
    case State::FAILED:
        return "FAILED";     
    case State::ERROR:
        return "ERROR";      
    default:
        return "UNKOWN_STATE";
    }
}

