class ProjectStepControl {
    /*
    * A class controlling DRV8825 Controller Circuit 
    */
    public:
        ProjectStepControl(int turnratedenominator, int m1pin, int m2pin, int m3pin, 
            int resetpin, int sleeppin, int steppin, int enablepin, int dirpin);
        bool SetStepsPerRevolution(int new_StepsPerRevolution);
        bool SetStepMode(int denominator);
        bool ToggleReset();
        bool ToggleSleep();
        bool ToggleEnable();
        void TakeStep(bool direction);

    private:
        // TODO: the memory consumption could be cut by choosing
        // smaller types than int
        int StepsPerRevolution;
        int turnRate;  
        int M1Pin;
        int M2Pin;
        int M3Pin;
        int ResetPin;
        int SleepPin;
        int StepPin;
        int EnablePin;
        int DirPin;
        bool TogglePin(int pin_number);
};