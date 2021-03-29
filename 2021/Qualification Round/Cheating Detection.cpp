#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <utility>
using namespace std;

const vector<pair<double, double> > ab_list{{0.1, 0.1}, {0.5, 0.5}, {1.0, 1.0}, {2.0, 2.0}, {5.0, 5.0}};

pair<int, int> count_num(string data){
	int cnt_one = 0, cnt_zero = 0;
	for(int i=0; i<data.size(); i++) {
		if(data[i] == '1') cnt_one++;
		else cnt_zero++;
	}
	return {cnt_one, cnt_zero};
}

double MLE(pair<int, int> cnt) {
	return (double)cnt.first / (double)(cnt.first + cnt.second);
}

double MAP(pair<int, int> cnt, double alpha, double beta) {
	return (double)(cnt.first + alpha - 1) / (double)(cnt.first + cnt.second + alpha + beta - 2);
}

vector< vector<double> > make_infos(vector<string> datas, vector<pair<double, double> > alpha_beta_list) {

	vector< vector<double> > infos;
	vector<double> info;
	for(auto data: datas) {
		info.push_back(MLE(count_num(data)));
	}
	infos.push_back(info);

	for(auto ab: alpha_beta_list){
		info.clear();
		double alpha = ab.first;
		double beta = ab.second;
		for(auto data: datas) {
			info.push_back(MAP(count_num(data), alpha, beta));
		}
		infos.push_back(info);
	}
	return infos;
}

vector<double> loss_function(vector< vector<double> > infos) {
	vector<double> losses(100, 0.0);
	for(auto info: infos) {
		for(int i=0; i<info.size(); i++) {
			losses[i] += (info[i] - 0.75) * (info[i] - 0.75);
		}
	}
	return losses;
}

int find_min_idx(vector<double> losses) {
	double min_val = 999999999;
	int min_idx = -1;
	for(int i=0; i<losses.size(); i++) {
		if(losses[i] < min_val) {
			min_val = losses[i];
			min_idx = i;
		}
	}
	return min_idx;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T; int P; cin >> T >> P;
	for(int tc=1; tc<=T; tc++) {
		vector<string> datas;
		for(int i=0; i<100; i++) {
			string data;
			cin >> data; datas.push_back(data);
		}
		auto infos = make_infos(datas, ab_list);
		auto losses = loss_function(infos);
		int idx = find_min_idx(losses);
		//cout << idx + 1 << "\n";
		cout << "Case #" << tc << ": " << idx+1 << "\n";



	}
}

