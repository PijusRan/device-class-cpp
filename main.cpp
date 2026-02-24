#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <assert.h>
#include <vector>
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
map<deviceType, string> typeTitles = {
    {light, "Light"},
    {environment, "Environment"},
    {appliance, "Appliance"},
    {display_audio, "Display / Audio"},
    {communication, "Communication"},
    {security, "Security"},
    {hub, "Hub"},
    {other, "Other"}
};

class device{
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
        void incN(){ n++; nextID++; }
        void decN(){ n--; }

    public:
    // --- CONSTRUCTOR ---
    

    device(string name, deviceType type, int power){
        setName(name);
        setType(type);
        setStatus(false);
        setPower(power);

        id = nextID;
        incN();
        
        cout << "Device ["+to_string(id)+"] created.\n";
    }

    // --- DESTRUCTOR ---
    ~device(){
        decN();

        cout << "Device ["+to_string(id)+"] removed.\n";
    }

    // --- GETTERS ---
        string getName(){ return name; }
        deviceType getType(){ return type; }
        bool getStatus(){ return isOn; }
        int getPower(){ return power; }
        unsigned int getID(){ return id; }
        unsigned int getN(){ return n; }

    // --- SETTERS ---
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
        stringstream ss;

        ss << "Device[" << id << "]: ";
        ss << name << ", ";
        ss << typeTitles[type] << ", ";
        ss << power << "W, ";
        ss << (isOn ? "On" : "Off");

        return ss.str();
    }
};
unsigned int device::n = 0;
unsigned int device::nextID = 0;

int main(){
    device d1 = device("Kitchen Light", light, 5);

    // --- Unit Tests ---

    // Informacija
    assert(d1.toString() == "Device[0]: Kitchen Light, Light, 5W, Off");
    assert(d1.getID() == 0);

    // Pavadinimas
    assert(d1.getName() == "Kitchen Light");
    d1.setName("Kitchen Hub");
    assert(d1.getName() == "Kitchen Hub");

    // Tipas
    assert(d1.getType() == light);
    d1.setType(hub);
    assert(d1.getType() == hub);

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
    vector<device*> D;
    for(int i = 1; i <= 3; i++){
        D.push_back(new device("device "+to_string(i), other, 0));
        assert((*D[D.size()-1]).getID() == i);
    }
    assert(d1.getN() == 4);
    for(int i = 0; i < 3; i++){
        delete(D[i]);
    };
    assert(d1.getN() == 1);

    // Patikrint ar id negrizta
    D.push_back(new device("device last", other, 0));
    delete(D[3]);

    assert(d1.getN() == 1);

    cout << "Tests passed.\n";
}