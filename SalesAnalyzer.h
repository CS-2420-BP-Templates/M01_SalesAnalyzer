//
// Created by kmurphy on 4/15/2026.
//

#ifndef INC_01_SALESANALYZER_SALESANALYZER_H
#define INC_01_SALESANALYZER_SALESANALYZER_H
#include <iostream>

class SalesAnalyzer {
public:
        //Constructor
        SalesAnalyzer();
        //Functions
        void addDailySale(int score);
        //Getters
        int getNumberOfDays()const;
        int countExcellentDays() const;
        int countGoodDays() const;
        int countPoorDays() const;
        int countIncreasingDays() const;

        double getAverageSales() const;
        std::string  getCategory(int sale) const;
        void displayReport(std::ostream &)const;
        friend std::ostream& operator<<(std::ostream &, const SalesAnalyzer & gt);
    public:
        static const int MAX_SIZE = 100;
        int sales[MAX_SIZE];
        int numberOfDays;
};


#endif //INC_01_SALESANALYZER_SALESANALYZER_H
