#include <iostream>
#include <string>

using namespace std;

int  DividePizza(int pizzaSize, int person);

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;
	try {
		cout << "피자 조각수를 입력하시요 : ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시요 : ";
		cin >> persons;
		
		slices_per_person = DividePizza(pizza_slices, persons);
		cout << "한사람당 피자는" << slices_per_person << "입니다" << endl;
	}
	catch (int e) {
		cout << "사람이" << e << "명 입니다." << endl;
	}

	return 0;
}

int  DividePizza(int pizzaSize, int person) {
	if (person == 0) {
		throw person;
	}
	return pizzaSize / person;
}
