#include <iostream>
#include <string>
#include "car.h"
#include "dealer.h"

using namespace std;

int main() {

    Car* c1 = new Car(2010, 9000, "blue");
    Car* c2 = new Car(2006, 4500, "black");
    Car* c3 = new Car(2018, 20000, "red");
    Car* c4 = new Car(1999, 500, "white");
    Car* c5 = new Car(2004, 3600, "black");

    Dealer dealer;
    try {
        dealer += *c1;
        dealer += *c2;
        dealer += *c3;
        dealer += *c4;
        dealer += *c5;
    }
    catch (runtime_error& exception) {
        printf("%s\n", exception.what());
        return 0;
    } 

    free(c1);
    free(c2);
    free(c3);
    free(c4);
    free(c5);

    printf("Offers for year > 2000: \n");
    dealer.PrintOffers([](Car c) {if (c.year > 2000) return true; return false; });
    /*
        Va afisa pe ecran:
            1. year = 2010, cost = 9000, color = blue
            2. year = 2006, cost = 4500, color = black
            3. year = 2018, cost = 20000, color = red
            4. year = 2004, cost = 3600, color = black
    */
    printf("Offers for year > 2000 and cost < 10000: \n");
    dealer.PrintOffers([](Car c) {if (c.year > 2000 && c.cost < 10000) return true; return false; });
    /*
        Va afisa pe ecran:
            1. year = 2010, cost = 9000, color = blue
            2. year = 2006, cost = 4500, color = black
            3. year = 2004, cost = 3600, color = black
    */
    printf("Offers for year > 2000 and cost < 2000: \n");
    dealer.PrintOffers([](Car c) {if (c.year > 2000 && c.cost < 2000) return true; return false; });
    /*
        Va afisa pe ecran:
            There are no offers matching.
    */
    printf("Offers for year > 2000 and color = black: \n");
    /*
        Apelati functia PrintOffers cu functia lambda corespunzatoare pentru a afisa pe ecran:
            1. year = 2006, cost = 4500, color = black
            2. year = 2004, cost = 3600, color = black
    */
 
    return 0;
}