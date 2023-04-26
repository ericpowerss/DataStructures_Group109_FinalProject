
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

    map<string, map<string, vector<pair<int, float>>>> sortedData;
};


#endif //DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
