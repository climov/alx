
export module alx.trig:bams;

import std;
import :angle;

namespace alx::trig {

//! Binary angular measurement (BAM) unit.
export template <std::integral N>
struct BinaryAngularMeasurement
{
    using Rep = N;
    // FIXME: fullCircle cannot be represented, figure out a way to work around this
    static constexpr auto fullCircle = std::is_signed_v<N> ? (std::numeric_limits<N>::max() + 1) * 2 : std::numeric_limits<N>::max() + 1;
};

//! Angles measured in BAMS
export template <std::integral Rep>
using Bam = Angle<Rep, BinaryAngularMeasurement<Rep>>;

export using Bam8   = Bam<std::uint8_t>;
export using Bam8s  = Bam<std::int8_t>;
export using Bam16  = Bam<std::uint16_t>;
export using Bam16s = Bam<std::int16_t>;
export using Bam32  = Bam<std::uint32_t>;
//export using Bam32s = Bam<std::int32_t>;
//export using Bam64  = Bam<std::uint64_t>;
//export using Bam64s = Bam<std::int64_t>;

export inline namespace literals {
inline namespace bam_literals {

constexpr Bam8   operator ""_bam8  (unsigned long long int v) { return {static_cast<std::uint8_t>(v)}; }
constexpr Bam8s  operator ""_bam8s (unsigned long long int v) { return {static_cast<std::int8_t>(v)}; }
constexpr Bam16  operator ""_bam16 (unsigned long long int v) { return {static_cast<std::uint16_t>(v)}; }
constexpr Bam16s operator ""_bam16s(unsigned long long int v) { return {static_cast<std::int16_t>(v)}; }
constexpr Bam32  operator ""_bam32 (unsigned long long int v) { return {static_cast<std::uint32_t>(v)}; }
//constexpr Bam32s operator ""_bam32s(unsigned long long int v) { return {static_cast<std::int32_t>(v)}; }
//constexpr Bam64  operator ""_bam64 (unsigned long long int v) { return {static_cast<std::uint64_t>(v)}; }
//constexpr Bam64s operator ""_bam64s(unsigned long long int v) { return {static_cast<std::int64_t>(v)}; }

} // namespace bam_literals
} // namespace literals

} // namespace alx::trig
