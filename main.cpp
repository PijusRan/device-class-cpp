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
        string getName(){ return name; }
        deviceType getType(){ return type; }
        bool getStatus(){ return isOn; }
        int getPower(){ return power; }
        
};

int main(){
    cout << "ok\n";
}