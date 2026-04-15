//
// Created by kmurphy on 4/15/2026.
//

#include "SalesAnalyzer.h"
#include <stdexcept>
#include <iomanip>

SalesAnalyzer::SalesAnalyzer() {
    numberOfDays = 0;
}

void SalesAnalyzer::addDailySale(int sale) {
    if (numberOfDays >= MAX_SIZE) {
        throw std::out_of_range("Maximum number of days reached");
    }
    sales[numberOfDays] = sale;
    numberOfDays++;
}

int SalesAnalyzer::getNumberOfDays() const {
    return numberOfDays;
}

// Category helper
std::string SalesAnalyzer::getCategory(int sale) const {
    if (sale > 1500) return "Excellent";      // Excellent
    else if (sale >= 1000) return "Good";// Good
    else return "Poor";                  // Poor
}

// Count functions
int SalesAnalyzer::countExcellentDays() const {
    int count = 0;
    for (int i = 0; i < numberOfDays; i++) {
        if (sales[i] > 1500) count++;
    }
    return count;
}

int SalesAnalyzer::countGoodDays() const {
    int count = 0;
    for (int i = 0; i < numberOfDays; i++) {
        if (sales[i] >= 1000 && sales[i] <= 1500) count++;
    }
    return count;
}

int SalesAnalyzer::countPoorDays() const {
    int count = 0;
    for (int i = 0; i < numberOfDays; i++) {
        if (sales[i] < 1000) count++;
    }
    return count;
}

int SalesAnalyzer::countIncreasingDays() const {
    int count = 0;
    for (int i = 1; i < numberOfDays; i++) {
        if (sales[i] > sales[i - 1]) {
            count++;
        }
    }
    return count;
}

double SalesAnalyzer::getAverageSales() const {
    if (numberOfDays == 0) return 0;

    int sum = 0;
    for (int i = 0; i < numberOfDays; i++) {
        sum += sales[i];
    }
    return (double)sum / numberOfDays;
}

void SalesAnalyzer::displayReport(std::ostream &out) const {
    out << "===== Sales Performance Report =====\n\n";

    out << std::setw(6) << "Day"
        << std::setw(10) << "Sales"
        << std::setw(12) << "Category\n";
    out << "-----------------------------------\n";

    for (int i = 0; i < numberOfDays; i++) {
        std::string label = getCategory(sales[i]);

        out << std::setw(6) << i + 1
            << std::setw(10) << sales[i]
            << std::setw(12) << label << "\n";
    }

    out << "\nSummary\n";
    out << "-----------------------------------\n";
    out << "Excellent Days  : " << countExcellentDays() << "\n";
    out << "Good Days       : " << countGoodDays() << "\n";
    out << "Poor Days       : " << countPoorDays() << "\n";
    out << "Increasing Days : " << countIncreasingDays() << "\n";
    out << "Average Sales   : " << getAverageSales() << "\n";
}

std::ostream& operator<<(std::ostream &out, const SalesAnalyzer &st) {
    st.displayReport(out);
    return out;
}