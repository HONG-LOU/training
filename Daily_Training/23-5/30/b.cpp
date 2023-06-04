#include <bits/stdc++.h>

int main () {
    std::string a = "a、o、e、i、u、ü、ai 、ei、 ui 、ao、 ou、 iu 、ie 、üe、 er、 an 、en 、in、 un 、ün 、ang 、eng、 ing 、ong";
        std::string b = "b、p、m、f、d、t、n、l、g、k、h、j、q、x、zh、ch、sh、r、z、c、s、y、w";
            for (int i = 0; i < (int) a.size(); i++) {
                    if (a[i] == '、') {
                                std::cout << ' ';
                                            continue;
                                                    }
                                                            std::cout << a[i];
                                                                }
                                                                    for (int i = 0; i < (int) b.size(); i++) {
                                                                            if (b[i] == '、') {
                                                                                        std::cout << ' ';
                                                                                                    continue;
                                                                                                            }
                                                                                                                    std::cout << b[i];
                                                                                                                        }
                                                                                                                        }