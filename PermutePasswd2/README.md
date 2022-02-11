# Permutation Password
ให้ แก้ไข โปรแกรม main.cpp เพื่อ ทำการ เดา รหัส password 
password ที่เป็นไปได้ทั้งหมด จะ ตามเงื่อนไข   
- password แต่ละ character ถูกสร้างจาก character ใน set {0-9,a-z,A-Z} จำนวน n  ตัว
และ สืบมาได้ว่า 
- password ที่ถูกต้อง ไม่มี 0,1,l,L,i,I,j,J,o,O
- password ที่ถูกต้อง มี ตัวใหญ่ ตัวหนังสือ อย่างน้อย อย่างละ 1 ตัว
- password ที่ถูกต้อง ไม่มีตัว ซ้ำกัน

นำ password ที่ได้ check กับ function login(string) ถ้า สำเร็จ จะ return true (bool)


## ข้อมูลเข้า
บรรทัดแรกประกอบด้วยจำนวน 1 ตัวคือ n

## ข้อมูลส่งออก
password ที่ สามารถใช้ได้ ทั้งหมด (อาจมีได้มากกว่า 1 ค่า)

## Example
### Input
~~~
3
~~~

### Output
~~~
Hg2
~~~
