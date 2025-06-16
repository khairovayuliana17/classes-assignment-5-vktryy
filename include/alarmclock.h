#include <string>

class AlarmClock {
  private:
    // your code here
  public:
    // Конструктор по умолчанию
    AlarmClock();

    // Возвращают *this для цепочек вызовов
    AlarmClock& setTime(int hours, int minutes);
    AlarmClock& turnOn();
    AlarmClock& turnOff();
    AlarmClock& setVolume(int volume);
    AlarmClock& setMelody(const std::string& melody);

    // Геттеры
    int getHours() const;
    int getMinutes() const;
    bool getActiveStatus() const;
    int getVolume() const;
    std::string getMelody() const;

    // Вывод состояния в консоль
    void printStatus() const;
};
