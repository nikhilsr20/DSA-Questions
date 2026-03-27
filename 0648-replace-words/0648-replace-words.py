class Solution(object):
    def replaceWords(self, dictionary, sentence):
        a=sentence.split(' ')
        map={}
        for i in dictionary:
            map[i]=1

        for i in range(0,len(a)):
            p=a[i]
            s=''
            for j in p:
                s=s+j
                if map.get(s,0)==1:
                    a[i]=s
                    break
        b=' '.join(a)
        return b
