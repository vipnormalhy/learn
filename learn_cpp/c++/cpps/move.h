#ifndef LEARN_MOVE_H
#define LEARN_MOVE_H

#include <utility>
#include <vector>
#include <memory>
#include <initializer_list>

class Movetest
{
public:
	Movetest() = default;
	//Movetest(void *p) : pv(nullptr) {};
	explicit Movetest(Movetest &movetest);
	explicit Movetest(Movetest &&movetest) noexcept;
	~Movetest() = default;
	Movetest &operator=(const Movetest &movetest) &;
	Movetest &operator=(Movetest &&movetest) & noexcept;
	int malloc(const std::initializer_list<int> vi);
private:
	std::shared_ptr<std::vector<int>> pv;
};

#endif
