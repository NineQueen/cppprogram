# The report of martingale
## *martingale strategy*的定义 
在一个可以买涨买跌的双边市场，总体上只押注一边。从1块钱开始押注。如果没有成功，就不断加码。直到成功，把之前所有的亏损全部回补，结束游戏。
## 建模
$$
假设有一个1:1赔率的赌博游戏，有p的概率获胜，每一次试验互相独立\\[2ex]
假设买家有无穷资金\\[2ex]  
对于第n轮试验,\; n \in N \\[2ex]
该轮赌注\; T_n = 2 ^ {n-1} \\[2ex]
总亏损\; Tot_n = \sum_{i=1}^{n} T_i = 2^{n-1} -1 \\[2ex]
P(第n轮试验成功) = 
\begin{cases}   
P(该次试验成功) \times P(n-1轮试验失败) = (1-p)^{n-1}\times p, \quad x \geq 2 \\[2ex]
p, \quad x = 1
\end{cases} \\[3ex]
若第n轮试验成功，则可以盈利\;T_n - Tot_n = 2^{n-1} - (2^{n-1} - 1) = 1 \\[2ex]
$$
## *martingale strategy*的必胜策略
$$
已知使用martingale\; strategy盈利当且仅当该轮试验成功\\[2ex]
则证martingale\;strategy可保证试验成功\\[2ex]
设事件A_n为在n次试验及之前成功\\[2ex]
\begin{aligned}
P(A_n) &= \sum_{i = 1}^{n} P(第n轮尝试成功) \\[3ex] 
&= \sum_{i=1}^{n} (1-p)^{n-1}*p \\[3ex]
&= p \times \frac{1-(1-p)^n}{1-(1-p)} \\[3ex]
& = 1 - (1-p)^n
\end{aligned}\\[2ex]
\\lim_{n \rightarrow +\infty}\; P(A_n) = 1 \\[2ex]
当可以试验无穷多次时，martingale\;strategy可确保试验成功，同时意味着盈利
$$
## *martingale strategy*的盈利能力
$$
现定义盈利率\;\rho = \frac{E_{income}}{E_{expense}}\\[2ex]
E_{income} = 1 \\[2ex]
\begin{aligned}
E_{expense} &= \sum_{i=1}^{\infty}\; P(第i轮试验成功)\times Tot_n \\[3ex]
&= \sum_{i=1}^{\infty}\; (1-p)^{n-1}\times p\times (2^{n-1} -1)\\[3ex]
&= \sum_{i=1}^{\infty}\; (1-p)^{n-1}\times p\times 2^{n-1} \; - \; \sum_{i=1}^{\infty}\; (1-p)^{n-1}\times p \\[3ex]
&=
\begin{cases}
\lim_{n \rightarrow +\infty}\;\bigg(p\times \frac{1-(2-2p)^n}{2p-1} -P(A_n)\bigg),\quad p \neq \frac{1}{2}\\[3ex]
\sum_{i=1}^{\infty}\; p \; - \; \lim_{n \rightarrow +\infty}\;\bigg(P(A_n)\bigg),\quad p = \frac{1}{2}\\[3ex]
\end{cases} \\[4ex]
&=\begin{cases}
\frac{1-p}{2p-1} , \quad p> \frac{1}{2} \\[3ex]
+\infty, \quad p \leq \frac{1}{2}
\end{cases}
\end{aligned} \\[3ex]
\begin{aligned}
\rho &=\frac{1}{E_{expense}} \\[3ex]
&=\begin{cases}
\frac{2p-1}{1-p}, \quad p> \frac{1}{2} \\[3ex]
0, \quad p \leq \frac{1}{2}
\end{cases}
\end{aligned} \\[2ex]
总结：当p>\frac{1}{2}时，该试验有盈利能力，反之，则可认为无盈利能力
$$
## 现实修正
然而，在现实生活中，资金往往无法支持进行无数次实验  
现对建模进行修正，给定总资产x , 当该轮投入 $\sigma_n = T_n + Tot_n > x$ 时结束试验