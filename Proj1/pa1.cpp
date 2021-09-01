#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm> // std::includes, std::sort
#include <set>

using namespace std;

string getChildState(string currentState, vector<vector<string>> nfaTable, set<string> &visitedState, set<string> &accounted_episolen_transition);
void cleanIntermediateDFA(vector<string> &intermidiateDFA, set<string> &finalDFAstates, set<string> &nfaFinalStates);
string getDFATranslation(vector<vector<string>> nfaTable, vector<string> intermidiateDFA, int translation, string DFAstate);

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
    set<string> accounted_episolen_transition;
    set<string>::iterator accounted_episolen_transition_iterator;
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

    //loop through each state transition in NFA table to create new DFA state
    for (int i = 0; i < nfaTable.size(); i++)
    {
        for (int j = 0; j < nfaTable[i].size(); j++)
        {
            //if state transition not empty
            if (nfaTable[i][j] != "{}")
            {
                stringstream ss;
                string temp_to_states;
                ss << "{";
                //cout << i + 1 << endl;
                //check if episolen transition accounted for in parent state
                accounted_episolen_transition_iterator = accounted_episolen_transition.find(to_string(i + 1));

                if (j == nfaTable[i].size() - 1 && accounted_episolen_transition_iterator == accounted_episolen_transition.end())
                {
                    accounted_episolen_transition.insert(to_string(i + 1));
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

                                string tempchildStates = getChildState(temp3, nfaTable, visitedStates, accounted_episolen_transition);
                                ss << tempchildStates;
                                if (k + 1 < nfaTable[i][j].length())
                                {
                                    ss << ",";
                                }
                            }
                        }
                    }
                }
                //if the state transition is not an episolen transition
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
                            accounted_episolen_transition.insert(temp3);
                            ss << temp3;
                            string tempchildStates = getChildState(temp3, nfaTable, visitedStates, accounted_episolen_transition);
                            ss << tempchildStates;
                            if (k + 1 < nfaTable[i][j].length())
                            {
                                ss << ",";
                            }
                        }
                    }
                }
                ss << "}";
                //add new state string to new DFA state vector
                ss >> temp_to_states;
                visitedStates.clear();
                if (temp_to_states != "{}")
                {
                    intermidiateDFA.push_back(temp_to_states);
                }
            }
            //special case where start state's episolen transition is pointing to itself if no episolen transition given
            else if (nfaTable[i][j] == "{}" && i == 0 && j == nfaTable[i].size() - 1)
            {
                intermidiateDFA.push_back("{1}");
            }
        }
    }
    //clean DFA state vector -- remove repeating entries, order states in incrementing order
    cleanIntermediateDFA(intermidiateDFA, finalDFAstates, nfaFinalStates);
    //print DFA info
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
    cout << "State\t";
    for (int i = 0; i < nfaInputs.size() - 1; i++)
    {
        cout << nfaInputs[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < intermidiateDFA.size(); i++)
    {
        cout << i + 1 << "\t";
        for (int j = 0; j < nfaInputs.size() - 1; j++)
        {
            //get the new DFA transition for a given input
            cout << getDFATranslation(nfaTable, intermidiateDFA, j, intermidiateDFA[i]) << "\t";
        }
        cout << endl;
    }
    return 0;
}

string getChildState(string currentState, vector<vector<string>> nfaTable, set<string> &visitedStates, set<string> &accounted_episolen_transition)
{
    stringstream ss;
    string childStates;
    set<string>::iterator visitedStatesIterator;
    int currentRow = stoi(currentState);
    currentRow -= 1;
    int currentCol = nfaTable[currentRow].size() - 1;
    visitedStatesIterator = visitedStates.find(currentState);
    //check if state has already been visited, or empty -- prevents an infinite recursion loop
    if (nfaTable[currentRow][currentCol] != "{}" && visitedStatesIterator == visitedStates.end())
    {
        ss << ",";
        visitedStates.insert(currentState);
        for (int k = 0; k < nfaTable[currentRow][currentCol].length(); k++)
        {
            //get episolen transition for all of the child state.
            if (nfaTable[currentRow][currentCol][k] != '{' && nfaTable[currentRow][currentCol][k] != '}')
            {
                stringstream current_ss;
                while (nfaTable[currentRow][currentCol][k] != ',' && nfaTable[currentRow][currentCol][k] != '}')
                {
                    current_ss << nfaTable[currentRow][currentCol][k];
                    k++;
                }
                string temp3;
                current_ss >> temp3;
                accounted_episolen_transition.insert(temp3);
                ss << temp3;
                //get episolen transition of the current states' child states
                string tempchildStates = getChildState(temp3, nfaTable, visitedStates, accounted_episolen_transition);
                ss << tempchildStates;
                if (k + 1 < nfaTable[currentRow][currentCol].length())
                {
                    ss << ",";
                }
            }
        }
    }
    else
    {
        accounted_episolen_transition.insert(currentState);
        return "";
    }
    ss >> childStates;
    return childStates;
}

void cleanIntermediateDFA(vector<string> &intermidiateDFA, set<string> &finalDFAstates, set<string> &nfaFinalStates)
{
    //This function is to clear DFA vector -- removes repeating states, and re-orders the states in increamenting order.
    ///Helps match output.
    set<int> temp_set;
    set<int>::iterator temp_set_iterator;
    set<string> newIntermediateDFA;
    vector<set<int>> all_sets;
    vector<set<int>>::iterator all_sets_iterator;
    set<string> newIntermediateDFAfinalState;
    set<string>::iterator newIntermediateDFAIterator;
    string tempString;
    for (int i = 0; i < intermidiateDFA.size(); i++)
    {
        for (int j = 0; j < intermidiateDFA[i].length(); j++)
        {
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
                    temp_set.insert(stoi(state_string));
                }
            }
        }
        //check if new DFA state contains the final state. if yes, add to vector containing new DFA final states
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
            //	cout<<"reg == "<<tempString<<endl;
            newIntermediateDFA.insert(tempString);
        }
        else
        {
            //	cout<<"final == "<<tempString<<endl;
            newIntermediateDFAfinalState.insert(tempString);
        }
        //cout<<"rejected == "<<tempString<<endl;
        all_sets.push_back(temp_set);
        temp_set.clear();
    }
    //delete old DFA vector and add cleaned DFA vector;
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

string getDFATranslation(vector<vector<string>> nfaTable, vector<string> intermidiateDFA, int translation, string DFAstate)
{

    string DFAStateTransition;
    string ret_string = "{";
    vector<int> NFA_states_to_check;

    //Add NFA states to check for transition
    for (int i = 0; i < DFAstate.length(); i++)
    {
        if (DFAstate[i] != '{' && DFAstate[i] != '}')
        {
            stringstream current_state;
            string state_string;
            int row;
            while (DFAstate[i] != ',' && DFAstate[i] != '}')
            {
                current_state << DFAstate[i];
                i++;
            }
            current_state >> state_string;
            row = stoi(state_string);
            row -= 1;
            NFA_states_to_check.push_back(row);
        }
    }
    //Check each NFA state and find corresponding DFA state if input transition exists
    for (int i = 0; i < NFA_states_to_check.size(); i++)
    {
        if (nfaTable[NFA_states_to_check[i]][translation] != "{}")
        {
            string searchStates = nfaTable[NFA_states_to_check[i]][translation];
            vector<string> searchStatesVector;
            bool stateContained = false;
            for (int j = 0; j < searchStates.length(); j++)
            {
                if (searchStates[j] != '{' && searchStates[j] != '}')
                {
                    stringstream current_state;
                    string state_string;
                    while (searchStates[j] != ',' && searchStates[j] != '}')
                    {
                        current_state << searchStates[j];
                        j++;
                    }
                    current_state >> state_string;
                    searchStatesVector.push_back(state_string);
                }
            }
            for (int k = 0; k < intermidiateDFA.size(); k++)
            {
                if (intermidiateDFA[k].find(searchStatesVector[0]) != -1)
                {
                    ret_string = "{" + to_string(k + 1);
                    k = intermidiateDFA.size();
                }
            }
            searchStates.clear();
        }
    }
    ret_string += "}";
    return ret_string;
}
