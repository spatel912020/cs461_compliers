#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

string getChildState(string currentState, vector<vector<string>> nfaTable);

int main()
{
    char temp[10];
    char temp2[10];
    string nfaInputsLine;
    char finalState[20];
    int initialState, totalState, numPossibleNFAinputs = 0;
    vector<char> nfaInputs;
    vector<string> intermidiateDFA;
    vector<vector<string>> nfaTable;

    //get initial state by parsing stdin
    scanf("%s %s %d\n", temp, temp2, &initialState);
    strcat(temp, " ");
    strcat(temp, temp2);

    //get final states by parsing stdin
    scanf("%s %s %s\n", temp, temp2, finalState);
    strcat(temp, " ");
    strcat(temp, temp2);

    //get total states by parsing stdin
    scanf("%s %s %d\n", temp, temp2, &totalState);
    strcat(temp, " ");
    strcat(temp, temp2);

    cin >> temp;
    getline(cin, nfaInputsLine);
    for (char &c : nfaInputsLine)
    {
        if (c != ' ')
        {
            nfaInputs.push_back(c);
            numPossibleNFAinputs++;
        }
    }

    //read nfa table from stdin
    nfaTable.resize(totalState);
    for (int i = 0; i < totalState; i++)
    {
        cin >> temp;
        nfaTable[i].resize(numPossibleNFAinputs);
        for (int input = 0; input < numPossibleNFAinputs; input++)
        {
            cin >> temp;
            nfaTable[i][input] = temp;
        }
    }

    cout << "reading NFA ... done." << endl;
    cout << endl;
    cout << "creating corresponding DFA ..." << endl;

    for (int i = 0; i < nfaTable.size(); i++)
    {
        for (int j = 0; j < nfaTable[i].size(); j++)
        {
            if (nfaTable[i][j] != "{}")
            {
                if (j == nfaTable[i].size() - 1)
                {
                    stringstream ss;
                    string temp_to_states;
                    ss << "{" << i + 1 << ",";
                    for (int k = 0; k < nfaTable[i][j].length(); k++)
                    {
                        if (nfaTable[i][j][k] != '{' && nfaTable[i][j][k] != '}')
                        {
                            stringstream current_ss;
                            while (nfaTable[i][j][k] != ',' && nfaTable[i][j][k] != '}')
                            {
                                current_ss << nfaTable[i][j][k];
                                ss << nfaTable[i][j][k];
                                k++;
                            }
                            if (nfaTable[i][j][k] != ('0' + (i + 1)))
                            {
                                string temp3;
                                current_ss >> temp3;
                                //insert in map nextState: childStates;
                                ss << getChildState(temp3, nfaTable);
                            }
                        }
                    }
                    ss << "}";
                    ss >> temp_to_states;
                    cout << temp_to_states << endl;
                }
            }
        }
    }
    return 0;
}

string getChildState(string currentState, vector<vector<string>> nfaTable)
{
    stringstream ss;
    ss << ",";
    string childStates;
    int currentRow = stoi(currentState);
    currentRow -= 1;
    int currentCol = nfaTable[currentRow].size() - 1;
    if (nfaTable[currentRow][currentCol] != "{}")
    {
        for (int k = 0; k < nfaTable[currentRow][currentCol].length(); k++)
        {
            if (nfaTable[currentRow][currentCol][k] != '{' && nfaTable[currentRow][currentCol][k] != '}')
            {
                stringstream current_ss;
                while (nfaTable[currentRow][currentCol][k] != ',' && nfaTable[currentRow][currentCol][k] != '}')
                {
                    //cout << "++++ " << k << endl;
                    //cout << "-----" << nfaTable[currentRow][currentCol][k] << endl;
                    current_ss << nfaTable[currentRow][currentCol][k];
                    k++;
                }
                string temp3;
                current_ss >> temp3;
                cout << temp3 << "-----" << currentState << endl;
                ss << temp3;
                ss << getChildState(temp3, nfaTable);
            }
        }
    }
    else
    {
        return ",";
    }
    ss >> childStates;
    return childStates;
}
