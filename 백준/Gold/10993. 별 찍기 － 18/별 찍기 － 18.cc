#include <iostream>

using std::cin;
using std::cout;

char arr[1024][2048]; // 높이 := 2^n - 1 넓이 := 2^(n+1) -3

void draw(int row, int rowLen, int col, int colLen, int level) {
	if(level & 1) { // 홀수 레벨 (좌하단 시작)
		for(int i = 0; i < rowLen; ++i) {
			if(!i)  // 가장 밑 변
				for(int j = 0; j < colLen; ++j) arr[row+i][col+j] = '*';
			else if(i == rowLen - 1) // 마지막 줄은 꼭짓점이 1개
				arr[row-i][col+rowLen-1]='*';
			else  // 나머지는 점 두개씩
				arr[row-i][col+i]=arr[row-i][col+colLen-i-1]='*';
		}
	}
	else { // 좌상단 시작
		for(int i = 0; i < rowLen; ++i) {
			if(!i) for(int j = 0; j < colLen; ++j) arr[row+i][col+j]='*';
			else if(i == rowLen - 1) arr[row+i][col+rowLen-1]='*';
			else  arr[row+i][col+i]=arr[row+i][col+colLen-i-1]='*';
		}
	}
}

void f(int row, int col, int level) {
	int rowLen = (1 << level) - 1, colLen = (1 << (level + 1)) - 3;
	// printf("level:%d row:%d rowLen:%d col:%d colLen:%d\n",level,row,rowLen,col,colLen);
	draw(row, rowLen, col, colLen, level);

	if (level == 1) return;

	if (level & 1)  // 짝수로 보내야함 -> 시점 := 좌하단
		f(row - (rowLen >> 1), col + (rowLen >> 1) + 1, level - 1);
	
	else  // 홀수로 보내야함 -> 시점: 좌상단
		f(row + (rowLen >> 1), col + (rowLen >> 1) + 1, level - 1 );
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < 1024; ++i)
		for(int j = 0; j < 2046; ++j)
			arr[i][j] = ' ';

	if(n&1) f((1 << n) - 2,0,n);
	else f(0,0,n);
	// freopen("output.txt", "w", stdout);
	// output
	for(int i = 0; i < (1 << n) -1; ++i) {
		if (n & 1) 
			for(int j = 0; j < (1 << n) - 1+i; ++j) cout << arr[i][j];
		else 
			for(int j = 0; j < ((1 << (n+1))-3)-i; ++j) cout << arr[i][j];
		cout << '\n';
	}
	
}