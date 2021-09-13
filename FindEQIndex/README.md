# Find equilibrium index of an array
https://www.techiedelight.com/find-equilibrium-index-array/

Given an integer array, find the equilibrium index in it.

For an array A consisting n elements, index i is an equilibrium index if the sum of elements of subarray A[0…i-1] is equal to the sum of elements of subarray A[i+1…n-1]. i.e.

(A[0] + A[1] + … + A[i-1]) = (A[i+1] + A[i+2] + … + A[n-1]), where 0 < i < n-1

Similarly, 0 is an equilibrium index if A[1] + A[2] + … + A[n-1] sums to 0 and n-1 is an equilibrium index if A[0] + A[1] + … + A[n-2] sums to 0.

 
Practice this problem

A naive solution would be to calculate the sum of elements to the left and the sum of elements to each array element’s right. If the left subarray sum is the same as the right subarray sum for an element, print its index. The time complexity of this solution is O(n2), where n is the size of the input.

## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวนเต็ม 1 ตัวคือ m
m เป็นความยาวของ ข้อมูล
หลังจากป็นข้อมูล a จำนวน m ตัว  โดย  -10000 <= a <= 10000
  
## ข้อมูลส่งออก
ตำแหน่ง  equilibrium index ที่เจอ ทั้งหมด เรียงจาก น้อยไปมาก
## Example
### Input
~~~
8
0 -3 5 -4 -2 3 1 0
~~~
### Output
~~~
0 3 7
~~~

