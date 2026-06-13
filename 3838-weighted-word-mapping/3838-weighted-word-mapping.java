class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuffer ans=new StringBuffer("");
        for(int i=0;i<words.length;i++){
            String s=words[i];
            int sum=0;
            for(int j=0;j<s.length();j++){
                int x=s.charAt(j)-'a';
               
                sum+=weights[x];

                
            }
             System.out.println(sum);
            sum=sum%26;
            char c=(char)(((25-sum))+'a');
            ans.append(c);
        }
        return ans.toString();
    }
}