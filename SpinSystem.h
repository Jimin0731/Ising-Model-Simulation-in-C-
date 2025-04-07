#ifndef SPINSYSTEM_H
#define SPINSYSTEM_H

#include <vector>

class SpinSystem {
private:
    std::vector<int> spins;
    int size;

public:
    SpinSystem(int systemSize);
    void initializeRandom();
    void printSpins() const;
    void attemptSpinFlip(double beta);

    int calculateTotalEnergy() const;
    int calculateMagnetization() const;
};

#endif

