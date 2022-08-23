//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_TEMPLATE_HPP_
#define _MY_TEMPLATE_HPP_

#include "my_random.hpp"

template < class T, template < typename ELEM, typename ALLOC = std::allocator< ELEM > > class C >

bool contains(C< T > *c, T t)
{
  typename C< T >::iterator i = c->begin();

  while (i != c->end()) {
    if (*i == t) {
      return true;
    }
    i++;
  }
  return false;
}

template < class T, template < typename ELEM, typename ALLOC = std::allocator< ELEM > > class C >

void push_back_if_unique(C< T > &c, T d)
{
  typename C< T >::iterator so = c.begin();
  typename C< T >::iterator eo = c.end();

  while (so != eo) {
    T t = *so;

    if (t == d) {
      return;
    }
    so++;
  }
  c.push_back(d);
}

template < class T, template < typename ELEM, typename ALLOC = std::allocator< ELEM > > class C >
T non_pcg_one_of(C< T > &c)
{
  typename C< T >::iterator so = c.begin();
  typename C< T >::iterator eo = c.end();

  size_t sz = eo - so;
  return *(so + (rand() % sz));
}

template < class T, template < typename ELEM, typename ALLOC = std::allocator< ELEM > > class C >
T pcg_one_of(C< T > &c)
{
  typename C< T >::iterator so = c.begin();
  typename C< T >::iterator eo = c.end();

  size_t sz = eo - so;
  return *(so + (pcg_rand() % sz));
}

// https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
// flips an associative container of A,B pairs to B,A pairs
template < typename A, typename B > std::pair< B, A > flip_pair(const std::pair< A, B > &p)
{
  return std::pair< B, A >(p.second, p.first);
}

template < typename A, typename B, template < class, class, class... > class M, class... Args >
std::multimap< B, A > flip_map(const M< A, B, Args... > &src)
{
  std::multimap< B, A > dst;
  std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair< A, B >);
  return dst;
}

#endif