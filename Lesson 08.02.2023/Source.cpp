#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Printer.h"
#include <memory>
class Incrementer {
public:
	Incrementer(int x): _x(x){}

	int operator()(int y) {
		return _x + y;
	}
	int operator()(int y,double z) {
		return _x + y + z;
	}
	int myFunc(int y) {
		const auto add = [this,y](int a) {//this  по указателю передали. *this передали по ссылке
			return _x + y + a;
		};
		return add(5);
	}
private:
	int _x;
};
using namespace Engine;


class Car :public Ivehicle {
public:
	Car(int speed) : _speed(speed){}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Car" << std::endl;
	}
private:
	int _speed;
};

class Bike : public Ivehicle {
public:
	Bike(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Bike" << std::endl;
	}
private:
	int _speed;
};

class Bike2 : public Ivehicle {
public:
	Bike2(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Bike2" << std::endl;
	}
private:
	int _speed;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::shared_ptr<Ivehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed" << v->getSpeed() << std::endl;
	v->printType();
	std::cout << "__________________________" << std::endl;

	std::shared_ptr<Ivehicle> vec = std::make_shared<Ivehicle>(30);



	Incrementer inc(50);

	int a = inc(5);//50 + 5
	int b = inc(5, 6);//50 + 5 + 6
	std::cout << a << std::endl;//55
	std::cout << b << std::endl;//61

	const auto myinc = [a](int number) {//лямбда
		return number + 5 + a; //6 + 5 + 55
	};
	a = 2;
	std::cout << myinc(7) << std::endl;//67

	//можно определить захват по умолчанию
	const auto myinc2 = [=,&a ](int number)-> int {//-> int явно указали какой тип вернет
	//захватили все переменные,
	//а вот а по ссылке захватить, можно [&, a]
	//[&,&a] такое выражение недопустимо
		return number + 5 + a; // 7+ 5 + 2
	};
	a = 2;
	std::cout << myinc2(7) << std::endl;//14

	//[&total, factor]
	//[factor, &totak]
	//[&, factor]
	//[=, &total]

	std::cout << inc.myFunc(3) << std::endl;//8
	std::cout << "____________________________" << std::endl;

	std::vector<int> vec{ 1, -4, 3 , -2 };
	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());

	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end(), [](int a, int  b) {
		return std::abs(a) > std::abs(b);
		});
	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	Printer f;
	f.printDefault();


}