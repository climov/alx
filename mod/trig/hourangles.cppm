
export module alx.trig:hourangles;

import std;
import alx.concepts;
import :angle;

namespace alx::trig {

//! Hour angle unit. There are 24 hour angles in a full circle
template <concepts::Arithmetic N = float>
struct HourAngle
{
    using Rep = N;
    static constexpr N fullCircle = 24;
};

//! Angles measured in hours
template <concepts::Arithmetic Rep = float>
using Hours = Angle<Rep, HourAngle<Rep>>;
//! Angles represented as floats and measured in hours
using HoursF = Hours<float>;

//! Ratio for the minute of time division for hour angles
using MinuteOfTime = std::ratio<1, 60>;

//! Angles measured in minutes of time
template <concepts::Arithmetic Rep = float>
using MinutesOfTime = Angle<Rep, HourAngle<Rep>, MinuteOfTime>;
//! Angles represented as floats and measured in minutes of time
using MinutesOfTimeF = MinutesOfTime<float>;

//! Ratio for the second of time division for hour angles
using SecondOfTime = std::ratio<1, 60*60>;

//! Angles measured in seconds of time
template <concepts::Arithmetic Rep = float>
using SecondsOfTime = Angle<Rep, HourAngle<Rep>, SecondOfTime>;
//! Angles represented as floats and measured in seconds of time
using SecondsOfTimeF = SecondsOfTime<float>;

inline namespace literals {
inline namespace hourangle_literals {

constexpr HoursF operator ""_hr(long double v) { return HoursF {static_cast<float>(v)}; }
constexpr HoursF operator ""_hr(unsigned long long int v) { return HoursF {static_cast<float>(v)}; }

constexpr MinutesOfTimeF operator ""_min(long double v) { return MinutesOfTimeF {static_cast<float>(v)}; }
constexpr MinutesOfTimeF operator ""_min(unsigned long long int v) { return MinutesOfTimeF {static_cast<float>(v)}; }

constexpr SecondsOfTimeF operator ""_sec(long double v) { return SecondsOfTimeF {static_cast<float>(v)}; }
constexpr SecondsOfTimeF operator ""_sec(unsigned long long int v) { return SecondsOfTimeF {static_cast<float>(v)}; }

} // namespace hourangle_literals
} // namespace literals

} // namespace alx::trig
