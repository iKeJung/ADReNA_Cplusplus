#include "backpropagationNeuron.h"

BackpropagationConnection::BackpropagationConnection(BackpropagationNeuron *n)
{
    neuron = n;
    deltaWeight = 0;
    valueWeight = QRandomGenerator::global()->generateDouble()-0.5;

}

BackpropagationNeuron::BackpropagationNeuron()
{
    valuePattern = 0;
    valueError = 0;
}

BackpropagationNeuron::BackpropagationNeuron(int valueP)
{
    valuePattern = valueP;
    valueError = 0;
}

double BackpropagationNeuron::getValuePattern() const
{
    return valuePattern;
}

void BackpropagationNeuron::setValuePattern(double value)
{
    valuePattern = value;
}

string BackpropagationNeuron::toString()
{
    stringstream ss;
    ss << valuePattern;
    return ss.str();
}


