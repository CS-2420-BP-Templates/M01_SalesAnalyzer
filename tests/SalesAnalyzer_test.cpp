

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SalesAnalyzer.h"

// Helper function to populate tracker
SalesAnalyzer createTracker(std::initializer_list<int> values) {
    SalesAnalyzer st;
    for (int v : values) {
        st.addDailySale(v);
    }
    return st;
}

TEST_CASE("Add and count days", "[basic]") {
SalesAnalyzer st;
st.addDailySale(1000);
st.addDailySale(1200);

REQUIRE(st.getNumberOfDays() == 2);
}

TEST_CASE("Category classification", "[category]") {
SalesAnalyzer st;

REQUIRE(st.getCategory(1600) == "Excellent");
REQUIRE(st.getCategory(1200) == "Good");
REQUIRE(st.getCategory(900)  == "Poor");
}

TEST_CASE("Count Excellent Days", "[count]") {
auto st = createTracker({1600, 1700, 1400, 800});
REQUIRE(st.countExcellentDays() == 2);
}

TEST_CASE("Count Good Days", "[count]") {
auto st = createTracker({1000, 1200, 1500, 1600});
REQUIRE(st.countGoodDays() == 3);
}

TEST_CASE("Count Poor Days", "[count]") {
auto st = createTracker({500, 800, 1200});
REQUIRE(st.countPoorDays() == 2);
}

TEST_CASE("Count Increasing Days", "[pattern]") {
auto st = createTracker({1000, 1200, 1100, 1300, 1300});

// 1000->1200 (yes)
// 1200->1100 (no)
// 1100->1300 (yes)
// 1300->1300 (no)

REQUIRE(st.countIncreasingDays() == 2);
}

TEST_CASE("Average Sales", "[math]") {
auto st = createTracker({1000, 2000, 3000});
REQUIRE(st.getAverageSales() == Approx(2000.0));
}

TEST_CASE("Empty Tracker Average", "[edge]") {
SalesAnalyzer st;
REQUIRE(st.getAverageSales() == 0);
}

TEST_CASE("Boundary values for categories", "[edge]") {
    SalesAnalyzer st;

REQUIRE(st.getCategory(1500) == "Good");
REQUIRE(st.getCategory(1000) == "Good");
REQUIRE(st.getCategory(999)  == "Poor");
}