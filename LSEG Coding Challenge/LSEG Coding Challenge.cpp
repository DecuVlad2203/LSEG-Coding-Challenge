// LSEG Coding Challenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include"DataPoints.h"
#include"Outliers.h"
#include"FunctionDefinition.h"
namespace fs = std::filesystem;


int main()
{
    // Path to the main directory --> Please replace it with your path where you have saved the StockExchange folder
    std::string MainDirectoryPath
        = "/mnt/c/Users/lucad/source/repos/LSEG Coding Challenge/LSEG Coding Challenge/StockExchange";

    struct stat sb;

    for (const auto& entry : fs::directory_iterator(MainDirectoryPath)) {

        //Get the directory for each stock exchange: LSE,NASDAQ,NYSE ....
        fs::path outfilename = entry.path();
        std::string outfilename_str = outfilename.string();
        const char* path = outfilename_str.c_str();

        fs::path p(path);

        std::cout << "Please insert the number of stock files to be processed for " << p.stem() << " stock exchange: ";

        int number_of_stocks;
        std::cin >> number_of_stocks;

        std::vector<std::string> a;

        for (const auto& entry2 : fs::directory_iterator(path)) {
         
            //Get the stock file in each stock exchange
            fs::path outfilename = entry2.path();
            std::string outfilename_str = outfilename.string();
            const char* stockpath = outfilename_str.c_str();
            if (stat(stockpath, &sb) == 0 && !(sb.st_mode & S_IFDIR))
                a.push_back(std::string(stockpath));
        }
        //Edge case: The input number of stocks to be processed is greater than the actual number of stocks from this stock exchange
        if (a.size() < number_of_stocks) {
            std::cout << p.stem() << " has less files than " << number_of_stocks << std::endl;
            std::cout << "Please proceed with " << a.size() << " files" << std::endl;
        }

        // Edge case: The stock exchange has no stocks to process
        if (a.size() == 0) {
            std::cout << p.stem() << "has no files to process, therefore we will go to the next stock exchange" << std::endl;
            continue;
        }

        //Edge case: The input number of stocks to be processed is lower than the actual number of stocks from this stock exchange
        if (a.size() > number_of_stocks) {
            std::cout << p.stem() << " has more files than " << number_of_stocks << std::endl;
            std::cout << "Therefore we will proceed with the first " << number_of_stocks << " stocks" << std::endl;

        }
        int stock_count = 0;
        //Now we process each stock file
        for (const auto& stock : a) {
            //Edge case: The stock file is empty 
            if (fs::is_empty(stock) == true) {
                fs::path name(stock);
                std::cout << name.stem() << " file is empty, therefore we ignore it" << std::endl;
                continue;
            }
            
            double WholeMean = 0;
            //Call to the first function
            std::vector<DataPoints> DP = RetrieveDataPoints(stock, &WholeMean);
            //Call to the second function
            std::vector<Outliers> O = RetrieveOutliers(DP, &WholeMean);

            //Now we need to write the list of found outlayers into .csv files

            //Edge case: No outliers found
            fs::path name(stock);
            if (O.size() == 0) {
               
                std::cout << "There are no outliers found for " << name.stem()<<"file" << std::endl;
            }
            else {
                //Create corresponding .csv files and put the outliers found
                std::fstream fout;
                std::string outputstock = stock;

                std::string filename = outputstock.substr(0,outputstock.length()-4);
                filename += "-Outliers.csv";
      
                fout.open(filename, std::ios::out | std::ios::app);

                for (int i = 0; i < O.size(); i++) {
                    fout << O[i];
                }
                fout.close();
            }
            ++stock_count;
            if (stock_count == number_of_stocks) {
                break;
            }
           
        }
        



    }


    return 0;
}

