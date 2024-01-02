
export module alx.trig:sextants;

import alx.concepts;
import :angle;

namespace alx::trig {

//! Sextant unit. There are 6 sextants in a full circle
template <concepts::Arithmetic N = float>
struct Sextant
{
    using Rep = N;
    static constexpr N fullCircle = 6;
};

//! Angles measured in sextants
template <concepts::Arithmetic Rep = float>
using Sextants = Angle<Rep, Sextant<Rep>>;
//! Angles represented as floats and measured in quadrants
using SextantsF = Sextants<float>;

inline namespace literals {
inline namespace sextant_literals {

constexpr SextantsF operator ""_sextants(long double v) { return SextantsF {static_cast<float>(v)}; }
constexpr SextantsF operator ""_sextants(unsigned long long int v) { return SextantsF {static_cast<float>(v)}; }

} // namespace sextant_literals
} // namespace literals

} // namespace alx::trig
