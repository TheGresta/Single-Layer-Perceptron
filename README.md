# Single-Layer-Perceptron
Single Layer Supresived Deep Learning

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147012025-bd6e4caa-7d0c-42fc-8ef8-c1ad759bfaeb.png" alt="Main 2"/>
</p>

## Guide

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147012782-f9313d5f-081f-4acc-994a-67682cf524b9.gif" alt="last"/>
</p>


### Perceptron

Perceptron is a one layered artifical neural network base unit. It consists of a single artifical neural network that can be teached and is a supervised learning algorithm. One perceptron input value includes: weight, deviation, weighted aritmetic mean and activation function. Input and output values are given and neural network is expected to be learned.

### Definition

A single layer perceptron (SLP) is a feed-forward network based on a threshold transfer function. SLP is the simplest type of artificial neural networks and can only classify linearly separable cases with a binary target (1 , 0).

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287315-95a37d54-3205-42c1-b1d7-f6a46c5422db.png" alt="Screenshot_1"/>
</p>

### Algorithm

The single layer perceptron does not have a priori knowledge, so the initial weights are assigned randomly. SLP sums all the weighted inputs and if the sum is above the threshold (some predetermined value), SLP is said to be activated (output=1). 

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287378-928bd6af-9a39-4da0-9af6-2db4b59314e5.png" alt="Screenshot_2"/>
</p>

The input values are presented to the perceptron, and if the predicted output is the same as the desired output, then the performance is considered satisfactory and no changes to the weights are made. However, if the output does not match the desired output, then the weights need to be changed to reduce the error. 

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287421-57fb963b-4143-4cdb-8442-2a9846d6038a.png" alt="Screenshot_3"/>
</p>

Because SLP is a linear classifier and if the cases are not linearly separable the learning process will never reach a point where all the cases are classified properly. The most famous example of the inability of perceptron to solve problems with linearly non-separable cases is the XOR problem.

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287443-e9ea29b8-eab4-47db-a24d-3f5295f4012a.png" alt="Screenshot_4"/>
</p>

However, a multi-layer perceptron using the backpropagation algorithm can successfully classify the XOR data.

## How do the code work?

### Hiding the input data

When the user selects a class and clicks our picture box, we save our input data inside the clicked location to a struct
Struct:
•	Input X coordinate
•	Input Y coordinate
•	Input ID

User’s clicked location is saved and organized according to our coordinate system as in X and Y. Later, to be able ensure supervision, we assign our snapped class index as ID value of the input also.

### Normalization

Because our coordinate plane is pixel based, our input data of X and Y values will be assigned as a pixel. But because these values will be immensely large numbers, it will come with a great work load. Our first priority is the minimize these values. That’s why we use normalization.

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287454-5a7ed2a0-82f9-4cd4-9041-fd7feb94d8eb.png" alt="1"/>
</p>

In the above process, all the input’s X and Y values are added sum and in radicand to calculate the norm value. After that we divide all the values of X and Y to the norm and realize the normalization process.

### Weight Coefficient

First we need some random weight coefficient numbers. These must be between 0 and 1. For this process we use rand() ve RAND_MAX function.
While every rand() function give us a random number, RAND_MAX will give the maximum number that can be obtainted through rand() function.

For every weight coefficient rand() / RAND_MAX is used and get weight coefficient number randomly between 0 and 1.

## Learning

### NET = W * X

In this process, we multiply our whole input X values with weight coefficient and calculate the net value.

### OUTPUT = f(net)

The purpose of this process is to calculate the output values by sending our net values to activation function. These values in the case of being higher than 0, is turned to 0 and 0 to 1 vice versa.
Signal value

This value is dependant to the learning method. For instance our Perceptron method signal value:

<p align="center">
  <img src="https://user-images.githubusercontent.com/74189776/147287466-cf3504ae-5236-48ab-a8e1-a0c9ea772e1b.png" alt="CodeCogsEqn"/>
</p>

•	r : Signal value
•	d: Desired output
•	o: Output

### W = W + crx

•	c : Learning rate (0.1)
•	r : Singnal value
•	x : Samples

Here crx represents the change of W value. With this weight coefficient is updated.

## How does the loop end?

We were using (d-o) process while calculating the signal value. If d and o values are the same the result will be 0. As a result crx process is bound to 0 that’s why the change of the value of the W will be 0.
As there will be no change in the W value our programme will be out of the loop.
Ultimately, weight coefficient and X values have gotten. Thus we could draw any line that we want for our programme. We use this process for every class only once.

# References

https://tr.wikipedia.org/wiki/Perceptron

https://www.saedsayad.com/artificial_neural_network_bkp.htm
