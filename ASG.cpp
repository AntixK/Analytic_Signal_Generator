#include "ASG.h"

ASG::ASG()
{
	N = 0;
	w1 = 0;
	w2 = 0;
	THB = 0.0;
	A_coeff.reserve(1);
}

void ASG::Gen_AS()
{
	double t = 0.0, temp;

	for (uint16_t n = 0; n < N; ++n)
	{
		t = 2 * PI*(n - (N - 1) / 2.0);
		temp = 0.0;

		if (n == (N - 1) / 2)
			temp = sqrt(2) * (w2 - w1);

		else if (n == ((N - 1) / 2) + 1 / (4 * THB))
			temp = THB*(sin(PI_4 *((THB + 2 * w2) / THB)) - sin(PI_4 *((THB + 2 * w1) / THB)));

		else if (n == ((N - 1) / 2) - 1 / (4 * THB))
			temp = THB*(sin(PI_4 *((THB - 2 * w2) / THB)) - sin(PI_4 *((THB - 2 * w1) / THB)));

		else
			temp = ((2 * PI*PI * cos(THB * t)) / (t*(4 * t*t * THB*THB - PI*PI)))
			       * (sin(PI_4 + w1 * t) - sin(PI_4 + w2 * t));
			
		A_coeff.push_back(temp);
	}
	
}

void ASG::Get_data()
{
	while (N < 1 || N > 5000)
	{
		cout << "\n Enter the value of N: ";
		cin >> N;
	}

	while (w1 >= w2)
	{
		cout << "\n Enter the lower and higher Half Amplitude points (w1 , w2) in rad/s: ";
		cin >> w1 >> w2;
	}

	cout << "\n Enter Transition Half bandwidth (THB) in rad/s: ";
	cin >> THB;

	cout << "\n Enter Sampling Frequency (1 if Normalized): ";
	cin >> Fs;

	w1 /= Fs;
	w2 /= Fs;
	THB /= Fs;
}

seq ASG::Get_Coeff()
{
	return A_coeff;
}

bool ASG::copy_to_file()
{
	file.open("Analytic_Signal.txt", ios::out);
	file << "\n Generated Analytic Signal - \n";
	file << "--------------------------------------\n";

	file << " A Coefficients - ";
	for (uint16_t i = 0;i < N;++i)
		file <<"\n"<< A_coeff[i];

	file << "\n\n B Coefficients - ";
	for (uint16_t i = N-1;i >0 ;--i)
		file << "\n" << A_coeff[i];

	file.close();
	return true;
}
