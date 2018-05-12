#include "backpropagation.h"


Backpropagation::Backpropagation(int inputLayerSize, int outputLayerSize)
{
    vector<int> hiddenlayersizes = { ((int)round((double)(inputLayerSize / 4)) > 2 ? (int)round((double)(inputLayerSize / 4)) : 2) };

    buildBackpropagation(inputLayerSize, outputLayerSize, hiddenlayersizes);
}

Backpropagation::Backpropagation(int inputLayerSize, int outputLayerSize, std::vector<int> hiddenLayerSizes)
{
    buildBackpropagation(inputLayerSize, outputLayerSize, hiddenLayerSizes);

}

bool Backpropagation::learn(DataSet trainingSet)
{
    if (trainingSet.getOutputSize() !=  this->outputLayerSize || trainingSet.getInputSize() != this->inputLayerSize){
        return false;
    }else{
        bool learned = false;
        vector<DataSetObject*> patterns = trainingSet.getList();
        for (int it = 1; learned == false && it <= maxIterationNumber; it++)
        {
            unsigned int allPatternOK = 0;
            for (unsigned int p = 0; p < patterns.size(); p++)
            {
                DataSetObject *pattern = patterns[p];

                applyPattern(pattern->getInput());

                doPropagation();

                if (calculateStopError(pattern->getTargetOutput()) > this->error)
                    doBackPropagation(pattern->getTargetOutput());
                else
                    allPatternOK++;

                if (allPatternOK == patterns.size())
                    learned = true;

                iterationNumber = it;
            }
        }
    }
    return true;
}

std::vector<double> Backpropagation::recognize(std::vector<double> input)
{
    if (input.size() != this->inputLayerSize)
        return vector<double>();
    else
    {
        applyPattern(input);
        doPropagation();
        return getDoubleArrayOutput();
    }
}

void Backpropagation::applyPattern(std::vector<double> pattern)
{
    BackpropagationLayer* inputLayer = layers[0];
    for (unsigned int x = 0; x < inputLayer->neurons.size(); ++x) {
        inputLayer->neurons[x]->setValuePattern(pattern[x]);
    }
}

void Backpropagation::doPropagation()
{
    for (unsigned int x = 0; x < layers.size(); ++x) {
        calculateSum(layers[x]);
    }
}

void Backpropagation::calculateSum(BackpropagationLayer* layer)
{
    for (unsigned int x = 0; x < layer->neurons.size(); ++x) {
        BackpropagationNeuron *neuron = layer->neurons[x];

        double sum = 0;
        for (unsigned int y = 0; y < neuron->listConnection.size(); ++y) {
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
    double result = 0;
    BackpropagationLayer* outLayer = layers[layers.size()-1];

    for (unsigned int x = 0; x < outPattern.size(); x++)
    {
        result += (outPattern[x] - outLayer->neurons[x]->getValuePattern())
                * (outPattern[x] - outLayer->neurons[x]->getValuePattern());
    }

    return result/2;
}

void Backpropagation::calculateErrorOut(std::vector<double> outPattern)
{
    BackpropagationLayer* outLayer = layers[layers.size() - 1];

    for (unsigned int x = 0; x < outPattern.size(); x++)
    {
        BackpropagationNeuron *neuronOut = outLayer->neurons[x];
        double valueError= (outPattern[x] -  neuronOut->getValuePattern())
                * neuronOut->getValuePattern() * (1 - neuronOut->getValuePattern());
        neuronOut->setValueError(valueError);
    }
}

void Backpropagation::doBackPropagation(std::vector<double> outPattern)
{
    calculateErrorOut(outPattern);

    for (int x = layers.size() - 2; x >= 0; x--)
    {
        BackpropagationLayer *layerL = layers[x];
        BackpropagationLayer *layerR = layers[x + 1];

        for(unsigned int y = 0; y < layerL->neurons.size(); y++)
        {
            BackpropagationNeuron *neuronL = layerL->neurons[y];
            neuronL->setValueError(0);

            double sum = 0;
            for (unsigned int z = 0; z < layerR->neurons.size(); z++)
            {
                BackpropagationNeuron *neuronR = layerR->neurons[z];
                for (unsigned int c = 0; c < neuronR->listConnection.size(); c++)
                {
                    BackpropagationConnection *connection = neuronR->listConnection[c];
                    if (connection->neuron == neuronL)
                    {
                        sum += neuronR->getValueError() * connection->valueWeight;
                        connection->valueWeight = connection->valueWeight + (neuronR->getValueError() * neuronL->getValuePattern());
                    }
                }
            }
            neuronL->setValueError(neuronL->getValuePattern() * (1 - neuronL->getValuePattern()) * sum);
        }
    }
}

std::vector<double> Backpropagation::getDoubleArrayOutput()
{
    BackpropagationLayer* outLayer = layers[layers.size() - 1];
    std::vector<double> result;

    for (int x = 0; x < outLayer->neurons.size(); x++)
    {
        BackpropagationNeuron *neuron = outLayer->neurons[x];
        result.push_back(neuron->getValuePattern());
    }
    return result;
}

void Backpropagation::buildBackpropagation(int inputLayerSize, int outputLayerSize, std::vector<int> hiddenLayerSizes)
{
    this->ETA = 0.3;
    this->error = 0.005;
    this->maxIterationNumber = 10000;

    this->inputLayerSize = inputLayerSize;
    this->outputLayerSize = outputLayerSize;
    this->hiddenLayerSizes = hiddenLayerSizes;

    for (int x = 0; x < layers.size(); ++x) {
        delete layers[x];
    }
    layers.clear();

    BackpropagationLayer *inputLayer = new BackpropagationLayer(inputLayerSize);
    layers.push_back(inputLayer);
    BackpropagationLayer *last = inputLayer;
    for (int x = 0; x < hiddenLayerSizes.size(); ++x) {
        int layerSize = hiddenLayerSizes[x];
        BackpropagationLayer *hiddenLayer = new BackpropagationLayer(layerSize, last);
        layers.push_back(hiddenLayer);
        last = hiddenLayer;
    }

    layers.push_back(new BackpropagationLayer(outputLayerSize, last));
}

int Backpropagation::getOutputLayerSize() const
{
    return outputLayerSize;
}

double Backpropagation::getError() const
{
    return error;
}

void Backpropagation::setError(double value)
{
    error = value;
}

double Backpropagation::getLearningRate() const
{
    return ETA;
}

void Backpropagation::setLearningRate(double value)
{
    ETA = value;
}

int Backpropagation::getIterationNumber() const
{
    return iterationNumber;
}

int Backpropagation::getMaxIterationNumber() const
{
    return maxIterationNumber;
}

void Backpropagation::setMaxIterationNumber(int value)
{
    maxIterationNumber = value;
}

bool Backpropagation::setLayers(const std::vector<BackpropagationLayer *> &value)
{
    bool incorrectDataFormat = false;

    if (value.size() == layers.size())
    {
        for (int x = 0; x < layers.size(); x++)
            if (value[x]->neurons.size() != layers[x]->neurons.size())
                incorrectDataFormat = true;
    }
    else
        incorrectDataFormat = true;

    if (incorrectDataFormat)
        return false;
    else
    {
        for (int x = 0; x < layers.size(); ++x) {
            delete layers[x];
        }
        layers = value;

        BackpropagationLayer* lastLayer = NULL;
        for (int x = 0; x < layers.size(); ++x) {
            BackpropagationLayer *layer = layers[x];
            for (int y = 0; y < layer->neurons.size(); ++y) {
                BackpropagationNeuron* neuron = layer->neurons[x];
                int connNumber = 0;
                for (int z = 0; z < neuron->listConnection.size(); ++z) {
                    BackpropagationConnection *conn = neuron->listConnection[x];
                    conn->neuron = lastLayer->neurons[connNumber];
                    connNumber++;
                }
            }
            lastLayer = layer;
        }
    }
    return true;
}

std::vector<BackpropagationLayer *> Backpropagation::getLayers() const
{
    return layers;
}

std::vector<int> Backpropagation::getHiddenLayerSizes() const
{
    return hiddenLayerSizes;
}
