/*
Para um sistema que realiza milhares de buscas por segundo e possui crescimento constante de dados,a estratégia mais eficiente é manter os dados ordenados e utilizar a busca binária.

A busca binária possui custo O(log n), sendo muito mais eficiente para buscas frequentes. Entretanto, ela exige que os dados estejam ordenados.

Como os dados são inseridos de forma aleatória, é necessário utilizar um algoritmo de ordenação, para isso o Merge Sort é ideial, uma vez que possui complexidade O(n log n), é eficiente para grandes volumes de dados e mantém bom desempenho mesmo com crescimento constante.

Portanto, o sistema realizara as pesquisas no conjunto de dados átraves da busca binaria, a partir da ordenação dos dados atraves do Merge Sort, além do mais, uma boa organização no código, para não haver retrabalho e custo elevado de manutenção.
*/