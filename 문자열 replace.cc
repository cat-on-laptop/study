string replace(string s, string x, string y) {
    // replace := s 에있는 x를 y로 교체해주는 함수

    int a = 0, b = 0;
    int len = x.length();
    while (true) {
        b = s.find(x, a);

        // 없다면 break;
        if (b == -1) break;

        // b idx부터 len의 길이만큼 제거
        s.erase(b, len);

        // 새로운 문자열 y 삽입
        s.insert(b, y);

        // 검색할 인덱스를 b에서 len만큼 추가
        a = b + len;
    }

    return s;
}
