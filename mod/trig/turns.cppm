
export module alx.trig:turns;

import std;
import alx.concepts;
import :angle;

namespace alx::trig {

//! Turn angle unit. There is 1 turn in a full circle
template <concepts::Arithmetic N = float>
struct Turn
{
    using Rep = N;
    static constexpr N fullCircle = 1;
};

//! Angles measured in turns
template <concepts::Arithmetic Rep = float>
using Turns = Angle<Rep, Turn<Rep>>;
//! Angles represented with floats and measured in turns
using TurnsF = Turns<float>;

//! Angles measured in centiturns
template <concepts::Arithmetic Rep = float>
using CentiTurns = Angle<Rep, Turn<Rep>, std::centi>;
//! Angles represented with floats and measured in centiturns
using CentiTurnsF = CentiTurns<float>;

//! Angles measured in milliturns
template <concepts::Arithmetic Rep = float>
using MilliTurns = Angle<Rep, Turn<Rep>, std::milli>;
//! Angles represented with floats and measured in milliturns
using MilliTurnsF = MilliTurns<float>;

inline namespace literals {
inline namespace turn_literals {

//! Literals for turns, centiturns and milliturns

constexpr TurnsF operator ""_turn(long double v) { return TurnsF {static_cast<float>(v)}; }
constexpr TurnsF operator ""_turn(unsigned long long int v) { return TurnsF {static_cast<float>(v)}; }

constexpr CentiTurnsF operator ""_cturn(long double v) { return CentiTurnsF {static_cast<float>(v)}; }
constexpr CentiTurnsF operator ""_cturn(unsigned long long int v) { return CentiTurnsF {static_cast<float>(v)}; }

constexpr MilliTurnsF operator ""_mturn(long double v) { return MilliTurnsF {static_cast<float>(v)}; }
constexpr MilliTurnsF operator ""_mturn(unsigned long long int v) { return MilliTurnsF {static_cast<float>(v)}; }

//! Alternate literals: PLA - Plenus Angulus

constexpr TurnsF operator ""_pla(long double v) { return TurnsF {static_cast<float>(v)}; }
constexpr TurnsF operator ""_pla(unsigned long long int v) { return TurnsF {static_cast<float>(v)}; }

constexpr CentiTurnsF operator ""_cpla(long double v) { return CentiTurnsF {static_cast<float>(v)}; }
constexpr CentiTurnsF operator ""_cpla(unsigned long long int v) { return CentiTurnsF {static_cast<float>(v)}; }

constexpr MilliTurnsF operator ""_mpla(long double v) { return MilliTurnsF {static_cast<float>(v)}; }
constexpr MilliTurnsF operator ""_mpla(unsigned long long int v) { return MilliTurnsF {static_cast<float>(v)}; }

} // namespace turn_literals
} // namespace literals

} // namespace alx::trig
