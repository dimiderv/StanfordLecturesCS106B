# 2nd Assignment 

* Word ladder script implements a connection from one word to another formed by changing one letter at a time with the contraint tha each step the sequence of letters still forms a valid word.For example, here is a word ladder connecting "code" to "data".  <br /> <br />
&ensp;&ensp; code → core → care → dare → date → data   <br />            
&ensp;This script finds the minimal word ladder between two words if it exists. The ADTs (Abstruct Data Types) that will be used for this problem are
Vectors,Queues and Lexicon. This problem is an instance of a shortest-path problem and breadth-first-search will be used. That's why
queues will be needed because BFS is typically implemented by using a queue to store partial ladders that represent posibilities to explore.

* Random Writer reads a source text, builds an order-k Markov model for it and then generates a random output that follows the frequenct patterns of the model. [Markov model](https://en.wikipedia.org/wiki/Markov_chain) is a statistical model that describes the future state of a system based on the current state and the conditional probabilities of the possible transitions. In this context the Markov model is used to describe the possibility of a particular character appearing given the sequence of characters seen so far. The ADTs that will be used for this problem are Maps and Vectors.
