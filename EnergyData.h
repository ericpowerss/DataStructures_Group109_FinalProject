
#ifndef DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
#define DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H

#include <string>
#include <unordered_map>
#include "State.h"

using namespace std;

class EnergyData {

    unordered_map<string, unordered_map<int, State>> energyData;

};


#endif //DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
