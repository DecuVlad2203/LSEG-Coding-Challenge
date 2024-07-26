#include "DataPoints.h"
#include <string>
#include <iostream>
#include <math.h>

DataPoints::DataPoints(std::string parameter_name, std::string parameter_timestamp, double parameter_price){	
	name = parameter_name;
	timestamp = parameter_timestamp;
	price = parameter_price;
}

std::ostream& operator<< (std::ostream& dev, const DataPoints& d) {

	dev << d.name << " " << d.timestamp << " " << d.price << std::endl;
	return dev;
 }
std::string DataPoints::getName(){
	return name;
}
std::string DataPoints::getTimestamp(){
	return timestamp;
}
double DataPoints::getPrice(){
	return price;
}
double getMean(const std::vector<DataPoints> &D) {

	double mean = 0;
	for (int i = 0; i < D.size(); i++)
		mean += D[i].price;
	mean /= D.size();

	return mean;

}

double getDeviation(const std::vector<DataPoints> &D) {


	double mean = getMean(D);

	double curr = 0;
	for (int i = 0; i < D.size(); i++) {
		curr += pow(abs(D[i].price - mean), 2);
	}

	double standard_dev = sqrt((curr / 30));

	return standard_dev;
 }

