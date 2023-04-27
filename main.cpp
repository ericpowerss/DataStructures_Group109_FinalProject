#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "EnergyData.h"

using namespace std;
const int miniRun = 32;

void quickSort(vector<pair<int, float>>& data, int left, int right) {
    if (left < right) {
        // Choose pivot as rightmost element
        float pivot = data[right].second;
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (data[j].second <= pivot) {
                i++;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[right]);

        int pivotIndex = i + 1;
        quickSort(data, left, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, right);
    }
}
void sortData(map<string, map<string, vector<pair<int, float>>>>& sortedData, const string& productionType) {
    for (auto& stateData : sortedData) {
        for (auto& typeData : stateData.second) {
            if (typeData.first == productionType) {
                vector<pair<int, float>>& data = typeData.second;
                quickSort(data, 0, data.size() - 1);
            }
        }
    }
}

void insertionSort(vector<pair<int, float>>& data, int left, int right){
    for(int i = left + 1; i <= right; i++){
        pair<int, float> temp = data[i];
        int j = i - 1;
        while (j >= left && data[j].second > temp.second){
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

void merge(vector<pair<int, float>>& data, int left, int middle, int right){
    int len1 = middle - left + 1;
    int len2 = right - middle;
    vector<pair<int, float>> first, second;
    first.resize(len1);
    second.resize(len2);
    for(int i = 0; i < len1; i++){
        first[i] = data[left + i];
    }
    for(int j = 0; j < len2; j++){
        second[j] = data[middle + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < len1 && j < len2){

        if(first[i].second <= second[j].second){
            data[k] = first[i];
            i++;
        }
        else{
            data[k] = second[j];
            j++;
        }
        k++;
    }

    while(i < len1){
        data[k] = first[i];
        k++;
        i++;
    }

    while(j < len2){
        data[k] = second[j];
        j++;
        k++;
    }
}

void timSort(vector<pair<int, float>>& data, int n){
    for(int q = 0; q < n; q += miniRun){
        insertionSort(data, q, min((q + miniRun - 1), (n - 1)));
    }

    for(int size = miniRun; size < n; size = 2*size){
        for(int left = 0; left < n; left += 2*size){
            int middle = left + size - 1;
            int right = min((left + 2 * size - 1), (n -1));

            if(middle < right){
                merge(data, left, middle, right);
            }
        }
    }
}

int main() {
    string item, line, firstRow, tempString;
    string fileName = "energy.csv";
    EnergyData data;
    string stateName;
    vector<string> names;
    vector<float> value;


    ifstream myFile;
    myFile.open(fileName);

    //Nothing important, just to exclude the state & year in the header file as to not include in the name vector.
    getline(myFile, firstRow, ',');
    getline(myFile, firstRow, ',');

    getline(myFile, line);

    // Parse the header energy types and store them in the name vector.
    stringstream ss(line);
    while (getline(ss, firstRow, ',')) {
        names.push_back(firstRow);
    }

    myFile.close();

    myFile.open(fileName);
    getline(myFile, firstRow);

    while (getline(myFile, line)) {

        stringstream sso(line);
        getline(sso, stateName, ',');

        getline(sso, tempString, ',');
        auto year = stoi(tempString);

        getline(sso, tempString, ',');
        auto production_coal = stof(tempString);
        value.push_back(production_coal);

        getline(sso, tempString, ',');
        auto consumption_commercial_coal = stof(tempString);
        value.push_back(consumption_commercial_coal);

        getline(sso, tempString, ',');
        auto consumption_commercial_distillateFuelOil = stof(tempString);
        value.push_back(consumption_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        auto consumption_commercial_geothermal = stof(tempString);
        value.push_back(consumption_commercial_geothermal);

        getline(sso, tempString, ',');
        auto consumption_commercial_hydropower = stof(tempString);
        value.push_back(consumption_commercial_hydropower);

        getline(sso, tempString, ',');
        auto consumption_commercial_kerosene = stof(tempString);
        value.push_back(consumption_commercial_kerosene);

        getline(sso, tempString, ',');
        auto consumption_commercial_petroleum = stof(tempString);
        value.push_back(consumption_commercial_petroleum);

        getline(sso, tempString, ',');
        auto consumption_commercial_naturalGas = stof(tempString);
        value.push_back(consumption_commercial_naturalGas);

        getline(sso, tempString, ',');
        auto consumption_commercial_solar = stof(tempString);
        value.push_back(consumption_commercial_solar);

        getline(sso, tempString, ',');
        auto consumption_commercial_wind = stof(tempString);
        value.push_back(consumption_commercial_wind);

        getline(sso, tempString, ',');
        auto consumption_commercial_wood = stof(tempString);
        value.push_back(consumption_commercial_wood);

        getline(sso, tempString, ',');
        auto consumption_electricPower_coal = stof(tempString);
        value.push_back(consumption_electricPower_coal);

        getline(sso, tempString, ',');
        auto consumption_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(consumption_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        auto consumption_electricPower_naturalGas = stof(tempString);
        value.push_back(consumption_electricPower_naturalGas);

        getline(sso, tempString, ',');
        auto consumption_electricPower_wood = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_coal = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_distillateFuelOil = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_geothermal = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_hydropower = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_kerosene = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_petroleum = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_naturalGas = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_otherPetroleumProducts = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_solar = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_wind = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_wood = stof(tempString);

        getline(sso, tempString, ',');
        auto consumption_refinery_coal = stof(tempString);
        value.push_back(consumption_refinery_coal);

        getline(sso, tempString, ',');
        auto consumption_refinery_distillateFuelOil = stof(tempString);
        value.push_back(consumption_refinery_distillateFuelOil);

        getline(sso, tempString, ',');
        auto consumption_refinery_naturalGas = stof(tempString);
        value.push_back(consumption_refinery_naturalGas);

        getline(sso, tempString, ',');
        auto consumption_residential_coal = stof(tempString);
        value.push_back(consumption_residential_coal);

        getline(sso, tempString, ',');
        auto consumption_residential_distillateFuelOil = stof(tempString);
        value.push_back(consumption_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        auto consumption_residential_geothermal = stof(tempString);
        value.push_back(consumption_residential_geothermal);

        getline(sso, tempString, ',');
        auto consumption_residential_kerosene = stof(tempString);
        value.push_back(consumption_residential_kerosene);

        getline(sso, tempString, ',');
        auto consumption_residential_petroleum = stof(tempString);
        value.push_back(consumption_residential_petroleum);

        getline(sso, tempString, ',');
        auto consumption_residential_naturalGas = stof(tempString);
        value.push_back(consumption_residential_naturalGas);

        getline(sso, tempString, ',');
        auto consumption_residential_wood = stof(tempString);
        value.push_back(consumption_residential_wood);

        getline(sso, tempString, ',');
        auto consumption_transportation_coal = stof(tempString);
        value.push_back(consumption_transportation_coal);

        getline(sso, tempString, ',');
        auto consumption_transportation_distillateFuelOil = stof(tempString);
        value.push_back(consumption_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        auto consumption_transportation_petroleum = stof(tempString);
        value.push_back(consumption_transportation_petroleum);


        getline(sso, tempString, ',');
        auto consumption_transportation_naturalGas = stof(tempString);
        value.push_back(consumption_transportation_naturalGas);

        getline(sso, tempString, ',');
        auto expenditure_commercial_coal = stof(tempString);
        value.push_back(expenditure_commercial_coal);

        getline(sso, tempString, ',');
        auto expenditure_commercial_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        auto expenditure_commercial_kerosene = stof(tempString);
        value.push_back(expenditure_commercial_kerosene);

        getline(sso, tempString, ',');
        auto expenditure_commercial_petroleum = stof(tempString);
        value.push_back(expenditure_commercial_petroleum);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_coal = stof(tempString);
        value.push_back(expenditure_electricPower_coal);

        getline(sso, tempString, ',');
        auto expenditure_commercial_naturalGas = stof(tempString);
        value.push_back(expenditure_commercial_naturalGas);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_naturalGas = stof(tempString);
        value.push_back(expenditure_electricPower_naturalGas);

        getline(sso, tempString, ',');
        auto expenditure_industrial_coal = stof(tempString);
        value.push_back(expenditure_industrial_coal);

        getline(sso, tempString, ',');
        auto expenditure_industrial_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        auto expenditure_industrial_kerosene = stof(tempString);
        value.push_back(expenditure_industrial_kerosene);

        getline(sso, tempString, ',');
        auto expenditure_industrial_petroleum = stof(tempString);
        value.push_back(expenditure_industrial_petroleum);

        getline(sso, tempString, ',');
        auto expenditure_industrial_naturalGas = stof(tempString);
        value.push_back(expenditure_industrial_naturalGas);

        getline(sso, tempString, ',');
        auto expenditure_industrial_otherPetroleumProducts = stof(tempString);
        value.push_back(expenditure_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        auto expenditure_residential_coal = stof(tempString);
        value.push_back(expenditure_residential_coal);

        getline(sso, tempString, ',');
        auto expenditure_residential_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        auto expenditure_residential_kerosene = stof(tempString);
        value.push_back(expenditure_residential_kerosene);

        getline(sso, tempString, ',');
        auto expenditure_residential_petroleum = stof(tempString);
        value.push_back(expenditure_residential_petroleum);

        getline(sso, tempString, ',');
        auto expenditure_residential_naturalGas = stof(tempString);
        value.push_back(expenditure_residential_naturalGas);

        getline(sso, tempString, ',');
        auto expenditure_residential_wood = stof(tempString);
        value.push_back(expenditure_residential_wood);

        getline(sso, tempString, ',');
        auto expenditure_transportation_coal = stof(tempString);
        value.push_back(expenditure_transportation_coal);

        getline(sso, tempString, ',');
        auto expenditure_transportation_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        auto expenditure_transportation_petroleum = stof(tempString);
        value.push_back(expenditure_transportation_petroleum);

        getline(sso, tempString, ',');
        auto expenditure_transportation_naturalGas = stof(tempString);
        value.push_back(expenditure_transportation_naturalGas);

        getline(sso, tempString, ',');
        auto price_commercial_coal = stof(tempString);
        value.push_back(price_commercial_coal);

        getline(sso, tempString, ',');
        auto price_commercial_distillateFuelOil = stof(tempString);
        value.push_back(price_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        auto price_commercial_kerosene = stof(tempString);
        value.push_back(price_commercial_kerosene);

        getline(sso, tempString, ',');
        auto price_commercial_petroleum = stof(tempString);
        value.push_back(price_commercial_petroleum);

        getline(sso, tempString, ',');
        auto price_commercial_naturalGas = stof(tempString);
        value.push_back(price_commercial_naturalGas);

        getline(sso, tempString, ',');
        auto price_electricPower_coal = stof(tempString);
        value.push_back(price_electricPower_coal);

        //gather here.
        getline(sso, tempString, ',');
        auto price_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(price_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        auto price_electricPower_naturalGas = stof(tempString);
        value.push_back(price_electricPower_naturalGas);

        getline(sso, tempString, ',');
        auto price_industrial_coal = stof(tempString);
        value.push_back(price_industrial_coal);

        getline(sso, tempString, ',');
        auto price_industrial_distillateFuelOil = stof(tempString);
        value.push_back(price_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        auto price_industrial_kerosene = stof(tempString);
        value.push_back(price_industrial_kerosene);

        getline(sso, tempString, ',');
        auto price_industrial_petroleum = stof(tempString);
        value.push_back(price_industrial_petroleum);

        getline(sso, tempString, ',');
        auto price_industrial_naturalGas = stof(tempString);
        value.push_back(price_industrial_naturalGas);

        getline(sso, tempString, ',');
        auto price_industrial_otherPetroleumProducts = stof(tempString);
        value.push_back(price_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        auto price_transportation_coal = stof(tempString);
        value.push_back(price_transportation_coal);

        getline(sso, tempString, ',');
        auto price_transportation_distillateFuelOil = stof(tempString);
        value.push_back(price_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        auto price_transportation_petroleum = stof(tempString);
        value.push_back(price_transportation_petroleum);

        getline(sso, tempString, ',');
        auto price_transportation_naturalGas = stof(tempString);
        value.push_back(price_transportation_naturalGas);
        //end gather


        //For Loop to create a storage container for vector values of each energy type with its associative year.
        //Works but at 69 location the value zero turn to wrong number.
        for (int i = 0; i < names.size(); i++) {
            data.sortedData.insert(make_pair(stateName, map<string, vector<pair<int, float>>>()));
            data.sortedData[stateName].insert(make_pair(names[i], vector<pair<int, float>>()));
            data.sortedData[stateName][names[i]].push_back(make_pair(year, value[i]));
        }
        value.clear();

    }

    string productionType;
    cout << "Which energy type?" << endl;
    cin >> productionType;
    EnergyData Tim(data);
    int r;

    for (auto &temp: Tim.sortedData) {
        for (auto &innerMap: temp.second) {
            if (innerMap.first == productionType) {
                vector<pair<int, float>> &specificData = innerMap.second;
                r = innerMap.second.size();
                timSort(specificData, r);
            }
        }
    }



    sortData(data.sortedData, "Consumption_Commercial_Distillate Fuel Oil");
    for (const auto& stateData : data.sortedData) {
        if (stateData.second.count("Consumption_Commercial_Distillate Fuel Oil") == 0) {
            continue;
        }
        cout << stateData.first << endl;
        cout << "Consumption_Commercial_Distillate Fuel Oil" << ": ";
        for (const auto& value : stateData.second.at("Consumption_Commercial_Distillate Fuel Oil")) {
            cout << "(" << value.first << ", " << value.second << ") ";
        }
        cout << endl;
    }
    return 0;
}