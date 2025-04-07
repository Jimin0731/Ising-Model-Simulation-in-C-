#include "SpinSystem.h"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    const int systemSize = 100;
    const int numConfigurations = 100;  
    const int stepsPerConfig = 1000;

    std::vector<double> betaValues = {0.1, 0.5, 1.0, 1.5, 2.0, 3.0};

    std::ofstream outFile("results.csv");
    outFile << "beta,avg_energy,avg_magnetization\n";  // CSV 헤더

    for (double beta : betaValues) {
        double totalEnergy = 0.0;
        double totalMagnetization = 0.0;

        for (int config = 0; config < numConfigurations; ++config) {
            SpinSystem system(systemSize);
            system.initializeRandom();

            for (int step = 0; step < stepsPerConfig; ++step) {
                system.attemptSpinFlip(beta);
            }

            totalEnergy += system.calculateTotalEnergy();
            totalMagnetization += system.calculateMagnetization();
        }

        double avgEnergy = totalEnergy / numConfigurations;
        double avgMagnetization = totalMagnetization / numConfigurations;

        std::cout << "β = " << beta
                  << " | Avg Energy = " << avgEnergy
                  << " | Avg Magnetization = " << avgMagnetization
                  << std::endl;

        outFile << beta << "," << avgEnergy << "," << avgMagnetization << "\n";

    }

    return 0;
}
