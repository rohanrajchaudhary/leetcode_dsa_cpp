
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            adj[pre].push_back(course);
        }

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            for(int v : adj[i])
            {
                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            count++;

            for(int v : adj[node])
            {
                indegree[v]--;

                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return count == numCourses;
    }
};
