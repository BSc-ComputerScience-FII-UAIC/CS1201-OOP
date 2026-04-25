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

class DogDoctor  {
public:
    virtual void treat(Dog *dog) { std::cout << "Dog treated!\n"; }
};

class AnimalDoctor : public DogDoctor {
public:
    void treat(Animal * animal) override { std::cout << "Animal treated!\n"; }  // error
};


int main(){
    Dog* dp = new Dog;
    DogDoctor dd;
    dd.treat(dp);
    AnimalDoctor ad;
    ad.treat(dp);
}
