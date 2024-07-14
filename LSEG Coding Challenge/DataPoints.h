#pragma once
#include<string>
#include<iostream>
#include<ostream>
#include<vector>
class DataPoints
{
protected:
	std::string name;
	std::string timestamp;
	double price;

public:
	DataPoints(std::string parameter_name, std::string parameter_timestamp, double parameter_price);
	friend std::ostream& operator<< (std::ostream&, const DataPoints&);
	std::string getName();
	std::string getTimestamp();
	double getPrice();
	friend double getMean(const std::vector<DataPoints>&);//calculates the mean of the 30 datapoints generated
	friend double getDeviation(const std::vector<DataPoints>&);//calculates the standard deviation of 30 datapoints generated

};

