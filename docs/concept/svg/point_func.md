# 一些预置点函数
## 变换
相同坐标系下，由一个点到另一个点。
### 线性变换
给定一个$2\times 2$的方阵$M$，然后对点进行该变换。
$$p'=Mp$$
### 直线对称
给定两个点$a,b$定一条直线，然后找到点相对于该直线的对称点。

首先得到$\overrightarrow{ab}=b-a=(x_b-x_a,y_b-y_a)$，由于对称与直线方向无关，取x轴分量$\ge 0$的方向，得到新的向量$\overrightarrow{v}=(dx, dy)$。

1. 如果$dx=0$，则关于y轴对称。
	$$p'=(2x_a-x_p,y_p)$$
2. 如果$dy=0$，则关于x轴对称。
	$$p'=(x_p,2y_a-y_p)$$
3. 否则，进行如下运算

	首先计算该直线的方程，易得：

	$$xdy-ydx+(y_adx-x_ady)=0$$

	点到直线的距离为：

	$$D=\frac{|x_pdy-y_pdx+(y_adx-x_ady)|}{\sqrt{dx^2+dy^2}}$$

	直线的垂直方向为：
	1. 点在直线上方，即$x_pdy-y_pdx+(y_adx-x_ady)<0$，则为$(\frac{1}{dy}, -\frac{1}{dx})$
	2. 反之，则为$(-\frac{1}{dy}, \frac{1}{dx})$

	新的点的位置：

	$$\begin{array}{ll}x_{p'}&=x_p±2D\frac{\frac{1}{dy}}{\sqrt{(\frac{1}{dx})^2+(\frac{1}{dx})^2}}\\&=x_p±2\frac{dx(x_pdy-y_pdx+(y_adx-x_ady))}{dx^2+dy^2}&\end{array}\\\begin{array}{ll}y_{p'}&=y_p\mp2D\frac{\frac{1}{dx}}{\sqrt{(\frac{1}{dx})^2+(\frac{1}{dx})^2}}\\&=y_p\mp2\frac{dy(x_pdy-y_pdx+(y_adx-x_ady))}{dx^2+dy^2}&\end{array}$$

	化简之，令$e=x_pdy-y_pdx+(y_adx-x_ady)$，则：

	$p'=(x_p-2\frac{edx}{dx^2+dy^2}, y_p+2\frac{edy}{dx^2+dy^2})$
### 中心对称
给定一个对称中心点$c$，找到点关于该点的对称点。
$$p'=2c-p$$
### 中心缩放
给定一个缩放中心点$c$，找到点关于该点以缩放比为$\lambda$的缩放后的点。
$$p'=c+\lambda(p-c)$$
### 中心旋转
将点相对旋转中心点$c$顺时针旋转$\theta$弧度。相当于进行如下线性变换：

$$M=\left(\begin{matrix}\cos{\theta}&\sin{\theta}\\-\sin{\theta}&\cos{\theta}\end{matrix}\right)$$
## 中心
相同坐标系下的若干个点，计算其某个中心。
### 几何中心
找到所有点的几何中心，通过算术平均。

$$p' = (\frac{\sum_i^n x_i}{n}, \frac{\sum_i^n y_i}{n})$$
### 多边形质心
设所有点依次连接为封闭多边形，则可以算出其多边形质心。

$$A=\frac{1}{2}\sum_{i=0}^{n-1}(x_iy_{i+1}-x_{i+1}y_i)\\p_x = \frac{1}{6A}\sum_{i=0}^{n-1}(x_i+x_{i+1})(x_iy_{i+1}-x_{i+1}y_i)\\p_y = \frac{1}{6A}\sum_{i=0}^{n-1}(y_i+y_{i+1})(x_iy_{i+1}-x_{i+1}y_i)$$
### 力平衡点
给定一组点，以及点处施加的力的大小，计算最后的力平衡点。

通过迭代的方式，反复向合力方向移动$\eta_i$，其中$\eta_i=loss(\eta_{i-1})$。当某次迭代中求出的合力小于$1e^{-4}$时停止。

## 坐标系转换

详见[几种坐标系定义与坐标系转换 - 坐标系转换](coordinate.md#坐标系转换)