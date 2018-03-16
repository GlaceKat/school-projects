#include <iostream>
#include <vector>

using namespace std;

struct Resistor{ // Resistor structure
    
    double powerAcross;
    double resistance;
    double voltageAcross;
    
};

class niceCircuit{ // Circuit class
    
    public:
    
    niceCircuit();
    void displayData();
    double calcCurrent(); // Calculate current in entire circuit
    double calcPower(); // Calculate power of entire circuit
    double calcVoltAcross(Resistor r); // Calculate the voltage across a resistor
    double calcPowerAcross(Resistor r); // Calculate the power across a resistor
    void calculate(); // Perform all calculations
    void menu();
    
    void addResistor(); // Add a resistor
    void changeVolt(); // Change the input voltage
    void deleteResistor(); // Delete a resistor
    void editResistor(); // Edit a resistor
    void groupAdd(); // Add multiple resistors
    
    private:
    
    double voltage;
    double current;
    double power;
    double totalResistance;
    double numOfResistors;
    vector<Resistor> resistors; // Vector of resistors
};

niceCircuit::niceCircuit(){
    totalResistance = 0; // Input voltage and total number of resistors
    cout << "Input Voltage: ";
    cin >> voltage;
    cout << endl;
    groupAdd();
    
    calculate();
}

void niceCircuit::menu(){
    int input = 0;
    while(input != 7){
        cout << "Choose an option: " << endl;
        cout << "1. Add a resistor" << endl;
        cout << "2. Change input voltage" << endl;
        cout << "3. Delete resistor" << endl;
        cout << "4. Edit resistor" << endl;
        cout << "5. Group add a series of resistors" << endl;
        cout << "6. Display network" << endl;
        cout << "7. Quit" << endl;
        cin >> input;
        switch(input){
            case 1:
            addResistor();
            break;
            case 2:
            changeVolt();
            break;
            case 3:
            deleteResistor();
            break;
            case 4:
            editResistor();
            break;
            case 5:
            groupAdd();
            break;
            case 6:
            displayData();
            break;
            case 7:
            break;
            default:
            cout << "Choose a valid option." << endl;
            break;
        }
        
        calculate();
    }
}

void niceCircuit::groupAdd(){
    int num;
    cout << "Number of resistors to add: ";
    cin >> num;
    cout << endl;
    
    for(int i = 0; i < num; i++){ // Input each resistor and add its resistance to total
        addResistor();
    }
}

void niceCircuit::addResistor(){
    Resistor r;
    double resistance;
    cout << "Enter resistance: " << endl;
    cin >> resistance;
    r.resistance = resistance;
    resistors.push_back(r);
    totalResistance += resistance;
    numOfResistors++;
}

void niceCircuit::changeVolt(){
    cout << "Enter new voltage: " << endl;
    double v;
    cin >> v;
    voltage = v;
}

void niceCircuit::deleteResistor(){
    cout << "Enter resistor number to delete: " << endl;
    int n;
    cin >> n;
    
    totalResistance -= resistors[n].resistance;
    numOfResistors--;
    resistors.erase(resistors.begin() + n);
}

void niceCircuit::editResistor(){
    int n;
    double r;
    cout << "Enter resistor number to edit: " << endl;
    cin >> n;
    cout << "Enter new resistance: " << endl;
    cin >> r;
    totalResistance -= resistors[n].resistance;
    totalResistance += r;
    resistors[n].resistance = r;
}

void niceCircuit::calculate(){
    current = calcCurrent();
    power = calcPower();
    
    for(int i = 0; i < numOfResistors; i++){ // Calculate values for each resistor
        resistors[i].voltageAcross = calcVoltAcross(resistors[i]);
        resistors[i].powerAcross = calcPowerAcross(resistors[i]);
    }
}

void niceCircuit::displayData(){
    
    cout << "Circuit Parameters:" << endl;
    cout << "Total Resistance: " << totalResistance << " Ohms" << endl;
    cout << "Voltage: " << voltage << " Volts" << endl;
    cout << "Current: " << current << " Amps" << endl;
    cout << "Total Power: " << power << " Watts" << endl;
    cout << endl;
    
    for(int i = 0; i < numOfResistors; i++){ // Display each resistor
        cout << "Resistor " << i << " Parameters:" << endl;
        cout << "Resistance: " << resistors[i].resistance << " Ohms" << endl;
        cout << "Voltage: " << resistors[i].voltageAcross << " Volts" << endl;
        cout << "Power: " << resistors[i].powerAcross << " Watts" << endl;
        cout << endl;
    }
}

double niceCircuit::calcCurrent(){
    
    return voltage/totalResistance;
    
}

double niceCircuit::calcVoltAcross(Resistor r){
    
    return current * r.resistance;
    
}

double niceCircuit::calcPower(){
    
    return voltage * current;
    
}

double niceCircuit::calcPowerAcross(Resistor r){
    return current*r.voltageAcross;
}


int main(){
    
    niceCircuit c;
    c.menu();
    return 0;
}