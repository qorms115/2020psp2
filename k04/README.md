# 課題4 レポート

bb35317057 PARK BAEGEUN

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
 まず、腎臓の標本になってくれるファイル（ここではheights.csv）を呼んでいます。エラーが出たら終了
 その次の標本になってくれる学生番号ファイル（IDs.csv）を呼んでいます。エラーが出たら終了
 この二つのファイルを使用して、各学生番号に対応する伸長を付与して、データを保存する。
 最後に、学生番号に該当する情報があれば、そのファイルをロードします。存在しない学生番号なら終了。

## 入出力結果
データが存在する場合
input the filename of sample height : heights.csv
the filename of sample height : heights.csv
input the filename of sample ID : IDs.csv
the filename of sample ID : IDs.csv
Which data do you want? : 45313125
================================
ID : 45313125
gender : female
height : 152.40
============================


データが存在しない場合
the filename of sample height : heights.csv
input the filename of sample ID : IDs.csv
the filename of sample ID : IDs.csv
Which data do you want? : 45313124
================================
No data
============================



## 修正履歴

[comment #20200630 moto]
- OKです。