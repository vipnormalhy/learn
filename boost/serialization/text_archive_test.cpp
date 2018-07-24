#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class CEntity {
	private:
		friend boost::serialization::access;
		template<typename Archive> void serialize(Archive &ar, const unsigned int version) {
			ar & hp;
			ar & mp;
		}
		unsigned int hp = 0;
		unsigned int mp = 0;
	public:
		inline void mod_hp(int value) {hp += value;}
		inline void mod_mp(int value) {mp += value;}
};

BOOST_CLASS_VERSION(CEntity, 0);

int main() {
	CEntity monster;
	monster.mod_hp(100);
	monster.mod_mp(50);

	std::ofstream ofs("./EntityClass.data");
	boost::archive::text_oarchive ar(ofs);
	ar << monster;
	ofs.close();
	return 0;
}
