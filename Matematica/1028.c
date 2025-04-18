#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, x, y, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        while(y != 0){
            temp = y;
            y = x % y;
            x = temp;
        }
        printf("%d\n", x);
    }

}