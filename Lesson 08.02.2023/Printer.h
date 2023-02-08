#pragma once

namespace Engine{
class Printer{
public:
	void printDefault();
	void printavto(std::shared_ptr<Ivehicle>& vec);
private:
	std::shared_ptr<Ivehicle> vec;
};

}
class Ivehicle {
public:
	virtual int getSpeed() const = 0;
	virtual void printType()const = 0;
	virtual ~Ivehicle() {}

};