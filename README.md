# Repositório para a matéria Computação Paralela
Um repositório para tarefas e trabalhos práticos da matéria Computação Paralela de [Ciência da Computação PUC-MG](http://www.icei.pucminas.br/index.php/cursos/graduacao/ciencia-da-computacao/coracao-eucaristico "Pagina Oficial do Curso") ministrada pelo professor **Luís Fabrício Wanderley Góes**

## Detalhes Acadêmicos:
 - **Aluno:** Arthur Ladislau Pereira.
 - **Período:** 6°.
 - **Semestre:** 2019/1.

## Informações Técnicas:
 - **Linguagens:** [C](https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o) "Página da Wikipedia").

### Requerimentos:
 - OpenMP

### Instruções:
Os arquivos em **C** devem ser compilados usando o compilador padrão do Linux seguindo o seguinte padrão:

```shell
~$ gcc -fopenmp Tarefa{X:02d}.c -o t{X:02d}.exe
```
E executando de acordo:
```
~$ ./t{X:02d}.exe
```

Onde *X* é o número da Tarefa substuindo as chaves seguindo o padrão da função [```format()```](https://docs.python.org/3.4/library/functions.html#format "Documentação do Format") de strings em [**Python**](https://www.python.org/ "Página Oficial da Linguagem").

#### Exemplo:
```zsh
~$ gcc -fopenmp Tarefa01.c -o t01.exe
~$ ./t01.exe
```
