Coursera上算法课讲的真是...节奏奇怪，还讲不清楚。

k = match到的最大长度  
j = P string 的长度-1  
k = -1 when j = 0;  
特征向量N[j] = k;  

#####求特征向量的算法框架：未优化版(ppt上的原代码)
    int findNext(string P){
    int m = P.length();
    assert( m > 0 );
    
    int *next = new int[m];
    assert( next != 0);
    next[0] = -1; 
    
    int j = 0,k = -1;
    while(j < m-1){
        while (k >= 0 && P[k] != P[j])     //不知为何它要用while，其实用if就行了
            k = next[k];                   //循环结束，不写括号容易看错; 按它的逻辑这里应该k=-1；这里完全就是错的
            j++; k++; next[j] = k;
    }
        return next;
    }
    
#####求特征向量的算法框架：未优化版(修改版)
其实思想相当简单，就是遍历字符串，拿第一个字符P[0]和别的字符一个一个对比，如果相同，k++，然后拿第二个字符P[1]和下一个字符对比，以此类推。这样我们拿的字符的位置又可以由k表示，即P[k]。
    //特征向量：最长的首尾配串值k
    int *findNext(string P){
    int m = P.length();
    assert( m > 0 );
    
    int *next = new int[m];
    assert( next != 0);
    next[0] = -1; 
    
    int k = 0;
    for(int j=1;j<m;j++)
    {
        if(P[k]==P[j]) k++;
        else           k=0;
        next[j]=k;
    }
    
    return next;
    }
    
#####在计算好特征向量N[j]之后，匹配算法很简单就能实现：
    int KMPStrMatching(string T, string P, int *N, int start){
    int j = 0;
    int i = start;
    int pLen = P.length();
    int tLen = T.length();
    
    if(tLen - start)  return(-1);
    
    while (j < pLen && i < tLen) {
        if (j == -1 || T[i] == P[j])
            i++, j++;
        else
            j = N[j];
    }
    
    if(j >= pLen)
        return (i-pLen);
    else
        return (-1);
    }
    


reference：  
1. http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html  
2. https://class.coursera.org/dsalgo-001/lecture/31  

notes:  
1.比KMP更好的算法：Boyer–Moore算法  
2.KMP实际上是AC自动机的特殊情况  
