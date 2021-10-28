class Solution {
  public:
    long long reversedBits(long long X) {
        long long NO_OF_BITS = sizeof(X) * 8;
        unsigned int reverse_num = 0;
        for (int i = 0; i < NO_OF_BITS; i++)
        {
            if((X & (1 << i)))
               reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
       }
        return reverse_num;
    }
};
