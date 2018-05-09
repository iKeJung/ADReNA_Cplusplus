#include "DataSetObject.h"

DataSetObject::DataSetObject()
{

}

DataSetObject::DataSetObject(DataSetObject *obj)
{
    input = obj->getInput();
    targetOutput = obj->getTargetOutput();
}

DataSetObject::~DataSetObject()
{
    for (unsigned int x = 0; x < input.size(); ++x) {
        delete input[x];
    }
    for (unsigned int x = 0; x < targetOutput.size(); ++x) {
        delete targetOutput[x];
    }
}

DataSetObject::DataSetObject(std::vector<double*> input, std::vector<double*> targetOutput)
{
    buildNewDataSetObject(input,targetOutput);
}

DataSetObject::DataSetObject(std::vector<double*> input)
{
    this->input = input;
}

void DataSetObject::buildNewDataSetObject(std::vector<double*> input, std::vector<double*> targetOutput)
{
    this->input = input;
    this->targetOutput = targetOutput;
}

std::vector<double*> DataSetObject::getInput() const
{
    std::vector<double*> newInput;
    for (unsigned int x = 0; x < input.size(); ++x) {
        double *value = new double(*input[x]);
        newInput.push_back(value);
    }
    return input;
}

void DataSetObject::setInput(std::vector<double*> value)
{
    for (unsigned int x = 0; x < input.size(); ++x) {
        delete input[x];
    }
    input = value;
}

std::vector<double*> DataSetObject::getTargetOutput() const
{
    std::vector<double*> newTargetOutput;
    for (unsigned int x = 0; x < targetOutput.size(); ++x) {
        double *value = new double(*targetOutput[x]);
        newTargetOutput.push_back(value);
    }
    return targetOutput;
}

void DataSetObject::setTargetOutput(std::vector<double *> value)
{
    for (unsigned int x = 0; x < targetOutput.size(); ++x) {
        delete targetOutput[x];
    }
    targetOutput = value;
}

int DataSetObject::getInputLenght()
{
    return input.size();
}

int DataSetObject::getTargetOutputLenght()
{
    return targetOutput.size();
}
