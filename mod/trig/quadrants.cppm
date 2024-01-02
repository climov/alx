
export module alx.trig:quadrants;

import alx.concepts;
import :angle;

namespace alx::trig {

//! Quadrant unit. There are 4 quadrants in a full circle
template <concepts::Arithmetic N = float>
struct Quadrant
{
    using Rep = N;
    static constexpr N fullCircle = 4;
};

//! Angles measured in quadrants
template <concepts::Arithmetic Rep = float>
using Quadrants = Angle<Rep, Quadrant<Rep>>;
//! Angles represented as floats and measured in quadrants
using QuadrantsF = Quadrants<float>;

inline namespace literals {
inline namespace quadrant_literals {

constexpr QuadrantsF operator ""_quadrants(long double v) { return QuadrantsF {static_cast<float>(v)}; }
constexpr QuadrantsF operator ""_quadrants(unsigned long long int v) { return QuadrantsF {static_cast<float>(v)}; }

} // namespace quadrant_literals
} // namespace literals

} // namespace alx::trig
