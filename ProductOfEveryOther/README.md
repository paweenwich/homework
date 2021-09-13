# Replace every array element with the product of every other element without using a division operator
https://www.techiedelight.com/replace-element-array-product-every-element-without-using-division-operator/

Given an integer array, replace each element with the product of every other element without using the division operator.
A naive solution would be to calculate the sum of elements to the left and the sum of elements to each array element’s right. If the left subarray sum is the same as the right subarray sum for an element, print its index. The time complexity of this solution is O(n2), where n is the size of the input.


## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวนเต็ม 1 ตัวคือ m
m เป็นความยาวของ ข้อมูล
หลังจากป็นข้อมูล a จำนวน m ตัว  โดย  1 < a < 10000
  
## ข้อมูลส่งออก
ผลของ การคูณของทุกตัวยกเว้นตัวมันเองในตำแหน่งนั้นๆ
## Example
### Input
~~~
5
1 2 3 4 5
~~~
### Output
~~~
120 60 40 30 24
~~~

### Input
~~~
6
5 3 4 2 6 8
~~~
### Output
~~~
1152 1920 1440 2880 960 720
~~~
