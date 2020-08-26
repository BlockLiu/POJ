## 百练
----------

### 1001 ~ 1999

#### 1001: Exponentiation
 - 求0~99内浮点数的n$(0<n<=25)$次方，典型的大整数乘法
 - 小数点可以单独记录
 - 难度：medium
#### 1002: 方便记忆的电话号码
 - 字符串读入做一个映射，然后用map记录一下即可
 - 难度：easy
#### 1003: Hangover
 - 直接循环判断即可。注意判断sum - len > 1e-6即可（double的比较方式）
 - 难度：easy
#### 1004: 财务管理
 - 求12个浮点数的均值。
 - cout浮点输出方式：
   - fixed: 设置为定点（表示精度为小数点位数，若不设置则精度为有效数字位数）
   - setprecision：精度设定为2
 - 难度：easy
#### 1005: I Think I Need a Houseboat
 - 求出坐标对应的半圆面积，除以每年侵蚀速度50即可
 - 难度：easy
#### 1006 Biorhythms
 - 输入：A（峰值1日期），B（峰值2日期），C（峰值3日期），D（一个其实日期）
 - 输出：D（不含D）之后某个日期，这个日期三个峰值都出现
- 中国剩余定理：
  - 问题形式：一个方程组
    - eq1: $X \equiv a1(\text{mod}~m_1)$
    - eq2: $X \equiv a_2(\text{mod}~m_2)$
    - ...
    - eqn: $X \equiv a_n(\text{mod}~m_n)$
  - 令$M = m_1\times m_2 \times \cdots \times m_n$, $M_i = M/m_i$
  - 令$t_i=M_i^{-1}$为$M_i$模$m_i$的逆元
  - 则方程组的通解为$x = a_1t_1M_1+a_2t_2M_2+\cdots+a_nt_nM_n+kM$
- 逆元：
  - 若$(P\cdot Q)\equiv 1 (\text{mod}~M)$，则称Q为P在模M下的逆元
  - 这题数据范围较小，不需要考虑特殊方法求逆元
- 难度：difficult
- 难点：数学题