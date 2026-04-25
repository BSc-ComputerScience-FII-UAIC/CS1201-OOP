//
// Created by Dorel Lucanu on 4/29/21.
//

int gcd(int a, int b) {
    if (b == 0) return a;
    if (a == 0) return b;
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}
