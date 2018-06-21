#include <iostream>
#include <list>

// I do not know what that is
void a1(int limit){
	if(limit > 0){
		std::cout << "Juhu" << std::endl;
		a1(limit-1);
	}
}

// Sum
int a2(std::list <int>* l){
	if(l == 0 || l->size() == 0) return 0;
	int f = l->front();
	l->pop_front();
	return f + a2(l);
}

// Index weighted sum
int a3(int* a, int length){
	if(a == 0 || length <= 0) return 0;
	return a[length-1] * length + a3(a, length-1);
}

// GGT
int a4(unsigned int a, unsigned int b){
	if(a==b) return a;
	return (a>b)? a4(a-b, b) : a4(b-a, a);
}

// Broken milk shelf
void a5(int f){
	if(f > 0){
		const char* p1 = (f==1)? "": "n";
		printf("%3.d Flasche%s Milch im Regal - %2.d Flaschen%s Milch. "
		"Und wenn eine runterfaellt ", f, p1, f, p1);
		printf("%s es nur noch %d Flasche%s Milch im Regal.\n", (f==1)? "ist": "sind", f, (f==1)? "": "n");
		a5(f-1);
	}
}

int main(){
	// a1
	std::cout << "a1" << std::endl << std::endl;
	a1(10);
	std::cout << std::endl;
	
	// a2
	std::list<int> l = std::list<int>({1, 2, 4});
	std::cout << "a2" << std::endl;
	std::cout << a2(&l) << std::endl << std::endl;

	// a3
	int a[] = {1,2,3,4,5};
	std::cout << "a3" << std::endl;
	std::cout << a3(a, 5) << std::endl << std::endl;
	
	// a4
	std::cout << "a4" << std::endl;
	std::cout << a4(14, 7) << std::endl << std::endl;
	
	// a5
	std::cout << "a5" << std::endl;
	a5(5);
}
