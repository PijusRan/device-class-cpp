#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

// Tipai apytiksliai paimti is Xiaomi parduotuves puslapio
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

class device{
    // --- LAUKAI ---
    private:
        string name;
        deviceType type;
        bool isOn;
        int power;

        // Numeracija
        static unsigned int n;
        unsigned int id;
        void incN(){ n++; }
        void decN(){ n--; }

    public:
    // --- CONSTRUCTOR ---
    device(string name, deviceType type, int power){
        setName(name);
        setType(type);
        setStatus(false);
        setPower(power);

        id = n;
        incN();
        
        cout << "Device created.\n";
    }

    // --- DESTRUCTOR ---
    ~device(){
        decN();

        cout << "Device removed.\n";
    }

    // --- SETTERS ---
        string getName(){ return name; }
        deviceType getType(){ return type; }
        bool getStatus(){ return isOn; }
        int getPower(){ return power; }

    // --- GETTERS ---
        void setName(string to){
            if(to.empty()){
                throw invalid_argument("Name cannot be empty");
            }
            name = to;
        }
        void setType(deviceType to){ type = to; }
        void setStatus(bool to){ isOn = to; }
        void setPower(int to){ power = to; }

    // --- TOSTRING ---
    string toString(){
        return "device["+id+"]("+name+", "+typeTitles[type]+", "+to_string(power)+"W , "+ (isOn ? "On" : "Off") + ")\n";
    }
};

int main(){
    
}