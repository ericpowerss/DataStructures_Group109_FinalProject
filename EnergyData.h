
#include <string>
#include <unordered_map>
#include <map>
#include "State.h"
#include <vector>

using namespace std;

class EnergyData {
public:
    unordered_map<string, unordered_map<int, State>> energyData;
    unordered_map<string, unordered_map<int, State>>::iterator it;
    unordered_map<int, State>::iterator iter;
    //State name,  energy type,     data, year
    map<string, map<string, vector<pair<int, int>>>> sortedData;

};


