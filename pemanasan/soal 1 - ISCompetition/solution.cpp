#include <bits/stdc++.h>
using namespace std;

long long f_pemimpin[500001], f_cerdas[500001], v[12];
pair<int,int> pemimpin[50001], cerdas[50001];
char nama[50001][10];
long long best;
int a,b,c,d,e,f;

void coba(int i,int j,int k,int x,int y,int z){
        if (i == j || i == k || i == x || i == y || i == z)
                return;
        if (j == k || j == x || j == y || j == z)
                return;
        if (k == x || k == y || k == z)
                return;
        if (x == y || x == z)
                return;
        if (y == z)
                return;
        long long res = (f_pemimpin[i] * f_pemimpin[j] * f_pemimpin[k]) + (f_cerdas[x] * f_cerdas[y] * f_cerdas[z]);
        if (res > best){
                best = res;
                a = i; b = j; c = k;
                d = x; e = y; f = z;
        }
}

int main() {
        int T;
        int N;
        scanf("%d",&T);
        while (T--) {
                scanf("%d",&N);
                for (int i=0;i<N;i++){
                        scanf("%s%d%d",nama[i],&a,&b);
                        f_pemimpin[i] = a;
                        f_cerdas[i] = b;

                        pemimpin[i].first = a;
                        pemimpin[i].second = i;
                        cerdas[i].first = b;
                        cerdas[i].second = i;
                }

                sort(pemimpin, pemimpin + N, std::greater<pair<int,int> >());
                sort(cerdas, cerdas + N, std::greater<pair<int,int> >());
                for (int i=0;i<6;i++){
                        v[i*2] = pemimpin[i].second;
                        v[i*2 + 1] = cerdas[i].second;
                }
                sort(v, v + 12);
                int SZ = unique (v, v + 12) - v;

                best = 0;
                for (int i = 0;i<SZ;i++)
                        for (int j=0;j<SZ;j++)
                                for (int k=0;k<SZ;k++)
                                        for (int x=0;x<SZ;x++)
                                                for (int y=0;y<SZ;y++)
                                                        for (int z=0;z<SZ;z++){
                                                                coba(v[i],v[j],v[k],v[x],v[y],v[z]);
                                                        }
                cout<<best<<endl;
                cout<<nama[a]<<" "<<nama[b]<<" "<<nama[c]<<endl;
                cout<<nama[d]<<" "<<nama[e]<<" "<<nama[f]<<endl;
        }
}
