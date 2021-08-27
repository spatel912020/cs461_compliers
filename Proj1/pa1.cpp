#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    char temp[10];
    char temp2[10];
    string nfaInputsLine;
    char finalState[20];
    int initialState, totalState, numPossibleNFAinputs = 0;
    vector<char> nfaInputs;
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
    return 0;
}
