/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:03:00
**/
#include <bits/stdc++.h>
#include "show.h"
#include "readG.h"

auto main () -> int {

  read r;

  auto w = r.read_grammar();

  w.print_grammar();

  w.first_check();

  w.print_grammar();

  w.second_check();

  w.print_grammar();
  
  return 0;
}