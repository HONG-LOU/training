#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
double exp()
{
	char s[35];
	cin >> s;
	switch (s[0])
	{
	case '+':
		return exp() + exp();
	case '-':
		return exp() - exp();
	case '*':
		return exp() * exp();
	case '/':
		return exp() / exp();
	default:
		return atof(s);
	break;
	}
}
 
int main()
{
	printf("%.1f\n", exp());
	return 0;
}