#ifndef ASG_H_
#define ASG_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

#pragma once
#define PI 3.1415926535897932
#define PI_4 0.7853981633974483

using namespace std;

typedef vector<double> seq;

class ASG
{
private:

	double w1;
	double w2;
	double Fs;
	uint16_t N;
	double THB;
	seq A_coeff;
	ofstream file;

public:
	ASG();
	void Gen_AS();
	void Get_data();
	seq Get_Coeff();
	bool copy_to_file();

};


#endif
