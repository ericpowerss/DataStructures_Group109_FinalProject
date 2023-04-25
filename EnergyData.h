
#ifndef DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
#define DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H

#include <string>
#include <unordered_map>
#include <map>
#include "State.h"

using namespace std;

class EnergyData {
public:
    unordered_map<string, unordered_map<int, State>> energyData;
    unordered_map<string, unordered_map<int, State>>::iterator it;
    unordered_map<int, State>::iterator iter;
        //State name,  energy type,     data,
    map<string, map<string, vector<pair<int, int>>>> sortedData;

};


#endif //DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
