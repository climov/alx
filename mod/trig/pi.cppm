
export module alx.trig:pi;

import std;
import alx.concepts;

namespace alx::trig {

//! Customization point for the PI constant
export template <typename T>
struct pi_t;

//! Specialization of pi_t for floating point types
export template <std::floating_point F>
struct pi_t<F>
{
    static constexpr F pi_v = std::numbers::pi_v<F>;
};

//! The PI constant
export template <concepts::Arithmetic N>
constexpr N pi_v = pi_t<N>::pi_v;

} // namespace alx::trig
