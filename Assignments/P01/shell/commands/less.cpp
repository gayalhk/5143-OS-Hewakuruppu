#include <iostream> 
#include <algorithm> 
#include <functional> 
using namespace std; 

template <typename A, typename B, 
		typename U = std::less<int> > 
		
bool f(A a, B b, U u = U()) 
{ 
	return u(a, b); 
} 

int main() 
{ 
	int X = 1, Y = 2; 
	cout << std::boolalpha; 
	cout << f(X, Y) << '\n'; 
	X = 2, Y = -1; 
	cout << f(X, Y) << '\n'; 

	return 0; 
}
