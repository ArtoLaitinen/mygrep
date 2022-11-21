# MyGrep

The whole project was inspired by the Linux command "grep". So it basically searches for a word or string of your choice from a file or input.
This program is intended to be run on the command line. 


<h3>Example 1, searching from input:</h3>

<h5>Command:</h5> 
mygrep.exe
<br>
<br>
If you use the command without any arguments, it will ask you for a string and then a substring and it will look for the 
substring from the "main" string. If the substring is found, the command will tell you, what the first position it was found in 
was. 
<br>
<br>

<h3>Example 2, searching from a file:</h3>

<h5>Command:</h5> 
mygrep.exe [the string that you look for] [the path to the file]
<br>
<br>
If you use the command with 2 arguments, it will look for the string from the given file and print all the lines from the file, which 
include the given string.
<br>
<br>

<h3>Example 3, using options:</h3>

<h5>Command:</h5> 
mygrep.exe -o[options] [the string that you look for] [the path to the file]
<br>
<br>
This will work the same as in example 2, but it will also give you some extra information. The options works so that you put the "-o" tag and then right after that add all the options you want to use. So for example -olo
<br>
<br>

The available options:
<br>
<h4>o</h4>
-also tells you how many lines the string appeared on 
<br>
<br>
<h4>l</h4>
-also tells you all the line numbers in which the string appeared



