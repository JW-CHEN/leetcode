class Solution {
public:
    int majorityElement(vector<int> &num) {
        // psuedo_code can refer to Daskupta Algorithm book
        int sz = num.size();
        int count = 0;
        if (sz%2 == 1) {
            for (int i = 0; i < sz; i++) {
                if (num[i] == num[sz-1])
                    count++;
            }
            if (count > sz/2)
                return num[sz-1];
            else
                sz--;
        }
        vector<int> half;
        for (int i = 0; i < sz/2; i++) {
            if (num[i] == num[sz-1-i])
                half.push_back(num[i]);
        }
        return majorityElement(half);
    }
};