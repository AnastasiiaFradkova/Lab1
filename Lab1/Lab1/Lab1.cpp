#include <iostream>
#include "Lab1.h"
using namespace std;

void countPrice(money& price) {
	price.cop = price.grn * 100 + price.cop;
	price.grn = 0;
}

void multiplyPrice(money& price, int q) {
	price.cop = price.cop * q;
	price.grn = price.cop / 100;
	price.cop = price.cop - price.grn * 100;
}

void roundCop(money& price) {
	if (price.cop % 10 < 5) {
		price.cop = price.cop - price.cop % 10;
	}
	else {
		price.cop = price.cop + (10 - price.cop % 10);
	}

	if (price.cop >= 100) {
		price.grn += price.cop / 100;
		price.cop = price.cop % 100;
	}
}

void printPrice(money& price) {
	if (price.cop > 100) {
		price.grn += price.cop / 100;
		price.cop = price.cop % 100;
	}

	cout << price.grn << "." << price.cop << endl;
}