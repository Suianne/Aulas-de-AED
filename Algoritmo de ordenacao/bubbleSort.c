#include <stdio.h>

void bubbleSort(int arr[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				//troca dos elementos
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(){
	
	int arr[];
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	return 0;
}