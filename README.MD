# Programa de threads leitoras e escritoras

Este programa em C demonstra o uso de threads leitoras e escritoras para acessar uma tabela compartilhada. O programa utiliza o mecanismo rwlock da biblioteca Pthreads para fornecer acesso concorrente seguro à tabela.

## Requisitos

- Compilador C que suporte a biblioteca Pthreads (por exemplo, GCC)

## Compilação

Execute o seguinte comando para compilar o programa:

```
gcc programa.c -o programa -lpthread
```

## Execução

Após compilar o programa, você pode executá-lo da seguinte maneira:

```
./programa
```

## Configuração

O programa atual está configurado para criar 14 threads leitoras e 2 threads escritoras. Se desejar alterar o número de threads leitoras ou escritoras, você pode modificar as constantes `NUM_THREADS_LEITURA` e `NUM_THREADS_ESCRITA` no código-fonte.

## Saída

Durante a execução do programa, você verá mensagens de leitura e escrita no console, indicando as ações das threads leitoras e escritoras.

## Observações

- Certifique-se de ter permissão para compilar e executar programas C no diretório em que você está trabalhando.
- Verifique se o compilador C e a biblioteca Pthreads estão instalados corretamente no seu sistema.
- Lembre-se de incluir a flag `-lpthread` durante a compilação para vincular a biblioteca Pthreads.
