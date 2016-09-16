#include <boost/python.hpp>
#include <utility>

class vec2 {
public:
    vec2() = default;
    vec2& operator=(vec2&) = default;
    vec2(float x, float y) {
        m_ix_ = x;
        m_iy_ = y;
    }
    float length(vec2 &other_vec);
    vec2 get_sqr() {
        vec2 result(m_ix_ * m_ix_, m_iy_ * m_iy_);
        return std::move(result);
    }
    inline float get_x() const {
        return m_ix_;
    }
    inline float get_y() const {
        return m_iy_;
    }
private:
    float m_ix_;
    float m_iy_;
};

float vec2::length(vec2 &other_vec) {
    float result1 = get_x() * get_x() + get_y() * get_y();
    float result2 = other_vec.get_x() * other_vec.get_x() + other_vec.get_y() * other_vec.get_y();
    return result1 - result2;
}


class Pvec2 : public vec2{
};


BOOST_PYTHON_MODULE(test) {
    using namespace boost::python;
    class_<Pvec2, bases<vec2> >("Pvec2")
        .def("length", &Pvec2::length);
}
