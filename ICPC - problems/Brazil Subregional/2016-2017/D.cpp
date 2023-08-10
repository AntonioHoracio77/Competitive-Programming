#include <stdio.h>

int main(){
	unsigned long long a,b,c,d,n,res = 0,maior;
        scanf("%llu %llu %llu %llu",&a,&b,&c,&d);
        if(a!=b && c!=d && c%a == 0){
            n = a;
            maior = c/2;
            while(n<=maior){
                if(n%a == 0 && n%b!=0 && c%n == 0 && d%n!=0){
                    res = n;
                    break;
                }
                n += a;
            }
        }
        if(!res)
            printf("-1\n");
        else
            printf("%llu\n",res);
	return 0;
}