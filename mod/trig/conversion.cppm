
export module alx.trig:conversion;

import alx.concepts;
import :pi;

namespace alx::trig {

//! convert degrees to radians
template <concepts::Arithmetic T>
constexpr T degToRad(const T deg)
{
    return deg * pi_v<T> / 180;
}

//! convert radians to degrees
template <concepts::Arithmetic T>
constexpr T radToDeg(const T rad)
{
    return rad * 180 / pi_v<T>;
}

} // namespace alx::trig
