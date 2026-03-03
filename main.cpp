#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <assert.h>
#include <vector>
using namespace std;

// Tipai apytiksliai paimti is Xiaomi parduotuves puslapio
enum deviceType{
    LIGHT,
    ENVIRONMENT,
    APPLIANCE,
    DISPLAY_AUDIO,
    COMMUNICATION,
    SECURITY,
    HUB,
    OTHER
};

class Device{
    // --- LAUKAI ---
    private:
        string name;
        deviceType type;
        bool isOn;
        int power;

        // Numeracija
        static unsigned int nextID;
        static unsigned int n;
        unsigned int id;

    // --- CONSTRUCTOR ---
    public:
        Device(string name, deviceType type, int power){
            setName(name);
            setType(type);
            setStatus(false);
            setPower(power);

            id = nextID;
            incN();
        }
        Device(string name, deviceType type, bool isOn, int power){
            setName(name);
            setType(type);
            setStatus(isOn);
            setPower(power);

            id = nextID;
            incN();
        }

        // --- DESTRUCTOR ---
        ~Device(){
            decN();
        }

        // --- GETTERS ---
        string getName(){
            return name;
        }
        deviceType getType(){
            return type;
        }
        bool getStatus(){
            return isOn;
        }
        int getPower(){
            return power;
        }
        unsigned int getID(){
            return id;
        }
        unsigned int getN(){
            return n;
        }

    // --- SETTERS ---
    private:
        void incN(){
            n++;
            nextID++;
        }
        void decN(){
            n--;
        }

    public:
        void setName(string to){
            if(!to.empty()){
                name = to;
            }
            else{
                throw invalid_argument("Name cannot be empty");
            }
        }
        void setType(deviceType to){
            type = to;
        }
        void setStatus(bool to){
            isOn = to;
        }
        void setPower(int to){
            power = to;
        }

        // --- TOSTRING ---
        string toString(){
            stringstream ss;

            ss << id << " ";
            ss << name << " ";
            ss << type << " ";
            ss << power << " ";
            ss << isOn;

            return ss.str();
        }
};
unsigned int Device::n = 0;
unsigned int Device::nextID = 0;

// -----

int main(){
    Device d1 = Device("Kitchen Light", LIGHT, 5);

    // --- Unit Tests ---

    // Informacija
    assert(d1.toString() == "0 Kitchen Light 0 5 0");
    assert(d1.getID() == 0);

    // Pavadinimas
    assert(d1.getName() == "Kitchen Light");
    d1.setName("Kitchen Hub");
    assert(d1.getName() == "Kitchen Hub");

    // Tipas
    assert(d1.getType() == LIGHT);
    d1.setType(HUB);
    assert(d1.getType() == HUB);

    // Busena
    assert(d1.getStatus() == false);
    d1.setStatus(true);
    assert(d1.getStatus() == true);

    // Galia
    assert(d1.getPower() == 5);
    d1.setPower(15);
    assert(d1.getPower() == 15);

    // Validacija
    try {         
        d1.setName("");
    } 
    catch (invalid_argument e) {}
    assert(d1.getName() != "");

    // Nauju irengininiu identifikavimas
    vector<Device*> D;
    for(int i = 1; i <= 3; i++){
        D.push_back(new Device("device "+to_string(i), OTHER, 0));
        assert((*D[D.size()-1]).getID() == i);
    }
    assert(d1.getN() == 4);
    for(int i = 0; i < 3; i++){
        delete(D[i]);
    };
    assert(d1.getN() == 1);

    // Patikrint ar id negrizta
    D.push_back(new Device("device last", OTHER, 0));
    delete(D[3]);

    assert(d1.getN() == 1);

    cout << "Tests passed.\n";
}