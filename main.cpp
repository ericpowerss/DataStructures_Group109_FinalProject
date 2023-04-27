#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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
    vector<string> validStateNames {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District of Columbia", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
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

    bool endMenu = true;
    cout << "Welcome to the super awesome state energy sorter!" << endl;
    while(endMenu)
    {
        string stringOption;
        int option = 0;
        string state;
        string state2;
        bool repeat = true;
        bool validStateName = false;
        bool validStateName2 = false;
        bool validEnergyType = false;
        bool keepGoing = true;


        cout << "Choose an option:" << endl;
        cout << "1: Specific Data from a state associate energy type given a year." << endl;
        cout << "2: Average usage of fuel source data from 1960 to 2019 for a given state." << endl;
        cout << "3: Compare the usage of two states fuel source data for a given year." << endl;
        cout << "4: Compare Tim sort with Quick sort with execution time." << endl;
        cout << "5: Exit Program." << endl;


        getline(cin, stringOption);

        for (char c : stringOption) {
            if (!isdigit(c)) {
                stringOption = "6";
                break;
            }
        }

        option = stoi(stringOption);
        cout << "\n";

        if(option == 1) {
            while (true) {
                cout << "Which state would you like to gather data on? (Please Capitalize the state.)" << endl;
                cin >> state;

                for (int i = 0; i < validStateNames.size(); i++) {
                    if (validStateNames[i] == state) {
                        validStateName = true;
                    }
                }
                if (validStateName) {
                    string energyType;
                    cout << "\n";
                    cout << "Which fuel source data would you like to see?" << endl;
                    cout << "1: Production_Coal\n2: Consumption_Commercial_Coal\n3: Consumption_Commercial_Distillate Fuel Oil\n";
                    cout << "4: Consumption_Commercial_Geothermal\n5: Consumption_Commercial_Hydropower\n6: Consumption_Commercial_Kerosene\n";
                    cout << "7: Consumption_Commercial_Petroleum\n8: Consumption_Commercial_Natural Gas\n9: Consumption_Commercial_Solar\n";
                    cout << "10: Consumption_Commercial_Wind\n11: Consumption_Commercial_Wood\n12: Consumption_Electric Power_Coal\n";
                    cout << "13: Consumption_Electric Power_Distillate Fuel Oil\n14: Consumption_Electric Power_Natural Gas\n15: Consumption_Electric Power_Wood\n";
                    cout << "16: Consumption_Industrial_Coal\n17: Consumption_Industrial_Distillate Fuel Oil\n18: Consumption_Industrial_Geothermal\n";
                    cout << "19: Consumption_Industrial_Hydropower\n20: Consumption_Industrial_Kerosene\n21: Consumption_Industrial_Petroleum\n";
                    cout << "22: Consumption_Industrial_Natural Gas\n23: Consumption_Industrial_Other Petroleum Products\n24: Consumption_Industrial_Solar\n";
                    cout << "25: Consumption_Industrial_Wind\n26: Consumption_Industrial_Wood\n27: Consumption_Refinery_Coal\n";
                    cout << "28: Consumption_Refinery_Distillate Fuel Oil\n29: Consumption_Refinery_Natural Gas\n30: Consumption_Residential_Coal\n";
                    cout << "31: Consumption_Residential_Distillate Fuel Oil\n32: Consumption_Residential_Geothermal\n33: Consumption_Residential_Kerosene\n";
                    cout << "34: Consumption_Residential_Petroleum\n35: Consumption_Residential_Natural Gas\n36: Consumption_Residential_Wood\n";
                    cout << "37: Consumption_Transportation_Coal\n38: Consumption_Transportation_Distillate Fuel Oil\n39: Consumption_Transportation_Petroleum\n";
                    cout << "40: Consumption_Transportation_Natural Gas\n41: Expenditure_Commercial_Coal\n42: Expenditure_Commercial_Distillate Fuel Oil\n";
                    cout << "43: Expenditure_Commercial_Kerosene\n44: Expenditure_Commercial_Petroleum\n45: Expenditure_Commercial_Natural Gas\n";
                    cout << "46: Expenditure_Electric Power_Coal\n47: Expenditure_Electric Power_Distillate Fuel Oil\n48: Expenditure_Electric Power_Natural Gas\n";
                    cout << "49: Expenditure_Industrial_Coal\n50: Expenditure_Industrial_Distillate Fuel Oil\n51: Expenditure_Industrial_Kerosene\n";
                    cout << "52: Expenditure_Industrial_Petroleum\n53: Expenditure_Industrial_Natural Gas\n54: Expenditure_Industrial_Other Petroleum Products\n";
                    cout << "55: Expenditure_Residential_Coal\n56: Expenditure_Residential_Distillate Fuel Oil\n57: Expenditure_Residential_Kerosene\n";
                    cout << "58: Expenditure_Residential_Petroleum\n59: Expenditure_Residential_Natural Gas\n60: Expenditure_Residential_Wood\n";
                    cout << "61: Expenditure_Transportation_Coal\n62: Expenditure_Transportation_Distillate Fuel Oil\n63: Expenditure_Transportation_Petroleum\n";
                    cout << "64: Expenditure_Transportation_Natural Gas\n65: Price_Commercial_Coal\n66: Price_Commercial_Distillate Fuel Oil\n";
                    cout << "67: Price_Commercial_Kerosene\n68: Price_Commercial_Petroleum\n69: Price_Commercial_Natural Gas\n";
                    cout << "70: Price_Electric Power_Coal\n71: Price_Electric Power_Distillate Fuel Oil\n72: Price_Electric Power_Natural Gas\n";
                    cout << "73: Price_Industrial_Coal\n74: Price_Industrial_Distillate Fuel Oil\n75: Price_Industrial_Kerosene\n";
                    cout << "76: Price_Industrial_Petroleum\n77: Price_Industrial_Natural Gas\n78: Price_Industrial_Other Petroleum Products\n";
                    cout << "79: Price_Transportation_Coal\n80: Price_Transportation_Distillate Fuel Oil\n81: Price_Transportation_Petroleum\n";
                    cout << "82: Price_Transportation_Natural Gas\n";
                    cout << "Please enter the name of energy type as it appears, not the number in list." << endl;

                    while(true){
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, energyType);

                    for(int i = 0; i < names.size(); i++){
                        if(names[i] == energyType){
                            validEnergyType = true;
                        }
                    }

                    if(validEnergyType){
                        int year;
                        while(keepGoing) {
                            cout << "\n";
                            cout << "Please enter the year you wish to view. This data base starts from 1960 till 2019." << endl;
                            cin >> year;
                            if (year >= 1960 && year <= 2019) {
                                sortData(data.sortedData, energyType);
                                for(auto& look : data.sortedData){
                                    for(auto& search : look.second){
                                        if(look.first == state && search.first == energyType){
                                            float temp = 0;
                                            for(auto& find : search.second){
                                                if(find.first == year){
                                                    temp = find.second;
                                                }
                                            }
                                            cout << state << " " << energyType << " "<< year << ": " << temp << endl;
                                            keepGoing = !keepGoing;
                                        }
                                    }
                                }
                            } else {
                                cout << "The year you've entered is invalid and is out of the scope of this data base." << endl;
                                continue;
                            }

                        }

                    }
                    else if(!validEnergyType){
                        cout << "The fuel source data you've entered is invalid. Please enter the fuel source exact as seen above with underscores and capitalization.\n" "You must press enter before entering another fuel source." << endl;
                        continue;
                    }

                    }

                } else if (!validStateName) {
                    cout << "The state name you've enter is invalid. Please enter the state you which to see with proper spacing and capitalization." << endl;
                    continue;
                }

            }
        }

        else if(option == 2){
            while (true) {
                cout << "Which state would you like to gather data on? (Please Capitalize the state.)" << endl;
                cin >> state;

                for (int i = 0; i < validStateNames.size(); i++) {
                    if (validStateNames[i] == state) {
                        validStateName = true;
                    }
                }
                if (validStateName) {
                    string energyType;
                    cout << "\n";
                    cout << "Which fuel source data would you like to see?" << endl;
                    cout << "1: Production_Coal\n2: Consumption_Commercial_Coal\n3: Consumption_Commercial_Distillate Fuel Oil\n";
                    cout << "4: Consumption_Commercial_Geothermal\n5: Consumption_Commercial_Hydropower\n6: Consumption_Commercial_Kerosene\n";
                    cout << "7: Consumption_Commercial_Petroleum\n8: Consumption_Commercial_Natural Gas\n9: Consumption_Commercial_Solar\n";
                    cout << "10: Consumption_Commercial_Wind\n11: Consumption_Commercial_Wood\n12: Consumption_Electric Power_Coal\n";
                    cout << "13: Consumption_Electric Power_Distillate Fuel Oil\n14: Consumption_Electric Power_Natural Gas\n15: Consumption_Electric Power_Wood\n";
                    cout << "16: Consumption_Industrial_Coal\n17: Consumption_Industrial_Distillate Fuel Oil\n18: Consumption_Industrial_Geothermal\n";
                    cout << "19: Consumption_Industrial_Hydropower\n20: Consumption_Industrial_Kerosene\n21: Consumption_Industrial_Petroleum\n";
                    cout << "22: Consumption_Industrial_Natural Gas\n23: Consumption_Industrial_Other Petroleum Products\n24: Consumption_Industrial_Solar\n";
                    cout << "25: Consumption_Industrial_Wind\n26: Consumption_Industrial_Wood\n27: Consumption_Refinery_Coal\n";
                    cout << "28: Consumption_Refinery_Distillate Fuel Oil\n29: Consumption_Refinery_Natural Gas\n30: Consumption_Residential_Coal\n";
                    cout << "31: Consumption_Residential_Distillate Fuel Oil\n32: Consumption_Residential_Geothermal\n33: Consumption_Residential_Kerosene\n";
                    cout << "34: Consumption_Residential_Petroleum\n35: Consumption_Residential_Natural Gas\n36: Consumption_Residential_Wood\n";
                    cout << "37: Consumption_Transportation_Coal\n38: Consumption_Transportation_Distillate Fuel Oil\n39: Consumption_Transportation_Petroleum\n";
                    cout << "40: Consumption_Transportation_Natural Gas\n41: Expenditure_Commercial_Coal\n42: Expenditure_Commercial_Distillate Fuel Oil\n";
                    cout << "43: Expenditure_Commercial_Kerosene\n44: Expenditure_Commercial_Petroleum\n45: Expenditure_Commercial_Natural Gas\n";
                    cout << "46: Expenditure_Electric Power_Coal\n47: Expenditure_Electric Power_Distillate Fuel Oil\n48: Expenditure_Electric Power_Natural Gas\n";
                    cout << "49: Expenditure_Industrial_Coal\n50: Expenditure_Industrial_Distillate Fuel Oil\n51: Expenditure_Industrial_Kerosene\n";
                    cout << "52: Expenditure_Industrial_Petroleum\n53: Expenditure_Industrial_Natural Gas\n54: Expenditure_Industrial_Other Petroleum Products\n";
                    cout << "55: Expenditure_Residential_Coal\n56: Expenditure_Residential_Distillate Fuel Oil\n57: Expenditure_Residential_Kerosene\n";
                    cout << "58: Expenditure_Residential_Petroleum\n59: Expenditure_Residential_Natural Gas\n60: Expenditure_Residential_Wood\n";
                    cout << "61: Expenditure_Transportation_Coal\n62: Expenditure_Transportation_Distillate Fuel Oil\n63: Expenditure_Transportation_Petroleum\n";
                    cout << "64: Expenditure_Transportation_Natural Gas\n65: Price_Commercial_Coal\n66: Price_Commercial_Distillate Fuel Oil\n";
                    cout << "67: Price_Commercial_Kerosene\n68: Price_Commercial_Petroleum\n69: Price_Commercial_Natural Gas\n";
                    cout << "70: Price_Electric Power_Coal\n71: Price_Electric Power_Distillate Fuel Oil\n72: Price_Electric Power_Natural Gas\n";
                    cout << "73: Price_Industrial_Coal\n74: Price_Industrial_Distillate Fuel Oil\n75: Price_Industrial_Kerosene\n";
                    cout << "76: Price_Industrial_Petroleum\n77: Price_Industrial_Natural Gas\n78: Price_Industrial_Other Petroleum Products\n";
                    cout << "79: Price_Transportation_Coal\n80: Price_Transportation_Distillate Fuel Oil\n81: Price_Transportation_Petroleum\n";
                    cout << "82: Price_Transportation_Natural Gas\n";
                    cout << "Please enter the name of energy type as it appears, not the number in list." << endl;

                    while(true){
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, energyType);

                        for(int i = 0; i < names.size(); i++){
                            if(names[i] == energyType){
                                validEnergyType = true;
                            }
                        }

                        if(validEnergyType){
                            sortData(data.sortedData, energyType);
                            float temp = 0.0;
                            for(auto& first : data.sortedData){
                                for (auto& second : first.second){
                                    for(auto& third : second.second){
                                        if(second.first == energyType && first.first == state)
                                        temp += third.second;
                                    }
                                }
                            }

                            cout << "The average data for " << energyType << " in " << state << " is " << temp/60.0;

                        }
                        else if(!validEnergyType){
                            cout << "The fuel source data you've entered is invalid. Please enter the fuel source exact as seen above with underscores and capitalization.\n" "You must press enter before entering another fuel source." << endl;
                            continue;
                        }
                    }
                } else if (!validStateName) {
                    cout << "The state name you've enter is invalid. Please enter the state you which to see with proper spacing and capitalization." << endl;
                    continue;
                }
            }
        }

        else if(option == 3){
            while (true) {
                cout << "Which first state would you like to gather data on and compare? (Please Capitalize the state.)" << endl;
                cin >> state;

                cout << "\n";
                cout << "Which second state would you like to gather data on and compare? (Please Capitalize the state.)" << endl;
                cin >> state2;

                for (int i = 0; i < validStateNames.size(); i++) {
                    if (validStateNames[i] == state) {
                        validStateName = true;
                    }
                    if (validStateNames[i] == state2){
                        validStateName2 = true;
                    }
                }
                if (validStateName && validStateName2) {
                    string energyType;
                    string energyType2;
                    cout << "\n";
                    cout << "Which fuel source data would you like to see?" << endl;
                    cout << "1: Production_Coal\n2: Consumption_Commercial_Coal\n3: Consumption_Commercial_Distillate Fuel Oil\n";
                    cout << "4: Consumption_Commercial_Geothermal\n5: Consumption_Commercial_Hydropower\n6: Consumption_Commercial_Kerosene\n";
                    cout << "7: Consumption_Commercial_Petroleum\n8: Consumption_Commercial_Natural Gas\n9: Consumption_Commercial_Solar\n";
                    cout << "10: Consumption_Commercial_Wind\n11: Consumption_Commercial_Wood\n12: Consumption_Electric Power_Coal\n";
                    cout << "13: Consumption_Electric Power_Distillate Fuel Oil\n14: Consumption_Electric Power_Natural Gas\n15: Consumption_Electric Power_Wood\n";
                    cout << "16: Consumption_Industrial_Coal\n17: Consumption_Industrial_Distillate Fuel Oil\n18: Consumption_Industrial_Geothermal\n";
                    cout << "19: Consumption_Industrial_Hydropower\n20: Consumption_Industrial_Kerosene\n21: Consumption_Industrial_Petroleum\n";
                    cout << "22: Consumption_Industrial_Natural Gas\n23: Consumption_Industrial_Other Petroleum Products\n24: Consumption_Industrial_Solar\n";
                    cout << "25: Consumption_Industrial_Wind\n26: Consumption_Industrial_Wood\n27: Consumption_Refinery_Coal\n";
                    cout << "28: Consumption_Refinery_Distillate Fuel Oil\n29: Consumption_Refinery_Natural Gas\n30: Consumption_Residential_Coal\n";
                    cout << "31: Consumption_Residential_Distillate Fuel Oil\n32: Consumption_Residential_Geothermal\n33: Consumption_Residential_Kerosene\n";
                    cout << "34: Consumption_Residential_Petroleum\n35: Consumption_Residential_Natural Gas\n36: Consumption_Residential_Wood\n";
                    cout << "37: Consumption_Transportation_Coal\n38: Consumption_Transportation_Distillate Fuel Oil\n39: Consumption_Transportation_Petroleum\n";
                    cout << "40: Consumption_Transportation_Natural Gas\n41: Expenditure_Commercial_Coal\n42: Expenditure_Commercial_Distillate Fuel Oil\n";
                    cout << "43: Expenditure_Commercial_Kerosene\n44: Expenditure_Commercial_Petroleum\n45: Expenditure_Commercial_Natural Gas\n";
                    cout << "46: Expenditure_Electric Power_Coal\n47: Expenditure_Electric Power_Distillate Fuel Oil\n48: Expenditure_Electric Power_Natural Gas\n";
                    cout << "49: Expenditure_Industrial_Coal\n50: Expenditure_Industrial_Distillate Fuel Oil\n51: Expenditure_Industrial_Kerosene\n";
                    cout << "52: Expenditure_Industrial_Petroleum\n53: Expenditure_Industrial_Natural Gas\n54: Expenditure_Industrial_Other Petroleum Products\n";
                    cout << "55: Expenditure_Residential_Coal\n56: Expenditure_Residential_Distillate Fuel Oil\n57: Expenditure_Residential_Kerosene\n";
                    cout << "58: Expenditure_Residential_Petroleum\n59: Expenditure_Residential_Natural Gas\n60: Expenditure_Residential_Wood\n";
                    cout << "61: Expenditure_Transportation_Coal\n62: Expenditure_Transportation_Distillate Fuel Oil\n63: Expenditure_Transportation_Petroleum\n";
                    cout << "64: Expenditure_Transportation_Natural Gas\n65: Price_Commercial_Coal\n66: Price_Commercial_Distillate Fuel Oil\n";
                    cout << "67: Price_Commercial_Kerosene\n68: Price_Commercial_Petroleum\n69: Price_Commercial_Natural Gas\n";
                    cout << "70: Price_Electric Power_Coal\n71: Price_Electric Power_Distillate Fuel Oil\n72: Price_Electric Power_Natural Gas\n";
                    cout << "73: Price_Industrial_Coal\n74: Price_Industrial_Distillate Fuel Oil\n75: Price_Industrial_Kerosene\n";
                    cout << "76: Price_Industrial_Petroleum\n77: Price_Industrial_Natural Gas\n78: Price_Industrial_Other Petroleum Products\n";
                    cout << "79: Price_Transportation_Coal\n80: Price_Transportation_Distillate Fuel Oil\n81: Price_Transportation_Petroleum\n";
                    cout << "82: Price_Transportation_Natural Gas\n";
                    cout << "Please enter the name of energy type as it appears, not the number in list." << endl;

                    while(true){
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, energyType);

                        for(int i = 0; i < names.size(); i++){
                            if(names[i] == energyType){
                                validEnergyType = true;
                            }
                        }

                        if(validEnergyType){
                            int year;
                            while(keepGoing) {
                                cout << "\n";
                                cout << "Please enter the year you wish to view. This data base starts from 1960 till 2019." << endl;
                                cin >> year;
                                if (year >= 1960 && year <= 2019) {
                                    sortData(data.sortedData, energyType);
                                    for(auto& look : data.sortedData){
                                        for(auto& search : look.second){
                                            if(look.first == state && search.first == energyType){
                                                float temp = 0;
                                                for(auto& find : search.second){
                                                    if(find.first == year){
                                                        temp = find.second;
                                                    }
                                                }
                                                cout << state << " " << energyType << " "<< year << " " << temp << endl;
                                                keepGoing = !keepGoing;
                                            }
                                            else if(look.first == state2 && search.first == energyType){
                                                float temp2 = 0;
                                                for(auto& find : search.second){
                                                    if(find.first == year){
                                                        temp2 = find.second;
                                                    }
                                                }
                                                cout << state2 << " " << energyType << " "<< year << " " << temp2 << endl;
                                                keepGoing = !keepGoing;
                                            }
                                        }
                                    }
                                } else {
                                    cout << "The year you've entered is invalid and is out of the scope of this data base." << endl;
                                    continue;
                                }
                            }
                        }
                        else if(!validEnergyType){
                            cout << "The fuel source data you've entered is invalid. Please enter the fuel source exact as seen above with underscores and capitalization.\n" "You must press enter before entering another fuel source." << endl;
                            continue;
                        }
                    }
                } else if (!validStateName) {
                    cout << "The state name you've enter is invalid. Please enter the state you which to see with proper spacing and capitalization." << endl;
                    continue;
                }
            }
        }



        // This is what you need to implement into option 4.

        else if (option == 4)
        {

            string productionType;
            cout << "Which fuel source data would you like to see?" << endl;
            cout << "1: Production_Coal\n2: Consumption_Commercial_Coal\n3: Consumption_Commercial_Distillate Fuel Oil\n";
            cout << "4: Consumption_Commercial_Geothermal\n5: Consumption_Commercial_Hydropower\n6: Consumption_Commercial_Kerosene\n";
            cout << "7: Consumption_Commercial_Petroleum\n8: Consumption_Commercial_Natural Gas\n9: Consumption_Commercial_Solar\n";
            cout << "10: Consumption_Commercial_Wind\n11: Consumption_Commercial_Wood\n12: Consumption_Electric Power_Coal\n";
            cout << "13: Consumption_Electric Power_Distillate Fuel Oil\n14: Consumption_Electric Power_Natural Gas\n15: Consumption_Electric Power_Wood\n";
            cout << "16: Consumption_Industrial_Coal\n17: Consumption_Industrial_Distillate Fuel Oil\n18: Consumption_Industrial_Geothermal\n";
            cout << "19: Consumption_Industrial_Hydropower\n20: Consumption_Industrial_Kerosene\n21: Consumption_Industrial_Petroleum\n";
            cout << "22: Consumption_Industrial_Natural Gas\n23: Consumption_Industrial_Other Petroleum Products\n24: Consumption_Industrial_Solar\n";
            cout << "25: Consumption_Industrial_Wind\n26: Consumption_Industrial_Wood\n27: Consumption_Refinery_Coal\n";
            cout << "28: Consumption_Refinery_Distillate Fuel Oil\n29: Consumption_Refinery_Natural Gas\n30: Consumption_Residential_Coal\n";
            cout << "31: Consumption_Residential_Distillate Fuel Oil\n32: Consumption_Residential_Geothermal\n33: Consumption_Residential_Kerosene\n";
            cout << "34: Consumption_Residential_Petroleum\n35: Consumption_Residential_Natural Gas\n36: Consumption_Residential_Wood\n";
            cout << "37: Consumption_Transportation_Coal\n38: Consumption_Transportation_Distillate Fuel Oil\n39: Consumption_Transportation_Petroleum\n";
            cout << "40: Consumption_Transportation_Natural Gas\n41: Expenditure_Commercial_Coal\n42: Expenditure_Commercial_Distillate Fuel Oil\n";
            cout << "43: Expenditure_Commercial_Kerosene\n44: Expenditure_Commercial_Petroleum\n45: Expenditure_Commercial_Natural Gas\n";
            cout << "46: Expenditure_Electric Power_Coal\n47: Expenditure_Electric Power_Distillate Fuel Oil\n48: Expenditure_Electric Power_Natural Gas\n";
            cout << "49: Expenditure_Industrial_Coal\n50: Expenditure_Industrial_Distillate Fuel Oil\n51: Expenditure_Industrial_Kerosene\n";
            cout << "52: Expenditure_Industrial_Petroleum\n53: Expenditure_Industrial_Natural Gas\n54: Expenditure_Industrial_Other Petroleum Products\n";
            cout << "55: Expenditure_Residential_Coal\n56: Expenditure_Residential_Distillate Fuel Oil\n57: Expenditure_Residential_Kerosene\n";
            cout << "58: Expenditure_Residential_Petroleum\n59: Expenditure_Residential_Natural Gas\n60: Expenditure_Residential_Wood\n";
            cout << "61: Expenditure_Transportation_Coal\n62: Expenditure_Transportation_Distillate Fuel Oil\n63: Expenditure_Transportation_Petroleum\n";
            cout << "64: Expenditure_Transportation_Natural Gas\n65: Price_Commercial_Coal\n66: Price_Commercial_Distillate Fuel Oil\n";
            cout << "67: Price_Commercial_Kerosene\n68: Price_Commercial_Petroleum\n69: Price_Commercial_Natural Gas\n";
            cout << "70: Price_Electric Power_Coal\n71: Price_Electric Power_Distillate Fuel Oil\n72: Price_Electric Power_Natural Gas\n";
            cout << "73: Price_Industrial_Coal\n74: Price_Industrial_Distillate Fuel Oil\n75: Price_Industrial_Kerosene\n";
            cout << "76: Price_Industrial_Petroleum\n77: Price_Industrial_Natural Gas\n78: Price_Industrial_Other Petroleum Products\n";
            cout << "79: Price_Transportation_Coal\n80: Price_Transportation_Distillate Fuel Oil\n81: Price_Transportation_Petroleum\n";
            cout << "82: Price_Transportation_Natural Gas\n";
            cout << "Please enter the name of energy type as it appears, not the number in list." << endl;

            getline(cin, productionType);
            EnergyData Tim(data);
            int r;

            if (productionType == "State" || productionType == "Year")
            {
                cout << productionType << " is not a valid name." << endl;
                continue;
            }

            auto it = find(names.begin(), names.end(), productionType);
            if (it != names.end()) {
                auto start1 = chrono::high_resolution_clock::now();
                for (auto &temp: Tim.sortedData) {
                    for (auto &innerMap: temp.second) {
                        if (innerMap.first == productionType) {
                            vector<pair<int, float>> &specificData = innerMap.second;
                            r = innerMap.second.size();
                            timSort(specificData, r);

                            cout << temp.first << endl;
                            cout << productionType << ": ";
                            for (const auto& pair : specificData) {
                                cout << "(" << pair.first << ", " << pair.second << ") ";
                            }
                        }
                    }
                    cout << endl;

                }
                auto end1 = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();


                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;



                auto start2 = chrono::high_resolution_clock::now();
                sortData(data.sortedData, productionType);

                for (const auto& stateData : data.sortedData) {

                    cout << stateData.first << endl;
                    cout << productionType << ": ";
                    for (const auto& value : stateData.second.at(productionType)) {
                        cout << "(" << value.first << ", " << value.second << ") ";
                    }
                    cout << endl;
                }

                auto end2 = chrono::high_resolution_clock::now();
                auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << endl;
                cout << "Quick sort elapsed time: " << duration1 << " ms" << std::endl;
                cout << "Tim sort elapsed time: " << duration2 << " ms" << endl;
                cout << endl;
            }

            else {
                cout << productionType << " is not a valid name." << endl;
            }



        }


        else if (option == 5)
        {
            endMenu = false;
            cout << "I hope you enjoyed this super awesome program!" << endl;
        }

        else
        {
            cout << "Please enter a valid option choice." << endl;
        }


    }


    return 0;
}