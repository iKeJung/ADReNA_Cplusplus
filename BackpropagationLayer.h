#ifndef BACKPROPAGATIONLAYER_H
#define BACKPROPAGATIONLAYER_H

#include <memory>
#include <vector>
#include "BackpropagationNeuron.h"
#include "Adrena_cplusplus_global.h"


class ADRENA_CPLUSPLUSSHARED_EXPORT BackpropagationLayer
{
public:
    BackpropagationLayer();
    BackpropagationLayer(int layerSize);
    BackpropagationLayer(int layerSize, BackpropagationLayer fatherLayer);
    vector<BackpropagationNeuron*> neurons;
};

#endif // BACKPROPAGATIONLAYER_H
