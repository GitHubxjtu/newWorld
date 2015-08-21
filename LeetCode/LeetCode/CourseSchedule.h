#pragma once
class CourseSchedule
{
public:
	CourseSchedule();
		stack<int> s;
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<vector<int> > v(numCourses, vector<int>());
			vector<int > visited(numCourses, 0);
			vector<int> ans(numCourses, 0);
			for (int i = 0; i<numCourses; i++)
				ans[i] = i;
			if (prerequisites.empty()){
				return ans;
			}
			for (int i = 0; i < prerequisites.size(); i++){
				v[prerequisites[i].second].push_back(prerequisites[i].first);
			}
			bool flag = false;
			for (int i = 0; i < numCourses;i++)
			dps(i, v, ans, visited, flag);
			if (flag) return vector < int>();
			int i = 0;
			while (!s.empty()){
				ans[i] = (s.top());
				i++;
				s.pop();
			}
			return ans;
		}
		void dps(int pos, const vector<vector<int> > &v, vector<int> &ans, vector<int > &visited, bool &flag){
			for (int i = 0; i < v[pos].size(); i++){
				if (visited[v[pos][i]] == 1) continue;
				if (flag || visited[v[pos][i]] == -1) {
					flag = true;
					break;
				}
				visited[pos] = visited[pos] ? visited[pos] : -1;
				dps(v[pos][i], v, ans, visited, flag);
			}
			if (flag) return;
			if (v[pos].empty() || isvisited(v[pos], visited)){
				if (visited[pos] == 1) return;
				visited[pos] = 1;
				s.push(pos);
				return;
			}
		}
		bool isvisited(vector<int> vertex, vector<int > visited){
			for (int i = 0; i < vertex.size(); i++){
				if (visited[vertex[i]] != 1) return false;
			}
			return true;
		}
	~CourseSchedule();
};

