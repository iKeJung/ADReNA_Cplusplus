#ifndef DATASET_H
#define DATASET_H

#include "dataset_global.h"
#include "DataSetObject.h"
class DATASETSHARED_EXPORT DataSet
{

public:
    DataSet(int inputSize=0, int outputSize=0);
    ~DataSet();
    void buildNewDataSet(int inputSize, int outputSize);
    bool add(DataSetObject* obj);
    std::vector<DataSetObject*> getList();
    int lenght();
    int getInputSize() const;
    int getOutputSize() const;

private:
    std::vector<DataSetObject*> data;
    int inputSize;
    int outputSize;
};

#endif // DATASET_H
