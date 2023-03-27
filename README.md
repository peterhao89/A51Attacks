These are the C++ codes corresponds to the IET submission (Extended version of the [Inscrypt 2021 paper of the same name](https://link.springer.com/chapter/10.1007/978-3-030-88323-2_10)) ``Revisit Two Memoryless State-Recovery Cryptanalysis Methods on A5/1''.
To run the codes, [NTL](https://libntl.org/) should be installed in advance. 

To compile the project, you may enter the run the following commands:
```
git clone https://github.com/peterhao89/A51Attacks.git
cd A51Attacks
mkdir build
cd build
cmake ..
make
```
Then, you will acquire an binary file named ``ntlGuessDeterminA51`` for generating the data for computing Table 1, 2, 3, 6, 7 following the prompts.  
For example, if we want verify Table 7 of the improved near collision attack, we only need to run as follows: 
```
 ./ntlGuessDeterminA51.exe
Set Data Complexity x of 2^x (default x=10)
30
Data complexity 2^10
Choose Experiment:
1. Our S0-Recovery
2. Our S1-Recovery
3. Golic's Guess-and-Determine
4. Zhang's Original Near Collision
5. Improved Near Collision
5
```
