#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "State.h"
#include "EnergyData.h"

using namespace std;

int main() {
    string item, line, firstRow, tempString;
    string fileName = "energy.csv";
    EnergyData data;
    string stateName;
    vector<string> names;
    vector<float> value;


    ifstream myFile;
    myFile.open(fileName);

    //getline(myFile, firstRow);
    getline(myFile, firstRow, ',');
    getline(myFile, firstRow, ',');

    while(getline(myFile, firstRow, ',')){
        stringstream temp(firstRow);
        names.push_back(firstRow);
    }

    while(getline(myFile, line))
    {

        stringstream sso(line);
        getline(sso, stateName, ',');

        getline(sso, tempString, ',');
        float year = stoi(tempString);

        getline(sso, tempString, ',');
        float production_coal = stoi(tempString);
        value.push_back(production_coal);

        getline(sso, tempString, ',');
        float consumption_commercial_coal = stoi(tempString);
        value.push_back(consumption_commercial_coal);

        getline(sso, tempString, ',');
        float consumption_commercial_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_commercial_geothermal = stoi(tempString);
        value.push_back(consumption_commercial_geothermal);

        getline(sso, tempString, ',');
        float consumption_commercial_hydropower = stoi(tempString);
        value.push_back(consumption_commercial_hydropower);

        getline(sso, tempString, ',');
        float consumption_commercial_kerosene = stoi(tempString);
        value.push_back(consumption_commercial_kerosene);

        getline(sso, tempString, ',');
        float consumption_commercial_petroleum = stoi(tempString);
        value.push_back(consumption_commercial_petroleum);

        getline(sso, tempString, ',');
        float consumption_commercial_naturalGas = stoi(tempString);
        value.push_back(consumption_commercial_naturalGas);

        getline(sso, tempString, ',');
        float consumption_commercial_solar = stoi(tempString);
        value.push_back(consumption_commercial_solar);

        getline(sso, tempString, ',');
        float consumption_commercial_wind = stoi(tempString);
        value.push_back(consumption_commercial_wind);

        getline(sso, tempString, ',');
        float consumption_commercial_wood = stoi(tempString);
        value.push_back(consumption_commercial_wood);

        getline(sso, tempString, ',');
        float consumption_electricPower_coal = stoi(tempString);
        value.push_back(consumption_electricPower_coal);

        getline(sso, tempString, ',');
        float consumption_electricPower_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_electricPower_naturalGas = stoi(tempString);
        value.push_back(consumption_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float consumption_electricPower_wood = stoi(tempString);
        value.push_back(consumption_electricPower_wood);

        getline(sso, tempString, ',');
        float consumption_industrial_coal = stoi(tempString);
        value.push_back(consumption_industrial_coal);

        getline(sso, tempString, ',');
        float consumption_industrial_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_industrial_geothermal = stoi(tempString);
        value.push_back(consumption_industrial_geothermal);

        getline(sso, tempString, ',');
        float consumption_industrial_hydropower = stoi(tempString);
        value.push_back(consumption_industrial_hydropower);

        getline(sso, tempString, ',');
        float consumption_industrial_kerosene = stoi(tempString);
        value.push_back(consumption_industrial_kerosene);

        getline(sso, tempString, ',');
        float consumption_industrial_petroleum = stoi(tempString);
        value.push_back(consumption_industrial_petroleum);

        getline(sso, tempString, ',');
        float consumption_industrial_naturalGas = stoi(tempString);
        value.push_back(consumption_industrial_naturalGas);

        getline(sso, tempString, ',');
        float consumption_industrial_otherPetroleumProducts = stoi(tempString);
        value.push_back(consumption_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        float consumption_industrial_solar = stoi(tempString);
        value.push_back(consumption_industrial_solar);

        getline(sso, tempString, ',');
        float consumption_industrial_wind = stoi(tempString);
        value.push_back(consumption_industrial_wind);

        getline(sso, tempString, ',');
        float consumption_industrial_wood = stoi(tempString);
        value.push_back(consumption_industrial_wood);

        getline(sso, tempString, ',');
        float consumption_refinery_coal = stoi(tempString);
        value.push_back(consumption_refinery_coal);
        

        getline(sso, tempString, ',');
        float consumption_refinery_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_refinery_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_refinery_naturalGas = stoi(tempString);
        value.push_back(consumption_refinery_naturalGas);

        getline(sso, tempString, ',');
        float consumption_residential_coal = stoi(tempString);
        value.push_back(consumption_residential_coal);

        getline(sso, tempString, ',');
        float consumption_residential_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_residential_geothermal = stoi(tempString);
        value.push_back(consumption_residential_geothermal);

        getline(sso, tempString, ',');
        float consumption_residential_kerosene = stoi(tempString);
        value.push_back(consumption_residential_kerosene);

        getline(sso, tempString, ',');
        float consumption_residential_petroleum = stoi(tempString);
        value.push_back(consumption_residential_petroleum);

        getline(sso, tempString, ',');
        float consumption_residential_naturalGas = stoi(tempString);
        value.push_back(consumption_residential_naturalGas);

        getline(sso, tempString, ',');
        float consumption_residential_wood = stoi(tempString);
        value.push_back(consumption_residential_wood);

        getline(sso, tempString, ',');
        float consumption_transportation_coal = stoi(tempString);
        value.push_back(consumption_transportation_coal);

        getline(sso, tempString, ',');
        float consumption_transportation_distillateFuelOil = stoi(tempString);
        value.push_back(consumption_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float consumption_transportation_petroleum = stoi(tempString);
        value.push_back(consumption_transportation_petroleum);

        getline(sso, tempString, ',');
        float consumption_transportation_naturalGas = stoi(tempString);
        value.push_back(consumption_transportation_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_commercial_coal = stoi(tempString);
        value.push_back(expenditure_commercial_coal);

        getline(sso, tempString, ',');
        float expenditure_commercial_distillateFuelOil = stoi(tempString);
        value.push_back(expenditure_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_commercial_kerosene = stoi(tempString);
        value.push_back(expenditure_commercial_kerosene);

        getline(sso, tempString, ',');
        float expenditure_commercial_petroleum = stoi(tempString);
        value.push_back(expenditure_commercial_petroleum);

        getline(sso, tempString, ',');
        float expenditure_electricPower_coal = stoi(tempString);
        value.push_back(expenditure_electricPower_coal);

        getline(sso, tempString, ',');
        float expenditure_commercial_naturalGas = stoi(tempString);
        value.push_back(expenditure_commercial_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_electricPower_distillateFuelOil = stoi(tempString);
        value.push_back(expenditure_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_electricPower_naturalGas = stoi(tempString);
        value.push_back(expenditure_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_industrial_coal = stoi(tempString);
        value.push_back(expenditure_industrial_coal);

        getline(sso, tempString, ',');
        float expenditure_industrial_distillateFuelOil = stoi(tempString);
        value.push_back(expenditure_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_industrial_kerosene = stoi(tempString);
        value.push_back(expenditure_industrial_kerosene);

        getline(sso, tempString, ',');
        float expenditure_industrial_petroleum = stoi(tempString);
        value.push_back(expenditure_industrial_petroleum);

        getline(sso, tempString, ',');
        float expenditure_industrial_naturalGas = stoi(tempString);
        value.push_back(expenditure_industrial_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_industrial_otherPetroleumProducts = stoi(tempString);
        value.push_back(expenditure_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        float expenditure_residential_coal = stoi(tempString);
        value.push_back(expenditure_residential_coal);

        getline(sso, tempString, ',');
        float expenditure_residential_distillateFuelOil = stoi(tempString);
        value.push_back(expenditure_residential_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_residential_kerosene = stoi(tempString);
        value.push_back(expenditure_residential_kerosene);

        getline(sso, tempString, ',');
        float expenditure_residential_petroleum = stoi(tempString);
        value.push_back(expenditure_residential_petroleum);

        getline(sso, tempString, ',');
        float expenditure_residential_naturalGas = stoi(tempString);
        value.push_back(expenditure_residential_naturalGas);

        getline(sso, tempString, ',');
        float expenditure_residential_wood = stoi(tempString);
        value.push_back(expenditure_residential_wood);

        getline(sso, tempString, ',');
        float expenditure_transportation_coal = stoi(tempString);
        value.push_back(expenditure_transportation_coal);

        getline(sso, tempString, ',');
        float expenditure_transportation_distillateFuelOil = stoi(tempString);
        value.push_back(expenditure_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float expenditure_transportation_petroleum = stoi(tempString);
        value.push_back(expenditure_transportation_petroleum);

        getline(sso, tempString, ',');
        float expenditure_transportation_naturalGas = stoi(tempString);
        value.push_back(expenditure_transportation_naturalGas);

        getline(sso, tempString, ',');
        float price_commercial_coal = stoi(tempString);
        value.push_back(price_commercial_coal);

        getline(sso, tempString, ',');
        float price_commercial_distillateFuelOil = stoi(tempString);
        value.push_back(price_commercial_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_commercial_kerosene = stoi(tempString);
        value.push_back(price_commercial_kerosene);

        getline(sso, tempString, ',');
        float price_commercial_petroleum = stoi(tempString);
        value.push_back(price_commercial_petroleum);

        getline(sso, tempString, ',');
        float price_commercial_naturalGas = stoi(tempString);
        value.push_back(price_commercial_naturalGas);

        getline(sso, tempString, ',');
        float price_electricPower_coal = stoi(tempString);
        value.push_back(price_electricPower_coal);

        getline(sso, tempString, ',');
        float price_electricPower_distillateFuelOil = stoi(tempString);
        value.push_back(price_electricPower_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_electricPower_naturalGas = stoi(tempString);
        value.push_back(price_electricPower_naturalGas);

        getline(sso, tempString, ',');
        float price_industrial_coal = stoi(tempString);
        value.push_back(price_industrial_coal);

        getline(sso, tempString, ',');
        float price_industrial_distillateFuelOil = stoi(tempString);
        value.push_back(price_industrial_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_industrial_kerosene = stoi(tempString);
        value.push_back(price_industrial_kerosene);

        getline(sso, tempString, ',');
        float price_industrial_petroleum = stoi(tempString);
        value.push_back(price_industrial_petroleum);

        getline(sso, tempString, ',');
        float price_industrial_naturalGas = stoi(tempString);
        value.push_back(price_industrial_naturalGas);

        getline(sso, tempString, ',');
        float price_industrial_otherPetroleumProducts = stoi(tempString);
        value.push_back(price_industrial_otherPetroleumProducts);

        getline(sso, tempString, ',');
        float price_transportation_coal = stoi(tempString);
        value.push_back(price_transportation_coal);

        getline(sso, tempString, ',');
        float price_transportation_distillateFuelOil = stoi(tempString);
        value.push_back(price_transportation_distillateFuelOil);

        getline(sso, tempString, ',');
        float price_transportation_petroleum = stoi(tempString);
        value.push_back(price_transportation_petroleum);

        getline(sso, tempString, ',');
        float price_transportation_naturalGas = stoi(tempString);
        value.push_back(price_transportation_naturalGas);

        State stateObject(production_coal, consumption_commercial_coal, consumption_commercial_distillateFuelOil, consumption_commercial_geothermal, consumption_commercial_hydropower, consumption_commercial_kerosene, consumption_commercial_petroleum, consumption_commercial_naturalGas, consumption_commercial_solar, consumption_commercial_wind, consumption_commercial_wood, consumption_electricPower_coal, consumption_electricPower_distillateFuelOil, consumption_electricPower_naturalGas, consumption_electricPower_wood, consumption_industrial_coal, consumption_industrial_distillateFuelOil, consumption_industrial_geothermal, consumption_industrial_hydropower, consumption_industrial_kerosene, consumption_industrial_petroleum, consumption_industrial_naturalGas, consumption_industrial_otherPetroleumProducts, consumption_industrial_solar, consumption_industrial_wind, consumption_industrial_wood, consumption_refinery_coal, consumption_refinery_distillateFuelOil, consumption_refinery_naturalGas, consumption_residential_coal, consumption_residential_distillateFuelOil, consumption_residential_geothermal, consumption_residential_kerosene, consumption_residential_petroleum, consumption_residential_naturalGas, consumption_residential_wood, consumption_transportation_coal, consumption_transportation_distillateFuelOil, consumption_transportation_petroleum, consumption_transportation_naturalGas, expenditure_commercial_coal, expenditure_commercial_distillateFuelOil, expenditure_commercial_kerosene, expenditure_commercial_petroleum, expenditure_commercial_naturalGas, expenditure_electricPower_coal, expenditure_electricPower_distillateFuelOil, expenditure_electricPower_naturalGas, expenditure_industrial_coal, expenditure_industrial_distillateFuelOil, expenditure_industrial_kerosene, expenditure_industrial_petroleum, expenditure_industrial_naturalGas, expenditure_industrial_otherPetroleumProducts, expenditure_residential_coal, expenditure_residential_distillateFuelOil, expenditure_residential_kerosene, expenditure_residential_petroleum, expenditure_residential_naturalGas, expenditure_residential_wood, expenditure_transportation_coal, expenditure_transportation_distillateFuelOil, expenditure_transportation_petroleum, expenditure_transportation_naturalGas, price_commercial_coal, price_commercial_distillateFuelOil, price_commercial_kerosene, price_commercial_petroleum,  price_commercial_naturalGas, price_electricPower_coal, price_electricPower_distillateFuelOil, price_electricPower_naturalGas, price_industrial_coal, price_industrial_distillateFuelOil, price_industrial_kerosene, price_industrial_petroleum, price_industrial_naturalGas, price_industrial_otherPetroleumProducts, price_transportation_coal, price_transportation_distillateFuelOil, price_transportation_petroleum, price_transportation_naturalGas);

        data.energyData.insert(make_pair(stateName, unordered_map<int, State>()));
        data.energyData[stateName].insert(make_pair(year, stateObject));


        for(int i = 0; i < names.size(); i++){
            data.sortedData.insert(make_pair(stateName, unordered_map<string, vector<pair<int, int>>>()));
            data.sortedData[stateName].insert(make_pair(names[i], vector<pair<int, int>>()));
            data.sortedData[stateName][names[i]].push_back(make_pair(year, names[i]));
        }

        data.sortedData.insert(make_pair(stateName, unordered_map<string, vector<pair<int, int>>>()));
        data.sortedData[stateName].insert(make_pair("production_coal", vector<pair<int, int>>()));
        data.sortedData[stateName]["production_coal"].push_back(make_pair(year, production_coal));

        data.sortedData.insert(make_pair(stateName, unordered_map<string, vector<pair<int, int>>>()));
        data.sortedData[stateName].insert(make_pair("consumption_commercial_coal", vector<pair<int, int>>()));
        data.sortedData[stateName]["consumption_commercial_coal"].push_back(make_pair(year, consumption_commercial_coal));

    }






    return 0;
}