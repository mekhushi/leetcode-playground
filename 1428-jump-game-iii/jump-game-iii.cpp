class Solution {
public:
    bool canReach(vector<int>& nums, int st) {
        
        int n= nums.size();

        queue<int>q;
        vector<int> seen(n, 0);

        q.push(st);

        while(!q.empty()) {

            int cur = q.front();
            q.pop();

            if(nums[cur] ==0)
                return true;

            if(seen[cur])
                continue;

            seen[cur]  = 1;

            int next1 = cur+ nums[cur];
            int next2 =cur -nums[cur];

            if(next1 <n)
                q.push(next1);

            if(next2 >=0)
                q.push(next2);
        }

        return false;
    }
};