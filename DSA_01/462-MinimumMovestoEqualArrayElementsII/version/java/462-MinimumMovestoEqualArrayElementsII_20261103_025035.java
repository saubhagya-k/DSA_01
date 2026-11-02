// Last updated: 03/11/2026, 02:50:35
1public class Solution {
2    public int minMoves2(int[] nums) {
3        Arrays.sort(nums);
4        long min = Long.MAX_VALUE, sum = 0, total = 0;
5        for (int num : nums) {
6            total += num;
7        }
8        for (int i = 0; i < nums.length; i++) {
9            long ans = ((long) nums[i] * i - sum) + ((total - sum) - (long) nums[i] * (nums.length - i));
10            System.out.println(nums[i] + " " + ans);
11            min = Math.min(min, ans);
12            sum += nums[i];
13        }
14        return (int) min;
15    }
16}
17