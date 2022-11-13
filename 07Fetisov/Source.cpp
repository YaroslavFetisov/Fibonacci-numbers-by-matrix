#include <iostream>
using namespace std;

struct Matrix2x2 {
	int _11, _12, _21, _22;
};

struct Vector2 {
	int _1, _2;
};

void matrixPow (Matrix2x2& Matrix, int n) {
	int a, b, c, d;
	for (int i = 0; i < n - 3; i++) {
		a = Matrix._11;
		b = Matrix._12;
		c = Matrix._21;
		d = Matrix._22;
		Matrix._11 = a + b ;
		Matrix._12 = a;
		Matrix._21 = c + d;
		Matrix._22 = c;
	}
}

void multiplyVector(Vector2 Vector, Matrix2x2 Matrix, int n)
{
	matrixPow(Matrix, n);

	Vector._1 = Matrix._11 * Vector._1 + Matrix._12 * Vector._2;
	Vector._2 = Matrix._21 * Vector._1 + Matrix._22 * Vector._2;

	cout << "Your Fibonacci number (n: " << n << ")" << " = " << Vector._1;
}

//Works for 3 < n < 47. For n > 47: integer overflowes
void fib(int n)
{
	multiplyVector({ 1, 1 }, { 1, 1 ,1 ,0 }, n);
}

void main(void) {
	int n;
	cout << "Enter the index of Fibonacci number: ";
	cin >> n;
	fib(n); 
}