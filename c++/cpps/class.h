#ifndef LEARN_CPP_CLASS_H
#define LEARN_CPP_CLASS_H

#include <iostream>
#include <string>

class TestObject {
public:
	//TestObject();
	TestObject() = default;
	//TestObject(int, int, std::string);
	explicit TestObject(int ref_t) : ref(ref_t) {};
	// TestObject(int):TestObject(1, "") {};
	const unsigned int get_ref_amount();
	inline const std::string get_path() {return object_path;};
	void tie_test();
private:
	unsigned int ref;
	std::string object_path;
	const static int ref_num = 0;
	int d;
};

#endif
