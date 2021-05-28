#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

template<class T>
class Sensor {
    public:
        Sensor(uint8_t id, uint8_t pin);
        bool hasChanged();
        T getValue();
        uint8_t getId();
        void execute();
    private:
        bool changed;
        T raw_value;
        uint8_t id;
        uint8_t pin;
        T value;
        T read();
};

template<class T>
Sensor<T>::Sensor(uint8_t id, uint8_t pin){
    this->id = id;
    this->pin = pin;
}

template<class T>
T Sensor<T>::read() {
    return analogRead(this->pin);
}

template<class T>
T Sensor<T>::getValue(){
    this->changed = false;
    return this->value;
}

template<class T>
uint8_t Sensor<T>::getId(){
    return this->id;
}

template<class T>
bool Sensor<T>::hasChanged(){
    return this->changed;
}

template<class T>
void Sensor<T>::execute(){
    T new_value = this->read();
    if(new_value != this->raw_value){
        this->changed = true;
        this->raw_value = new_value;
        this->value = new_value;
    }
}

#endif