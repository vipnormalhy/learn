#pragma once

#include <stdlib.h>
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

bool check_value(int value, unsigned int base) {
	if (value >= 0) {
		if (UINT_MAX - base < static_cast<unsigned int>(value)) {
			return false;
		} else {
			return true;
		}
	} else {
		unsigned int abs_value = abs(value);
		if (abs_value > base) {
			return false;
		} else {
			return true;
		}
	}
}

bool CEntity::mod_hp(int value) {
	if (!check_value(value, hp)) {
		return false;
	}
		
	hp += value;
	return true;
}

bool CEntity::mod_mp(int value) {
	if (!check_value(value, mp)) {
		return false;
	}
	mp += value;
	return true;
}
