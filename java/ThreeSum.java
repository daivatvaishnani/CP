import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
  class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
      Arrays.sort(nums);
      List<List<Integer>> triplets = new ArrayList<>();
      for (int i = 0; i < nums.length - 2 && nums[i] <= 0; ++i) {
        if (i == 0 || nums[i - 1] != nums[i]) {
          twoSum(i, nums, triplets);
        }
      }
      return triplets;
    }

    private void twoSum(int i, int[] nums, List<List<Integer>> triplets) {
      int lo = i + 1, hi = nums.length - 1;
      while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
          lo++;
        } else if (sum > 0) {
          hi--;
        } else {
          triplets.add(List.of(nums[i], nums[lo++], nums[hi--]));
          while (lo < hi && nums[lo - 1] == nums[lo]) {
            lo++;
          }
        }
      }
    }
  }
}
