
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int y = x;
        long long rev = 0;

        while (x > 0)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        if (y == rev)
        {
            return true;
        }
        else
            return false;
    }
};