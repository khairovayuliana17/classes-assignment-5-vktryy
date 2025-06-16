#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "alarmclock.h"

TEST_CASE("AlarmClock initialization", "[AlarmClock]") {
    AlarmClock clock;

    SECTION("Default constructor sets correct initial values") {
        REQUIRE(clock.getHours() == 0);
        REQUIRE(clock.getMinutes() == 0);
        REQUIRE(clock.getActiveStatus() == false);
        REQUIRE(clock.getVolume() == 50);
        REQUIRE(clock.getMelody() == "Default melody");
    }
}

TEST_CASE("AlarmClock::setTime()", "[AlarmClock]") {
    AlarmClock clock;

    SECTION("Valid time sets correctly") {
        clock.setTime(7, 30);
        REQUIRE(clock.getHours() == 7);
        REQUIRE(clock.getMinutes() == 30);
    }

    SECTION("Chaining works") {
        clock.setTime(12, 45).setTime(8, 15);
        REQUIRE(clock.getHours() == 8);
        REQUIRE(clock.getMinutes() == 15);
    }
}

TEST_CASE("AlarmClock::turnOn() / turnOff()", "[AlarmClock]") {
    AlarmClock clock;

    SECTION("Initially inactive") { REQUIRE(clock.getActiveStatus() == false); }

    SECTION("Turn on works") {
        clock.turnOn();
        REQUIRE(clock.getActiveStatus() == true);
    }

    SECTION("Turn off works") {
        clock.turnOn();
        clock.turnOff();
        REQUIRE(clock.getActiveStatus() == false);
    }

    SECTION("Chaining works") {
        clock.turnOn().turnOff().turnOn();
        REQUIRE(clock.getActiveStatus() == true);
    }
}

TEST_CASE("AlarmClock::setVolume()", "[AlarmClock]") {
    AlarmClock clock;

    SECTION("Valid volume sets correctly") {
        clock.setVolume(80);
        REQUIRE(clock.getVolume() == 80);
    }

    SECTION("Volume clamps to 0-100 range") {
        clock.setVolume(-10);
        REQUIRE(clock.getVolume() == 0);

        clock.setVolume(150);
        REQUIRE(clock.getVolume() == 100);
    }

    SECTION("Chaining works") {
        clock.setVolume(30).setVolume(70);
        REQUIRE(clock.getVolume() == 70);
    }
}

TEST_CASE("AlarmClock::setMelody()", "[AlarmClock]") {
    AlarmClock clock;

    SECTION("Melody sets correctly") {
        clock.setMelody("Morning melody");
        REQUIRE(clock.getMelody() == "Morning melody");
    }

    SECTION("Chaining works") {
        clock.setMelody("Beep").setMelody("Alarm");
        REQUIRE(clock.getMelody() == "Alarm");
    }
}

TEST_CASE("AlarmClock::printStatus()", "[AlarmClock]") {
    AlarmClock clock;
    clock.setTime(7, 30).setVolume(80).turnOn().setMelody("Morning melody");

    SECTION("Output matches expected format") {
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        clock.printStatus();
        std::cout.rdbuf(oldCout);

        std::string expected = "Time: 07:30, Volume: 80, Melody: 'Morning melody', Status: ON\n";
        REQUIRE(oss.str() == expected);
    }
}
