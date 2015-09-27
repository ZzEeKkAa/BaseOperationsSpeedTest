#include <stdio.h>
#include <ctime>

using namespace std;

void char_test();
void int_test();
void long_long_test();
void float_test();
void double_test();
void print_gist(char *type,int sum, int min, int mult, int div, int ops){
    int mint=sum; if(min<mint) mint=min; if(mult<mint) mint=mult; if(div<mint) mint=div;
    char *c=new char[41]; for(int i=0; i<41; ++i) c[i]='#';
    int pr=40;

    c[pr]='#'; pr=40.*(double) mint/sum; c[pr]=0;
    printf("+ %10s %.9lfms %40s %.2lf%%\n", type, ((double)sum) /ops/CLOCKS_PER_SEC*1000, c, 100.*(double) mint/sum);
    c[pr]='#'; pr=40.*(double) mint/min; c[pr]=0;
    printf("- %10s %.9lfms %40s %.2lf%%\n", type, ((double)min) /ops/CLOCKS_PER_SEC*1000, c, 100.*(double) mint/min);
    c[pr]='#'; pr=40.*(double) mint/mult; c[pr]=0;
    printf("* %10s %.9lfms %40s %.2lf%%\n", type, ((double)mult)/ops/CLOCKS_PER_SEC*1000, c, 100.*(double) mint/mult);
    c[pr]='#'; pr=40.*(double) mint/div; c[pr]=0;
    printf("/ %10s %.9lfms %40s %.2lf%%\n", type, ((double)div) /ops/CLOCKS_PER_SEC*1000, c, 100.*(double) mint/div);
    delete[] c;
}


int main(){
    char_test();      printf("\n");
    int_test();       printf("\n");
    long_long_test(); printf("\n");
    float_test();     printf("\n");
    double_test();    printf("\n");
}

void char_test(){
    int t_sum=0;
    int t_min=0;
    int t_mult=0;
    int t_div=0;

    time_t t=NULL;
    time_t ct=NULL;

    int n=10000000;
    char a=1;
    char b=1;
    char c=1;
    char i;

    ct=clock();
    i=1;
    for(int j=0; j<n; ++j,++i){
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        if(i>240) i=0;
    };
    ct=clock()-ct;

    // ----------------------- SUM -----------------------
    t=clock();
    for(int j=0; j<n; ++j,++i){
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        if(i>240) i=1;
    }
    t=clock()-t;
    t_sum=t-ct;

    // ----------------------- MIN -----------------------
    a=1;b=1;c=1;
    t=clock();
    i=1;
    for(int j=0; j<n; ++j,++i){
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        if(i>240) i=1;
    }
    t=clock()-t;
    t_min=t-ct;

    // ----------------------- MULT ----------------------
    a=1;b=1;c=1;
    t=clock();
    i=1;
    for(int j=0; j<n; ++j,++i){
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        if(i>240) i=1;
    }
    t=clock()-t;
    t_mult=t-ct;

    // ----------------------- DIV ----------------------
    a=1;b=1;c=1;
    t=clock();
    i=1;
    for(int j=1; j<n; ++j,++i){
        if(i==0) continue;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;a=239/i;b=238/i;c=237/i;
        if(i>240) i=1;
    }
    t=clock()-t;
    t_div=t-ct;

    //cout<<t_sum<<" "<<t_min<<" "<<t_mult<<" "<<t_div<<endl;
    print_gist("char",t_sum,t_min,t_mult,t_div,n*108);
}

void int_test(){
    int t_sum=0;
    int t_min=0;
    int t_mult=0;
    int t_div=0;

    time_t t=NULL;
    time_t ct=NULL;

    int n=10000000;
    int a=1;
    int b=1;
    int c=1;

    ct=clock();
    for(int i=0; i<n; ++i){
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
    };
    ct=clock()-ct;

    // ----------------------- SUM -----------------------
    t=clock();
    for(int i=0; i<n; ++i){
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
    }
    t=clock()-t;
    t_sum=t-ct;

    // ----------------------- MIN -----------------------
    a=1;b=1;c=1;
    t=clock();
    for(int i=0; i<n; ++i){
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
    }
    t=clock()-t;
    t_min=t-ct;

    // ----------------------- MULT ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(int i=0; i<n; ++i){
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
    }
    t=clock()-t;
    t_mult=t-ct;

    // ----------------------- DIV ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(int i=1; i<n; ++i){
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
    }
    t=clock()-t;
    t_div=t-ct;

    //cout<<t_sum<<" "<<t_min<<" "<<t_mult<<" "<<t_div<<endl;
    print_gist("int",t_sum,t_min,t_mult,t_div,n*108);
}

void long_long_test(){
    int t_sum=0;
    int t_min=0;
    int t_mult=0;
    int t_div=0;

    time_t t=NULL;
    time_t ct=NULL;

    long long n=5000000;
    long long a=1;
    long long b=1;
    long long c=1;

    ct=clock();
    for(long long i=0; i<n; ++i){
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
    };
    ct=clock()-ct;

    // ----------------------- SUM -----------------------
    t=clock();
    for(long long i=0; i<n; ++i){
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
    }
    t=clock()-t;
    t_sum=t-ct;

    // ----------------------- MIN -----------------------
    a=1;b=1;c=1;
    t=clock();
    for(long long i=0; i<n; ++i){
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
    }
    t=clock()-t;
    t_min=t-ct;

    // ----------------------- MULT ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(long long i=0; i<n; ++i){
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
    }
    t=clock()-t;
    t_mult=t-ct;

    // ----------------------- DIV ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(long long i=1; i<n; ++i){
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
    }
    t=clock()-t;
    t_div=t-ct;

    //cout<<t_sum<<" "<<t_min<<" "<<t_mult<<" "<<t_div<<endl;
    print_gist("long long",t_sum,t_min,t_mult,t_div,n*108);
}

void float_test(){
    int t_sum=0;
    int t_min=0;
    int t_mult=0;
    int t_div=0;

    time_t t=NULL;
    time_t ct=NULL;

    float n=2000000;
    float a=1;
    float b=1;
    float c=1;

    ct=clock();
    for(float i=0; i<n; i+=1){
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
    };
    ct=clock()-ct;

    // ----------------------- SUM -----------------------
    t=clock();
    for(float i=0; i<n; i+=1){
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
    }
    t=clock()-t;
    t_sum=t-ct;

    // ----------------------- MIN -----------------------
    a=1;b=1;c=1;
    t=clock();
    for(float i=0; i<n; i+=1){
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
    }
    t=clock()-t;
    t_min=t-ct;

    // ----------------------- MULT ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(float i=0; i<n; i+=1){
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
    }
    t=clock()-t;
    t_mult=t-ct;

    // ----------------------- DIV ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(float i=1; i<n; i+=1){
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
    }
    t=clock()-t;
    t_div=t-ct;

    //cout<<t_sum<<" "<<t_min<<" "<<t_mult<<" "<<t_div<<endl;
    print_gist("float",t_sum,t_min,t_mult,t_div,n*108);
}


void double_test(){
    int t_sum=0;
    int t_min=0;
    int t_mult=0;
    int t_div=0;

    time_t t=NULL;
    time_t ct=NULL;

    double n=1000000;
    double a=1;
    double b=1;
    double c=1;

    ct=clock();
    for(double i=0; i<n; i+=1){
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
        a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i; a=i; b=i; c=i;
    };
    ct=clock()-ct;

    // ----------------------- SUM -----------------------
    t=clock();
    for(double i=0; i<n; i+=1){
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
        a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i; a=b+a; b=i+a; c=b+i;
    }
    t=clock()-t;
    t_sum=t-ct;

    // ----------------------- MIN -----------------------
    a=1;b=1;c=1;
    t=clock();
    for(double i=0; i<n; i+=1){
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
        a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i; a=b-a; b=i-a; c=b-i;
    }
    t=clock()-t;
    t_min=t-ct;

    // ----------------------- MULT ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(double i=0; i<n; i+=1){
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
        a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i; a=b*a; b=i*a; c=b*i;
    }
    t=clock()-t;
    t_mult=t-ct;

    // ----------------------- DIV ----------------------
    a=1;b=1;c=1;
    t=clock();
    for(double i=1; i<n; i+=1){
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
        a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;a=b/i; b=a/i; c=b/i;
    }
    t=clock()-t;
    t_div=t-ct;

    //cout<<t_sum<<" "<<t_min<<" "<<t_mult<<" "<<t_div<<endl;
    print_gist("double",t_sum,t_min,t_mult,t_div,n*108);
}
