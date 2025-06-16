#include "alarmclock.h"
#include <iostream>
#include <iomanip>

// your code here

// Вывод состояния
void AlarmClock::printStatus() const {
    std::cout << "Time: " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2)
              << std::setfill('0') << minutes << ", Volume: " << volume << ", Melody: '" << melody
              << "'"
              << ", Status: " << (activeStatus ? "ON" : "OFF") << std::endl;
}
