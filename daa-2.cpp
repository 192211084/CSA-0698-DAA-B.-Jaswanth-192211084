#include<stdio.h>
#include<math.h>
int countnum(int n){
	if(n==0)
		return 0;
	else
		return 1+countnum(n/10);
}
int sumofpow(int n, int power){
	if(n==0)
		return 0;
	else
		return pow(n%10,power) + sumofpow(n/10,power);
}
int isarmstrong(int n){
	int numdigits=countnum(n);
	return n==sumofpow(n,numdigits);
}
int main(){
	int num;
	printf("enter a number: ");
	scanf("%d",&num);
	if(isarmstrong(num)){
		printf("armstrong");
	}
	else{
		printf("not an armstrong number");
	}
	return 0;
}
