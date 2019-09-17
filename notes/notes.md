

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

# Sources 
[1] GCC WIKI :  https://gcc.gnu.org/wiki/cxx-modules
[2] Bryce Adelstein Lelbach - Modules are Coming , YouTube presentation  https://www.youtube.com/watch?v=Di_oqMh4gM8


