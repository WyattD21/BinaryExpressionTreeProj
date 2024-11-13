#include "binaryExpressionTree.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std; 

int main() {
    binaryExpressionTree expressionTree;
    ifstream inFile("RpnData.txt");
    ofstream outFile("Output.txt");

    if (!inFile) {
        cerr << "Error: Could not open RpnData.txt\n";
        return 1;
    }
    if (!outFile) {
        cerr << "Error: Could not create Output.txt\n";
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        expressionTree.buildExpressionTree(line); 
        double result = expressionTree.evaluateExpressionTree(); 
        outFile << "Expression: " << line << " = " << result << "\n";
    }

    inFile.close();
    outFile.close();
    cout << "Evaluation complete. Results saved to Output.txt.\n";
    return 0;
}
