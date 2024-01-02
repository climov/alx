
export module alx.trig:degrees;

import std;
import alx.concepts;
import :angle;

namespace alx::trig {

//! Degree angle unit. There are 360 degrees in a full circle
export template <concepts::Arithmetic N = float>
struct Degree
{
    using Rep = N;
    static constexpr N fullCircle = 360;
};

//! Angles measured in degrees
export template <concepts::Arithmetic Rep = float>
using Degrees = Angle<Rep, Degree<Rep>>;
//! Angles represented as floats and measured in degrees
export using DegreesF = Degrees<float>;

//! Shorthand aliases for Degrees and DegreesF
export template <concepts::Arithmetic Rep = float>
using Deg = Degrees<Rep>;
export using DegF = DegreesF;

//! Ratio for the arcminute division of degree
export using ArcMinute = std::ratio<1, 60>;

//! Angles measured in arcminutes
export template <concepts::Arithmetic Rep = float>
using ArcMinutes = Angle<Rep, Degree<Rep>, ArcMinute>;
//! Angles represented as floats and measured in arcminutes
export using ArcMinutesF = ArcMinutes<float>;

//! Shorthand aliases for ArcMinutes and ArcMinutesF
export template <concepts::Arithmetic Rep = float>
using ArcMin = ArcMinutes<Rep>;
export using ArcMinF = ArcMinutesF;

//! Ratio for the arcsecond division of degree
export using ArcSecond = std::ratio<1, 60*60>;

//! Angles measured in arcseconds
export template <concepts::Arithmetic Rep = float>
using ArcSeconds = Angle<Rep, Degree<Rep>, ArcSecond>;
//! Angles represented as floats and measured in arcseconds
export using ArcSecondsF = ArcSeconds<float>;

//! Shorthand aliases for ArcSeconds and ArcSecondsF
export template <concepts::Arithmetic Rep = float>
using ArcSec = ArcSeconds<Rep>;
export using ArcSecF = ArcSecondsF;

export inline namespace literals {
inline namespace degree_literals {

constexpr DegF operator ""_deg(long double v) { return DegF {static_cast<float>(v)}; }
constexpr DegF operator ""_deg(unsigned long long int v) { return DegF {static_cast<float>(v)}; }

constexpr ArcMinF operator ""_arcmin(long double v) { return ArcMinF {static_cast<float>(v)}; }
constexpr ArcMinF operator ""_arcmin(unsigned long long int v) { return ArcMinF {static_cast<float>(v)}; }

constexpr ArcSecF operator ""_arcsec(long double v) { return ArcSecF {static_cast<float>(v)}; }
constexpr ArcSecF operator ""_arcsec(unsigned long long int v) { return ArcSecF {static_cast<float>(v)}; }

} // namespace degree_literals
} // namespace literals

} // namespace alx::trig
