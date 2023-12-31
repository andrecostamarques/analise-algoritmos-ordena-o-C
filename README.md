# README

## Instruções de Uso

Este repositório contém um código em C para a análise de desempenho de diferentes algoritmos de ordenação. Siga as instruções abaixo para executar e analisar os resultados.

### 1. Configurações Iniciais

- Abra o arquivo `metodos.h` para visualizar e/ou modificar os métodos de ordenação disponíveis.

### 2. Configuração dos Parâmetros

No arquivo `main.c`, encontre as configurações iniciais na parte superior do código:

#### Tamanho dos Vetores (Linha 24)

```c
int vetores[5] = {10000, 50000, 100000, 500000, 1000000};
```

Defina os tamanhos dos vetores desejados nesta linha.

#### Seed para Geração de Números Aleatórios (Linha 26)

```c
unsigned int seed = 22001640;
```

Substitua o valor da `seed` para o de sua preferência.

#### Seleção dos Métodos de Ordenação (Linha 32)

```c
for(int j = 2; j < 6; j++){
    int sort = j;
    // ...
}
```

Modifique o loop para escolher quais métodos de ordenação deseja executar.

#### Seleção do Tipo de Teste (Linha 34)

```c
for(int l = 1; l < 3; l++){
    int tipo = l;
    // ...
}
```

Modifique o loop para escolher o tipo de teste.

### 3. Execução

Compile e execute o código. O programa gerará um arquivo CSV chamado `data.csv` com os resultados dos testes.

### 4. Análise dos Resultados

- Após a execução, verifique se o arquivo CSV `data.csv` foi gerado no mesmo diretório do código-fonte.

- Utilize o arquivo Jupyter Notebook fornecido (`analise_data.ipynb`) para análises detalhadas. Este notebook exportará automaticamente um arquivo Excel chamado `Tempos.xlsx` com os tempos médios de execução e variações para cada método de ordenação testado.

- O Python criará gráficos automaticamente, mas qualquer modificação, incluindo adição ou remoção de métodos, é simples de realizar.

<img src="/output/ex_grafico.png">

**Observações:**

- A saída do arquivo `data.csv` pode variar dependendo do compilador C utilizado. Certifique-se de que o arquivo é salvo no local desejado.

- Este código é livre para qualquer pessoa usar, modificar e distribuir conforme necessário.

- Para a visualização do código comentado, modifique para a branch teste.

- Em testes, o Quick Sort Pivo 0, e o Quick Sort Pivo LS, para o vetor tipo 2 sofreu complicações ao compilar (GCC) em Windows.