#pragma once

class Blink {
    public:
        Blink(int pin, int interval);
        ~Blink();
        void update();
    private:
        int pin_;
        int interval_;
        unsigned long previousMillis_;
        bool ledState_;
};