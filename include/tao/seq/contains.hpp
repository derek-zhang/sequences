// Copyright (c) 2017 Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/sequences/

#ifndef TAOCPP_SEQUENCES_INCLUDE_CONTAINS_HPP
#define TAOCPP_SEQUENCES_INCLUDE_CONTAINS_HPP

#include "integer_sequence.hpp"
#include "is_any.hpp"
#include "sequence_helper.hpp"

namespace tao
{
   namespace seq
   {
      namespace impl
      {
         template< typename T >
         struct contains
         {
            template< T N, T... Ns >
            using type = is_any< ( N == Ns )... >;
         };

         template< typename T, T... Ns >
         struct contains< integer_sequence< T, Ns... > >
         {
            template< T N >
            using type = is_any< ( N == Ns )... >;
         };
      }

      template< typename T, typename impl::element_type< T >::type N, typename impl::element_type< T >::type... Ns >
      using contains = typename impl::contains< T >::template type< N, Ns... >;
   }
}

#endif  // TAOCPP_SEQUENCES_INCLUDE_CONTAINS_HPP
