#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX 30
int main(){
	int array[MAX];
	int n,i,gap,value;
	printf("\nHow many elements: ");
	scanf("%d",&n);
	printf("\nEnter array elements: ");
	
	for(i=0;i<n;i++){
		printf("\nEnter element @index %d:");
		scanf("%d",&array[i]);
		
	}
	printf("\nArray before sorting is: ");
	for(i=0;i<n;i++){
		printf("%d",array[i]);
	}
	for(i=1;i<n;i++){
		value=array[i];
		gap=i;
		while(gap>0 &&array[gap-1]>value){
			array[gap]=array[gap-1];
			gap--;
			
		}
		array[gap]=value;
		
	}
	printf("\nArray after sorting is:");
	for(i=0;i<n;i++){
		printf("%d",array[i]);
	}
	getche();
	
	}