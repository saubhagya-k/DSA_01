// Last updated: 19/09/2026, 17:23:59
1class Solution {
2public:
3    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
4
5        int xi=0;
6        int yi=0;
7
8        if(xc<x1){
9            xi = x1;
10        }
11        else if(xc>x2){
12            xi = x2;
13        }
14        else{
15            xi = xc;
16        }
17
18        if(yc<y1){
19            yi = y1;
20        }
21        else if(yc>y2){
22            yi = y2;
23        }
24        else{
25            yi = yc;
26        }
27
28       return  sqrt((xi-xc)*(xi-xc)+(yi-yc)*(yi-yc))<=radius;
29
30       
31        
32    }
33};