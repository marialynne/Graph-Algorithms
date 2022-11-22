#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <sstream>

using namespace std;

bool regexNumber(string numb)
{ // Time: O(1)
    const regex expReg("^[1-9]|10$");
    return regex_match(numb, expReg);
}

bool regexHat(string numb)
{ // Time: O(1)
    const regex expReg("^([1-9]|[1-9][0-9]|100)$");
    return regex_match(numb, expReg);
}

bool validHatChoice(vector<int> currentComb, int currentHat)
{
    for (auto hat : currentComb)
    {
        if (hat == currentHat)
            return false;
    }
    return true;
}

void findHatCombinations(int currentPerson, vector<vector<int>> hatsPerPerson, vector<bool> assignedHats, vector<int> currentCombination, vector<vector<int>> &hatsCombination)
{
    if (all_of(assignedHats.begin(), assignedHats.end(), [](int i)
               { return i == 1; }))
    {
        hatsCombination.push_back(currentCombination);
        return;
    }

    for (int person = currentPerson; person < hatsPerPerson.size(); person++)
    {
        if (!assignedHats[person])
        { // bitmask to determine if hat has been assigned
            for (int hat = 0; hat < hatsPerPerson[person].size(); hat++)
            {
                int currentHat = hatsPerPerson[person][hat];
                if (validHatChoice(currentCombination, currentHat))
                {
                    currentCombination.push_back(hatsPerPerson[person][hat]);
                    assignedHats[person] = true;

                    findHatCombinations(currentPerson + 1, hatsPerPerson, assignedHats, currentCombination, hatsCombination);

                    currentCombination.pop_back();
                    assignedHats[person] = false;
                }
            }
        }
    }
};

int main()
{
    /*
    Existen 100 diferentes tipos de gorras y cada una tiene un ID de 1 a 100.
    Ademas, hay 'n' personas cada una tiene una colección variable de gorras.
    Cierta fecha todas esas personas deciden ir a una fiesta usando una gorra,
    pero para verse de manera única han decidido que ninguno de ellos usará el mismo tipo de gorra.
    Se les ha encomendado encontrar el numero total de arreglos o forma diferentes que ninguno de
    ellos lleve el mismo tipo de gorra. Tomando en cuenta la restricción que 1 <= 'n' <= 10. */
    string inputNumberPersons;
    vector<vector<int>> hatsPerPerson;
    vector<bool> assignedHats;
    vector<vector<int>> hatsCombination;
    vector<int> currentCombination;

    cout << "Input number of people: \n";
    cin >> inputNumberPersons;

    if (!regexNumber(inputNumberPersons))
    {
        cout << "Invalid number \n";
        exit(0);
    }

    cin.ignore();
    for (int person = 0; person < stoi(inputNumberPersons); person++)
    {
        string inputHat;
        vector<int> hatsList;
        cout << "Input hats for person " << person + 1 << "\n";
        getline(cin, inputHat);

        stringstream ss(inputHat);
        for (string i; ss >> i;)
        {
            if (regexHat(i))
            {
                hatsList.push_back(stoi(i));
            }
            else
            {
                cout << "Data not valid (Hat values are from 1 to 100)\n";
                exit(0);
            }
        }

        hatsPerPerson.push_back(hatsList);
        assignedHats.push_back(0);
    }

    findHatCombinations(0, hatsPerPerson, assignedHats, currentCombination, hatsCombination);

    if (hatsCombination.empty())
    {
        cout << "No solution found \n";
        exit(0);
    }

    cout << "--- Solutions found --- \n";
    for (int person = 0; person < hatsCombination.size(); person++)
    {
        for (int hat = 0; hat < hatsCombination[person].size(); hat++)
        {
            cout << hatsCombination[person][hat] << " ";
        }
        cout << "\n";
    }
};