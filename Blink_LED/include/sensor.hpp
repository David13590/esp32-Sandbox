#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#define XshutSensor1 33
#define XshutSensor2 15

struct sensorReturnOutput{
    int sensorDistanceLeft;
    int sensorDistanceRight;
};

void sensorSetup();
sensorReturnOutput* sensorRead();

#endif