#include<iostream>
#include<string>

class Entity
{
public:
	virtual std::string getName() const { return "Entity";}	
private:
};


class DerivedFromEntity : public Entity
{
public:
	DerivedFromEntity() {}
	DerivedFromEntity(std::string name) : name_(name) {}
	std::string getName() const override final {
		return name_;
	}
private:
	std::string name_;
};

static void printName(Entity* object) {
	std::cout << object->getName() << std::endl;
}
/*
class derived3 : public DerivedFromEntity
{
public:
	derived3();
	~derived3();

	std::string getName() const override {
		std::cout << "\b Clearly this is a bug";
	}

private:

};

derived3::derived3()
{
}

derived3::~derived3()
{
}
*/
int main() {
	Entity *e = new Entity();
	printName(e);
	DerivedFromEntity* d = new DerivedFromEntity("DerivedEntity");
	printName(d);
}
