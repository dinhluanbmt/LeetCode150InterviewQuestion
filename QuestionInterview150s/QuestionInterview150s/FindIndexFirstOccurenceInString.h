#pragma once
#include <string>
using namespace std;

//28. Find the Index of the First Occurrence in a String
 
/*
* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        unsigned hs = haystack.length();
        unsigned ns = needle.length();
        if (ns > hs) return -1;
        unsigned idx = 0;
        unsigned ni;
        unsigned nf = 0;
        unsigned nl = ns - 1;
        while (idx <= (hs - nl))
        {
            if (needle[0] == haystack[idx] && needle[nl] == haystack[idx + nl])
            {
                for (ni = 1; ni < nl; ++ni)
                {
                    if (needle[ni] != haystack[idx + ni])
                        break;
                }
                if (ni >= nl)
                    return idx;
                idx++;
            }
            else
                idx++;
        }
        return -1;

    }
};