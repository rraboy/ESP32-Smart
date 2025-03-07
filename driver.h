#pragma once
#include "smartdevices.h"
#include "smartsensors.h"
#include "loopable.h"

class DeviceDriver : public Loopable {

    protected:
        SmartDevice* const dev;

    public:
        DeviceDriver(SmartDevice* _dev);
        virtual void loop() = 0;
};

class MusicDeviceDriver : public DeviceDriver {

    protected:
        MusicRGBDevice* const musicdev;

    public:
        MusicDeviceDriver(RGBDevice* _dev, MusicRGBDevice* _musicdev);
        virtual void loop() = 0;
};

class SensorDriver : public Loopable {

    protected:
        SmartSensorBase* const dev;

    public:
        SensorDriver(SmartSensorBase* _dev);
        virtual void loop() = 0;
        virtual void update() = 0;
};

template<typename T>
class DriverMonitorFrontEndUpdatable {

    private:
        T value;
        T default_value;

    public:
        DriverMonitorFrontEndUpdatable(T& t);
        const T getReset();
        void set(T& t);

};

template<typename T>
class DriverMonitorFrontEndUpdatableDelegate {



};