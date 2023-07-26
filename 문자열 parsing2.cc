void parsing(string& x) {
    // 마지막에 '_'를 추가해서 마지막 단어도 추가되도록 처리
    x += '_';
    int a = -1, b = 0;
    while (true) {
        a = x.find('_', a + 1);
        if (a == -1) {
            // 못찾은 경우
            break;
        }
        int len = a - b;
        string temp = x.substr(b, len);
        arr.push_back(temp);

        while (a < x.length() && x[a] == '_') {
            // _____인 경우를 처리가힉 위해 '_'가 안나올때까지 a를 늘림
            ++a;
        }
        b = a--;
    }
}
