#include <iostream>
#include <fstream>
#include <string> 

class Address {
private:
	std::string Town;
	std::string Street;
	int numberHome;
	int numberFlat;
public:
	Address(std::string Town, std::string Street, int numberHome, int numberFlat) {
		this->Town = Town;
		this->Street = Street;
		this->numberHome = numberHome;
		this->numberFlat = numberFlat;
	}

	Address() {
		Town = "Town";
		Street = "Street";
		numberHome = 0;
		numberFlat = 0;
	}
	
	std::string PrintAddress() {
		return Town + ", " + Street + ", " + std::to_string(numberHome) + ", " + std::to_string(numberFlat);
	}
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	std::ifstream fin;
	std::ofstream fout;

	int countAddress = 0;

	std::string Town;
	std::string Street;
	int numberHome = 0;
	int numberFlat = 0;

	std::string checkEndFile;

	fin.open("in.txt");

	if (!(fin.is_open())) {
		std::cout << "Error opening the file" << std::endl;
		return 1;
	}

	if (!(fin >> countAddress)) {
		std::cout << "Data not found" << std::endl;
		return 1;
	}

	if (countAddress <= 0) {
		std::cout << "Quantity of Addresses cannnot be equal zero or negative" << std::endl;
		return 1;
	}

	Address* ptrAddress = new Address[countAddress]{};

	for (int i = 0; i < countAddress; ++i) {
		if (!(fin >> Town) || !(fin >> Street) || !(fin >> numberHome) || !(fin >> numberFlat)) {
			std::cout << "Data not found" << std::endl;
			return 1;
		}

		if (numberHome <= 0 && numberFlat <= 0) {
			std::cout << "Home and flat numbers cannnot be equal zero or negative" << std::endl;
			return 1;
		}

		ptrAddress[i] = Address(Town, Street, numberHome, numberFlat);
	}

	if (fin>>checkEndFile) {
		std::cout << "The file is not read to the end" << std::endl;
		return 1;
	}
	
	fin.close();

	fout.open("out.txt");

	if (!(fout.is_open())) {
		std::cout << "Error opening the file" << std::endl;
		return 1;
	}

	fout << countAddress << std::endl;

	for (int i = countAddress-1; i >= 0; --i) {
		fout << ptrAddress[i].PrintAddress() << std::endl;
	}

	fout.close();

	delete[] ptrAddress;

	return 0;
}