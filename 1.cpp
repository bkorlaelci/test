#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	int numberCount;
	string read_numbers;
	ifstream dosya;

	dosya.open("input.txt");
	
	if (dosya.is_open()) {
		cout << "input.txt dosyasi basariyla acildi!" << endl;
	}
	else {
		cout << "input.txt dosya acma hatasi!" << endl;
		exit(1);
	}
	
	getline(dosya, read_numbers);
	numberCount = stoi(read_numbers);
	cout << numberCount << endl;

	int* numbers = new int[numberCount];
	int i;

	for (i = 0; i < numberCount; i++) {
		if (dosya.eof()) {
			cout << "Error: Not enough numbers in the file." << endl;
			exit(1);
		}
		getline(dosya, read_numbers, ' ');
		numbers[i] = stoi(read_numbers);
		cout << "[" << i << "]=" << numbers[i] << endl;
	}
	
	dosya.close();

	int sum=0, product=1, average, smallest_number;

	for (i = 0; i < numberCount; i++) {
		sum = sum + numbers[i];
		product = product * numbers[i];
	}
	average = sum / numberCount;

	smallest_number = numbers[0];
	for (i = 1; i < numberCount; i++) {
		if (numbers[i] < smallest_number)
			smallest_number = numbers[i];
		else
			continue;
	}

	cout << endl;
	cout << "Sum is: "<< sum << endl;
	cout <<"Product is: "<< product << endl;
	cout << "Average is: "<< average << endl;
	cout << "Smallest is: "<< smallest_number << endl;

	delete[]numbers;

	cout << endl;
	system("pause");
	return 0;
}