#include <iostream>
#include <fstream>
#include "SalesAnalyzer.h"

using namespace std;
int main() {
    std::cout << "Sales Performance Analyzer" << std::endl;
    SalesAnalyzer analyzer;
    string filename = "../Sales.txt";
    ifstream in(filename);
    if(!in){
        cout << "Error Opening File" << endl;
        return 1;
    }
    int numDays;
    in >> numDays;

    int sale;
    for(int i = 0; i < numDays; i++){
        in >> sale;
        analyzer.addDailySale(sale);
    }
    cout << analyzer;
    return 0;
}
