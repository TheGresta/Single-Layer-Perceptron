#pragma once

#ifndef RULES_H
#define RULES_H

// Include the cmath for the pow() function

#include <cmath>

// Constants

#define BIAS 1.0f
#define EULER 2.7182f
#define POS_INF 100000.0f
#define NEG_INF -100000.0f
#define ERR 0.1f

// Activation macros

#define SGN(x) ((x >= 0.0f)? 1.0f : (0.0f))
#define RELU(x) ((x >= 0.0f)? (x) : 0.0f)
#define SIGMOID(x) (1.0f / (1.0f + pow(EULER, -(x))))
#define foo(x) (x * x)

// Activation derivative macros

#define SGN_DEV(x) (0.0f)
#define RELU_DEV(x) (((x) > 0.0f) ? 1.0f : 0.0f)
#define SIGMOID_DEV(x) (SIGMOID(x) * (1 - SIGMOID(x)))

// Float number comparision macro

#define IS_EQUAL(x, y) (((x) > (y) - ERR && (x) < (y) + ERR) ? (1) : (0))

// Set used activation function

#define ACTIVATION SIGMOID
#define ACTIVATION_DEV SIGMOID_DEV

namespace learning_rule {

	// Learning rules from the lectures

	enum Rule {
		PERCEPTRON,
		DELTA_RULE
	};

	void supervised(int, int, int, const float*, float*, const float*, Rule, float = 0.1f, int = 10000);
	// unsupervised( ... ) ?
}

// Preprocessing operations

namespace preprocessing {
	void normalize(float*, int, float*);
	void randomize(float*, int);
	int getCycle();
}

#endif
