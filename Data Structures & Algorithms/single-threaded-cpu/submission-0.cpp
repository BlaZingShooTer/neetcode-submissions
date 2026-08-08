class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // Store: {enqueueTime, processingTime, originalIndex}
        vector<vector<int>> arr;

        for (int i = 0; i < tasks.size(); i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort tasks by enqueue time
        sort(arr.begin(), arr.end());

        // Min Heap:
        // {processingTime, originalIndex}
        // The task with the smallest processing time comes first.
        // If processing times are equal, the smaller index comes first.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans;

        long long time = 0;   // Current CPU time
        int i = 0;            // Points to the next task that has not been inserted

        while (i < arr.size() || !pq.empty()) {

            // If CPU is idle and no task is available,
            // jump directly to the next task's enqueue time.
            if (pq.empty() && time < arr[i][0]) {
                time = arr[i][0];
            }

            // Insert every task that has arrived by the current time
            while (i < arr.size() && arr[i][0] <= time) {

                // Push {processingTime, originalIndex}
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            // Get the task with
            // 1. smallest processing time
            // 2. smallest index (if tie)
            auto [processTime, index] = pq.top();
            pq.pop();

            // Execute the task
            time += processTime;

            // Store execution order
            ans.push_back(index);
        }

        return ans;
    }
};