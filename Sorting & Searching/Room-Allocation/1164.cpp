#include <bits/stdc++.h>
#define i64 int64_t
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::vector<int>> A(N + 2, std::vector<int> (3));
	std::set<int> s;
	std::vector<int> answer(N + 2);
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;

	for (int i = 1; i <= N; i++) {
		std::cin >> A[i][0] >> A[i][1];
		A[i][2] = i;
		s.insert(i);
	}

	std::sort(A.begin() + 1, A.begin() + N + 1);

	for (int i = 1; i <= N; i++) {
		while (!pq.empty() and A[i][0] > pq.top()[0]) {
			int roomID = answer[pq.top()[1]];
			auto it = pq.top();
			pq.pop();
			s.insert(roomID);
		}

		answer[A[i][2]] = *s.begin();
		pq.push({A[i][1], A[i][2]});
		s.erase(answer[A[i][2]]);
	}

	cout << *max_element(answer.begin() + 1, answer.begin() + N + 1) << '\n';
	for (int i = 1; i <= N; i++) std::cout << answer[i] << ' ';
	return 0;
}