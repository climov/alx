
export module alx.trig:radians;

import std;
import alx.concepts;
import :pi;
import :angle;

export namespace alx::trig {

//! Radian angle unit. There are 2*pi radians in a full circle
template <concepts::Arithmetic N = float>
struct Radian
{
    using Rep = N;
    static constexpr N fullCircle = 2 * pi_v<N>;
};

//! Angles measured in radians
template <concepts::Arithmetic Rep = float>
using Radians = Angle<Rep, Radian<Rep>>;
//! Angles represented with floats and measured in radians
using RadiansF = Radians<float>;

//! Shorthand aliases for Radians/RadiansF
template <concepts::Arithmetic Rep = float>
using Rad = Radians<Rep>;
using RadF = RadiansF;

//! Angles measured in milliradians
template <concepts::Arithmetic Rep = float>
using MilliRadians = Angle<Rep, Radian<Rep>, std::milli>;
//! Angles represented with floats and measured in milliradians
using MilliRadiansF = MilliRadians<float>;

//! Shorhand aliases for MilliRadians/MilliRadiansF
template <concepts::Arithmetic Rep = float>
using MilliRad = MilliRadians<Rep>;
using MilliRadF = MilliRadiansF;

inline namespace literals {
inline namespace radian_literals {

//! Literals for radians and milliradians

constexpr RadF operator ""_rad(long double v) { return RadF {static_cast<float>(v)}; }
constexpr RadF operator ""_rad(unsigned long long int v) { return RadF {static_cast<float>(v)}; }

constexpr MilliRadF operator ""_mrad(long double v) { return MilliRadF {static_cast<float>(v)}; }
constexpr MilliRadF operator ""_mrad(unsigned long long int v) { return MilliRadF {static_cast<float>(v)}; }

} // namespace radian_literals
} // namespace literals

} // namespace alx::trig
