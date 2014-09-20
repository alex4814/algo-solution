#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 405
#define MAXE 1005
#define MOD p

typedef pair<int, int> pii;
typedef long long ll;

struct Matrix {
	int m[32][32];

	Matrix() {
		memset(m, 0, sizeof(m));
	}
	void unit(int n) {
		for (int i = 0; i < n; ++i) {
			m[i][i] = 1;
		}
	}
	int conflict(int u, int v, int n) {
		for (int i = 1; i < n; ++i) {
			if ((u & 1) == (v & 1) && (u & 2) == (v & 2)) {
				int s = u & 1;
				int t = (u & 2) >> 1;
				if (s == t) return 1;
			}
			u >>= 1, v >>= 1;
		}
		return 0;
	}
	void init(int n) {
		memset(m, 0, sizeof(m));
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < (1 << n); ++j) {
				m[i][j] = !conflict(i, j, n);
			}
		}
	}
	void print(int n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j) printf(" ");
				printf("%d", m[i][j]);
			}
			printf("\n");
		}
	}
};

int T, m, p;
int f[32];
Matrix A;


/*
高精度进制转换 
把oldBase 进制的数转化为newBase 进制的数输出。
调用方法，输入str, oldBase newBase.
change();
solve();
output();
也可以修改output(),使符合要求，或者存入另外一个字符数组，备用 
*/
char str[MAXN];//输入字符串
int start[MAXN],ans[MAXN],res[MAXN];//被除数，商，余数
int oldBase=10,newBase=2;//转换前后的进制

void change()
{//各个数位还原为数字形式
    int i,len = strlen(str);
    start[0] = len;
    for(i=1;i<= len;i++)
    {
        if(str[i-1] >= '0' && str[i-1] <= '9')
        {
            start[i] = str[i-1] - '0';
        }
    } 
}

void solve()
{
    memset(res,0,sizeof(res));//余数初始化为空
    int y,i,j;
    //模n取余法，(总体规律是先余为低位，后余为高位)
    while(start[0] >= 1)
    {//只要被除数仍然大于等于1，那就继续“模2取余”
        y=0;
        i=1;
        ans[0]=start[0];
        //
        while(i <= start[0])
        {
            y = y * oldBase + start[i];
            ans[i++] = y/newBase;
            y %= newBase; 
        }
        res[++res[0]] = y;//这一轮运算得到的余数
        i = 1;
        //找到下一轮商的起始处
        while((i<=ans[0]) && (ans[i]==0)) i++;
        //清除这一轮使用的被除数
        memset(start,0,sizeof(start));
        //本轮得到的商变为下一轮的被除数
        for(j = i;j <= ans[0];j++)
            start[++start[0]] = ans[j]; 
        memset(ans,0,sizeof(ans)); //清除这一轮的商，为下一轮运算做准备
    }

	// res -= 1;
	res[1]--;
	for (int i = 1; i <= res[0]; ++i) {
		if (res[i] < 0) {
			res[i] += 2;
			res[i + 1] -= 1;
		}
	}
	if (res[ res[0] ] == 0 && res[0] != 1) res[0]--;
}

void output()
{//从高位到低位逆序输出
    int i;
    for(i = res[0];i >= 1;--i)
    {  
        printf("%d",res[i]);
    }
    printf("\n"); 
}

Matrix mul(Matrix a, Matrix b, int n) {
	Matrix c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k)
				c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % MOD) % MOD;
		}
	}
	return c;
}

// exp = res[ res[0] ]..res[1]
Matrix quickmul(Matrix a, int n) {
	Matrix ans;
	ans.unit(n);
	for (int i = 1; i <= res[0]; ++i) {
		if (res[i] == 1) ans = mul(ans, a, n);
		a = mul(a, a, n);
	}
	return ans;
}

int main() {
	scanf("%d", &T);

	for (int nCase = 0; nCase < T; ++nCase) {
		scanf("%s %d %d", str, &m, &p);
		A.init(m);
		//A.print(1 << m);
		change(); solve();
		A = quickmul(A, 1 << m);
		int ret = 0;
		for (int i = 0; i < (1 << m); ++i) {
			for (int j = 0; j < (1 << m); ++j) {
				ret = (ret + A.m[i][j]) % p;
			}
		}
		printf("%d\n", ret);
		if (nCase + 1 != T) putchar('\n');
	}

	return 0;
}


