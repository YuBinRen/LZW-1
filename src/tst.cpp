#include<stdio.h>
#include<iostream>
#include<time.h>
#include<cmath>
#include<windows.h>
using namespace std;

/*グローバル変数*/
int a, gcduv, b;
int x, e, P;
/*=============*/

inline void InitRand() {
	srand((unsigned int)time(NULL));
}

inline int Dice() {
	return rand() % 300 + 1;
}

inline int Dice2() {
	return rand() % 5000 + P;
}

inline int Dice3() {
	return rand() % P - 1;
}

//素数ならTRUEを返す
bool isPrimeNum(int x) {
	if (x <= 1) {
		return false;
	}
	//sqrtは引数の平方根をdouble型で返すので,intでキャスト
	int n = (int)sqrt((double)x);

	for (int i = 2; i <= n; i++) {
		if (x%i == 0) {
			return false;	//割り切る整数がある場合、判定終了
		}
	}
	return true;	//割り切る整数がない場合、素数
}

//拡張ユークリッド
int yukurid(int *P, int *e) {
	//Step1
	int P1 = 1;
	int P2 = *P;
	int P3 = 0;

	int e1 = 0;
	int e2 = *e;
	int e3 = 1;

	for (int i = 2; i > 1; i++) {
		//Step2
		int w = P2 / e2;
		int t1 = P2 - e2 * w;
		int t2 = P2 - e2 * w;
		int t3 = P3 - e3 * w;

		P1 = e1;
		P2 = e2;
		P3 = e3;

		e1 = t1;
		e2 = t2;
		e3 = t3;

		if (e2 == 0) {
			i = 0;
		}
	}
	a = P1;
	gcduv = P2;
	b = P3;
	return a, gcduv, b;
}

int main(void) {
	int sumk = 0;
	int end, e, m, Z, M, Euc, c, cal, mul;
	int count = 0;
	int n = 8;

	cout << "Step1\t法Zを入力してください。" << endl;
	cin >> Z;
	cout << "平文mを入力してください。" << endl;
	cin >> m;

	cout << endl;

	cout << "Step2\t秘密鍵ベクトルの生成" << endl;
	cout << endl;

	int* bi = new int[7];
	int* ai = new int[7];

	int sumbi = 0;
	int bri = 0;
	int bir = 0;
	int Csum = 0;
	int* C = new int[];
	int* sumC = new int[];
	int* ir = new int[7];
	int* biri = new int[7];
	int* sumai = new int[7];

	int sum = 0;

	ir[0] = 0;
	ir[1] = 0;
	ir[2] = 0;
	ir[3] = 0;
	ir[4] = 0;
	ir[5] = 0;
	ir[6] = 0;
	ir[7] = 0;
	bool s = false;
	bool cc = false;

	//公開鍵ベクトルの次元の入力

	int *a = new int[n];
	InitRand();
	for (int i = 0; i < n; i++) {
		int ran;
		ran = Dice();
		a[i] = ran;
		cout << flush;
	}
	cout << "生成された乱数s" << endl;
	for (int i = 0; i < n; i++) {
		if(i != n - 1) {
			cout << a[i] << ',';
		}
		else {
			cout << a[i];
		}
	}
	cout << endl;

	sumk = 0;
	for (int i = 0; i < n; i++) {
		sumk += a[i];
	}

	cout << endl;

	cout << "sum(s) =" << sumk << endl;
	cout << endl;

	cout << "Step3\t素数Pを生成" << endl;
	cout << endl;

	bool sosuu = false;

	P > sumk&&sumk > P / 2;

	for (; !sosuu;) {
		InitRand();
		x = Dice2();
		cout << x << endl;
		if (isPrimeNum(x)) {
			cout << "A prime nuber" << endl;
			sosuu = true;
		}
		else {
			cout << "Not a prime number" << endl;
			//sleep(1000);
		}
	}

	P = x;
	e = Dice3();
	cout << "P=" << P << endl;
	cout << "step4 eを生成" << endl;
	cout << "e=" << e << endl;
	cout << endl;

	cout << "step5 公開鍵aを生成" << endl;
	cout << endl;
	cout << "ai=";
	for (int j = 0; j < n; j++) {
		mul = (e*a[j]) % P;
		cout << mul << ",";
		ai[j] = mul;
	}
	cout <<endl;
	cout << endl;

	cout << "step6 公開鍵ベクトルbを生成" << endl;
	cout << endl;

	cout << "bi=";
	for (int j = 0; j < n; j++) {
		cal = a[j] % Z;
		cout << cal << ",";
		bi[j] = cal;
	}
	for (int i = 0; i < 8; i++) {
		sumbi = sumbi + bi[i];
	}
	for (int i = 0; bri < sumbi; i++) {
		biri[i] = m + Z * i;
		bri = biri[i];
		bir++;
	}
	for (end = 0; !s; end++) {
		if (ir[7] == 0) {
			ir[7] = 1;
			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << "ir[0]" << "ir[1]" << "ir[2]" << "ir[3]" << "ir[4]" << "ir[5]" << "ir[6]" << "ir[7]" << "の和は" << biri[i
					] << "となり式を満たします" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
				}
				sumC[count] = Csum;
				count++;
			}
		}
		sum = 0;
	}
	if (ir[7] == 1 && ir[6] == 0) {
		ir[7] = 0;
		ir[6] = 1;

		for (int i = 0; i < 8; i++) {
			sumai[i] = ir[i] * bi[i];
			sum = sum + sumai[i];
		}
		for (int i = 0; i < bir; i++) {
			if (sum == biri[i]) {
				C[count] = sum;
				cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] <<ir[6] << ir[7] << "の和は" << biri[i] << "となり式を満たします" << endl;
				Csum = 0;
				for (int i = 0; i < 8; i++) {
					C[i] = ai[i] * ir[i];
					Csum = Csum + C[i];
				}
				sumC[count] = Csum;
				count++;
			}
		}
		sum = 0;
	}
	if (ir[7] == 1 && ir[6] == 1 && ir[5] == 0) {
		ir[7] == 0;
		ir[6] == 0;
		ir[5] == 1;

		for (int i = 0; i < 8; i++) {
			sumai[i] = ir[i] * bi[i];
			sum = sum + sumai[i];
		}
		for (int i = 0; i < bir; i++) {
			if (sum == biri[i]) {
				C[count] = sum;
				cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7 ]<< "の和は" << biri[i] << "となり式を満たします" << endl;

			}
		}
	}
}