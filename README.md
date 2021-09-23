# homework

## Using checker
<b>Example</b>
cd in each problem directory
~~~
$ ./myprogram < data1.txt | ../checker data1.txt
PASS
~~~

## Using checker.sh
~~~
$ ../checker.sh ./myprogram testdata.txt
PASS
~~~

To dump compile object with -g 
 objdump -g -C -D -S bug1.exe > t.txt