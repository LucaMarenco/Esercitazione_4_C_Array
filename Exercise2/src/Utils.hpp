#pragma once

#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r);		   


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
                  const double& rate, 
				  const double& V);
				  

int PrintResult(const size_t& n,
				const double& S,
                const double* const& w,
                const double* const& r,
                const double& rate, 
				const double& V);
				
bool Value(const size_t& n,
		   const double& S,
           const double* const& w,
           const double* const& r,
           double& rate, 
		   double& V);
		   

string ArrayToString(const size_t& n,
                     const double* const& v);