class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children){
            return -1;

        }
        money-=children;
        int count=0;
   
        for(int i=0;i<children;i++){
           if(money<7){
            break;
           }
           else{
            count++;
            money-=7;
           }
        }

        if(count==children && money>0){
            return count-1;
        }
        else if(money==3 && count!=0 && count==children-1){
            return count-1;
        }
        else{
            return count;
        }

      

    }
};