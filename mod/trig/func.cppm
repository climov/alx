
export module alx.trig:func;

import std;
import alx.concepts;
import :radians;

namespace alx::trig {

export template <concepts::Angle A> auto               sin(const A a)                           { using std::sin; return sin(cast<Rad<typename A::Rep>>(a).value); }
export template <concepts::Angle A> auto               cos(const A a)                           { using std::cos; return cos(cast<Rad<typename A::Rep>>(a).value); }
export template <concepts::Angle A> auto               tan(const A a)                           { using std::tan; return tan(cast<Rad<typename A::Rep>>(a).value); }
export template <concepts::Arithmetic Rep> Rad<Rep>   asin(const Rep value)                     { return {static_cast<Rep>(std::asin(value))}; }
export template <concepts::Arithmetic Rep> Rad<Rep>   acos(const Rep value)                     { return {static_cast<Rep>(std::acos(value))}; }
export template <concepts::Arithmetic Rep> Rad<Rep>   atan2(const Rep valY, const Rep valX)     { return {static_cast<Rep>(std::atan2(valY, valX))}; }

} // namespace alx::trig
