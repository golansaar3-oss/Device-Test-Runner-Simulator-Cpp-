#pragma once

class DeviceSimulator
{
public:
    DeviceSimulator();

    void setVoltage(double voltage);
    double readVoltage() const;

private:
    double currentVoltage;
};