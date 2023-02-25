def solution(price, money, count):
    return price * count * (count + 1)  // 2 - money if price * count * (count + 1)  // 2 - money > 0 else 0