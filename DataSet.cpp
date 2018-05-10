#include "DataSet.h"

DataSet::DataSet(int inputSize, int outputSize)
{
    buildNewDataSet(inputSize,outputSize);
}

DataSet::~DataSet()
{
    for (unsigned int x = 0; x < data.size(); ++x) {
        delete data[x];
    }
}

void DataSet::buildNewDataSet(int inputSize, int outputSize)
{
    this->inputSize = inputSize;
    this->outputSize = outputSize;

}

bool DataSet::add(DataSetObject *obj)
{
    if(obj->getInputLenght() == inputSize && obj->getTargetOutputLenght() == outputSize){
        data.push_back(obj);
        return true;
    }
    return false;
}

std::vector<DataSetObject *> DataSet::getList()
{
    std::vector<DataSetObject*> newList;
    for (unsigned int x = 0; x < data.size(); ++x) {
        newList.push_back(new DataSetObject(*data[x]));
    }
    return newList;
}

int DataSet::lenght()
{
    return data.size();
}

unsigned int DataSet::getInputSize() const
{
    return inputSize;
}

unsigned int DataSet::getOutputSize() const
{
    return outputSize;
}
