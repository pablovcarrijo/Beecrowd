#include <stdio.h>
#include <stdlib.h>

int josepheus(int x, int k){
    if(x == 1){
        return 1;
    }else{
        return ((josepheus(x-1, k) + k-1)%x)+1;
    }
}

int main(){

    int x, k, n;
    scanf("%d%*c", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &k);
        printf("Case %d: %d\n", (i+1), josepheus(x, k));
    }

    return 0;

}