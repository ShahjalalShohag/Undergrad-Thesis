### Topic: 
A Novel Algorithm to Maximize Core Resilience of Networks under Random Edge and Node Deletions

### Proposed Algorithm: 
Dominating Neighbours Algorithm (DNA)

### Abstract

Although there are numerous graph properties related to its structure, not all of them provide insight into its strength or vulnerability in terms of network strength. It’s valuable to understand which properties have the most impact on a network’s strength and also which property we can use to define or set a measurement of strength.

K-core is a very important network property which gives us a high level of intuition about the network’s overall structure. Also, we can set up a measure of node centrality within a network with the terms of K-core. Again, using core number and K-core distribution, we can set up new measurements of the core structure resilience and measure damages caused by dropped communication links.

In this research we came up with some potential node and edge property in a network which can be used to improve its resilience when under attack of communication dropping. More formally when a network goes through certain damages with its connections, it can be represented as edge deletion of a graph and when the communication endpoints are corrupted it can be marked as node deletion . By introducing a new node property, namely _Neighbour Domination Coefficient(NDC)_, we have shown that it can be used as a means of adding some budget edges to the network to keep the core resilience high even after the damage. Using the NDC property later on we came up with the _Dominating Neighbour Algorithm(DNA)_ which is able to keep the core resilience high in terms of edge deletion. Associating more node and edge property with our algorithms DNA we came up with another algorithm eDNA which is significant in terms of node deletion. 

We performed our algorithm on various real-life networks, and found that it performs well and gives better results when compared to baseline methods like _Greedy_ or _Random_. Against edge deletion our algorithm DNA improves the core resilience by **27.233%** while the baseline methods − _Random_ improves it by **13.9042%** and _Greedy_ improves it by **14.9138%**. And against node deletion our algorithm eDNA improves the core resilience by **24.1707%** while the baseline methods − _Random_ improves it by **7.023%** and _Greedy_ improves it by **15.3194%**.
