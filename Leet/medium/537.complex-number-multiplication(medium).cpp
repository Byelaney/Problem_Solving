Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
    size_t p1 = a.find("+");
    size_t p2 = b.find("+");
    vector<int> v(4);
    v[0] = stoi(a.substr(0, p1));
    v[1] = stoi(a.substr(p1 + 1, a.size() - p1 - 2));
    v[2] = stoi(b.substr(0, p2));
    v[3] = stoi(b.substr(p2 + 1, b.size() - p2 - 2));
    int real = v[0] * v[2] - v[1] * v[3];
    int imaginary = v[0] * v[3] + v[1] * v[2];
    return to_string(real) + "+" + to_string(imaginary) + "i";
}
};
