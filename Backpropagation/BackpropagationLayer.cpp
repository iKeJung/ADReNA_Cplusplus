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
        foreach (BackpropagationNeuron* fatherNeuron, fatherLayer.neurons) {
            neuron->listConnection.push_back(new BackpropagationConnection(fatherNeuron));
        }
        /*for (int x = 0; x < fatherLayer.size(); ++x) {
            neuron->listConnection.push_back(new BackpropagationConnection(fatherLayer[x]));
        }*/
    }
}
