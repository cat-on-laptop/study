#include<stdio.h>
#include<math.h>

int main(void) {
	int n, x1, x2, y1, y2, r1, r2;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		float distance = sqrt((int)pow((x1 - x2),2)  + (int)pow((y1 - y2),2) );
		int sub = r1 > r2 ? r1 - r2 : r2 - r1;
		int result;
	
		if (r1 == r2 && distance == 0)
			result = -1;
		else if (distance < r1 + r2 && distance > sub)
			result = 2;
		else if (distance == r1 + r2 || distance == sub)
			result = 1;
		else
			result = 0;
		printf("%d\n", result);
	}

	return 0;


}