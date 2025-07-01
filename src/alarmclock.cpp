#include "alarmclock.h"
#include <iostream>
#include <iomanip>

// your code here
AlarmClock::AlarmClock() :
    hours(0), minutes(0), activeStatus(false), volume(50), melody("Default melody") {}

AlarmClock& AlarmClock::setTime(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
    return *this;
}

AlarmClock& AlarmClock::turnOn() {
    this->activeStatus = true;
    return *this;
}

AlarmClock& AlarmClock::turnOff() {
    this->activeStatus = false;
    return *this;
}

AlarmClock& AlarmClock::setVolume(int volume) {
    if (volume < 0) {
        this->volume = 0;
    } else if (volume > 100) {
        this->volume = 100;
    } else {
        this->volume = volume;
    }
    return *this;
}

AlarmClock& AlarmClock::setMelody(const std::string& melody) {
    this->melody = melody;
    return *this;
}

int AlarmClock::getHours() const { return hours; }

int AlarmClock::getMinutes() const { return minutes; }

bool AlarmClock::getActiveStatus() const { return activeStatus; }

int AlarmClock::getVolume() const { return volume; }

std::string AlarmClock::getMelody() const { return melody; }

// Вывод состояния
void AlarmClock::printStatus() const {
    std::cout << "Time: " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2)
              << std::setfill('0') << minutes << ", Volume: " << volume << ", Melody: '" << melody
              << "'"
              << ", Status: " << (activeStatus ? "ON" : "OFF") << std::endl;
}
