#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
	string inputFile = "data.txt";
	size_t n;
	double S;
	double *w = nullptr;
	double *r = nullptr;
	double V;
	double rate;
	
	if(!ImportVectors(inputFile, n, S, w, r)) 
	{
		cerr<< "Something goes wrong with import"<< endl;
		return 1;
	}

	if(!Value(n, S, w, r, rate, V))
	{
		cerr<< "Something went wrong computing the rate of return and the final value";
		return 1;
	}

	string outputFileName = "./result.txt";
	if (!ExportResult(outputFileName, n, S, w, r, rate, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return 1;
    }
	
	PrintResult( n, S, w, r, rate, V);
	
	
	delete[] w;
    delete[] r; 
	
    return 0;
}
  

                  
                 