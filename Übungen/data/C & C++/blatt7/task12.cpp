#include <cstdlib>
#include <iostream>
void sortiere (int a[], int length);
void tausche(int& a, int& b);

int main(int argc, char** argv) {
	int array[127];
	
	for(int i = 0; i < 127; ++i) {
		array[i] = rand();
	}
	
	sortiere(array, 127);
	
	for(int i = 0; i < 127; ++i) {
		std::cout << array[i] << " ";
	}
	
	std::cout << std::endl;
	return 0;
}
void sortiere(int arr[], int length) {
   for (int i = 0; i < length-1; i++)
       for (int j = 0; j < length-1-1; j++)
           if (arr[j] > arr[j+1])
              tausche(arr[j], arr[j+1]);
}

void tausche (int& a, int& b) {
	char tmp = a;
	a = b;
	b = tmp;
}
