#include "DataSetObject.h"

DataSetObject::DataSetObject()
{

}

DataSetObject::DataSetObject(vector<double*> input, vector<double*> targetOutput)
{
    buildNewDataSetObject(input,targetOutput);
}

DataSetObject::DataSetObject(vector<double*> input)
{
    this->input = input;
}

void DataSetObject::buildNewDataSetObject(vector<double*> input, vector<double*> targetOutput)
{
    this->input = input;
    this->targetOutput = targetOutput;
}

vector<double*> DataSetObject::getInput() const
{
    return input;
}

void DataSetObject::setInput(vector<double*> value)
{
    input = value;
}

vector<double*> DataSetObject::getTargetOutput() const
{
    return targetOutput;
}

void DataSetObject::setTargetOutput(vector<double *> value)
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
