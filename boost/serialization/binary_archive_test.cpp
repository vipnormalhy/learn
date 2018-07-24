#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class CEntity {
	private:
		friend boost::serialization::access;
		template<typename Archive>
		void serialize(Archive &ar, const unsigned int version) {
			ar & hp;
			ar & mp;
		}

		unsigned int hp = 0;
		unsigned int mp = 0;
	public:
		inline void mod_hp(int value) {hp += value;}
		inline void mod_mp(int value) {mp += value;}
		inline unsigned int get_hp() {return hp;}
		inline unsigned int get_mp() {return mp;}
};

BOOST_CLASS_VERSION(CEntity, 0);

std::ostringstream &pack_binary_archive(CEntity &entity, std::ostringstream &oss) {
	boost::archive::binary_oarchive oa(oss);
	oa << entity;
	return oss;
}

CEntity unpack_binary_archive(std::ostringstream &oss) {
	assert(oss);

	std::istringstream iss(oss.str());
	boost::archive::binary_iarchive ia(iss);

	CEntity entity;
	ia >> entity;
	return entity;
}


void binary_archive_test() {
	printf("Start binary serialization test-------------\n");
	CEntity monster;
	monster.mod_hp(100);
	monster.mod_mp(100);
	std::ostringstream oss;
	pack_binary_archive(monster, oss);

	CEntity monster2;
	std::cout << "hp is " << monster2.get_hp() << std::endl;
	std::cout << "mp is " << monster2.get_mp() << std::endl;
	monster2 = unpack_binary_archive(oss);
	std::cout << "hp is " << monster2.get_hp() << std::endl;
	std::cout << "mp is " << monster2.get_mp() << std::endl;
	printf("Stop binary serialization test-------------\n");
}


bool dump_archive_to_file(CEntity &entity, std::string &filename) {
	std::ofstream ofs(filename.c_str());
	boost::archive::text_oarchive oa(ofs);
	oa << entity;
	ofs.close();
	return true;
}

bool restore_from_archive_file(CEntity &entity, std::string &filename) {
	std::ifstream ifs(filename.c_str());
	boost::archive::text_iarchive ia(ifs);
	ia >> entity;
	return true;
}

void text_archive_test() {
	printf("Start text serialization test-------------\n");
	CEntity monster;
	monster.mod_hp(100);
	monster.mod_mp(100);

	std::string filename("dump_entity.data");
	dump_archive_to_file(monster, filename);
	CEntity monster2;
	std::cout << "hp is " << monster2.get_hp() << std::endl;
	std::cout << "mp is " << monster2.get_mp() << std::endl;
	restore_from_archive_file(monster2, filename);
	std::cout << "hp is " << monster2.get_hp() << std::endl;
	std::cout << "mp is " << monster2.get_mp() << std::endl;
	printf("Stop text serialization test-------------\n");
}


int main() {
	binary_archive_test();
	text_archive_test();
	return 0;
}
