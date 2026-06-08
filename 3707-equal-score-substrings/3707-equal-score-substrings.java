class Solution {
    public boolean scoreBalance(String s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int x=s.charAt(i)-'a';

            sum+=(x+1);

        }
         int sum2=0;

         for(int i=0;i<s.length();i++){
            int x=s.charAt(i)-'a';
            sum2+=(x+1);
            System.out.println(sum2);

            if(sum2*2==sum){
                return true;
            }

        }
        return false;
    }
}