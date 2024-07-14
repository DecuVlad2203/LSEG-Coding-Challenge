#pragma once
#include "DataPoints.h"
#include<iostream>
#include<string>
#include<vector>

class Outliers: public DataPoints {
private:
	double OutlierMean;
	double ActualMean;
	std::string AboveDeviationPercentage;
public:
	Outliers(std::string,std::string,double,double,double, std::string);
	friend std::ostream& operator<<(std::ostream& dev, const Outliers&);
};

