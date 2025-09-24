
class ProjectWiFi {
    public: 
        ProjectWiFi(const char * password, const char * ssid);
        ~ProjectWiFi();
        bool is_connected();
        bool Connect_WiFi();
    private: 
        const char * password = "Default";
        const char * ssid = "Default";
};