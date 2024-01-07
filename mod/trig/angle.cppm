
export module alx.trig:angle;

import std;
import alx.concepts;

namespace alx::trig {

//! Class that represents an angle, with Arithmetic representation, unit and ratio
export template <concepts::Arithmetic Rep_, concepts::AngleUnit<Rep_> Unit_, concepts::Ratio Ratio_ = std::ratio<1>>
struct Angle
{
    //! Representation
    using Rep = Rep_;
    //! Unit
    using Unit = Unit_;
    //! Ratio
    using Ratio = typename Ratio_::type;

    //! Angle value, in the given Representation, Unit and Ratio
    Rep value = {};

    //! Casting
    template <concepts::Angle Other>
    constexpr /*explicit*/ operator Other() const;

    //! Arithmetic assignment operators
    constexpr Angle& operator +=(const Angle other) { value += other.value; return *this; }
    constexpr Angle& operator +=(const concepts::Angle auto other) { value += static_cast<Angle>(other).value; return *this; }
    constexpr Angle& operator -=(const concepts::Angle auto other) { value -= static_cast<Angle>(other).value; return *this; }
    constexpr Angle& operator *=(const Rep factor) { value *= factor; return *this; }
    constexpr Angle& operator /=(const Rep factor) { value /= factor; return *this; }

    //! True if the angle is acute: greater than Zero and less than a Right angle
    [[nodiscard]] constexpr bool isAcute() const;
    //! True if the angle is obtuse: greater than a Right angle and less than a Straight angle
    constexpr bool isObtuse() const;
    //! True if the angle is reflex: greater than a Straight angle and less than a Full angle
    constexpr bool isReflex() const;

    //! Returns the complementary angle, that is, the angle that would have to be added to get a Right angle
    constexpr Angle complementary() const;
    //! Returns the supplementary angle, that is, the angle that would have to be added to get a Straight angle
    constexpr Angle supplementary() const;
    //! Returns the conjugate (explementary) angle, that is, the angle that would have to be added to get a Full angle
    constexpr Angle conjugate() const;

    //! Since angles are periodic with respect to a Full angle, we define:
    //!     * the (unsigned) reduced angle as the angle between Zero inclusive and Full exclusive that is congruent with the original
    //!     * the signed reduced angle as the angle between -Straight inclusiv and +Straight exclusive that is congruent with the original

    //! Change the angle to its reduced equivalent and return a reference
    constexpr Angle& reduce() requires std::is_floating_point_v<Rep_>
    {
        using std::fmod;
        value = fmod(value, Unit::fullCircle);
        if (value < 0) {
            value += Unit::fullCircle;
        }
        return *this;
    }

    constexpr Angle& reduce() requires std::is_integral_v<Rep_>
    {
        value %= Unit::fullCircle;
        if (value < 0) {
            value += Unit::fullCircle;
        }
        return *this;
    }

    //! Change the angle to its signed reduced equivalent and return a reference
    constexpr Angle& signedReduce() requires std::is_floating_point_v<Rep_>
    {
        using std::fmod;
        value = fmod(value, Unit::fullCircle);
        if (value >= Unit::fullCircle / 2) {
            value -= Unit::fullCircle;
        } else if (value < Unit::fullCircle / 2) {
            value += Unit::fullCircle;
        }
        return *this;
    }

    constexpr Angle& signedReduce() requires std::is_integral_v<Rep_> && std::is_signed_v<Rep_>
    {
        value %= Unit::fullCircle;
        if (value >= Unit::fullCircle / 2) {
            value -= Unit::fullCircle;
        } else if (value < Unit::fullCircle / 2) {
            value += Unit::fullCircle;
        }
        return *this;
    }

    //! Returns the reduced angle
    constexpr Angle reduced() const requires std::is_floating_point_v<Rep_>
    {
        using std::fmod;
        Rep result = fmod(value, Unit::fullCircle);
        if (result < 0) {
            result += Unit::fullCircle;
        }
        return {result};
    }

    constexpr Angle reduced() const requires std::is_integral_v<Rep_>
    {
        Rep result = value % Unit::fullCircle;
        if (result < 0) {
            result += Unit::fullCircle;
        }
        return {result};
    }

    //! Returns the signed reduced angle
    constexpr Angle signedReduced() const requires std::is_floating_point_v<Rep_>
    {
        using std::fmod;
        Rep result = fmod(value, Unit::fullCircle);
        if (result >= Unit::fullCircle / 2) {
            result -= Unit::fullCircle;
        } else if (result < Unit::fullCircle / 2) {
            result += Unit::fullCircle;
        }
        return {result};
    }

    constexpr Angle signedReduced() const requires std::is_integral_v<Rep_> && std::is_signed_v<Rep_>
    {
        Rep result = value % Unit::fullCircle;
        if (result >= Unit::fullCircle / 2) {
            result -= Unit::fullCircle;
        } else if (result < Unit::fullCircle / 2) {
            result += Unit::fullCircle;
        }
        return {result};
    }
};

namespace impl {

template <typename T> requires concepts::AngleUnit<T> || concepts::Angle<T>
struct Constants
{
    using U = std::conditional_t<concepts::AngleUnit<T>, T, typename T::Unit>;
    //using A = std::conditional_t<concepts::Angle<T>, T, Angle<typename T::Rep, T>>;
    using A = Angle<typename U::Rep, U>;

    static constexpr A Zero = {0};
    static constexpr A Right = {U::fullCircle / 4 * A::Ratio::den / A::Ratio::num};
    static constexpr A Straight = {U::fullCircle / 2 * A::Ratio::den / A::Ratio::num};
    static constexpr A Full = {U::fullCircle * A::Ratio::den / A::Ratio::num};
};

} // namespace impl

//! Zero angle
export template <typename T> requires concepts::AngleUnit<T> || concepts::Angle<T>
constexpr inline auto Zero = impl::Constants<T>::Zero;

//! Right angle (quarter turn)
export template <typename T> requires concepts::AngleUnit<T> || concepts::Angle<T>
constexpr inline auto Right = impl::Constants<T>::Right;

//! Straight angle (half turn)
export template <typename T> requires concepts::AngleUnit<T> || concepts::Angle<T>
constexpr inline auto Straight = impl::Constants<T>::Straight;

//! Full angle (full turn)
export template <typename T> requires concepts::AngleUnit<T> || concepts::Angle<T>
constexpr inline auto Full = impl::Constants<T>::Full;

template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
template <concepts::Angle Other>
constexpr /*explicit*/ Angle<Rep, Unit, Ratio>::operator Other() const
{
    using divRatio = std::ratio_divide<Ratio, typename Other::Ratio>;
    static constexpr auto f = Other::Unit::fullCircle / Unit::fullCircle * divRatio::num / divRatio::den;
    return {static_cast<typename Other::Rep>(value * f)};
}

//! Cast between angles
export template <concepts::Angle Other>
constexpr Other cast(const concepts::Angle auto angle)
{
    return static_cast<Other>(angle);
}

//! Angle addition. The result is *not* reduced
export template <concepts::Angle A1, concepts::Angle A2>
constexpr auto operator +(const A1 a1, const A2 a2)
{
    using Rep = std::common_type_t<typename A1::Rep, typename A2::Rep>;
    using Ret = Angle<Rep, typename A1::Unit, typename A1::Ratio>;
    return Ret {cast<Ret>(a1).value + cast<Ret>(a2).value};
}

//! Angle subtraction. The result is *not* reduced
export template <concepts::Angle A1, concepts::Angle A2>
constexpr auto operator -(const A1 a1, const A2 a2)
{
    using Rep = std::common_type_t<typename A1::Rep, typename A2::Rep>;
    using Ret = Angle<Rep, typename A1::Unit, typename A1::Ratio>;
    return Ret {cast<Ret>(a1).value - cast<Ret>(a2).value};
}

//! Unary plus. Returns the angle unchanged
export constexpr auto operator +(const concepts::Angle auto a)
{
    return a;
}

//! Unary negation. Returns the opposite angle (negated value). The result is *not* reduced
export template <concepts::Angle A>
constexpr A operator -(const A a)
{
    return {-a.value};
}

//! Multiply angle by a scalar factor. The result is *not* reduced
export template <concepts::Angle A, concepts::Arithmetic N>
constexpr auto operator *(const A angle, N factor)
{
    using Rep = std::common_type_t<typename A::Rep, N>;
    using Ret = Angle<Rep, typename A::Unit, typename A::Ratio>;
    return Ret {angle.value * factor};
}

//! Multiply a scalar factor by an angle. The result is *not* reduced
export template <concepts::Angle A, concepts::Arithmetic N>
constexpr auto operator *(N factor, const A angle)
{
    using Rep = std::common_type_t<typename A::Rep, N>;
    using Ret = Angle<Rep, typename A::Unit, typename A::Ratio>;
    return Ret {angle.value * factor};
}

//! Divide and angle by a scalar factor. The result is *not* reduced
export template <concepts::Angle A, concepts::Arithmetic N>
constexpr auto operator /(const A angle, N divisor)
{
    using Rep = std::common_type_t<typename A::Rep, N>;
    using Ret = Angle<Rep, typename A::Unit, typename A::Ratio>;
    return Ret {angle.value / divisor};
}

//! Three-way angle comparison. The comparison is done on the reduced equivalents of the inputs
export template <concepts::Angle A1, concepts::Angle A2>
constexpr auto operator <=>(const A1 a1, const A2 a2)
{
    static constexpr auto f1 = A2::Unit::fullCircle * A1::Ratio::num * A2::Ratio::den;
    static constexpr auto f2 = A1::Unit::fullCircle * A2::Ratio::num * A1::Ratio::den;
    return a1.reduced().value * f1 <=> a2.reduced().value * f2;
}

template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr bool Angle<Rep, Unit, Ratio>::isAcute() const
{
    return *this > Zero<Unit> && *this < Right<Unit>;
}
template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr bool Angle<Rep, Unit, Ratio>::isObtuse() const
{
    return *this > Right<Unit> && *this < Straight<Unit>;
}
template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr bool Angle<Rep, Unit, Ratio>::isReflex() const
{
    return *this > Straight<Unit> && *this < Full<Unit>;
}

template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr Angle<Rep, Unit, Ratio> Angle<Rep, Unit, Ratio>::complementary() const
{
    return Right<Angle<Rep, Unit, Ratio>> - *this;
}
template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr Angle<Rep, Unit, Ratio> Angle<Rep, Unit, Ratio>::supplementary() const
{
    return Straight<Angle<Rep, Unit, Ratio>> - *this;
}
template <concepts::Arithmetic Rep, concepts::AngleUnit<Rep> Unit, concepts::Ratio Ratio>
constexpr Angle<Rep, Unit, Ratio> Angle<Rep, Unit, Ratio>::conjugate() const
{
    return Full<Angle<Rep, Unit, Ratio>> - *this;
}

} // namespace alx::trig
