#include "Outliers.h"
#include<iostream>
#pragma once
#include<string>
#include<vector>


Outliers::Outliers(std::string a, std::string b, double c, double d, double e, std::string f):DataPoints(a,b,c){
    OutlierMean = d;
    ActualMean = e;
    AboveDeviationPercentage = f;
}

std::ostream& operator<<(std::ostream& dev, const Outliers& O){
    dev << O.name << "," << O.timestamp << "," << O.price<< "," << O.OutlierMean << "," << O.ActualMean << "," << O.AboveDeviationPercentage << std::endl;

    return dev;
}
