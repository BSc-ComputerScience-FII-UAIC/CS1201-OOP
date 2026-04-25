//
// Created by Dorel Lucanu on 4/29/21.
//

int gcd(int a, int b) {
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}
