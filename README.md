# push_swap 

## Because it sound better than swap_push

This project is part of the second circle of the 42 common core. The goal is to create a program which take in input a list of int (signed numbers), and output all the actions to do to sort them. For that, I had two stacks and a list of possible movements. It also make me more comfortable about linked lists, because I use them to represent stacks. You will find the subject of the project into the repository. My grade : 125/100.

## Rules

At the beginning, all numbers are in the stack A, and the stack B is empty. Numbers can bepositive and negative but not duplicated.
At the end, the stack A must be sorted in ascending order and the stack B must be empty.

The list of possible movements is the following one :

| Movements | Explanations |
| --------- | ------------ |
| sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | sa and sb at the same time. |
| pa (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra (rotate a) | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb (rotate b) | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr | rra and rrb at the same time. |

## How to use it

1. Clone it `git clone git@github.com:AnthonyVerdon-42Projects/push_swap.git`.
2. Compile it `make`.
3. You can use it like this :

```
./push_swap "-3 1 2" +4 -5
./push_swap [random numbers].
./push_swap `shuf -i 1-100 -n50` (1-100 is the range between minimum and maximum numbers, and 50 is the number of number)
```

## Checker

It's good to have a list of instructions, but it can be really boring to check manually if it's accurate. To solve that, compile `make bonus`. It will create another executable which will say if the list of instructions sort the stack or not. You can use it like this :

```
ARGS=`shuf -i 1-100 -n50`; ./push_swap $ARGS | ./checker $ARGS
```

## Friends work

My friend Théo Guerin (login 42 : tguerin, Github account : https://github.com/TheoGuerin64) made a website to simulate this project (https://theoguerin64.github.io/push-swap-lab.github.io/) and a visualizer (https://github.com/TheoGuerin64/push-swap-visualizer), take a look !

## Find a bug ?

If you find an undefined behaviour (crash, leaks, ...), please submit an issue or contact me
