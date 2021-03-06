# 課題 5 レポート

aa83988848 薗田光太郎

## 課題

工学部 20 代の男性の身長は女性の身長より大きいと言えるか．工学部 20 代の男性と女性の身長の分散は等しいとする．

1. 今回の男女の標本から推定される工学部 20 代男女の身長差の９５％信頼区間はどのような範囲か
2. 1 の信頼区間から，工学部 20 代男女の平均身長が同じであると推測できるか．

### 参考

1. 標本平均 2 つの差(男性-女性) を <img src="/k05/tex/c0722151ad3bf5c7b392feebe23530e1.svg?invert_in_darkmode&sanitize=true" align=middle width=69.14402385pt height=19.1781018pt/> ，
   母集団平均 2 つの差(男性-女性) を $\mu_{f} - \mu_{f}$ ，
   とすると，

   $$t = \frac{(m_{m} - m_{f}) - (\mu_{m} - \mu_{f})}{\sqrt{\dfrac{u^2}{n_m} + \dfrac{u^2}{n_f}}}$$

   が自由度 $n_m + n_f - 2$ の $t$ 分布に従うことが知られている．

   - 式中の $u^2$ は，男性標本の不偏分散 $u_m^2$ と女性標本の不偏分散$u_f^2$の自由度重み付き平均で，男女共通の母集団の分散の推定値と考えたものである．

   $$u^2 = \frac{n_1-1}{n_1+n_2-2}u_1^2 + \frac{n_2-1}{n_1+n_2-2}u_2^2$$

   上の $t$ の式は，平均 $\mu$ ，分散 $\sigma^2$ の正規分布上の $x$ を標準化（標準正規分布 $N(0,1)$ 上に射影）した，
   
   $$ z = \frac{x - \mu}{\sigma} $$
   
   に似ている．自由度 $df$ の $t$ 分布とは，正規分布の $\sigma^2$ の代わりに，不偏分散 $u^2 = \dfrac{s^2}{df}$ を使ったもので，ほぼ形は正規分布に近いいわゆる「0 中心の左右対称のつりがね型」なのである．

   95%信頼区間とは，現在集めた標本を使った上の式 $t$ の値の範囲が $t$ 分布の体積の 95%となるとしたときの，推定される $\mu_m-\mu_f$ の誤差範囲である．

   （正しくは，標本をいろいろ変えたときに$\mu_m-\mu_f$の推定値はこの誤差範囲に $100$ 回中 $95$ 回含まれる）

   $t$分布の体積の 95%範囲は，考え方が 2 種類あって，今回の標本の自由度$n_m(8)+n_f(6)-2=12$の$t$分布での範囲では，
   $t$分布表より，両側$t_{12}(0.05)=2.1788$，片側$t_{12}(0.05*2)=1.7823$であるから

   1. 0 周りに左右対称に 95%: $-2.1788 \leq t \leq +2.1788$
   2. 上側だけ削って 95%：$t \leq 1.7823$

   とりあえず，下限を$t_L$，上限を$t_U$としておく．$t_L \leq t \leq t_U$.　すなわち，

   $$ t_L \leq \frac{(m_m - m_f) - (\mu_m - \mu_f)}{\sqrt{\dfrac{u^2}{n_m}+\dfrac{u^2}{n_f}}} \leq t_U $$

   $$ t_L * \sqrt{\dfrac{u^2}{n_m}+\dfrac{u^2}{n_f}} \leq (m_m - m_f) - (\mu_m - \mu_f) \leq t_U * \sqrt{\dfrac{u^2}{n_m}+\dfrac{u^2}{n_f}} $$

   よって，
   
   $$ (m_m -m_f) - t_U * \sqrt{\dfrac{u^2}{n_m}+\dfrac{u^2}{n_f}} \leq　(\mu_m - \mu_f) \leq (m_m -m_f) - t_L * \sqrt{\dfrac{u^2}{n_m}+\dfrac{u^2}{n_f}} $$

   95%信頼区間は，

   1. $6.695 \leq \mu_m-\mu_f \leq 20.473$
   2. $7.948 \leq \mu_m-\mu_f \leq +\infty$

2. 信頼区間に，<img src="/k05/tex/cebab1a0dc12040d331c8801f3218ac5.svg?invert_in_darkmode&sanitize=true" align=middle width=91.04642249999999pt height=21.18721440000001pt/>が含まれるかどうかを見る．含まれていれば，それは標本からそのようなことが起こりうるといえる．含まれていなければそのようなことは滅多にないといえる．

## ソースコードの説明

## 入出力結果

## 修正履歴
