#include <iostream>

using namespace std;

// Struct stores resistor data
struct Resistor{
    
    double powerAcross;
    double resistance;
    double voltageAcross;
    
};

// Display the circuit data
void displayData(double powerAcross, double resistance, double voltageAcross, double current){
    
    cout << "Circuit Parameters:" << endl;
    cout << "Resistance: " << resistance << " Ohm" << endl;
    cout << "Voltage: " << voltageAcross << " Volts" << endl;
    cout << "Current: " << current << " Amps" << endl;
    cout << "Power: " << powerAcross << " Watts" << endl;
    
}

double calcCurrent(double t_resistance, double voltage){ // Calculate the current in the circuit
    
    return voltage/t_resistance;
    
}

double calcVoltAcross(double current, double resistance){ // Calculate the voltage drop in the resistor
    
    return current * resistance;
    
}

double calcPower(double voltageAcross, double current){ // Calculate the power use in the resistor
    
    return voltageAcross * current;
    
}


int main(){
    Resistor r1; // Resistor
    double inputVoltage, current; 
    
    cout << "Enter an input voltage: " << endl; // Input voltage and resistance
    cin >> inputVoltage;
    cout << "Enter the resistance: " << endl;
    cin >> r1.resistance;
    
    current = calcCurrent(r1.resistance, inputVoltage); // Calculate current in circuit
    r1.voltageAcross = calcVoltAcross(current, r1.resistance); // calculate voltage
    r1.powerAcross = calcPower(r1.voltageAcross, current); // Calculate power
    
    displayData(r1.powerAcross, r1.resistance, r1.voltageAcross, current); // Display calculated data
    
    
    
    return 0;
}