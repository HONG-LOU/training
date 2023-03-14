/**
 *    author:  HONG-LOU
 *    created: 2023-02-19 17:53:52
 **/
#include <bits/stdc++.h>

auto main() -> int
{
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

  auto change = [&] (std::string resource_str, std::string sub_str, std::string new_str) {
    std::string dst_str = resource_str;
    std::string::size_type pos = 0;
    while ((pos = dst_str.find(sub_str)) != std::string::npos) {
      dst_str.replace(pos, sub_str.length(), new_str);
    }
    return dst_str;
  };
  std::string s = "helloworldhelloworlddfdjskhello";
  s = change(s, "hello", "world");
  std::cout << s << "\n";
  return 0;
}