#include "SpinSystem.h"
#include <random>
#include <iostream>
#include <cmath>

SpinSystem::SpinSystem(int systemSize) : size(systemSize) {
    spins.resize(size);
}

void SpinSystem::initializeRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < size; ++i) {
        spins[i] = dist(gen) == 0 ? -1 : +1;
    }
}

void SpinSystem::printSpins() const {
    for (int s : spins) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void SpinSystem::attemptSpinFlip(double beta) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> indexDist(0, size - 1);
    std::uniform_real_distribution<double> probDist(0.0, 1.0);

    int i = indexDist(gen);  

    int left = (i == 0) ? 0 : spins[i - 1];
    int right = (i == size - 1) ? 0 : spins[i + 1];

    int deltaE = 2 * spins[i] * (left + right);  

    double p = std::exp(-beta * deltaE);  

    if (p >= 1.0 || probDist(gen) < p) {
        spins[i] *= -1;  
    }
}

int SpinSystem::calculateTotalEnergy() const {
    int energy = 0;
    for (int i = 0; i < size - 1; ++i) {
        energy += spins[i] * spins[i + 1];
    }
    return -1 * energy;  
}

int SpinSystem::calculateMagnetization() const {
    int mag = 0;
    for (int s : spins) {
        mag += s;
    }
    return mag;
}