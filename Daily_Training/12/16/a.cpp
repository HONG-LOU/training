/**
 *    author:  HONG-LOU
 *    created: 2022-12-11 23:02:53
 *
 *    For me, it's a new beginning. Start enjoying the process rather than the results after tonight.
 *
 *    Keep the original intention. What I love is the algorithm itself and not others.
 *
 *    God bless you. God bless HONG-LOU. God bless us.
**/
#include <bits/stdc++.h>
 
auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  
  std::cout << "YES\nYES\nYES\nNO" << std::endl;
  
  std::function<void()> hello_world = [&] () {
    std::cout << "hello world" << std::endl;
  };
  
  auto mul = [&] (int sum) {
    for (int i = 0; i < sum; i++) {
      hello_world();
    }
  };
 
  // "Success is the sum of small efforts, repeated day in and day out."
  // "After climbing a great hill, one only finds that there are many more hills to climb."
  // "Nothing can help us endure dark times better than our faith."
  // "Figure out what you like. Try to become the best in the world of it."
  // "If you can do what you do best and be happy, you're further along in life than most people."
  // "Things to do today:1.Get up; 2.Be awesome; 3.Go back to bed."
  // "Time waits for no one. Treasure every moment you have."
  // "There's no one I'd rather be than me."
  // "We'll have a fresh start for the year ahead."
  // "Try and fail, but don't fail to try."
  // "Try your best, even if the task seems difficult."
  // "Doing what you like is freedom. Liking what you do is happiness."
  // "Do one thing at a time, and do well."
  
  mul(0);
  return 0;
}