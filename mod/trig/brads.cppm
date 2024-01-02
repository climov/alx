
export module alx.trig:brads;

import alx.concepts;
import :angle;

namespace alx::trig {

//! Binary radian (brad) unit. There are 256 brads in a full circle
export template <concepts::Arithmetic N = float>
struct BinaryRadian
{
    using Rep = N;
    static constexpr N fullCircle = 256;
};

//! Angles measured in brads
export template <concepts::Arithmetic Rep = float>
using Brad = Angle<Rep, BinaryRadian<Rep>>;
//! Angles represented as floats and measured in hours
export using BradF = Brad<float>;

export inline namespace literals {
inline namespace brad_literals {

constexpr BradF operator ""_brad(long double v) { return BradF {static_cast<float>(v)}; }
constexpr BradF operator ""_brad(unsigned long long int v) { return BradF {static_cast<float>(v)}; }

} // namespace brad_literals
} // namespace literals

} // namespace alx::trig
