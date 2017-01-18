#pragma once

#ifndef __LONGEST_PALINDROME__
#define __LONGEST_PALINDROME__

#include <string>

using namespace std;
class LongestPlaindrome
{
private:
	string s;

public:
	LongestPlaindrome(string newstring)
		: s(newstring)
	{
	}

	string doLongestPlaindrome()
	{
		int length = s.length();

		if (length == 0)
			return "";

		if (length == 1)
			return s;

		int left, right, start = 0, max_length = 1, new_length = 0, min_left = 0;

		for (; start < length;)
		{
			new_length = 0;
			if (length - start <= max_length / 2)
				break;
			
			left = right = start;

			while (right < length - 1 && s[right] == s[right + 1])
				++right;

			start = right + 1;

			while (right < length - 1 && left > 0 && s[right + 1] == s[left - 1] )
			{
				++right;
				--left;
			}
			new_length = right - left + 1;

			if (new_length > max_length)
			{
				min_left = left;
				max_length = new_length;
			}
		}

		return s.substr(min_left, max_length);
	}
};
#endif
