#include<bits/stdc++.h>
#include<windows.h> 
#define m (l + r) / 2
#define LL long long int

using namespace std;

int n;
const LL mxn = 1e6 + 1;
                   //區間和 1          //最小 2                //最大 3              //積  4
vector<LL> v(mxn), sseg((mxn << 2) | 1), lseg((mxn << 2) | 1), hseg((mxn << 2) | 1), fseg((mxn << 2) | 1), stag((mxn << 2) | 1), ltag((mxn << 2) | 1), htag((mxn << 2) | 1);
int whattree;
void build(int l = 0, int r = n , int i = 1) {
	if(r - l == 1) {
		hseg[i] = v[l];
		lseg[i] = v[l];
		sseg[i] = v[l];
		fseg[i] = v[l];
		return;
	}
	build (l, m, i << 1); build(m, r, i << 1 | 1);
	hseg[i] = max(hseg[i << 1],hseg[i << 1 | 1]);
	lseg[i] = min(lseg[i << 1],lseg[i << 1 | 1]);
	sseg[i] = sseg[i << 1] + sseg[i << 1 | 1];
	fseg[i] = fseg[i << 1] * fseg[i << 1 | 1];
	}

void push(int l, int r, int i){
	if(!stag[i]) return;
	if(r - l == 1) {
		if(whattree == 1){
			sseg[i] += stag[i];
			stag[i] = 0;
		}
		else if(whattree == 2){
			lseg[i] += ltag[i];
			ltag[i] = 0;
		}
		else if(whattree == 3){
			hseg[i] += htag[i];
			htag[i] = 0;
		}
		else if(whattree == 5){
			sseg[i] += stag[i];
			stag[i] = 0;
			lseg[i] += ltag[i];
			ltag[i] = 0;
			hseg[i] += htag[i];
			htag[i] = 0;
		}
		return;
	}
	if(whattree == 1){
		sseg[i] += (r - l) * stag[i];
		stag[i << 1] += stag[i], stag[i << 1 | 1] += stag[i], stag[i] = 0; 
	}
	else if(whattree == 2){
		lseg[i] += ltag[i]; 
		ltag[i << 1] += ltag[i], ltag[i << 1 | 1] += ltag[i], ltag[i] = 0;
	}
	else if(whattree == 3){
		hseg[i] += htag[i]; 
		htag[i << 1] += htag[i], htag[i << 1 | 1] += htag[i], htag[i] = 0;
	}	
	else if(whattree == 5){
		sseg[i] += (r - l) * stag[i];
		stag[i << 1] += stag[i], stag[i << 1 | 1] += stag[i], stag[i] = 0;
		lseg[i] += ltag[i]; 
		ltag[i << 1] += ltag[i], ltag[i << 1 | 1] += ltag[i], ltag[i] = 0; 
		hseg[i] += htag[i]; 
		htag[i << 1] += htag[i], htag[i << 1 | 1] += htag[i], htag[i] = 0;
	}
}

int query(int ql, int qr, int l = 0, int r = n, int i = 1){
	whattree = 1;
	push(l, r, i);
	if(qr <= l || r <= ql) 
		return 0;
	if(ql <= l && r <= qr) 
		return sseg[i];
	return query(ql, qr, l, m, i << 1) + query(ql, qr, m, r, i << 1 | 1);
}

int query_multiply(int ql, int qr, int l = 0, int r = n, int i = 1){
	
	if(qr <= l || r <= ql) 
		return 1;
	if(ql <= l && r <= qr) 
		return fseg[i];
	return query_multiply(ql, qr, l, m, i << 1) * query_multiply(ql, qr, m, r, i << 1 | 1);
}

int maxtree(int ql, int qr, int l = 0, int r = n, int i = 1){
	whattree = 3;
	push(l, r, i);
	if(qr <= l || r <= ql)
		return -2147483648;
	if(ql <= l && r <= qr)
		return hseg[i];
	return max(maxtree(ql, qr, l, m, i << 1), maxtree(ql, qr, m, r, i << 1 | 1));
	}
	
int mintree(int ql, int qr, int l = 0, int r = n, int i = 1) {
	whattree = 2;
	push(l, r, i);
	if(qr <= l || r <= ql)
		return 2147483647;
	if(ql <= l && r <= qr)
		return lseg[i];
	return min(mintree(ql, qr, l, m, i << 1),mintree(ql, qr, m, r, i << 1 | 1));
}	

void upd(int idx, int val, int l = 0, int r = n, int i = 1){
	if(idx < l || r <= idx) 
		return;
	if(r - l == 1) {
		hseg[i] = val; 
		lseg[i] = val; 
		sseg[i] = val; 
		fseg[i] = val; 
		return;
	}
	upd(idx, val, l, m, i << 1), upd(idx, val, m, r, i << 1 | 1);
	hseg[i] = max(hseg[i << 1] , hseg[i << 1 | 1]);
	lseg[i] = min(lseg[i << 1] , lseg[i << 1 | 1]);
	sseg[i] = sseg[i << 1] + sseg[i << 1 | 1];
	fseg[i] = fseg[i << 1] * fseg[i << 1 | 1];
}

void upd_nlogn(int idx, int val, int l = 0, int r = n, int i = 1){ //區間積線段數區間更新加
	if(idx < l || r <= idx) 
		return;
	if(r - l == 1) {
		fseg[i] += val; 
		return;
	}
	upd_nlogn(idx, val, l, m, i << 1), upd_nlogn(idx, val, m, r, i << 1 | 1);
	fseg[i] = fseg[i << 1] * fseg[i << 1 | 1];
}

void modify(int ql, int qr, LL val, int l = 0, int r = n, int i = 1){
	whattree = 5;
	push(l, r, i);
	if(qr <= l || r <= ql) return;
	if(ql <= l && r <= qr) {
		stag[i] += val;
		ltag[i] += val;
		htag[i] += val;
		push(l, r, i);
		return;
	}
	modify(ql, qr, val, l, m, i << 1), modify(ql, qr, val, m, r, i << 1 | 1);
	hseg[i] = max(hseg[i << 1] , hseg[i << 1 | 1]);
	lseg[i] = min(lseg[i << 1] , lseg[i << 1 | 1]);
	sseg[i] = sseg[i << 1] + sseg[i << 1 | 1];
}

int main(){
	int a,b;
	
	cout << "歡迎使用線段數資料處理工具" << '\n'; 
	cout << "請輸入線段個數" <<'\n';
	cin >> n;
	cout << "請輸入線段"<<'\n';
	for(int i = 0; i < n; i++)
		cin >> v[i];
	build();
	int cc = 0;
	while(cout << "請輸入指令" <<'\n'){
		if(cc == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "若輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-U-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可更新線段  ，輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-K-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可更新區間線段\n若輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-H-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可計算最大值，輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-L-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可計算最小值\n若輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-F-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可搜尋區間和，輸入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "-M-";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "可搜尋區間積\n";
			cc = 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		string s;
		int L,R,VAL;
		cin >> s;
		if( s == "U") { //update 
			cout << "請輸入-N-和-M-(更新第N個數為M)" << '\n';
			cin >> a >> b;
			v[a - 1] = b;
			upd(a - 1, b);
			cout << "線段為";
			for(int i = 0; i < n; i++)
				cout << v[i] << " ";
			cout << '\n';
		}
		else if( s == "K"){
			cout << "請輸入-L-、-R-和-VAL-(線段L到R加VAL)" <<'\n';
			cin >> L >> R >> VAL;
			for(int j = L - 1; j < R; j++){
				v[j] += VAL;
			}
			modify(L - 1, R, VAL);
			for(int j = L - 1; j < R; j++){
				upd_nlogn(j, VAL);
			}
			cout << "線段為";
			for(int i = 0; i < n; i++)
				cout << v[i] << " ";
			cout << '\n';
		}
		else if(s == "H") { //max
			cout << "請輸入查詢區域計算最大值" <<'\n';
			cin >> L >> R;
			cout << "線段"<< L << "到" << R << "的最大值為" << maxtree(L - 1,R) <<'\n';
		}
		else if(s == "L") { //min
			cout << "請輸入查詢區域計算最小值" <<'\n';
			cin >> L >> R;
			cout << "線段"<< L << "到" << R << "的最小值為" <<mintree(L - 1,R) <<'\n';
		}
		else if(s == "F") { //interval
			cout << "請輸入查詢區域計算區間和" <<'\n';
			cin >> L >> R;
			cout << "線段"<< L << "到" << R << "的區間合為" << query(L - 1, R) <<'\n';
		}
		else if(s == "M") { //interval product
			cout << "請輸入查詢區域計算區間積" <<'\n';
			cin >> L >> R;
			cout << "線段"<< L << "到" << R << "的區間積為" << query_multiply(L - 1, R) <<'\n'; 
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << "指令無效" <<'\n'; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}	
	}
	return 0;
}
