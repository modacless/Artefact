#pragma once
#include <string>

#define NO_OF_CHARS 256
using namespace std;

static class PoorTools
{
public:

    // Function to remove occurrence of string
    static void removeOccurrences(string& s, string t)
    {

        int m = t.length();
        int n = s.length();
        int badChar[NO_OF_CHARS];

        preBadChar(t, m, badChar);

        int i = 0;
        while (i <= n - m) {
            int j = m - 1;

            while (j >= 0 && t[j] == s[i + j]) {
                j--;
            }

            if (j < 0) {
                s.erase(i, m);
                n = s.length();
                i += m;
            }
            else {
                i += max(1, j - badChar[s[i + j]]);
            }
        }
    }

private:



    static void preBadChar(string t, int m, int badChar[])
    {
        int i;

        for (i = 0; i < NO_OF_CHARS; i++) {
            badChar[i] = -1;
        }

        for (i = 0; i < m; i++) {
            badChar[(int)t[i]] = i;
        }
    }

};

