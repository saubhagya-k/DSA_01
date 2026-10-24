// Last updated: 24/10/2026, 21:23:04
1class Solution {
2public:
3
4    int findDayOfYear(const string& day, const vector<int>& cumMonthDays) {
5        int month = stoi(day.substr(0, 2));
6        int date  = stoi(day.substr(3));
7        return cumMonthDays[month - 1] + date;
8    }
9
10    int countDaysTogether(string arriveAlice, string leaveAlice,
11                          string arriveBob, string leaveBob) {
12        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
13
14        vector<int> cumMonthDays(13, 0);
15        cumMonthDays[1] = 31; //January
16        for(int i = 1; i <= 12; i++) {
17            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
18        }
19
20        int arriveAliceDay  = findDayOfYear(arriveAlice, cumMonthDays);
21        int leaveAliceDay   = findDayOfYear(leaveAlice, cumMonthDays);
22        int arriveBobDay    = findDayOfYear(arriveBob, cumMonthDays);
23        int leaveBobDay     = findDayOfYear(leaveBob, cumMonthDays);
24
25        //Now, just find the overlap
26        int overLapDays = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;
27
28        return overLapDays < 0 ? 0 : overLapDays;
29    }
30};
31