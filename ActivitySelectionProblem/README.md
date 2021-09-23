# Activity Selection Problem
https://www.techiedelight.com/activity-selection-problem/

Activity Selection Problem: Given a set of activities, along with the starting and finishing time of each activity, find the maximum number of activities performed by a single person assuming that a person can only work on a single activity at a time.

## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวนเต็ม 1 ตัวคือ m เป็นความยาวของ activity 
หลังจากป็นข้อมูล activity a b จำนวน m ตัว โดย  a,b <= 1000000  
โดยที่ a คือ เวลาเริ่ม b คือ เวลาจบ 
เช่น
(1,2) หมายถึงเริ่ม ที่ t=1 และจบที่ t=2
บุคคล สามารภทำได้ แต่ activity เดียวในเวลาใดๆ ดังนั้น 
(1,2)  (2,3) ไม่สามารถทำพร้อมกันได้
  
## ข้อมูลส่งออก
ค่าของข้อมูล activity ที่ทำได้ เรียงตามเวลา
## Example
### Input
~~~
12
6 2
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
~~~
### Output
~~~
1 4
5 7
8 11
12 14
~~~
