#include<iostream>
#include<math.h>

#define A14 0.347854
#define A23 0.652145

#define A16 0.171324
#define A25 0.360761
#define A34 0.467913

#define A18 0.101228
#define A27 0.222381
#define A36 0.313706
#define A45 0.362683

#define T41 0.861136
#define T42 0.339981
#define T43 0.339981
#define T44 0.861136

#define T61 0.932464
#define T62 0.661209
#define T63 0.238619
#define T64 0.238619
#define T65 0.661209
#define T66 0.932464

#define T81 0.960289
#define T82 0.796666
#define T83 0.525532
#define T84 0.183434
#define T85 0.183434
#define T86 0.525532
#define T87 0.796666
#define T88 0.960289

double K = 1.6;
double L = 1.2;

double function(double x) {
	double result = (x + L) / (x * (x + 1) + K);
	return result;
}

void main(){
	std::cout << "Print border K: ";
	std::cin >> K;
	std::cout << "Print border L: ";
	std::cin >> L;
	double x = K + L;
	std::cout << "Integral: ";
	double I = 1 / 2. * log(x * (x + 1) + K) + (L - 0.5) / (sqrt(K - 0.25)) * atan((x + 0.5) / (sqrt(K - 0.25)));
	 x = (K - L) / 2.;
	I -= 1 / 2. * log(x * (x + 1) + K) + (L - 0.5) / (sqrt(K - 0.25)) * atan((x + 0.5) / (sqrt(K - 0.25)));
	std::cout << "I: " << I << '\n';
	int step;
	std::cout << "print n: ";
	std::cin >> step;
	double I_tr = 0.0;
	double a = (K - L) / 2.;
	double b = K + L;
	double h = (b - a) / step;
	std::cout << "f(x0): " << function(a) << '\n';
	std::cout << "f(x" << step << "): " << function(b)<< '\n';
	I_tr += function(a);
	I_tr += function(b);
	for (int i = 1; i < step; ++i) {
		std::cout << "f(x" << i << "): " << function(a + h * i) << '\n';
		I_tr = I_tr + 2. * function(a + h * i);
	}
	std::cout << "I_tr: " << I_tr * h/2 << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\n";

	double I_pr = 0;
	std::cout << "f(x0): " << function(a) << '\n';
	std::cout << "f(x" << 2 * step << "): " << function(b) << '\n';
	I_pr += function(a);
	I_pr += function(b);
	h = (b - a) / (2. * step);
	for (int i = 1; i < step * 2; ++i) {
		std::cout << "f(x" << i << "): " << function(a + h * i) << '\n';
		if (i % 2 == 0)
			I_pr = I_pr + 2. * function(a + h * i);
		else
			I_pr = I_pr + 4. * function(a + h * i);
	}
	std::cout << "I_par: " << I_pr * h / 3 << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\n";

	double I_g = 0;
	h = (b - a) / 2;
	switch (step) {
	case 4:
		for (int i = 1; i < step + 1; ++i) {
			switch (i) {
			case 1:
				std::cout << "f(x" << i << "): " << A14 * function((a + b) / 2 + h * -T41) << '\n';
				I_g = I_g + A14 * function((a + b) / 2 + h * -T41);
				break;
			case 2:
				std::cout << "f(x" << i << "): " << A23 * function((a + b) / 2 + h * -T42) << '\n';
				I_g = I_g + A23 * function((a + b) / 2 + h * -T42);
				break;
			case 3:
				std::cout << "f(x" << i << "): " << A23 * function((a + b) / 2 + h * T43) << '\n';
				I_g = I_g + A23 * function((a + b) / 2 + h * T43);
				break;
			case 4:
				std::cout << "f(x" << i << "): " << A14 * function((a + b) / 2 + h * T41) << '\n';
				I_g = I_g + A14 * function((a + b) / 2 + h * T44);
				break;
			}
		}
		break;
	case 6:
		for (int i = 1; i < step + 1; ++i) {
			switch (i) {
			case 1:
				std::cout << "f(x" << i << "): " << A16 * function((a + b) / 2 + h * -T61) << '\n';
				I_g = I_g + A16 * function((a + b) / 2 + h * -T61);
				break;
			case 2:
				std::cout << "f(x" << i << "): " << A25 * function((a + b) / 2 + h * -T62) << '\n';
				I_g = I_g + A25 * function((a + b) / 2 + h * -T62);
				break;
			case 3:
				std::cout << "f(x" << i << "): " << A34 * function((a + b) / 2 + h * -T63) << '\n';
				I_g = I_g + A34 * function((a + b) / 2 + h * -T63);
				break;
			case 4:
				std::cout << "f(x" << i << "): " << A34 * function((a + b) / 2 + h * T64) << '\n';
				I_g = I_g + A34 * function((a + b) / 2 + h * T63);
				break;
			case 5:
				std::cout << "f(x" << i << "): " << A25 * function((a + b) / 2 + h * T65) << '\n';
				I_g = I_g + A25 * function((a + b) / 2 + h * T65);
				break;
			case 6:
				std::cout << "f(x" << i << "): " << A16 * function((a + b) / 2 + h * T66) << '\n';
				I_g = I_g + A16 * function((a + b) / 2 + h * T66);
				break;
			}
		}
		break;
	case 8:
		for (int i = 1; i < step + 1; ++i) {
			switch (i) {
			case 1:
				std::cout << "f(x" << i << "): " << A18 * function((a + b) / 2 + h * -T81) << '\n';
				I_g = I_g + A18 * function((a + b) / 2 + h * -T81);
				break;
			case 2:
				std::cout << "f(x" << i << "): " << A27 * function((a + b) / 2 + h * -T82) << '\n';
				I_g = I_g + A27 * function((a + b) / 2 + h * -T82);
				break;
			case 3:
				std::cout << "f(x" << i << "): " << A36 * function((a + b) / 2 + h * -T83) << '\n';
				I_g = I_g + A36 * function((a + b) / 2 + h * -T83);
				break;
			case 4:
				std::cout << "f(x" << i << "): " << A45 * function((a + b) / 2 + h * -T84) << '\n';
				I_g = I_g + A45 * function((a + b) / 2 + h * -T84);
				break;
			case 5:
				std::cout << "f(x" << i << "): " << A45 * function((a + b) / 2 + h * T85) << '\n';
				I_g = I_g + A45 * function((a + b) / 2 + h * T85);
				break;
			case 6:
				std::cout << "f(x" << i << "): " << A36 * function((a + b) / 2 + h * T86) << '\n';
				I_g = I_g + A36 * function((a + b) / 2 + h * T86);
				break;
			case 7:
				std::cout << "f(x" << i << "): " << A27 * function((a + b) / 2 + h * T87) << '\n';
				I_g = I_g + A27 * function((a + b) / 2 + h * T87);
				break;
			case 8:
				std::cout << "f(x" << i << "): " << A18 * function((a + b) / 2 + h * T88) << '\n';
				I_g = I_g + A18 * function((a + b) / 2 + h * T88);
				break;
			}
		}
		break;
			
	}
	std::cout << "I_g: " << I_g * h;
}