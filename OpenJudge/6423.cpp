#include<cstdio>
#include<iostream>
using namespace std;
int main(){
int x,y,r;
char z;
scanf("%d%d %c",&x,&y,&z);
if(z=='+'){
    r=x+y;
    printf("%d",r);
}
else if(z=='-'){
    r=x-y;
    printf("%d",r);
}
else if(z=='*'){
    r=x*y;
    printf("%d",r);
}
else if(z=='/'){
    if(y==0){
        printf("Divided by zero!");
    }
    else
    {
    
    r=x/y;
    printf("%d",r);
    }
}
else
printf("Invalid operator!");
return 0;
}