#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#define XshutSensor1 15
#define XshutSensor2 33

struct sensorReturnOutput{
    int sensorDistanceLeft;
    int sensorDistanceRight;
};

void sensorSetup();
sensorReturnOutput* sensorRead();

#endif