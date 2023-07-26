void parsing(const string& x) {
    int a = -1, b;
    while (true) {
        // a의 다음 index부터 탐색
        a = x.find('[', a + 1);

        // 못찾으면 break;
        if (a == -1) break;

        b = x.find(']', a + 1);

        // arr에 추가
        int size = b - a + 1;
        // substr(idx, size) -> idx 포함 글자 수

        // 주식 종목이면 정답에 추가
        string candidate = x.substr(a, size);
        if (candidate.length() == 7) arr.push_back(candidate);

        // a를 b ']'의 idx로 넘겨줌 -> find시 a+1부터 찾기 때문에
        a = b;
    }
}
