# Initializers
Uses group 1 as an initializer group, each command in group 1 shifts recognition values from group 1 to the corresponding group
  ex.
    Group 1 command 1 -> Switch to group 2
    Group 1 command 2 -> Switch to group 3
    Group 1 command 3 -> Switch to group 4
    Group 1 command 4 -> Switch to group 5
    Group 1 command 5 can't exist given the module's 5 group limit...
    
*-Group 1 will be called the Initializer group. It's composed of initializers
  (Initializer group{initializer1,initializer2,initializer3,initializer4,initializer5})*
*-Groups 2-5 will be called subgroups. Subgroups are numbered based on the commands they're prescribed to
  (group 2 = subgroup 1, group 3 = subgroup 2, etc.)
and are composed of commands*
  (subgroup 1{command1,command2,command3,command4,command5}, subgroup 2{command1,command2,command3,command4,command5}, etc.)


# Commands
Each subgroup has 5 possible commands, they can do whatever, as long as they always end in:
```
Serial.write(0x11);
CG=1;
```
this line is what makes you start checking group 1 again

# What This Actually Means

The arduino will check for any of the initializers. After calling one, voice recognition will match input with whatever you have recorded in its corresponding subgroup on the next go.
  ex.
  --Recording--
  "Alexa" -> initializer1
  --Switch to subgroup1--
  "This is so sad, play Despacito" -> subgroup1.command1
  --Switch to back to group1--
