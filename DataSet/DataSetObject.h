#ifndef DATASETOBJECT_H
#define DATASETOBJECT_H

#include "vector"


class DataSetObject
{
public:

    DataSetObject();
    DataSetObject(DataSetObject* obj);
    ~DataSetObject();
    DataSetObject(std::vector<double*> input, std::vector<double*> targetOutput);
    DataSetObject(std::vector<double*> input);
    void buildNewDataSetObject(std::vector<double*> input, std::vector<double*> targetOutput);
    std::vector<double*> getInput() const;
    void setInput(std::vector<double*> value);
    std::vector<double*> getTargetOutput() const;
    void setTargetOutput(std::vector<double*> value);

    int getInputLenght();
    int getTargetOutputLenght();

private:
    std::vector<double*> input;
    std::vector<double*> targetOutput;
};

#endif // DATASETOBJECT_H
