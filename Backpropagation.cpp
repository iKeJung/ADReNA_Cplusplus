#include "backpropagation.h"


Backpropagation::Backpropagation()
{
}

void Backpropagation::learn(DataSet trainingSet)
{

}

std::vector<double> Backpropagation::recognize(std::vector<double> input)
{

}

void Backpropagation::applyPatter(std::vector<double> pattern)
{
    BackpropagationLayer* inputLayer = layers[0];
    for (int x = 0; x < inputLayer->neurons.size(); ++x) {
        inputLayer->neurons[x]->setValuePattern(pattern[x]);
    }
}

void Backpropagation::doPropagation()
{
    for (int x = 0; x < layers.size(); ++x) {
        calculateSum(layers[x]);
    }
}

void Backpropagation::calculateSum(BackpropagationLayer* layer)
{
    for (int x = 0; x < layer->neurons.size(); ++x) {
        BackpropagationNeuron *neuron = layer->neurons[x];

        double sum = 0;
        for (int y = 0; y < neuron->listConnection.size(); ++y) {
            BackpropagationConnection* connection = neuron->listConnection[y];
            sum += connection->neuron->getValuePattern()*connection->valueWeight;
        }

        neuron->setValuePattern(transferFunction(sum));
    }
}

double Backpropagation::transferFunction(double value)
{
    return (1/(1+(pow(exp(1.0),-value))));
}

double Backpropagation::calculateStopError(std::vector<double> outPattern)
{

}

void Backpropagation::calculateErrorOut(std::vector<double> outPattern)
{

}

void Backpropagation::doBackPropagation(std::vector<double> outPattern)
{

}

std::vector<double> Backpropagation::getDoubleArrayOutput()
{

}

void Backpropagation::buildBackpropagation(int inputLayerSize, int outputLayerSize, std::vector<int> hiddenLayerSizes)
{

}
