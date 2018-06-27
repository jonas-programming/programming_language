#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

int main() {
	int s1;
	std::cout << "Size of matrices: ";
	std::cin >> s1;
	
	std::clock_t begin = std::clock();

	std::vector < int > A = std::vector < int > (s1 *s1, 0);
	std::vector < int > B = std::vector < int > (s1 *s1, 0);
	std::vector < int > C = std::vector < int > (s1 *s1, 0); // Filled with zeros
  	for (int i = 0; i < s1; i++) {
  		for (int j = 0; j < s1; j++) {
      	A[i *s1 + j] = i * s1 + j + 1;
      	B[i *s1 + j] = i * s1 + j + 1;
    	}
  	}

	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s1; j++) {
      		for (int k = 0; k < s1; k++) {
       			C[i *s1 + j] = C[i *s1 + j] + A[i *s1 + k] *B[j *s1 + k];
      	}
    	}
    	if(s1 > 1000 && i % (s1 / 10) == 0){
    		std::cout << std::round(i*100.0 / s1) << "%" << std::endl;
    	}
  	}

  	std::clock_t end = std::clock();
  	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  	std::cout << "Time: " << elapsed << "s" << std::endl;


  	for (int i = 0; i < s1; i++) {
    	for (int j = 0; j < s1; j++) {
      		std::cout << C[i *s1 + j] << " ";
    	}
   		 std::cout << std::endl;
  	}

}
