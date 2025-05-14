class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;
        while (columnNumber != 0)
        {
            --columnNumber;
            res += static_cast<char>('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};