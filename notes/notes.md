

# Translation Units
|                                      | Example                                      | Extension | Artifact  | Notes                  |
| ------------------------------------ | -------------------------------------------- | --------- | --------- | ---------------------- |
| Non-Modular (The old way)            | # include "..."                              | .cpp      | .o        |                        |
| Header Unit                          | Created by: import <...>;                    | .hpp      | .cmi (.o) |                        |
| Module Interface Unit                | export module [module-name];                 | .ixx      | .cmi (.o) | Exactly one per module |
| Module Implementation Unit           | module [module-name];                        | .mxx      | .o        | At most one per unit   |
| Module Partition Interface Unit      | export module [module-name]:[partition-name] | .ixx      | .cmi (.o) |                        |
| Module Partition Implementation Unit | module [module-name]:[partition-name]        | .mxx      | .o        |                        |
[2] : 5241s


# module partition units 
starts at https://youtu.be/Di_oqMh4gM8?t=4935 

# MSVC Docs
 * Blog 1 https://devblogs.microsoft.com/cppblog/c-modules-in-vs-2015-update-1/
 * Blog 2 https://devblogs.microsoft.com/cppblog/cpp-modules-in-visual-studio-2017/
 * 
 * Overview of modules in C++  https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=vs-2019
 * /experimental:module (Enable module support) https://docs.microsoft.com/en-us/cpp/build/reference/experimental-module?view=vs-2019

# Funny error messages: 
1.  We are damaged, This is broken.
    Logic is lost,
    We struggle,
    Hunt through the rubble for what once was.



# Sources 
[1] GCC WIKI :  https://gcc.gnu.org/wiki/cxx-modules
[2] Bryce Adelstein Lelbach - Modules are Coming , YouTube presentation  https://www.youtube.com/watch?v=Di_oqMh4gM8


