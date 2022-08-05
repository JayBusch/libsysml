#include "element_def.hpp"
#include "config_kerml.hpp"

namespace kerml { namespace element
{
    BOOST_SPIRIT_INSTANTIATE(element_type, iterator_type, context_type);
}}
