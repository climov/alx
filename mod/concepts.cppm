
export module alx.concepts;

import std;

namespace alx::concepts {

//! Arithmetic types have the full range of arithmetic operations and are comparable both for equality and inequality
export template <typename T>
concept Arithmetic = requires (T a, T b) {
    { +a } -> std::convertible_to<T>;
    { -a } -> std::convertible_to<T>;
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
    { a / b } -> std::convertible_to<T>;
    { a += b } -> std::convertible_to<T>;
    { a -= b } -> std::convertible_to<T>;
    { a *= b } -> std::convertible_to<T>;
    { a /= b } -> std::convertible_to<T>;
    requires std::equality_comparable<T>;
    requires std::three_way_comparable<T>;
};

using std::sqrt;

export template <typename T>
concept HasSquareRoot = requires (T a) {
    requires Arithmetic<T>;
    { sqrt(a) } -> std::convertible_to<T>;
};

//! Concept associated to std::ratio
export template <typename T>
concept Ratio = std::is_same_v<typename T::type, std::ratio<T::num, T::den>>;

//! Angle Units have:
//!     * a type member named Rep that is the type of their Arithmetic representation
//!     * a static constexpr member variable named fullCircle of type Rep, representing the number of units in a circle
export template <typename T, typename Rep = typename T::Rep>
concept AngleUnit = requires {
    requires Arithmetic<Rep>;
    requires Arithmetic<typename T::Rep>;
    requires std::same_as<Rep, typename T::Rep>;
    { T::fullCircle } -> std::convertible_to<Rep>;
};

//! Angles have:
//!     * a type member named Rep that is the type of their Arithmetic representation
//!     * a type member named Unit that is the type of their Angle Unit, with the same representation as the angle
//!     * a type member named Ratio that is the Ratio used for multiples/subdivisions
//!     * a member variable named value of type Rep, representing the actual measure of the angle
export template <typename T>
concept Angle = requires (T a) {
    requires Arithmetic<typename T::Rep>;
    requires AngleUnit<typename T::Unit, typename T::Rep>;
    requires Ratio<typename T::Ratio>;
    { a.value } -> std::convertible_to<typename T::Rep>;
};

} // namespace alx::concepts
