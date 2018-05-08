#ifndef DATASETOBJECT_H
#define DATASETOBJECT_H

#include <vector>

using namespace std;

class DataSetObject
{
public:

    DataSetObject();    
    DataSetObject(vector<double*> input, vector<double*> targetOutput);
    DataSetObject(vector<double*> input);
    void buildNewDataSetObject(vector<double*> input, vector<double*> targetOutput);
    vector<double*> getInput() const;
    void setInput(vector<double*> value);
    vector<double*> getTargetOutput() const;
    void setTargetOutput(vector<double*> value);
    int getInputLenght();
    int getTargetOutputLenght();

private:
    vector<double*> input;
    vector<double*> targetOutput;
};

#endif // DATASETOBJECT_H
