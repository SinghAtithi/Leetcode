class Solution {
public:
   
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        if(n==-1)return 1/x;
        double t=1;
        if(abs(n)%2==1)t=x;
        if(n>0) return t*myPow(x*x,n/2);
        else return (1/t)*(myPow(x*x,n/2));
    }
};