#include <bits/stdc++.h>

using namespace std;

int minMeetingRoomsPrefixSum(vector<vector<int>> &intervals) {
  const int maxt = 1e6+5;
  const int nintervals = intervals.size();
  vector<int> tasks(maxt, 0);
  for (int i = 0; i < nintervals; ++i) {
    tasks[intervals[i][0]]++;
    tasks[intervals[i][1]]--;
  }
  int nconfs = tasks[0];
  for (int i = 1; i < maxt; ++i) {
    tasks[i] += tasks[i-1];
    nconfs = max(nconfs, tasks[i]);
  }
  return nconfs;
}

int minMeetingRooms(vector<vector<int>> &intervals) {
  const int nintervals = intervals.size();
  vector<int> tstart, tend;
  for (auto &interval: intervals) {
    tstart.push_back(interval[0]);
    tend.push_back(interval[1]);
  }
  sort(tstart.begin(), tstart.end());
  sort(tend.begin(), tend.end());
  int ts = 0, te = 0;
  int nconf = 0, maxconf = 0;
  while(ts < nintervals && te < nintervals) {
    if (tstart[ts] < tend[te]) {
      nconf++;
      ts++;
    } else if (tstart[ts] == tend[te]) {
      te++;
      ts++;
    } else {
      nconf--;
      te++;
    }
    maxconf = max(maxconf, nconf);
  }
  return maxconf;
}

int main() {
  vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
  cout << minMeetingRooms(intervals) << "\n";
  return 0;
}
