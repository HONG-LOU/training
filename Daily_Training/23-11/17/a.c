#include <stdio.h>
  
int main() {
	double r, s, S, R, x, y, n;
	scanf("%lf", &r);
	n = 3.14159;
	R = r + 3;
	s = n * r * r;
	S = n * R * R;
	x = (S - s) * 40.0;
	y = 2 * n * R * 55.0;
	printf("%.0f %.0f", x, y);
	return 0;
}