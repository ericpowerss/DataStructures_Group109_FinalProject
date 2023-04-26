#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "State.h"
#include "EnergyData.h"

using namespace std;

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
        int year = stoi(tempString);

        getline(sso, tempString, ',');
        float production_coal = stof(tempString);
        value.push_back(production_coal);

        getline(sso, tempString, ',');
        float consumption_commercial_coal = stof(tempString);
        value.push_back(consumption_commercial_coal);

        getline(sso, tempString, ',');
        float consumption_commercial_distillateFuelOil = stof(tempString);
        value.push_back(consumption_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_commercial_geothermal = stof(tempString);
        value.push_back(consumption_commercial_geothermal);

        getline(sso, tempString, ',');
        float consumption_commercial_hydropower = stof(tempString);
        value.push_back(consumption_commercial_hydropower);

        getline(sso, tempString, ',');
        float consumption_commercial_kerosene = stof(tempString);
        value.push_back(consumption_commercial_kerosene);

        getline(sso, tempString, ',');
        float consumption_commercial_petroleum = stof(tempString);
        value.push_back(consumption_commercial_petroleum);

        getline(sso, tempString, ',');
        float consumption_commercial_naturalGas = stof(tempString);
        value.push_back(consumption_commercial_naturalGas);

        getline(sso, tempString, ',');
        float consumption_commercial_solar = stof(tempString);
        value.push_back(consumption_commercial_solar);

        getline(sso, tempString, ',');
        float consumption_commercial_wind = stof(tempString);
        value.push_back(consumption_commercial_wind);

        getline(sso, tempString, ',');
        float consumption_commercial_wood = stof(tempString);
        value.push_back(consumption_commercial_wood);

        getline(sso, tempString, ',');
        float consumption_electricPower_coal = stof(tempString);
        value.push_back(consumption_electricPower_coal);

        getline(sso, tempString, ',');
        float consumption_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(consumption_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_electricPower_naturalGas = stof(tempString);
        value.push_back(consumption_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float consumption_electricPower_wood = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_coal = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_distillateFuelOil = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_geothermal = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_hydropower = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_kerosene = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_petroleum = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_naturalGas = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_otherPetroleumProducts = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_solar = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_wind = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_industrial_wood = stof(tempString);

        getline(sso, tempString, ',');
        float consumption_refinery_coal = stof(tempString);
        value.push_back(consumption_refinery_coal);

        getline(sso, tempString, ',');
        float consumption_refinery_distillateFuelOil = stof(tempString);
        value.push_back(consumption_refinery_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_refinery_naturalGas = stof(tempString);
        value.push_back(consumption_refinery_naturalGas);

        getline(sso, tempString, ',');
        float consumption_residential_coal = stof(tempString);
        value.push_back(consumption_residential_coal);

        getline(sso, tempString, ',');
        float consumption_residential_distillateFuelOil = stof(tempString);
        value.push_back(consumption_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_residential_geothermal = stof(tempString);
        value.push_back(consumption_residential_geothermal);

        getline(sso, tempString, ',');
        float consumption_residential_kerosene = stof(tempString);
        value.push_back(consumption_residential_kerosene);

        getline(sso, tempString, ',');
        float consumption_residential_petroleum = stof(tempString);
        value.push_back(consumption_residential_petroleum);

        getline(sso, tempString, ',');
        float consumption_residential_naturalGas = stof(tempString);
        value.push_back(consumption_residential_naturalGas);

        getline(sso, tempString, ',');
        float consumption_residential_wood = stof(tempString);
        value.push_back(consumption_residential_wood);

        getline(sso, tempString, ',');
        float consumption_transportation_coal = stof(tempString);
        value.push_back(consumption_transportation_coal);

        getline(sso, tempString, ',');
        float consumption_transportation_distillateFuelOil = stof(tempString);
        value.push_back(consumption_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_transportation_petroleum = stof(tempString);
        value.push_back(consumption_transportation_petroleum);


        getline(sso, tempString, ',');
        float consumption_transportation_naturalGas = stof(tempString);
        value.push_back(consumption_transportation_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_commercial_coal = stof(tempString);
        value.push_back(expenditure_commercial_coal);

        getline(sso, tempString, ',');
        float expenditure_commercial_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_commercial_kerosene = stof(tempString);
        value.push_back(expenditure_commercial_kerosene);

        getline(sso, tempString, ',');
        float expenditure_commercial_petroleum = stof(tempString);
        value.push_back(expenditure_commercial_petroleum);

        getline(sso, tempString, ',');
        float expenditure_electricPower_coal = stof(tempString);
        value.push_back(expenditure_electricPower_coal);

        getline(sso, tempString, ',');
        float expenditure_commercial_naturalGas = stof(tempString);
        value.push_back(expenditure_commercial_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_electricPower_naturalGas = stof(tempString);
        value.push_back(expenditure_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_industrial_coal = stof(tempString);
        value.push_back(expenditure_industrial_coal);

        getline(sso, tempString, ',');
        float expenditure_industrial_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_industrial_kerosene = stof(tempString);
        value.push_back(expenditure_industrial_kerosene);

        getline(sso, tempString, ',');
        float expenditure_industrial_petroleum = stof(tempString);
        value.push_back(expenditure_industrial_petroleum);

        getline(sso, tempString, ',');
        float expenditure_industrial_naturalGas = stof(tempString);
        value.push_back(expenditure_industrial_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_industrial_otherPetroleumProducts = stof(tempString);
        value.push_back(expenditure_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        float expenditure_residential_coal = stof(tempString);
        value.push_back(expenditure_residential_coal);

        getline(sso, tempString, ',');
        float expenditure_residential_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_residential_kerosene = stof(tempString);
        value.push_back(expenditure_residential_kerosene);

        getline(sso, tempString, ',');
        float expenditure_residential_petroleum = stof(tempString);
        value.push_back(expenditure_residential_petroleum);

        getline(sso, tempString, ',');
        float expenditure_residential_naturalGas = stof(tempString);
        value.push_back(expenditure_residential_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_residential_wood = stof(tempString);
        value.push_back(expenditure_residential_wood);

        getline(sso, tempString, ',');
        float expenditure_transportation_coal = stof(tempString);
        value.push_back(expenditure_transportation_coal);

        getline(sso, tempString, ',');
        float expenditure_transportation_distillateFuelOil = stof(tempString);
        value.push_back(expenditure_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_transportation_petroleum = stof(tempString);
        value.push_back(expenditure_transportation_petroleum);

        getline(sso, tempString, ',');
        float expenditure_transportation_naturalGas = stof(tempString);
        value.push_back(expenditure_transportation_naturalGas);

        getline(sso, tempString, ',');
        float price_commercial_coal = stof(tempString);
        value.push_back(price_commercial_coal);

        getline(sso, tempString, ',');
        float price_commercial_distillateFuelOil = stof(tempString);
        value.push_back(price_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_commercial_kerosene = stof(tempString);
        value.push_back(price_commercial_kerosene);

        getline(sso, tempString, ',');
        float price_commercial_petroleum = stof(tempString);
        value.push_back(price_commercial_petroleum);

        getline(sso, tempString, ',');
        float price_commercial_naturalGas = stof(tempString);
        value.push_back(price_commercial_naturalGas);

        getline(sso, tempString, ',');
        float price_electricPower_coal = stof(tempString);
        value.push_back(price_electricPower_coal);

        getline(sso, tempString, ',');
        float price_electricPower_distillateFuelOil = stof(tempString);
        value.push_back(price_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_electricPower_naturalGas = stof(tempString);
        value.push_back(price_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float price_industrial_coal = stof(tempString);
        value.push_back(price_industrial_coal);

        getline(sso, tempString, ',');
        float price_industrial_distillateFuelOil = stof(tempString);
        value.push_back(price_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_industrial_kerosene = stof(tempString);
        value.push_back(price_industrial_kerosene);

        getline(sso, tempString, ',');
        float price_industrial_petroleum = stof(tempString);
        value.push_back(price_industrial_petroleum);

        getline(sso, tempString, ',');
        float price_industrial_naturalGas = stof(tempString);
        value.push_back(price_industrial_naturalGas);

        getline(sso, tempString, ',');
        float price_industrial_otherPetroleumProducts = stof(tempString);
        value.push_back(price_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        float price_transportation_coal = stof(tempString);
        value.push_back(price_transportation_coal);

        getline(sso, tempString, ',');
        float price_transportation_distillateFuelOil = stof(tempString);
        value.push_back(price_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_transportation_petroleum = stof(tempString);
        value.push_back(price_transportation_petroleum);

        getline(sso, tempString, ',');
        float price_transportation_naturalGas = stof(tempString);
        value.push_back(price_transportation_naturalGas);

        State stateObject(production_coal, consumption_commercial_coal, consumption_commercial_distillateFuelOil,
                          consumption_commercial_geothermal, consumption_commercial_hydropower,
                          consumption_commercial_kerosene, consumption_commercial_petroleum,
                          consumption_commercial_naturalGas, consumption_commercial_solar, consumption_commercial_wind,
                          consumption_commercial_wood, consumption_electricPower_coal,
                          consumption_electricPower_distillateFuelOil, consumption_electricPower_naturalGas,
                          consumption_electricPower_wood, consumption_industrial_coal,
                          consumption_industrial_distillateFuelOil, consumption_industrial_geothermal,
                          consumption_industrial_hydropower, consumption_industrial_kerosene,
                          consumption_industrial_petroleum, consumption_industrial_naturalGas,
                          consumption_industrial_otherPetroleumProducts, consumption_industrial_solar,
                          consumption_industrial_wind, consumption_industrial_wood, consumption_refinery_coal,
                          consumption_refinery_distillateFuelOil, consumption_refinery_naturalGas,
                          consumption_residential_coal, consumption_residential_distillateFuelOil,
                          consumption_residential_geothermal, consumption_residential_kerosene,
                          consumption_residential_petroleum, consumption_residential_naturalGas,
                          consumption_residential_wood, consumption_transportation_coal,
                          consumption_transportation_distillateFuelOil, consumption_transportation_petroleum,
                          consumption_transportation_naturalGas, expenditure_commercial_coal,
                          expenditure_commercial_distillateFuelOil, expenditure_commercial_kerosene,
                          expenditure_commercial_petroleum, expenditure_commercial_naturalGas,
                          expenditure_electricPower_coal, expenditure_electricPower_distillateFuelOil,
                          expenditure_electricPower_naturalGas, expenditure_industrial_coal,
                          expenditure_industrial_distillateFuelOil, expenditure_industrial_kerosene,
                          expenditure_industrial_petroleum, expenditure_industrial_naturalGas,
                          expenditure_industrial_otherPetroleumProducts, expenditure_residential_coal,
                          expenditure_residential_distillateFuelOil, expenditure_residential_kerosene,
                          expenditure_residential_petroleum, expenditure_residential_naturalGas,
                          expenditure_residential_wood, expenditure_transportation_coal,
                          expenditure_transportation_distillateFuelOil, expenditure_transportation_petroleum,
                          expenditure_transportation_naturalGas, price_commercial_coal,
                          price_commercial_distillateFuelOil, price_commercial_kerosene, price_commercial_petroleum,
                          price_commercial_naturalGas, price_electricPower_coal, price_electricPower_distillateFuelOil,
                          price_electricPower_naturalGas, price_industrial_coal, price_industrial_distillateFuelOil,
                          price_industrial_kerosene, price_industrial_petroleum, price_industrial_naturalGas,
                          price_industrial_otherPetroleumProducts, price_transportation_coal,
                          price_transportation_distillateFuelOil, price_transportation_petroleum,
                          price_transportation_naturalGas);

        data.energyData.insert(make_pair(stateName, unordered_map<int, State>()));
        data.energyData[stateName].insert(make_pair(year, stateObject));


        //For Loop to create a storage container for vector values of each energy type with its associative year.
        //Works but at 69 location the value zero turn to wrong number.
        for (int i = 0; i < names.size(); i++) {
            data.sortedData.insert(make_pair(stateName, map<string, vector<pair<int, float>>>()));
            data.sortedData[stateName].insert(make_pair(names[i], vector<pair<int, float>>()));
            data.sortedData[stateName][names[i]].push_back(make_pair(year, value[i]));
        }
        value.clear();


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










