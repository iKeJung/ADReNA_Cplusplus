#ifndef BACKPROPAGATIONLAYER_H
#define BACKPROPAGATIONLAYER_H

#include <vector>
#include "BackpropagationNeuron.h"
#include <memory>
class BackpropagationLayer
{
public:
    BackpropagationLayer();
    BackpropagationLayer(int layerSize);
    BackpropagationLayer(int layerSize, BackpropagationLayer fatherLayer);
    vector<BackpropagationNeuron*> neurons;
};

#endif // BACKPROPAGATIONLAYER_H
