#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double a = -5, b = 2;

double func(double x){
	return (1 - x) * (1 - x) + exp(x);
}

void get_min(double T_min, double T_max, bool moderator) {
	int i = 1;
	srand(time(NULL));
	double x1 = a + (b - a) * rand() / RAND_MAX;
	double f1;
	if (moderator == 1) {
		f1 = func(x1);
	}
	else {
		f1 = sin(5*x1) * func(x1);
	}
	cout << setw(3) <<"N" << setw(12) << "T" <<setw(9) << "X" << setw(8) << "f(x)" << endl;
	cout << setw(3) << i << setw(12) << fixed << setprecision(3) << T_max << setw(9) << x1 << setw(8) << f1 << endl;
	while (T_max > T_min) {
		i++;
		double x2 = a + (b - a) * rand() / RAND_MAX;
		double f2;
		if (moderator == 1) {
			f2 = func(x2);
		}
		else {
			f2 = sin(5*x2) * func(x2);
		}
		double delt_f = f2 - f1;
		if (delt_f <= 0) {
			x1 = x2;
			f1 = f2;
		}
		else {
			double P = -delt_f / pow(M_E, T_max);
			double ver = rand() % 100;
			if (ver <= P) {
				x1 = x2;
				f1 = f2;
			}
		}
		T_max *= 0.95;
		cout << setw(3) << i << setw(12) << fixed << setprecision(3) << T_max << setw(9) << x1 << setw(8) << f1 << endl;
	}
	cout << "Result: X_min = " << x1 << "   F_min = " << f1;
}

int main(){
	double T_MAX = 10000.000, T_MIN = 0.100;
	cout << "For f(x)"<<endl;
	get_min(T_MIN, T_MAX, 1);
	cout << endl << "For f(x)*sin(5x)" << endl;
	get_min(T_MIN, T_MAX, 0);
	return 0;
}
