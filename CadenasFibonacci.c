/**
 * @file CadenasFibonacci.c
 * @author Hector Valencia (contacto@hecthoringo.com)
 * @website https://www.hecthoringo.com
 * @brief Los números Fibonacci se definirán así F1=1, F2=1, Fn=Fn-1+ Fn-2. Una cadena Fibonacci la definimos como: F1+F2+...+Fn. Dado un número N calcule la suma de las primeras N cadenas Fibonacci módulo 1000000007
 *        LIMITES   1 <= N <= 10^17
 *        ENTRADA   El número ya descrito
 *        SALIDA    El valor que solicita
 *
 * @version 1.0
 * @date
 * @copyright hecthoringo
 * 
 */

#include <bits/stdc++.h>
#define ll long long
#define DIM 4
#define MOD (ll)(7+1e9)
using namespace std;

/**
 * @brief Define a matrix as struct type
 * 
 */

struct matrix {
    ll a[DIM][DIM];

	matrix() {
		for(ll i=0; i<DIM; i++) for(ll j=0; j<DIM; j++) a[i][j]=0;
		return;
	}
	matrix operator* (matrix b) {
		matrix c;
		for(ll i=0; i<DIM; i++){
            for(ll j=0; j<DIM; j++){
                for(ll k=0; k<DIM; k++) {
                    c.a[i][j]=(c.a[i][j]+((a[i][k]*b.a[k][j])%MOD))%MOD;
                }
            }
		}
		return c;
	}
};

/**
 * @brief 
 * 
 * @param a 
 * @param n 
 * @return matrix 
 */

matrix pow_matrix(matrix a, ll n) {
    if(n == 0){
        for(ll i=0; i<DIM; i++) for(ll j=0; j<DIM; j++) (i==j)?a.a[i][j]=1:a.a[i][j]=0;
        return a;
    }
	if(n == 1) return a;

	matrix b = pow_matrix(a, n / 2);
	b = b * b;
	if (n & 1) b = b * a;

	return b;
}

ll n , ans;
matrix A;

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{

    scanf("%lld",&n);

    if(n==1){
        cout << 1;
        return 0;
    }

    A.a[0][1] = A.a[0][3] = A.a[1][0] = A.a[1][1] = A.a[1][3] = A.a[3][2] = 1;
    A.a[2][3] = MOD-1;
    A.a[3][3] = 2;
    A = pow_matrix( A , n-2 );

    ans = (A.a[0][3] + A.a[1][3])%MOD;
    if( ans < 0 ) ans+=MOD;
    ans = (ans+A.a[2][3])%MOD;
    if( ans < 0 ) ans+=MOD;
    ans = ( ans + A.a[3][3] )%MOD;
    if( ans < 0 ) ans+=MOD;
    ans = ( ans + A.a[3][3] )%MOD;
    if( ans < 0 ) ans+=MOD;
    ans = ( ans + A.a[3][3] )%MOD;
    if( ans < 0 ) ans+=MOD;

    printf("%lld",ans);

    return 0;
}
