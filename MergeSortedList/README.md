# Merge `M` sorted lists of variable length
https://www.techiedelight.com/merge-m-sorted-lists-variable-length/

Given M sorted lists of variable length, merge them efficiently in sorted order.

## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวนเต็ม 1 ตัวคือ m เป็นจำนวนของ sorted list ที่ต้อง merge
บรรทัดต่อมา เป็น ตวามยาว ของ sorted list m จำนวน
ต่อมาเป็น ข้อมูล ของ list แต่ละตัว m บรรทัด
  
## ข้อมูลส่งออก
ผลของการ sort ทั้งหมด
## Example
### Input
~~~
4
4 3 5 2
10 20 30 40
15 25 35
27 29 37 48 93
32 33
~~~
### Output
~~~
10 15 20 25 27 29 30 32 33 35 37 40 48 93
~~~
