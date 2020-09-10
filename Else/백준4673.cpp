#include <iostream>
#include <math.h>

using namespace std;
int num[10001] = { 0 };

void selfnumber(int n) {
	int i = 1; int temp = n;
	int position_value = 0;
	int num_length = 0;
	while (n >= i) {
		i *= 10;
		num_length++;
	}
	if (num_length == 0 ) {
		n = n + n;
	}
	else {
		for (i = num_length - 1; i > -1; i--) {
			position_value = temp / pow(10, i);
			temp = temp % int(pow(10, i));
			n = n + position_value;
		}
	}
	num[n]=1;

	if(n<10000)
		selfnumber(n);
}

int main() {
	int i = 0;
	for(i=1;i<10000;i++){
		if (num[i] == 0)
			selfnumber(i);
	}
	for (i = 1; i < 10000; i++) {
		if (num[i] == 0)
			cout << i << endl;
	}
	
}