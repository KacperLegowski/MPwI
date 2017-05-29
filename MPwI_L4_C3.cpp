#include <iostream>

using namespace std;

#define N 3

#define N2 2




double policzU2(double prog, double px[]) {
	double result = 0;
	double ppp[3];
	double pu1mfu2[3];
	double suma = 0;
	double pu2 = (double)1 / 3;

	for (int i = 0; i< 3; i++) {
		ppp[i] = px[i] / prog;

		if (ppp[i] > 1) {
			ppp[i] = 1;
		}

		suma += ppp[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << i << ": " << ppp[i] / suma << " " << endl;
	}

	for (int i = 0; i < 3; i++) {
		pu1mfu2[i] = pu2 * ppp[i];
	}

	for (int i = 0; i < 3; i++) {
		result += pu1mfu2[i];
	}

	return result;
}

int main() {
	double px[3] = { 0.2,0.3,0.5 };
	double U1[3] = { 1.0,0.51,0.4 };
	for (int i = 0; i < 3; i++) {
		cout << policzU2(U1[i], px) << endl;
	}


	return 0;
}