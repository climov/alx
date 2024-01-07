
add_library(alx STATIC)
target_sources(alx PUBLIC FILE_SET HEADERS FILES include/alx/rassert.h include/alx/trace.h)
target_sources(alx PUBLIC FILE_SET CXX_MODULES FILES
    mod/alx.cppm
    mod/concepts.cppm
    mod/rassert.cppm
    mod/valgebra.cppm
    mod/trig/angle.cppm
    mod/trig/bams.cppm
    mod/trig/brads.cppm
    mod/trig/conversion.cppm
    mod/trig/degrees.cppm
    mod/trig/func.cppm
    mod/trig/gradians.cppm
    mod/trig/hourangles.cppm
    mod/trig/pi.cppm
    mod/trig/points.cppm
    mod/trig/quadrants.cppm
    mod/trig/radians.cppm
    mod/trig/sextants.cppm
    mod/trig/trig.cppm
    mod/trig/turns.cppm
)
if(WIN32)
    target_compile_options(alx PRIVATE
        -Wall -WX
        -experimental:external -external:W0 -external:anglebrackets
        -wd4514
        -wd4820
        -wd5045
        -wd4625 -wd4626 -wd5026 -wd5027
        -wd4244
        -wd4061
        -wd4710 -wd4711
        -wd4738
        -wd4582 -wd4365
        -wd4686
        -wd4746
    )
else()
    target_compile_options(alx PRIVATE
        -Wall -Wextra -Weverything -Werror
        -Wno-c++98-compat -Wno-c++98-compat-pedantic
        -Wno-documentation-unknown-command
        -Wno-padded
        -Wno-exit-time-destructors -Wno-global-constructors
        -Wno-shadow-uncaptured-local
        -Wno-gnu-zero-variadic-macro-arguments
        -Wno-switch-enum
        -Wno-implicit-int-float-conversion
        -Wno-missing-prototypes
    )
endif()
target_include_directories(alx SYSTEM PUBLIC include)
target_link_libraries(alx PUBLIC std)
