using namespace std;

struct money {
	int grn;
	short int cop;
};

void countPrice(money& price);
void multiplyPrice(money& price, int q);
void printPrice(money& price);
void roundCop(money& price);