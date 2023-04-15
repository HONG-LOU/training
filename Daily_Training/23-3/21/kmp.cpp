/**
 *    author:  HONG-LOU
 *    created: 2023-03-21 16:43:02
**/
#include <bits/stdc++.h>

const int maxn = (int) 1e6 + 7;

int kmp[maxn];

char a[maxn], b[maxn];

int lena, lenb;

auto Fkmp () -> std::vector<int> {
  std::vector<int> ans;
  lena = strlen(a + 1);
  lenb = strlen(b + 1);

  for (int i = 2, j = 0; i <= lenb; i++) {
    while (j && b[i] != b[j + 1]) j = kmp[j];

    if (b[j + 1] == b[i]) j++;
    kmp[i] = j;
  }

  for (int i = 1, j = 0; i <= lena; i++) {
    while (j && b[j + 1] != a[i]) j = kmp[j];

    if (b[j + 1] == a[i]) j++;

    if (j == lenb) {
      ans.push_back(i - lenb + 1);
      j = kmp[j];
    }
  }
  return ans;
}

auto Fbf () -> std::vector<int> {
  lena = strlen(a + 1);
  lenb = strlen(b + 1);
  std::vector<int> ans;

  for (int i = 1; i <= lena; i++) {
    for (int j = 1; j <= lenb && (i + j - 1) <= lena; j++) {
      if (b[j] != a[i + j - 1]) {
        break;
      }
      if (j == lenb) {
        ans.push_back(i);
      }
    }
  }
  return ans;
}

auto showFkmp () -> double {
  auto kstart = std::chrono::steady_clock::now();
	Fkmp();
	auto kend = std::chrono::steady_clock::now();
	double kduration_millsecond = std::chrono::duration<double, std::micro>(kend - kstart).count();
  return kduration_millsecond;
}

auto showFbf () -> double {
  auto start = std::chrono::steady_clock::now();
	Fbf();
	auto end = std::chrono::steady_clock::now();
  double duration_millsecond = std::chrono::duration<double, std::micro>(end - start).count();
  return duration_millsecond;
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  freopen("test.txt", "r", stdin);
  scanf("%s %s", a + 1, b + 1);
  fclose(stdin);

  double bfsum = 0, kmpsum = 0;
  for (int i = 0; i < 3000; i++) {
    bfsum += showFbf();
    kmpsum += showFkmp();
  }
  std::cout << "BF Result : " << std::endl;
  auto bfans = Fbf();
  auto kmpans = Fkmp();
  for (int xx : bfans) {
    std::cout << xx << ' ';
  }
  std::cout << std::endl;
  std::cout << "KMP Result : " << std::endl;
  for (int xx : kmpans) {
    std::cout << xx << ' ';
  }
  std::cout << std::endl;
  std::cout << std::fixed;
  std::setprecision(0);
  std::cout << "3000 BF TOTAL TIME :  " << bfsum << " us" << std::endl;
  std::cout << "3000 KMP TOTAL TIME : " << kmpsum << " us" << std::endl;
  return 0;
}

/*
BF Result : 
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
KMP Result :
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
3000 BF TOTAL TIME :  6656826.000000 us
3000 KMP TOTAL TIME : 4643054.000000 us

BF Result : 
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
KMP Result :
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
3000 BF TOTAL TIME :  6974498.000000 us
3000 KMP TOTAL TIME : 4571886.000000 us

BF Result : 
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
KMP Result :
5 27376 94205 157740 192373 242321 275677 313418 360838 422724 464808 492730 547915
3000 BF TOTAL TIME :  6726393.000000 us
3000 KMP TOTAL TIME : 4791403.000000 us
*/