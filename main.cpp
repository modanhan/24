#include <bits/stdc++.h>
using namespace std;

bool f;
int calc(int l, int r, int o) {
	switch (o) {
	case 0:
		return l + r;
	case 1:
		return l - r;
	case 2:
		return l * r;
	case 3:
		if (l % r) {
			f = 1;
			return 0;
		} else {
			return l / r;
		}
	}
}

char op(int o) {
	switch (o) {
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	}
}

int main() {
	vector<int> v(4, 0);
	while (cin >> v[0]) {
		for (int i = 1; i < 4; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int o1 = 0; o1 < 4; o1++) {
			for (int o2 = 0; o2 < 4; o2++) {
				for (int o3 = 0; o3 < 4; o3++) {

					f = 0;
					int v1, v2, v3;
					v1 = calc(v[0], v[1], o1);
					if (f) {
						break;
					}
					v2 = calc(v1, v[2], o2);
					if (f) {
						break;
					}
					v3 = calc(v2, v[3], o3);
					if (f) {
						break;
					}
					if (v3 == 24) {
						cout << "((" << v[0] << op(o1) << v[1] << ")" << op(o2)
								<< v[2] << ")" << op(o3) << v[3] << "=" << v3
								<< "\n";
					}
					if (v3 == 24) {
						goto possible;
					}
				}
			}
		}
		while (next_permutation(v.begin(), v.end())) {
			for (int o1 = 0; o1 < 4; o1++) {
				for (int o2 = 0; o2 < 4; o2++) {
					for (int o3 = 0; o3 < 4; o3++) {

						f = 0;
						int v1, v2, v3;
						v1 = calc(v[0], v[1], o1);
						if (f) {
							break;
						}
						v2 = calc(v1, v[2], o2);
						if (f) {
							break;
						}
						v3 = calc(v2, v[3], o3);
						if (f) {
							break;
						}
						if (v3 == 24) {
							cout << "((" << v[0] << op(o1) << v[1] << ")"
									<< op(o2) << v[2] << ")" << op(o3) << v[3]
									<< "=" << v3 << "\n";
						}
						if (v3 == 24) {
							goto possible;
						}
					}
				}
			}
		}
		cout << "impossible\n";
	possible:;}
}
