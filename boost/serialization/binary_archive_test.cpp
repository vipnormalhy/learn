#include <sstream>
#include <iostream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

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

int main() {
	CEntity monster;
	monster.mod_hp(100);
	monster.mod_mp(100);

	std::ostringstream oss;
	boost::archive::binary_oarchive oa(oss);
	oa << monster;

	CEntity monster2;
	std::istringstream iss(oss.str());
	boost::archive::binary_iarchive ia(iss);
	ia >> monster2;
	std::cout << monster2.get_hp() << " mp is " << monster2.get_mp() << std::endl;
	return 0;
}
