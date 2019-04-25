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

void test_member_archive() {
	CEntityQueue entity_queue;
	CEntity &entity = entity_queue.get_head();
	entity.mod_hp(100);
	entity.mod_mp(50);
	CEntity &entity2 = entity_queue.get_end();
	entity2.mod_hp(1000);
	entity2.mod_mp(30);
	CEntity *pentity = entity_queue.get_middle();
	if (pentity) {
		pentity->mod_hp(3576);
		pentity->mod_mp(876);
	}

	std::cout << "head hp is " << entity_queue.get_head().get_hp() << "head mp is " << entity_queue.get_head().get_mp() << std::endl;
	std::cout << "head hp is " << entity_queue.get_end().get_hp() << "head mp is " << entity_queue.get_end().get_mp() << std::endl;
	std::cout << "head hp is " << entity_queue.get_middle()->get_hp() << "head mp is " << entity_queue.get_middle()->get_mp() << std::endl;

	std::stringstream ss;
	boost::archive::binary_oarchive oa(ss);
	oa << entity_queue;

	CEntityQueue entity_queue2;
	boost::archive::binary_iarchive ia(ss);
	ia >> entity_queue2;
	std::cout << "head hp is " << entity_queue2.get_head().get_hp() << "head mp is " << entity_queue2.get_head().get_mp() << std::endl;
	std::cout << "head hp is " << entity_queue2.get_end().get_hp() << "head mp is " << entity_queue2.get_end().get_mp() << std::endl;
	std::cout << "head hp is " << entity_queue.get_middle()->get_hp() << "head mp is " << entity_queue.get_middle()->get_mp() << std::endl;
}

void test_derived_archive() {
	CMonster monster;
	monster.mod_hp(10000);
	monster.mod_mp(500);
	std::string name("test");
	monster.set_name(name);

	std::stringstream ss;
	boost::archive::binary_oarchive oa(ss);
	oa << monster;

	CMonster monster2;
	boost::archive::binary_iarchive ia(ss);
	ia >> monster2;

	std::cout << "hp is " << monster2.get_hp() << " mp is " << monster2.get_mp() << std::endl;
	std::cout << "name is " << monster2.get_name() << std::endl;
}

int main() {
	test_archive();
	test_member_archive();
	test_derived_archive();
	return 0;
}