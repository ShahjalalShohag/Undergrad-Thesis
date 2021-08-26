### Topic: 
A Novel Algorithm to Maximize Core Resilience of Networks under Random Edge and Node Deletions

### Proposed Algorithm: 
Dominating Neighbours Algorithm (DNA)

### Abstract
Although there are numerous graph properties related to its structure, not all of them provide insight into its strength or vulnerability in terms of network strength. It's valuable to understand which properties have the most impact on a network's strength and also which property we can use to define or set a measurement of strength. 

\vspace{1mm}
\textit{$K$-core} is a very important network property which gives us a high level of intuition about the network's overall structure. Also, we can set up a measure of node centrality within a network with the terms of \textit{$k$-core}. Again, using  core number and \textit{$k$-core} distribution, we can set up new measurements of the core structure resilience and measure damages caused by dropped communication links. 

\vspace{1mm}
In this research we came up with a potential node property in a network which can be used to improve its resilience when under attack of communication dropping. More formally when a network goes through certain damages with its connections, it can be represented as edge deletion of a graph. By introducing a new node property, namely \textit{Neighbour Domination Coefficient(NDC)}, we have shown that it can be used as a means of adding some budget edges to the network to keep the core resilience high even after the damage. Using the \textit{NDC} property later on we came up with the \textit{Dominating Neighbour Algorithm(DNA)} which is able to keep the core resilience high. 

\vspace{1mm}
We performed our algorithm on various real-life networks, and found that it performs well and gives better results when compared to baseline methods like \textit{Greedy} or \textit{Random}. Our algorithm improves the core resilience by $27.233\%$ while the baseline methods $-$ \textit{Random} improves it by $13.9042\%$ and \textit{Greedy} improves it by $14.9138\%$.
