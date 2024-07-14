#pragma once
#include<iostream>
#include "DataPoints.h"
#include <vector>
#include <string>
#include "Outliers.h"

//Definition of first function
std::vector<DataPoints> RetrieveDataPoints(std::string path, double* WholeMean);

//Definition of second function
std::vector<Outliers> RetrieveOutliers(std::vector<DataPoints>& datapoints, double* WholeMean);