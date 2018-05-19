package blatt1;

public class TaskSolver {

	public static int it_add(int n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i;
		}
		return sum;
	}

	public static int rek_add(int n) {
		if (n == 1)
			return n;
		if (n <= 0)
			return 0;
		return rek_add(n - 1) + n;
	}

	public static int it_product(int n) {
		int product = (n <= 0) ? 0 : 1;
		for (int i = 1; i <= n; i++) {
			product *= i;
		}
		return product;
	}

	public static int rek_product(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return n;
		return rek_product(n - 1) * n;
	}

	public static int it_fibo(int n) {
		int a = 0;
		int b = 1;
		for (int i = 2; i <= n; i++) {
			int tmp = a;
			a = b;
			b = tmp + b;
		}
		return (n > 0) ? b : 0;
	}

	public static int rek_fibo(int n) {
		if (n < 0)
			return 0;
		if (n < 2)
			return n;
		return rek_fibo(n - 1) + rek_fibo(n - 2);
	}

	public static void main(String... args) {
		System.out.println(it_add(10));
		System.out.println(rek_add(10));
		System.out.println(it_product(10));
		System.out.println(rek_product(10));
		System.out.println(it_fibo(10));
		System.out.println(rek_fibo(10));
	}

}
