#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include <cmath>

#include "Adrena_cplusplus_global.h"
#include "BackpropagationLayer.h"
#include "DataSet.h"

class ADRENA_CPLUSPLUSSHARED_EXPORT Backpropagation
{

public:
    Backpropagation();
    void learn(DataSet trainingSet); //has a thrown exception
    std::vector<double> recognize(std::vector<double> input);



private:
    void applyPatter(std::vector<double> pattern);
    void doPropagation();
    void calculateSum(BackpropagationLayer *layer);
    double transferFunction(double value);
    double calculateStopError(std::vector<double> outPattern);
    void calculateErrorOut(std::vector<double> outPattern);
    void doBackPropagation(std::vector<double> outPattern);
    std::vector<double> getDoubleArrayOutput();
    void buildBackpropagation(int inputLayerSize, int outputLayerSize, std::vector<int> hiddenLayerSizes);


    double ETA;
    double error;
    int maxIterationNumber;
    int iterationNumber;
    int inputLayerSize;
    int outputLayerSize;
    std::vector<int*> hiddenLayerSizes;
    std::vector<BackpropagationLayer*> layers;
};

#endif // BACKPROPAGATION_H
