#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

enum deviceType{
    light,
    environment,
    appliance,
    display_audio,
    communication,
    security,
    hub,
    other
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
        void setName(string to){
            if(to.empty()){
                throw invalid_argument("Name cannot be empty");
            }
            name = to;
        }
        void setType(deviceType to){ type = to; }
        void setStatus(bool to){ isOn = to; }
        void setPower(int to){ power = to; }

    // Constructor / Destructor
    device(string name, deviceType type, int power){
        setName(name);
        setType(type);
        setStatus(false);
        setPower(power);
        
        cout << "Device created.\n";
    }
    ~device(){
        cout << "Device removed.\n";
    }

    // toString
    string toString(){
        map<int, string> typeTitles = {
            {0, "Light"},
            {1, "Environment"},
            {2, "Appliance"},
            {3, "Display / Audio"},
            {4, "Communication"},
            {5, "Security"},
            {6, "Hub"},
            {7, "Other"}
        };

        return "device("+name+", "+typeTitles[type]+", "+to_string(power)+"W , "+ (isOn ? "On" : "Off") + ")\n";
    }
};

int main(){
    device dev("Lamp", light, 5);

    cout << dev.toString();
}