#include <iostream>
#include <vector>
#include <memory>

class MyClass
{
public:
	MyClass(int data) : data_(data)
	{
		std::cout << "Constructing MyClass with data: " << data_ << std::endl;
	}

	~MyClass()
	{
		std::cout << "Destructing MyClass with data: " << data_ << std::endl;
	}

	void processData()
	{
		std::cout << "Processing data: " << data_ << std::endl;
		// Perform data processing...
	}

private:
	int data_;
};

int main()
{
	std::cout << "Creating vector of MyClass objects" << std::endl;

	std::vector<std::unique_ptr<MyClass>> myObjects;

	// Add objects to the vector
	myObjects.emplace_back(std::make_unique<MyClass>(1));
	myObjects.emplace_back(std::make_unique<MyClass>(2));
	myObjects.emplace_back(std::make_unique<MyClass>(3));

	std::cout << "Processing objects" << std::endl;

	// Process each object in the vector
	for (const auto &obj : myObjects)
	{
		obj->processData();
	}

	std::cout << "End of program" << std::endl;

	return 0;
}
