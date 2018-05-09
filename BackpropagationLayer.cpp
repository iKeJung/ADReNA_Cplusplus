#include "BackpropagationLayer.h"

BackpropagationLayer::BackpropagationLayer()
{

}

BackpropagationLayer::BackpropagationLayer(int layerSize)
{
    for (int x = 0; x < layerSize; ++x) {
        neurons.push_back(new BackpropagationNeuron());
    }
}

BackpropagationLayer::BackpropagationLayer(int layerSize, BackpropagationLayer fatherLayer)
{
    for (int x = 0; x < layerSize; ++x) {
        BackpropagationNeuron* neuron = new BackpropagationNeuron();
        neurons.push_back(neuron);
        for (int x = 0; x < fatherLayer.neurons.size(); ++x) {
            neuron->listConnection.push_back(new BackpropagationConnection(fatherLayer.neurons[x]));
        }
    }
}

BackpropagationLayer::~BackpropagationLayer()
{
    for (int x = 0; x < neurons.size(); ++x) {
        delete neurons[x];
    }
}
