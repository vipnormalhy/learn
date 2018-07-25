#include <iostream>
#include <sstream>
#include "archive_test.hpp"

void test_archive() {
	CEntity entity;
	entity.mod_hp(100);
	entity.mod_mp(50);

	std::stringstream ss;
	boost::archive::binary_oarchive oa(ss);
	oa << entity;

	CEntity backupentity;
	boost::archive::binary_iarchive ia(ss);
	ia >> backupentity;
	std::cout << "hp is " << backupentity.get_hp() << ",mp is " << backupentity.get_mp() << std::endl;
}

int main() {
	test_archive();
	return 0;
}
