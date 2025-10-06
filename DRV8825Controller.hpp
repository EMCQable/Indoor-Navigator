class DRV8825Controller {
    /*
    * A class controlling DRV8825 Controller Circuit 
    */
    public:
        DRV8825Controller(int turnratedenominator, int m1pin, int m2pin, int m3pin, 
            int resetpin, int sleeppin, int steppin, int enablepin, int dirpin);
        bool setStepsPerRevolution(int new_StepsPerRevolution);
        bool setStepMode(int denominator);
        bool toggleReset();
        bool toggleSleep();
        bool toggleEnable();
        void takeStep(bool direction);

    private:
        bool togglePin(int pin_number);
        
        // TODO: the memory consumption could be cut by choosing
        // smaller types than int
        int stepsPerRevolution_;
        int turnRate_;

        // Pins
        const int stepPin_;
        const int dirPin_;
        const int m1Pin_;
        const int mPin_;
        const int m3Pin_;
        const int enablePin_;
        const int resetPin_;
        const int sleepPin_;
};