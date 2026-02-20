#include <iostream>
#include <string>
using namespace std;

enum deviceType{
    light,
    environment,
    appliance,
    display_audio,
    communication,
    security,
    hub
};
// Tipai apytiksliai paimti is Xiaomi parduotuves puslapio


class device{
    private:
        string name;
        deviceType type;
        bool isOn;
        int power;

    public:
    // Setters
        string getName(){ return name; }
        deviceType getType(){ return type; }
        bool getStatus(){ return isOn; }
        int getPower(){ return power; }
    // Getters
        void setName(string to){ name = to; }
        void settype(deviceType to){ type = to; }
        void setStatus(bool to){ isOn = to; }
        void setPower(int to){ power = to; }

    // Constructor
    device(string name, deviceType type, int power){
        this->name = name;
        this->type = type;
        this->power = power;
        cout << "Device created.";
    }
    ~device(){
        cout << "Device removed.";
    }
};

int main(){
    cout << "ok\n";
}