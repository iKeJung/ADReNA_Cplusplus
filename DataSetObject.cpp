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

}

DataSetObject::DataSetObject(std::vector<double> input, std::vector<double> targetOutput)
{
    buildNewDataSetObject(input,targetOutput);
}

DataSetObject::DataSetObject(std::vector<double> input)
{
    this->input = input;
}

void DataSetObject::buildNewDataSetObject(std::vector<double> input, std::vector<double> targetOutput)
{
    this->input = input;
    this->targetOutput = targetOutput;
}

std::vector<double> DataSetObject::getInput() const
{
    return input;
}

void DataSetObject::setInput(std::vector<double> value)
{
    input = value;
}

std::vector<double> DataSetObject::getTargetOutput() const
{
    return targetOutput;
}

void DataSetObject::setTargetOutput(std::vector<double> value)
{
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
