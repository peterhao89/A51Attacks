These are the C++ codes corresponding to the Inscrypt 2021 paper ``Revisit Two Memoryless State-Recovery Cryptanalysis Methods on A5/1''.
To run the codes, [NTL](https://libntl.org/) should be installed in advance. 

The macro settings at line 5-9 in ``main.cpp'' file correspond to different 
experiments. The default settings are as follows: 
```cpp
#define TEST 0
#define MERGE 0
#define GEN_GUESS_TABLE 0
#define PRACTICAL_ATTACK 1
#define DDT_GENERATE 0
```
In this setting, we are able to generate Table 1, 3, 4 of the paper. 

Table 1, 3, 4 are to be generated respectively by commenting lines 510-512:
For Table 1, use line 512:
```cpp
getFilterStrengthAtRound(1, round, testTime);
```
For Table 3, use line 510
```cpp
getFilterStrengthAtRoundAfter5GuessClocks(1, round, testTime);
```
For Table 4, use line 511
```cpp
getFilterStrengthAtRoundAfter5(1, round, testTime);
```

To implement the CP-recovery phase for Zhang's near collision attack, modify lines 5-9 as
```cpp
#define TEST 0
#define MERGE 1
#define GEN_GUESS_TABLE 0
#define PRACTICAL_ATTACK 0
#define DDT_GENERATE 0
```