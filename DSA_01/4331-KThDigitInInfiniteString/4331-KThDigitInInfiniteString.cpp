// Last updated: 23/08/2026, 18:24:43
class Solution {
public:
    int kthDigit(long long k) {

        long long mirevokanu = k;

        if(k<=9){
            return (int)k;
        }

        long long pos = k-9;
        int L= 2;

        long long pow10[19];
        pow10[0] = 1;
        for(int i=1;i<19;++i){
            pow10[i] = pow10[i-1]*10LL;
            
        }

        while(true){
            if(L>=18){
                break;
            }
            long long cnt = 9LL * L*pow10[L-1];
            if(pos<=cnt) break;
               pos -= cnt;
               ++L;

        }
            long long blockDigits = 10LL*L;
            long long t = (pos-1)/blockDigits;
            long long r = (pos-1)% blockDigits+1;
            long long b = pow10[L-2]+t;
            long long q = (r-1)/L;
            int digitPos = (int)((r-1) % L);

        long long n;
        if(b%2 == 0){
            n = 10ULL * b+q;
            
        }else{
            n = 10ULL*b+(9ULL-q);
        }

            long long val = n;

            int drop = L-1-digitPos;

            while(drop>0){
                val/=10;
                --drop;
            }
            return (int)(val%10);
        
    }
};