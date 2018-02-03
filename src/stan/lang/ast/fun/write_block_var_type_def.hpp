#ifndef STAN_LANG_AST_FUN_WRITE_BLOCK_VAR_TYPE_DEF_HPP
#define STAN_LANG_AST_FUN_WRITE_BLOCK_VAR_TYPE_DEF_HPP

#include <stan/lang/ast/fun/write_block_var_type.hpp>
#include <boost/variant.hpp>

namespace stan {
  namespace lang {

    std::ostream& write_block_var_type(std::ostream& o, block_var_type type) {
      block_var_type el_type = type;
      if (type.is_array_type()) {
        o << type.array_dims()
          << "-dim array of "
          << type.array_contains().name();
        el_type = type.array_contains();
      } else {
        o << type.name();
      }
      if (el_type.has_def_bounds()) {
        range bounds = el_type.bounds();
        o << "<";
        if (bounds.has_low())
          o << " lower";
        if (bounds.has_low() && bounds.has_high())
          o << ",";
        if (bounds.has_high())
          o << " upper";
        o << ">";
      }
      return o;
    }
  }
}

#endif
