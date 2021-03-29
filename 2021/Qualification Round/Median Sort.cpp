#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;

int query(int a, int b, int c) {
	cout << a << " " << b << " " << c << "\n";
	cout.flush();
	int num; cin >> num;
	return num;
}

int query2(vector<int> v) {
	for(auto val: v) {
		cout << val << " ";
	}
	cout << "\n";
	cout.flush();
	int cor; cin >> cor;
	return cor;
}

void init(vector<int> &v, int num) {
	if(num == 1) {
		v.push_back(2); v.push_back(1); v.push_back(3);
	}
	else if(num == 2){
		v.push_back(1); v.push_back(2); v.push_back(3);
	}
	else {
		v.push_back(1); v.push_back(3); v.push_back(2);
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T, N, Q; cin >> T >> N >> Q;
	for(int tc=1; tc<=T; tc++) {
		vector<int> v;
		int f = query(1, 2, 3);
		init(v, f);

		for(int i = 3; i < N; i++) {	

			int index = 0;
			int start = 1;
			int end = v.size() - 1;
			while(true) {
				int mid = (start + end) / 2;
				int num = query(v[index], v[mid], i + 1);

				if(num == v[index]) {
					v.insert(v.begin() + index, i + 1);
					break;
				}

				else if(num == v[mid]) {
					index = mid;
					start = mid + 1;
					if(start > end) {
						if(start == v.size()) {
							v.push_back(i + 1);
						}
						else {
							v.insert(v.begin() + start, i + 1);
						}
						break;
					}
				}
				else {
					if(mid == index + 1) {
						v.insert(v.begin() + mid, i + 1);
						break;
					}
					end = mid - 1;
				} 
				// cout << index << " " << mid << " " << start << " " << end << "\n";
			}

			// cout << "Check : ";
			// for(auto val : v) {
			// 	cout << val << " ";
			// }
			// cout << "\n";
		
		}
		if(!query2(v)) {
			return 0;
		}
	}
}
