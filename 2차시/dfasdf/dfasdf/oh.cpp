#include <iostream>
#include <string>

using namespace std;

int  DividePizza(int pizzaSize, int person);

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;
	try {
		cout << "���� �������� �Է��Ͻÿ� : ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ� : ";
		cin >> persons;
		
		slices_per_person = DividePizza(pizza_slices, persons);
		cout << "�ѻ���� ���ڴ�" << slices_per_person << "�Դϴ�" << endl;
	}
	catch (int e) {
		cout << "�����" << e << "�� �Դϴ�." << endl;
	}

	return 0;
}

int  DividePizza(int pizzaSize, int person) {
	if (person == 0) {
		throw person;
	}
	return pizzaSize / person;
}
