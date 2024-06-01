#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    // Predefined symptoms and corresponding diseases
    map<string, vector<string>> symptomToDiseases = {
        {"fever", {"Flu", "Common Cold", "COVID-19"}},
        {"cough", {"Flu", "Common Cold", "COVID-19", "Bronchitis"}},
        {"fatigue", {"Flu", "COVID-19", "Anemia", "Diabetes"}},
        {"headache", {"Migraine", "Flu", "Tension Headache"}},
        {"sore throat", {"Flu", "Common Cold", "Strep Throat"}},
        {"shortness of breath", {"COVID-19", "Asthma", "Pneumonia"}},
        {"nausea", {"Food Poisoning", "Gastroenteritis", "Pregnancy"}}
    };

    // Input symptoms from the user
    string symptom;
    vector<string> userSymptoms;
    cout << "Enter your symptoms one by one (type 'done' when finished):" << endl;
    
    while (true) {
        cout << "Symptom: ";
        getline(cin, symptom);
        symptom = toLower(symptom);
        if (symptom == "done") break;
        userSymptoms.push_back(symptom);
    }

    // Set to store potential diseases
    map<string, int> potentialDiseases;

    // Find diseases based on input symptoms
    for (const auto& sym : userSymptoms) {
        if (symptomToDiseases.find(sym) != symptomToDiseases.end()) {
            for (const auto& disease : symptomToDiseases[sym]) {
                potentialDiseases[disease]++;
            }
        }
    }

    // Display potential diseases
    cout << "\nPotential diseases based on your symptoms:" << endl;
    for (const auto& disease : potentialDiseases) {
        cout << "- " << disease.first << " (matches: " << disease.second << ")" << endl;
    }

    return 0;
}
