#include "device_simulator.hpp"

DeviceSimulator::DeviceSimulator() : currentVoltage(0.0)
{
    
}


void DeviceSimulator::setVoltage(double voltage)
{
    currentVoltage = voltage;
}

double DeviceSimulator::readVoltage() const
{
    return currentVoltage;
}

