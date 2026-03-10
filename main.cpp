#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <vector>
using namespace std;

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
    // --- FIELDS ---
        private:
            string name;
                deviceType type;
            bool isOn;
        int power;

    // Enumeration
static unsigned int nextID;
    static unsigned int n;
        unsigned int id;

            // --- CONSTRUCTOR ---
                private:
                    void init(string name, deviceType type, bool isOn, int power){
                setName(name);
            setType(type);
        setStatus(false);
    setPower(power);

id = nextID;
    incN();
        }
            public:
                Device(string name, deviceType type, int power){
                    init(name, type, false, power);
                }
            Device(string name, deviceType type, bool isOn, int power){
        init(name, type, isOn, power);
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
            unsigned static int getN(){
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
        name = to;
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
};
            unsigned int Device::n = 0;
            unsigned int Device::nextID = 0;

class toString{
    public:
    static string output(Device d){
            stringstream ss;

            ss << d.getID() << " ";
            ss << d.getName() << " ";
            ss << d.getType() << " ";
            ss << d.getPower() << " ";
            ss << d.getType();

            return ss.str();
    }
};

// -----

int main(){
    try
    {
        Device d1 = Device("Kitchen Light", LIGHT, 5);

        // --- Unit Tests ---

        // General Information
        assert(toString::output(d1) == "0 Kitchen Light 0 5 0");
        assert(d1.getID() == 0);

        // Name test
        assert(d1.getName() == "Kitchen Light");
        d1.setName("Kitchen Hub");
        assert(d1.getName() == "Kitchen Hub");

        // Type test
        assert(d1.getType() == LIGHT);
        d1.setType(HUB);
        assert(d1.getType() == HUB);

        // Status test
        assert(d1.getStatus() == false);
        d1.setStatus(true);
        assert(d1.getStatus() == true);

        // Power test
        assert(d1.getPower() == 5);
        d1.setPower(15);
        assert(d1.getPower() == 15);

        // Validation test
        try {         
            d1.setName("");
        } 
        catch (invalid_argument e) {}
        assert(d1.getName() != "");

        // New device identification test
        vector<Device*> D;

        // Create 3 new devices
        for(int i = 1; i <= 3; i++){
            D.push_back(new Device("device "+to_string(i), OTHER, 0));
            // Check their names
            assert((*D[D.size()-1]).getID() == i);
        }

        // Check if N decreased
        assert(d1.getN() == 4);

        // Delete new devices
        for(int i = 0; i < 3; i++){
            delete(D[i]);
        };

        // Check if N decreased
        assert(d1.getN() == 1);

        // Check if id doesn't decrease
        D.push_back(new Device("device last", OTHER, 0));
        delete(D[3]);

        assert(d1.getN() == 1);

        cout << "Tests passed.\n";
    }
    catch (const exception &e)
    {
        cerr << "Unexpected exception thrown!\n";
    }

    assert(Device::getN() == 0);
}