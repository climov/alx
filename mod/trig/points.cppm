
export module alx.trig:points;

import std;
import alx.concepts;
import :angle;

namespace alx::trig {

//! Compass point/wind unit. There are 32 compass points/winds in a full circle
template <concepts::Arithmetic N = float>
struct CompassPoint
{
    using Rep = N;
    static constexpr N fullCircle = 32;
};

//! Angles measured in compass poins
template <concepts::Arithmetic Rep = float>
using Points = Angle<Rep, CompassPoint<Rep>>;
//! Angles represented as floats and measured in hours
using PointsF = Points<float>;

//! Alternate name for compass points: wind
template <concepts::Arithmetic Rep = float>
using Wind = Points<Rep>;
using WindF = PointsF;

//! Ratio for the quarter point division for points
using QuarterPoint = std::ratio<1, 4>;

//! Angles measured in quarter points
template <concepts::Arithmetic Rep = float>
using QuarterPoints = Angle<Rep, CompassPoint<Rep>, QuarterPoint>;
//! Angles represented as floats and measured in quarter points
using QuarterPointsF = QuarterPoints<float>;

inline namespace literals {
inline namespace point_literals {

constexpr PointsF operator ""_points(long double v) { return PointsF {static_cast<float>(v)}; }
constexpr PointsF operator ""_points(unsigned long long int v) { return PointsF {static_cast<float>(v)}; }

constexpr WindF operator ""_wind(long double v) { return WindF {static_cast<float>(v)}; }
constexpr WindF operator ""_wind(unsigned long long int v) { return WindF {static_cast<float>(v)}; }

constexpr QuarterPointsF operator ""_qpoints(long double v) { return QuarterPointsF {static_cast<float>(v)}; }
constexpr QuarterPointsF operator ""_qpoints(unsigned long long int v) { return QuarterPointsF {static_cast<float>(v)}; }

} // namespace point_literals
} // namespace literals

} // namespace alx::trig
