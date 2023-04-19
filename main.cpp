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


    ifstream myFile;
    myFile.open(fileName);

    getline(myFile, firstRow);

    while(getline(myFile, line))
    {

        stringstream sso(line);
        getline(sso, stateName, ',');

        getline(sso, tempString, ',');
        auto year = stoi(tempString);

        getline(sso, tempString, ',');
        auto production_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_geothermal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_hydropower = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_solar = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_wind = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_commercial_wood = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_electricPower_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_electricPower_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_electricPower_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_electricPower_wood = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_geothermal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_hydropower = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_otherPetroleumProducts = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_solar = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_wind = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_industrial_wood = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_refinery_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_refinery_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_refinery_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_geothermal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_residential_wood = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_transportation_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_transportation_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_transportation_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto consumption_transportation_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_commercial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_commercial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_commercial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_commercial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_commercial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_electricPower_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_industrial_otherPetroleumProducts = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_residential_wood = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_transportation_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_transportation_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_transportation_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto expenditure_transportation_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_commercial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_commercial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_commercial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_commercial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_commercial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_electricPower_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_electricPower_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_electricPower_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_kerosene = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_naturalGas = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_industrial_otherPetroleumProducts = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_transportation_coal = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_transportation_distillateFuelOil = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_transportation_petroleum = stoi(tempString);

        getline(sso, tempString, ',');
        auto price_transportation_naturalGas = stoi(tempString);

        State stateObject(production_coal, consumption_commercial_coal, consumption_commercial_distillateFuelOil, consumption_commercial_geothermal, consumption_commercial_hydropower, consumption_commercial_kerosene, consumption_commercial_petroleum, consumption_commercial_naturalGas, consumption_commercial_solar, consumption_commercial_wind, consumption_commercial_wood, consumption_electricPower_coal, consumption_electricPower_distillateFuelOil, consumption_electricPower_naturalGas, consumption_electricPower_wood, consumption_industrial_coal, consumption_industrial_distillateFuelOil, consumption_industrial_geothermal, consumption_industrial_hydropower, consumption_industrial_kerosene, consumption_industrial_petroleum, consumption_industrial_naturalGas, consumption_industrial_otherPetroleumProducts, consumption_industrial_solar, consumption_industrial_wind, consumption_industrial_wood, consumption_refinery_coal, consumption_refinery_distillateFuelOil, consumption_refinery_naturalGas, consumption_residential_coal, consumption_residential_distillateFuelOil, consumption_residential_geothermal, consumption_residential_kerosene, consumption_residential_petroleum, consumption_residential_naturalGas, consumption_residential_wood, consumption_transportation_coal, consumption_transportation_distillateFuelOil, consumption_transportation_petroleum, consumption_transportation_naturalGas, expenditure_commercial_coal, expenditure_commercial_distillateFuelOil, expenditure_commercial_kerosene, expenditure_commercial_petroleum, expenditure_commercial_naturalGas, expenditure_electricPower_coal, expenditure_electricPower_distillateFuelOil, expenditure_electricPower_naturalGas, expenditure_industrial_coal, expenditure_industrial_distillateFuelOil, expenditure_industrial_kerosene, expenditure_industrial_petroleum, expenditure_industrial_naturalGas, expenditure_industrial_otherPetroleumProducts, expenditure_residential_coal, expenditure_residential_distillateFuelOil, expenditure_residential_kerosene, expenditure_residential_petroleum, expenditure_residential_naturalGas, expenditure_residential_wood, expenditure_transportation_coal, expenditure_transportation_distillateFuelOil, expenditure_transportation_petroleum, expenditure_transportation_naturalGas, price_commercial_coal, price_commercial_distillateFuelOil, price_commercial_kerosene, price_commercial_petroleum,  price_commercial_naturalGas, price_electricPower_coal, price_electricPower_distillateFuelOil, price_electricPower_naturalGas, price_industrial_coal, price_industrial_distillateFuelOil, price_industrial_kerosene, price_industrial_petroleum, price_industrial_naturalGas, price_industrial_otherPetroleumProducts, price_transportation_coal, price_transportation_distillateFuelOil, price_transportation_petroleum, price_transportation_naturalGas);






    }




    return 0;
}
