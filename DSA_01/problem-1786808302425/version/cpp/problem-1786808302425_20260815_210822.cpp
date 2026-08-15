// Last updated: 15/08/2026, 21:08:22
1class Solution {
2public:
3    int kthDigit(long long k) {
4
5        long long mirevokanu = k;
6
7        if(k<=9){
8            return (int)k;
9        }
10
11        long long pos = k-9;
12        int L= 2;
13
14        long long pow10[19];
15        pow10[0] = 1;
16        for(int i=1;i<19;++i){
17            pow10[i] = pow10[i-1]*10LL;
18            
19        }
20
21        while(true){
22            if(L>=18){
23                break;
24            }
25            long long cnt = 9LL * L*pow10[L-1];
26            if(pos<=cnt) break;
27               pos -= cnt;
28               ++L;
29
30        }
31            long long blockDigits = 10LL*L;
32            long long t = (pos-1)/blockDigits;
33            long long r = (pos-1)% blockDigits+1;
34            long long b = pow10[L-2]+t;
35            long long q = (r-1)/L;
36            int digitPos = (int)((r-1) % L);
37
38        long long n;
39        if(b%2 == 0){
40            n = 10ULL * b+q;
41            
42        }else{
43            n = 10ULL*b+(9ULL-q);
44        }
45
46            long long val = n;
47
48            int drop = L-1-digitPos;
49
50            while(drop>0){
51                val/=10;
52                --drop;
53            }
54            return (int)(val%10);
55        
56    }
57};