/*
Logic -

// map of symbol and val m
        // now calc length of total num say l
        // iterate num and for every num[i] check l-i
        // like for l-i >= 3 it's m check this now and for this check num[i]
        // how many M's needed check for 1 and if(num[i] <= 4) check how much
        // less like if 3 then 2x the prev of M (here) and else how much less
        // than 9
        // for less than 4: 2 zeros -> C's D, 1 zero -> X's L, no zero -> I's V
        // for more than 4: 2 zeros -> C's M, 1 zero -> X's C, no zero -> I's
        // after V for 4: 2 zeros -> CD, 1 zero -> XL, no zero -> IV for 9: 2
        // zeros -> CM, 1 zero -> XC, no zero -> IX

// for less than 4: 2 zeros -> C's D, 1 zero -> X's L, no zero -> I's
        // for more than 4: 2 zeros -> D C's, 1 zero -> L X's, no zero -> V then I's
        // for 4: 2 zeros -> CD, 1 zero -> XL, no zero -> IV for 9: 2
        // zeros -> CM, 1 zero -> XC, no zero -> IX


*/

class Solution
{
public:
    string intToRoman(int num)
    {
        string s = "";
        int e = num % 10;
        num /= 10;
        int t = num % 10;
        num /= 10;
        int h = num % 10;
        num /= 10;
        int th = num % 10;

        // Thousands place
        for (int i = 0; i < th; i++)
        {
            s += "M";
        }

        // Hundreds place
        if (h < 4)
        {
            for (int i = 0; i < h; i++)
            {
                s += "C";
            }
        }
        else if (h == 4)
        {
            s += "CD";
        }
        else if (h < 9)
        {
            s += "D";
            for (int i = 0; i < h - 5; i++)
            {
                s += "C";
            }
        }
        else
        {
            s += "CM";
        }

        // Tens place
        if (t < 4)
        {
            for (int i = 0; i < t; i++)
            {
                s += "X";
            }
        }
        else if (t == 4)
        {
            s += "XL";
        }
        else if (t < 9)
        {
            s += "L";
            for (int i = 0; i < t - 5; i++)
            {
                s += "X";
            }
        }
        else
        {
            s += "XC";
        }

        // Ones place
        if (e < 4)
        {
            for (int i = 0; i < e; i++)
            {
                s += "I";
            }
        }
        else if (e == 4)
        {
            s += "IV";
        }
        else if (e < 9)
        {
            s += "V";
            for (int i = 0; i < e - 5; i++)
            {
                s += "I";
            }
        }
        else
        {
            s += "IX";
        }

        return s;
    }
};