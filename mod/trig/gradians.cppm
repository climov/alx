
export module alx.trig:gradians;

import std;
import alx.concepts;
import :angle;

namespace alx::trig {

//! Gradian angle unit. There are 400 gradians in a full circle
export template <concepts::Arithmetic N = float>
struct Gradian
{
    using Rep = N;
    static constexpr N fullCircle = 400;
};

//! Angles measured in gradians
export template <concepts::Arithmetic Rep = float>
using Gradians = Angle<Rep, Gradian<Rep>>;
//! Angles represented with floats and measured in gradians
export using GradiansF = Gradians<float>;

//! Shorthand aliases for Gradians/GradiansF
export template <concepts::Arithmetic Rep = float>
using Grad = Gradians<Rep>;
export using GradF = GradiansF;

//! Alternate names for gradians
export template <concepts::Arithmetic Rep = float>
using Gon = Gradians<Rep>;
export using GonF = GradiansF;

//! Angles measured in centigradians
export template <concepts::Arithmetic Rep = float>
using CentiGradians = Angle<Rep, Gradian<Rep>, std::centi>;
//! Angles represented with floats and measured in centigradians
export using CentiGradiansF = CentiGradians<float>;

//! Shorhand aliases for CentiGradians/CentiGradiansF
export template <concepts::Arithmetic Rep = float>
using CentiGrad = CentiGradians<Rep>;
export using CentiGradF = CentiGradiansF;

//! Alternate names for centigradians
export template <concepts::Arithmetic Rep = float>
using CentiGon = CentiGradians<Rep>;
export using CentiGonF = CentiGradiansF;

export inline namespace literals {
inline namespace gradian_literals {

//! Literals for gradians and centiradians

constexpr GradF operator ""_grad(long double v) { return GradF {static_cast<float>(v)}; }
constexpr GradF operator ""_grad(unsigned long long int v) { return GradF {static_cast<float>(v)}; }

constexpr CentiGradF operator ""_cgrad(long double v) { return CentiGradF {static_cast<float>(v)}; }
constexpr CentiGradF operator ""_cgrad(unsigned long long int v) { return CentiGradF {static_cast<float>(v)}; }

constexpr GonF operator ""_gon(long double v) { return GradF {static_cast<float>(v)}; }
constexpr GonF operator ""_gon(unsigned long long int v) { return GradF {static_cast<float>(v)}; }

constexpr CentiGonF operator ""_cgon(long double v) { return CentiGradF {static_cast<float>(v)}; }
constexpr CentiGonF operator ""_cgon(unsigned long long int v) { return CentiGradF {static_cast<float>(v)}; }

} // namespace gradian_literals
} // namespace literals

} // namespace alx::trig
