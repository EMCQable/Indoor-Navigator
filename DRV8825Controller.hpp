class DRV8825Controller {
    /*
    * A class controlling DRV8825 Controller Circuit 
    */
    public:
        DRV8825Controller(int turnratedenominator, int resPin1, int resPin2, int resPin3, 
            int resetpin, int sleeppin, int steppin, int enablepin, int dirpin);
        bool setStepsPerRevolution(int new_StepsPerRevolution);
        bool setStepResolution(char resolution);
        bool toggleReset();
        bool toggleSleep();
        bool toggleEnable();
        void takeStep(bool direction);

    private:
        bool togglePin(int pin_number);
        
        // TODO: the memory consumption could be cut by choosing
        // smaller types than int
        int stepResolution_;
        int turnRate_;

        // Pins
        const char stepPin_;
        const char dirPin_;
        const unsigned char resolutionPin1_;
        const unsigned char resolutionPin2_;
        const unsigned char resolutionPin3_;
        const char enablePin_;
        const char resetPin_;
        const char sleepPin_;
};