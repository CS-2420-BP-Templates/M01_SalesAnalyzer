# Sales Analyzer
## Description
In this lab, you will build a C++ program that reads daily store sales from a file, stores the data in a class, and generates a summary report.

Create a program
- You will read the sales data from a file
- Store the data in a class
- Analyze the data
- Display formatted data

## Required Class
Create a class called SalesAnalyzer with the following methods

### `void addDailySale(int score);`
Adds the sales for the day to the Analyzer 

### `int getNumberOfDays()const;`

Returns the total number of days of sales

### Categorize Each Day
```
int countExcellentDays() const;
int countGoodDays() const;
int countPoorDays() const;
```

Returns a count of the respective number of days given the following criteria:
```angular2html
Excellent: > 1500
Good: 1000–1500
Poor: < 1000
```
### `int countIncreasingDays() const;`
This function counts every time the sales are higher than that of the previous day.


### `double getAverageSales() const;`
Returns the average number of sales for given amount of days.

###`std::string getCategory(int sale) const;`
This function will return the Excellent, Good, Poor based upon the sale of that day.
```angular2html
Excellent: > 1500
Good: 1000–1500
Poor: < 1000
```

### `void displayReport(std::ostream &)const;`
The function will output the information of the class to the stream

### `friend std::ostream& operator<<(std::ostream &, const SalesAnalyzer & gt);`
The ostream operator will call displayReport function to display the information of the class.

## Write the Main method
Write a program that instantiates a SalesAnalyzer object. Open the Sales.txt file and read the first value, which represents the number of sales entries in the file.

Using this value, read in each sales amount and add it to your SalesAnalyzer object. Once all data has been processed, display the results by printing the SalesAnalyzer object.
## Sample Output
```angular2html
===== Sales Performance Report =====

Day     Sales     Category
-----------------------------
1       1200      Good
2       950       Poor
3       1430      Good
4       800       Poor
5       1600      Excellent
...

Summary
-----------------------------
Excellent Days   : 1
Good Days        : 3
Poor Days        : 3
Increasing Days  : 2
Average Sales    : 1152.86
```