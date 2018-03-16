#include <iostream>
#include <vector>

using namespace std;

struct Resistor{ // Resistor struct
    
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
    cout << "Number of resistors in circuit: ";
    cin >> numOfResistors;
    cout << endl;
    
    for(int i = 0; i < numOfResistors; i++){ // Input each resistor and add its resistance to total
        Resistor r;
        double resistance;
        cout << "Enter resistance: " << endl;
        cin >> resistance;
        r.resistance = resistance;
        resistors.push_back(r);
        totalResistance += resistance;
    }
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
    c.calculate();
    c.displayData();
    
    return 0;
}