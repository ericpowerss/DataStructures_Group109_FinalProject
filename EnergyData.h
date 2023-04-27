
#ifndef DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
#define DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H

#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class EnergyData {
public:
    EnergyData() {

    }

    EnergyData(EnergyData& copy){
        sortedData = copy.sortedData;
    }
//    unordered_map<string, unordered_map<int, State>> energyData;
//    unordered_map<string, unordered_map<int, State>>::iterator it;
//    unordered_map<int, State>::iterator iter;

//     StateName,   EnergyType          Year,  Data
    map<string, map<string, vector<pair<int, float>>>> sortedData;
};


#endif //DATASTRUCTURES_GROUP109_FINALPROJECT_ENERGYDATA_H
