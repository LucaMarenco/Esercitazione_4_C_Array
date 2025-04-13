#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  
#include <string>
#include <cstring>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r)
{
	ifstream fstr(inputFilePath);
	
	if(fstr.fail())
		return false;
	
	string tmp;
    
    getline(fstr, tmp);
	std::stringstream ss(tmp);
    std::string label;
    getline(ss, label, ';');  
    ss >> S; 
	
	getline(fstr, tmp);
	std::stringstream sl(tmp);
    std::string label1;
    getline(sl, label1, ';');  
    sl >> n; 

	w = new double[n];
	r = new double[n];
	
	getline(fstr, tmp);
	unsigned int i = 0;
	while (getline(fstr, tmp)) {  
        stringstream ss(tmp);  
        std::string str ;
        double r_val;
        std::stringstream ds;
        ds << str;  
    
        getline(ss,str, ';'); 
        ss >> r_val; 
        w[i] = stod(str);
        r[i] = r_val ;
        i++;
    }
	

	fstr.close();
	
	return true;
}

bool Value(const size_t& n,
		   const double& S,
           const double* const& w,
           const double* const& r,
           double& rate, 
		   double& V)
{
    rate = 0.0;
    for (unsigned int i = 0; i < n; i++) 
	{
        rate += w[i] * r[i];
    }

    V = S * (1 + rate);
	
    return true;
}


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
                  const double& rate, 
				  const double& V)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "File open failed"<< endl;
        return false;
    }
    file << std::fixed << std::setprecision(2);
    file << "S = " << S << ", ";
	file << std::resetiosflags(std::ios::fixed) << setprecision(3);
	file << "n = " << n << endl;
    file << "w =  "<< ArrayToString(n, w) << endl;
    file << "r = "<<  ArrayToString(n, r) << endl;
    file << "Rate of return of the portfolio: " << rate << endl;
    file << std::fixed << std::setprecision(2);
    file << "V: "<< V << endl;
 
    // Close File
    file.close();

    return true;
}


 

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

int PrintResult(const size_t& n,
				const double& S,
                const double* const& w,
                const double* const& r,
                const double& rate, 
				const double& V)
{
    cout << std::fixed << setprecision(2) << "S = " << S << ", ";
	cout << std::resetiosflags(std::ios::fixed) << setprecision(3);
    cout << "n = " << n << endl;
    cout << "w =  "<< ArrayToString(n, w) << endl;
    cout << "r = "<<  ArrayToString(n, r) << endl;
    cout << "Rate of return of the portfolio: " << rate << endl;
	cout << std::fixed << std::setprecision(2);
    cout << "V: "<< V << endl;
	return 0;
}
 