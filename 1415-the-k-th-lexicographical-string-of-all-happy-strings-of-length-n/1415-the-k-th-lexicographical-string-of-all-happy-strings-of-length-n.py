class Solution:
    def find(self,a,n,s):
        if n==0:
            self.a.append(s)
            return

        if len(s)==0:
            self.find(self.a,n-1,s+'a')  
            self.find(self.a,n-1,s+'b')  
            self.find(self.a,n-1,s+'c')  
        elif s[len(s)-1]=='a':
            self.find(self.a,n-1,s+'b')  
            self.find(self.a,n-1,s+'c') 
        elif s[len(s)-1]=='b':
            self.find(self.a,n-1,s+'a')  
            self.find(self.a,n-1,s+'c')
        elif s[len(s)-1]=='c':
            self.find(self.a,n-1,s+'a')  
            self.find(self.a,n-1,s+'b')           




    def getHappyString(self, n: int, k: int) -> str:
        self.a=[]
        s=""
        self.find(self.a,n,s)
        if len(self.a)<k:
            return ""
        self.a.sort()    
        return self.a[k-1]
        