#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

string getChildState(string currentState, vector<vector<string>> nfaTable, map<string, string> &dfaLookupTable, set<string> &visitedState);
void cleanIntermediateDFA(vector<string> &intermidiateDFA, set<string> &finalDFAstates, set<string> &nfaFinalStates);

int main()
{
    char temp[10];
    char temp2[10];
    string nfaInputsLine;
    char tempfinalState[20];
    string finalState;
    int initialState, totalState, numPossibleNFAinputs = 0;
    vector<char> nfaInputs;
    vector<string> intermidiateDFA;
    vector<vector<string>> nfaTable;
    set<string> visitedStates;
    set<string> finalDFAstates;
    set<string>::iterator finalDFAstatesIterator;
    set<string> nfaFinalStates;
    set<string>::iterator visitedStatesIterator;
    map<string, string> dfaLookupTable;
    map<string, string>::iterator dfaLookupTableIterator;

    //get initial state by parsing stdin
    scanf("%s %s %d\n", temp, temp2, &initialState);
    strcat(temp, " ");
    strcat(temp, temp2);

    //get final states by parsing stdin
    scanf("%s %s %s\n", temp, temp2, tempfinalState);
    strcat(temp, " ");
    strcat(temp, temp2);
    finalState = string(tempfinalState);
    for (int i = 0; i < finalState.length(); i++)
    {
        string temp3;
        if (finalState[i] != '{' && finalState[i] != '}')
        {
            stringstream current_ss;
            while (finalState[i] != ',' && finalState[i] != '}')
            {
                current_ss << finalState[i];
                i++;
            }
            current_ss >> temp3;
            nfaFinalStates.insert(temp3);
        }
    }

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
                stringstream ss;
                string temp_to_states;
                ss << "{";
                //cout << i + 1 << endl;
                dfaLookupTableIterator = dfaLookupTable.find(to_string(i + 1));
                if (j == nfaTable[i].size() - 1 && dfaLookupTableIterator == dfaLookupTable.end())
                {
                    ss << i + 1 << ",";
                    visitedStates.insert(to_string(i + 1));
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
                                dfaLookupTableIterator = dfaLookupTable.find(temp3);
                                if (dfaLookupTableIterator != dfaLookupTable.end())
                                {
                                    ss << dfaLookupTable.find(temp3)->second;
                                    if (k + 1 < nfaTable[i][j].length())
                                    {
                                        ss << ",";
                                    }
                                }
                                else
                                {
                                    string tempchildStates = getChildState(temp3, nfaTable, dfaLookupTable, visitedStates);
                                    ss << tempchildStates;
                                    if (k + 1 < nfaTable[i][j].length())
                                    {
                                        ss << ",";
                                    }
                                    dfaLookupTable.insert(pair<string, string>(temp3, tempchildStates));
                                }
                            }
                        }
                    }
                }
                else if (j != nfaTable[i].size() - 1)
                {
                    for (int k = 0; k < nfaTable[i][j].length(); k++)
                    {
                        if (nfaTable[i][j][k] != '{' && nfaTable[i][j][k] != '}')
                        {
                            stringstream current_ss;
                            while (nfaTable[i][j][k] != ',' && nfaTable[i][j][k] != '}')
                            {
                                current_ss << nfaTable[i][j][k];
                                k++;
                            }
                            string temp3;
                            current_ss >> temp3;
                            dfaLookupTableIterator = dfaLookupTable.find(temp3);
                            if (dfaLookupTableIterator != dfaLookupTable.end())
                            {
                                ss << dfaLookupTable.find(temp3)->first;
                                ss << dfaLookupTable.find(temp3)->second;
                                if (k + 1 < nfaTable[i][j].length())
                                {
                                    ss << ",";
                                }
                                string tempchildStates = getChildState(temp3, nfaTable, dfaLookupTable, visitedStates);
                                ss << tempchildStates;
                                if (k + 1 < nfaTable[i][j].length())
                                {
                                    ss << ",";
                                }
                                dfaLookupTable.insert(pair<string, string>(temp3, tempchildStates));
                            }
                            else
                            {
                                ss << temp3;
                                string tempchildStates = getChildState(temp3, nfaTable, dfaLookupTable, visitedStates);
                                ss << tempchildStates;
                                if (k + 1 < nfaTable[i][j].length())
                                {
                                    ss << ",";
                                }
                                dfaLookupTable.insert(pair<string, string>(temp3, tempchildStates));
                            }
                        }
                    }
                }
                ss << "}";
                ss >> temp_to_states;
                visitedStates.clear();
                //cout << temp_to_states << "-----------------------" << i + 1 << endl;
                if (temp_to_states != "{}")
                {
                    intermidiateDFA.push_back(temp_to_states);
                    //cout << "new DFA state: "<< "\t" << intermidiateDFA.size() << "    -->    " << temp_to_states << endl;
                }
            }
            else if (nfaTable[i][j] == "{}" && i == 0 && j == nfaTable[i].size() - 1)
            {
                intermidiateDFA.push_back("{1}");
            }
        }
    }
    cleanIntermediateDFA(intermidiateDFA, finalDFAstates, nfaFinalStates);
    for (int i = 0; i < intermidiateDFA.size(); i++)
    {
        cout << "new DFA state:  " << i + 1 << "    -->  " << intermidiateDFA[i] << endl;
    }
    cout << "done." << endl;
    cout << endl;
    cout << "final DFA:" << endl;
    cout << "Initial State:  " << initialState << endl;
    cout << "Final States:  {";
    for (finalDFAstatesIterator = finalDFAstates.begin(); finalDFAstatesIterator != finalDFAstates.end(); finalDFAstatesIterator++)
    {
        if (finalDFAstatesIterator != finalDFAstates.begin())
        {
            cout << ",";
        }
        cout << *finalDFAstatesIterator;
    }
    cout << "}" << endl;
    cout << "Total State:  " << intermidiateDFA.size() << endl;
    /*for (dfaLookupTableIterator = dfaLookupTable.begin(); dfaLookupTableIterator != dfaLookupTable.end(); dfaLookupTableIterator++)
    {
        cout << dfaLookupTableIterator->first << " ====== " << dfaLookupTableIterator->second << endl;
    }
    */

    return 0;
}

string getChildState(string currentState, vector<vector<string>> nfaTable, map<string, string> &dfaLookupTable, set<string> &visitedStates)
{
    stringstream ss;
    string childStates;
    map<string, string>::iterator dfaLookupTableIterator;
    set<string>::iterator visitedStatesIterator;
    int currentRow = stoi(currentState);
    currentRow -= 1;
    int currentCol = nfaTable[currentRow].size() - 1;
    dfaLookupTableIterator = dfaLookupTable.find(currentState);
    visitedStatesIterator = visitedStates.find(currentState);
    if (nfaTable[currentRow][currentCol] != "{}" && dfaLookupTableIterator == dfaLookupTable.end() && visitedStatesIterator == visitedStates.end())
    {
        ss << ",";
        visitedStates.insert(currentState);
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
                //cout << temp3 << "-----" << currentState << endl;
                ss << temp3;
                dfaLookupTableIterator = dfaLookupTable.find(temp3);
                if (dfaLookupTableIterator != dfaLookupTable.end())
                {
                    //cout << "true";
                    ss << dfaLookupTable.find(temp3)->second;
                    if (k + 1 < nfaTable[currentRow][currentCol].length())
                    {
                        ss << ",";
                    }
                }
                else
                {
                    //insert in map nextState: childStates;
                    //cout << "inserting " << temp3 << " into map with " << getChildState(temp3, nfaTable, dfaLookupTable, visitedStates) << endl;
                    //cout << "false" << endl;
                    string tempchildStates = getChildState(temp3, nfaTable, dfaLookupTable, visitedStates);
                    ss << tempchildStates;
                    if (k + 1 < nfaTable[currentRow][currentCol].length())
                    {
                        ss << ",";
                    }
                    dfaLookupTable.insert(pair<string, string>(temp3, tempchildStates));
                }
            }
        }
    }
    else
    {
        return "";
    }
    ss >> childStates;
    return childStates;
}

void cleanIntermediateDFA(vector<string> &intermidiateDFA, set<string> &finalDFAstates, set<string> &nfaFinalStates)
{
    set<int> temp_set;
    set<int>::iterator temp_set_iterator;
    set<string> newIntermediateDFA;
    set<string> newIntermediateDFAfinalState;
    set<string>::iterator newIntermediateDFAIterator;
    string tempString;
    for (int i = 0; i < intermidiateDFA.size(); i++)
    {
        for (int j = 0; j < intermidiateDFA[i].length(); j++)
        {
            //cout << "------------" << intermidiateDFA[i] << endl;
            if (intermidiateDFA[i][j] != '{' && intermidiateDFA[i][j] != '}')
            {
                stringstream current_state;
                string state_string;
                while (intermidiateDFA[i][j] != ',' && intermidiateDFA[i][j] != '}')
                {
                    current_state << intermidiateDFA[i][j];
                    j++;
                }
                current_state >> state_string;
                //cout << state_string.length() << endl;
                if (state_string != "," && state_string.length() != 0)
                {
                    //cout << state_string << endl;
                    temp_set.insert(stoi(state_string));
                }
            }
        }
        stringstream ss;
        bool containFinalState = false;
        for (temp_set_iterator = temp_set.begin(); temp_set_iterator != temp_set.end(); temp_set_iterator++)
        {
            if (temp_set_iterator != temp_set.begin())
            {
                ss << ",";
            }
            if (nfaFinalStates.find(to_string(*temp_set_iterator)) != nfaFinalStates.end())
            {
                containFinalState = true;
            }
            ss << *temp_set_iterator;
        }
        ss >> tempString;
        if (!containFinalState)
        {
            newIntermediateDFA.insert(tempString);
        }
        else
        {
            newIntermediateDFAfinalState.insert(tempString);
        }
        temp_set.clear();
    }
    intermidiateDFA.clear();
    stringstream finalIntermediateDFA;
    for (newIntermediateDFAIterator = newIntermediateDFA.begin(); newIntermediateDFAIterator != newIntermediateDFA.end(); newIntermediateDFAIterator++)
    {
        string temp;
        finalIntermediateDFA << "{" << *newIntermediateDFAIterator << "}";
        finalIntermediateDFA >> temp;
        intermidiateDFA.push_back(temp);
        finalIntermediateDFA.clear();
    }

    for (newIntermediateDFAIterator = newIntermediateDFAfinalState.begin(); newIntermediateDFAIterator != newIntermediateDFAfinalState.end(); newIntermediateDFAIterator++)
    {
        string temp;
        finalIntermediateDFA << "{" << *newIntermediateDFAIterator << "}";
        finalIntermediateDFA >> temp;
        intermidiateDFA.push_back(temp);
        finalDFAstates.insert(to_string(intermidiateDFA.size()));
        finalIntermediateDFA.clear();
    }
}