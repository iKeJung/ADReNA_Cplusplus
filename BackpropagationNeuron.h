#ifndef BACKPROPAGATIONNEURON_H
#define BACKPROPAGATIONNEURON_H

#include "Adrena_cplusplus_global.h"
#include <vector>
#include <QRandomGenerator>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

class ADRENA_CPLUSPLUSSHARED_EXPORT BackpropagationNeuron;

struct ADRENA_CPLUSPLUSSHARED_EXPORT BackpropagationConnection
{
    double valueWeight;
    double deltaWeight;
    BackpropagationNeuron* neuron;
    BackpropagationConnection(BackpropagationNeuron* n);
};

class ADRENA_CPLUSPLUSSHARED_EXPORT BackpropagationNeuron
{
public:
    BackpropagationNeuron();
    BackpropagationNeuron(int valueP);

    double getValuePattern() const;
    void setValuePattern(double value);
    string toString();
    vector<BackpropagationConnection*> listConnection;

private:
    double valuePattern;
    double valueError;
};

#endif // BACKPROPAGATIONNEURON_H
