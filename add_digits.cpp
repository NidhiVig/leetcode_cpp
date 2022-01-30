class Solution {
public:
    int add(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum=add(num);
        while(sum/10!=0){
            sum=add(sum);
        }
        return sum;
    }
};
