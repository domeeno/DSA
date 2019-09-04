#include <stdio.h>
#include <stdlib.h>

int A[100];
int B[100];

//functie pentru input a array-ului unidemnsional
void Read(int n){
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}}
//functie output a array-ului unidimensional
void Print(int arr[], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);}} 
//functie ce arata maximul nr din array unidimensional
int GetMax(int arr[], int n){
	int max = arr[0]; 
	for(int i = 0; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;}
//functie ce arata minimul nr din array unidimensional
int GetMin(int arr[], int n){
	int min = arr[0]; 
	for(int i = 0; i < n; i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;}
//functie pentru calcularea nr de aparitii a numarului maxim dintr-un array unidimensional
int nrMax(int str[], int n, int max){
	int nrmax = 0;
	for(int i = 0; i < n; i++){
		if(str[i] == max){
			nrmax++;
		}
	}
	return nrmax;}
//functie pentru calcularea nr de aparitii a numarului minim dintr-un array unidimensional
int nrMin(int str[], int n, int min){
	int nrmin = 0;
	for(int i = 0; i < n; i++){
		if(str[i] == min){
			nrmin++;
		}
	}
	return nrmin;}
//functie pentru gasirea primului element negativ din array unidimensional
int GetNeg(int arr[], int n){
	int neg;
	for(int i = 0; i < n; i++){
		if(A[i] < 0){
			neg = i;
			break;
		}
	}
	return neg;}
//functie ce afiseaza suma elementelor dupa primul element negativ a unui array unidimensional
int nAfterSum(int arr[], int n){
	int l = GetNeg(arr, n), sum = 0;
	l++;
	for(int i = l; i < n; i++)
	{
		sum += A[i];
	}

	return sum;}
//functie de permutare a elementelor array-ului unidimensional A cu un indice spre stanga 
void Permut(int n){
	B[n-1] = A[0];
	for(int i = 0; i < n-1; i++){
		B[i] = A[i+1];
	} }
//functie pentru calcularea nr-ului de schimbari a semnului dintre elemente vecine dintr-un array unidimensional
int signCheck(int arr[], int n){
	int sC = 0;
	for(int i = 0; i < n-1; i++){
		if((A[i] < 0 && A[i+1] > 0) || (A[i] > 0 && A[i+1] < 0))
			sC++;
	}
	return sC;}

int main(){
	int n, M, m, nrM, nrm, chge;
	scanf("%d", &n); printf("\n");
	Read(n);
	Print(A, n);
	M = GetMax(A, n);
	m = GetMin(A, n);
	nrM = nrMax(A, n, M);
	nrm = nrMin(A, n, m);
	chge = signCheck(A, n);
	Permut(n);
	
	printf("\nNr maxim este: %d si se repeta de: %d ori", M, nrM);
	printf("\nNr minim este: %d si se repeta de: %d ori", m, nrm);
	printf("\nSuma este egala cu: %d",  nAfterSum(A, n));
	printf("\nSemnul s-a schimbat de %d ori", chge);
	Print(B, n);
	return 0;}