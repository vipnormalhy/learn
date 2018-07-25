#pragma once

#include <iostream>
#include <sstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class CEntity {
	private:
		friend boost::serialization::access;
		template<typename Archive> void save(Archive &ar, const unsigned int version) const;
		template<typename Archive> void load(Archive &ar, const unsigned int version);
		BOOST_SERIALIZATION_SPLIT_MEMBER();
		unsigned int hp = 0;
		unsigned int mp = 0;
		unsigned int sp = 0;
	public:
		inline unsigned int get_hp() {return hp;}
		inline unsigned int get_mp() {return mp;}
		inline bool mod_hp(int value);
		inline bool mod_mp(int value);
};

BOOST_CLASS_VERSION(CEntity, 0);

template<typename Archive>
void CEntity::save(Archive &ar, const unsigned int version) const {
	// avoid error from editor
	if ((int)version < 0) {
		return;
	}
	ar << hp;
	ar << mp;
}

template<typename Archive>
void CEntity::load(Archive &ar, const unsigned int version) {
	// avoid error from editor
	if ((int)version < 0) {
		return;
	}

	ar >> hp;
	ar >> mp;
	ar >> sp;
}
