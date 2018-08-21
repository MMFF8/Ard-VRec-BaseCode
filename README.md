# Terminologies
**-Group 1 will be called the Initializer group. It's composed of initializers** <br>
  &nbsp; (Initializer group {initializer1, initializer2, initializer3, initializer4, initializer5} )

**-Groups 2-5 will be called subgroups. Subgroups are numbered based on the initializer they're prescribed to** <br>
  &nbsp; (group 2 = subgroup 1, group 3 = subgroup 2, etc.)
  
**and are composed of commands** <br>
  &nbsp; (subgroup 1 {command1, command2, command3, command4, command5}, <br>
  &nbsp; subgroup 2 {command1, command2, command3, command4, command5}, <br>
  &nbsp; etc.)

# Initializers
When an initializer is detected, recognition values shift from the initializer group to the corresponding subgroup of the afformentioned initializer using the lines:<br>
```
Serial.write(X);
CG=Y;
```
where X = 0x12, 0x13, 0x14, or 0x15, depending on what subgroup you're going to use<br>
&nbsp;&nbsp;(0x12 = subgroup 1, 0x13 = subgroup 2, etc.)<br>
where Y = the number of the group to be used<br>
&nbsp;&nbsp;(group = subgroup number + 1)<br>
<br>
&nbsp; ex.
  
    Intializer 1 -> Check input using subgroup 1
    Intializer 2 -> Check input using subgroup 2
    Intializer 3 -> Check input using subgroup 3
    Intializer 4 -> Check input using subgroup 4
    Intializer 5 can't have it's own subgroup given the module's 5 group limit...

# Commands
Each subgroup has 5 possible commands, they can do whatever, as long as they always end in:
```
Serial.write(0x11);
CG=1;
```
these lines are what make you start checking for initializers again

# What This Actually Means

The Arduino will check for any of the initializers. After calling one, voice recognition will match input with whatever you have recorded in its corresponding subgroup on the next go. <br>
&nbsp; ex.<br>
&nbsp;&nbsp;--Recording--<br>
"Alexa" -> initializer1<br>
&nbsp;&nbsp;--Switch to subgroup1--<br>
"This is so sad. Alexa, play Despacito" -> subgroup1.command1<br>
&nbsp;&nbsp;--Switch to back to group1--
