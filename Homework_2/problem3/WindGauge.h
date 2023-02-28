#ifndef WINDGAUGE_H
#define WINDGAUGE_H
#include <deque>

class WindGauge {
    private:
        int period;
        std::deque<int> speeds;
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void printSpeeds() const;
};

#endif