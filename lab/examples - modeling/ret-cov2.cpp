#include <iostream>

class Animal {
public:
    virtual void makeNoise() = 0;
    virtual ~Animal() =  default;
};

class Dog : public Animal {
public:
    void makeNoise() override { std::cout << "ham!\n"; }
};

class AnimalBreeder {
public:
    virtual Animal* produce() = 0;
};

class DogBreeder : public AnimalBreeder {
public:
     Dog* produce() override { return new Dog(); }
};

int main(){
    DogBreeder db;
    Dog* dp = db.produce();
    dp->makeNoise();
    delete dp;
}

