# Sort an array based on order defined by another array
https://www.techiedelight.com/custom-sort-sort-elements-array-order-elements-defined-second-array/

Given tow inteher arrays, re order elements of the first array by the order of element defined by the second array.  
THe element that are not present in seccond array but presented in first array should be sorted and append at the end.  Some element in the second might not resepnt in the first. 


## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวนเต็ม 2 ตัวคือ m  n เป็นจำนวน ข้อมูล ของ first and second array.
หลังจากป็นข้อมูล first array a  (0 <= a < 1,000,000)  m ตัว 
หลังจากป็นข้อมูล second array a  (0 <= a < 1,000,000)  n ตัว 

## ข้อมูลส่งออก
ผลของการเรียงข้อมูล มีขนาด m
## Example
### Input
~~~
15 4
5 8 9 3 5 7 1 3 4 9 3 5 1 8 4
3 5 7 2
~~~
### Output
~~~
3 3 3 5 5 5 7 1 1 4 4 8 8 9 9
~~~

