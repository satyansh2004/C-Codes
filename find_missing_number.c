#include <stdio.h>

int sort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}

int check(int arr[], int size) {
	for (int i = 1; i <= size; i++) {
		if (arr[i] != i) {
			printf("%d not present", i);
			return 1;
		}
	}

	return 0;
}

int main() {
	int arr[2] = {1};
	int size = sizeof(arr) / sizeof(int);

	sort(arr, size);
	check(arr, size);
	return 0;
}
