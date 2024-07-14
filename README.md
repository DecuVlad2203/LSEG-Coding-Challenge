# LSEG Coding Challenge

**Brief summary on how to set up the project:**

After you imported the project, in the LSEGCodingChallenge.cpp file, in the main() function, line 20, just change the path in order to correspond with your actual path where you have
saved the StockExchange folder from the .zip file.

Then run the program and check the outputs, and check in the corresponding folders for each stock exchange the output files that have been created.

**Brief summary on how the project works:**

There are 7 files in this project:

Headers:     DataPoints.h (1)
             Outliers.h (2)
             FunctionImplementation.h (3)



SourceFiles: DataPoints.cpp(4)
             Outliers.cpp(5)
             FunctionImplementation.cpp(6)
              LSEGCodingChallenge.cpp(7)

(1) --> This file contains the definition of the DataPoints class which has 3 attributes: name, timestamp and price; corresponding to the format given in the input file

(2) --> This file contatins the definition of Outliers class which is derived from DataPoints class and has 3 extra attributes: mean of the 30 datapoints, actual mean and % over deviation 
corresponding to the format given on how the output file should be.

(3) --> This file contatins the definition of the 2 functions specified in the requirments of the project:
        1st function: RetrieveDataPoints ---> Based on the given path file to the input .csv file, 30 datapoints are taken starting from a random line in the file, then those datapoints are
        saved in an array and returned. On top of that the mean of all the datapoints from the files is calculated in the second parameter so we can build the outliers based on that.
        2nd function: RetrieveOutliers ---> Based on the array returned from the 1st function, the mean of the 30 datapoints, the standard deviation and the actual mean are calculated,
        then those outliers are saved in an array and returned to the main function.


(4),(5),(6) ---> These files contain the implementation of the things defined at (1),(2),(3)


(7) ---> In this file, we have the main function. After we take the input folder where all stock exchanges are, we open each subfolder from it, and from each subfolder we process each .csv file.
         There are a few edge cases treated described by comment //Edge case: ..... such as empty files, no files, unable to open the file, no outliers found and so on.
         After that the 2 functions are called for every .csv file and if we have found outliers, the output .csv files will be created in the same location with the name: "StockName-Outliers.csv".

Observations!!!

It is possible that we won't get any outliers when we run the program. In this case we need to run again the program until there are some output files generated. That is because the starting point from where   the 30 datapoints are retrieved in the first function needs to have another value.

For finding out the standard deviation the following formula has been used, and the result is the standard deviation: 

                   /-----------------------------------------------
                  /  __N___
                 /   \
                /    /____   (M - VALi)^2
          \    /      i=0      
           \  /    ------------------------------------------------
            \/              N

where: N- total number of datapoints 
       M - mean of the 30 datapoints    
       VALi - datapoint value at index i

References: --> For this project, I have used some pieces of code for proccessing strings or files from: Geeksforgeeks.com, stackoverflow.com



         
         
         
