#include "FunctionDefinition.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "DataPoints.h"
#include "Outliers.h"

std::vector<DataPoints> RetrieveDataPoints(std::string path, double* WholeMean) {
	int number_of_lines = 0;
	std::ifstream fin;
	std::vector<std::string> values;
	std::string line;
	std::vector<DataPoints> datapoints;
	fin.open(path);
	//Edge case: The stock file cannot be open
	if (!fin.is_open()) {
		int pos = path.find("/", 0);
		while (pos != std::string::npos) {
			pos = path.find("/", pos + 1);
			std::cout << "Could not open " << path.substr(pos, path.length() - pos) << " file" << std::endl;
		}
	}

	    //Get each line from the stock file
	    while (getline(fin, line)) {
		values.push_back(line);
	    }
	    fin.close();
		//Generate the starting point to take 30 random datapoints
		int n = values.size();
		srand((unsigned)time(NULL));
		int starting_of_datapoints = (rand() % (n - 29)) + 1;

		int i = 0, k = 30;
		//Now we traverse each line from the stock file
		for (i = 0; i < n; i++) {

			//We process each price value in order to calculate the mean of the whole datapoints from the file and store it in WholeMean 
			std::stringstream ss_mean(values[i]);
			std::vector<std::string> fields_mean;
			while (ss_mean.good()) {
				std::string substr_mean;
				getline(ss_mean, substr_mean, ',');
				fields_mean.push_back(substr_mean);
			}
			*WholeMean += std::stof(fields_mean[2]);
			//From this point we store the datapoints in an array because we have reached the starting point
			//Until we get 30 datapoints
			if (i >= starting_of_datapoints - 1 && k > 0) {


				std::stringstream ss(values[i]);
				std::vector<std::string> fields;


				while (ss.good()) {

					std::string substr;
					getline(ss, substr, ',');
					fields.push_back(substr);
				}
				//We create Datapoints objects and store them in an array
				DataPoints D(fields[0], fields[1], std::stof(fields[2]));
				datapoints.push_back(D);

				k--;

			}
		}
		*WholeMean = *WholeMean / n;
		return datapoints;

	}
std::vector<Outliers> RetrieveOutliers(std::vector<DataPoints>&datapoints, double* WholeMean) {
		

	//Calculate mean and standard deviation of the 30 datapoints generated
	double standard_dev = getDeviation(datapoints);
	double mean = getMean(datapoints);

	std::vector<Outliers> out;
	for (int i = 0; i < datapoints.size(); i++)
		//We check whether the price is greater than the threshold --> that is 2 standard deviations above the mean
		if ((datapoints[i].getPrice() > (2 * standard_dev + mean))) {

			std::string percentage;
			//We calculate the percentage deviation by using the rule of simple 3
			double overdeviation = (100 * datapoints[i].getPrice()) / (2 * standard_dev + mean);
			percentage = std::to_string(overdeviation - 100.0) + "%";

			//We create Outlier objects and store them into and array
			Outliers O(datapoints[i].getName(), datapoints[i].getTimestamp(), datapoints[i].getPrice(), mean, *WholeMean, percentage);
			out.push_back(O);

		}
	return out;
}