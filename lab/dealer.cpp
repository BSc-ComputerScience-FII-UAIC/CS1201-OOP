#include "dealer.h"


void Dealer::operator+=(Car c) {
	if (listOfCars.size() + 1 > maxCapacity) {
		throw std::runtime_error("Error");
	} 
	listOfCars.push_back(c);
}

void Dealer::PrintOffers(bool(*filter)(Car c)) {
	int nr = 0;
	for (auto cr : listOfCars) {
		if (filter(cr)) {
			cout << cr.year << " " << cr.cost << " " << cr.color << "\n";
			nr++;
		}
	}

	if (nr == 0) {
		cout << "There are no offers matching.\n";
	}

}
