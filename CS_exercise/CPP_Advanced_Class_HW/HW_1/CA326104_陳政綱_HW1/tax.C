#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int total_income;
	double tax_rate;
	int tax;
	int discount;
	int tax_pay;
	scanf("%d",&total_income);
	
	if(total_income <= 370000){
		tax_rate = 0.06;
		tax = tax_rate * total_income;
		discount =0;
		tax_pay = tax - discount;
	}
	else if(total_income > 370000 && total_income <=990000){
		tax_rate = 0.13;
		tax = tax_rate * total_income;
		discount =25900;
		tax_pay = tax - discount;
	}
	else if(total_income > 990000 && total_income <=1980000){
		tax_rate = 0.21;
		tax = tax_rate * total_income;
		discount =105100;
		tax_pay = tax - discount;
	}
	else if(total_income > 1980000 && total_income <=3720000){
		tax_rate = 0.3;
		tax = tax_rate * total_income;
		discount =283300;
		tax_pay = tax - discount;
	}
	else if(total_income > 3720000){
		tax_rate = 0.4;
		tax = tax_rate * total_income;
		discount =655300;
		tax_pay = tax - discount;
	}
	printf("income %d\n",total_income);
	printf("tax rate %0.f%%\n", tax_rate*100);
	printf("tax %d\n",tax);
	printf("discount %d\n" , discount);
	printf("taxpay %d\n",tax_pay);	
	return 0;
}
