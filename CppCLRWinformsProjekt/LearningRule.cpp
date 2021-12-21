#include "Form1.h"
#include "LearningRule.h"

int cycle = 0;

void learning_rule::supervised(int feature_dim, int sample_count, int neuron_count, const float* dataset, float* weight, const float* d_output, Rule rule, float learning_rate, int epochs) {

	const float* sample, *desired_output;
	float *net, *output, r_signal;
	int i, j, step, epoch, is_completed;

	net = new float[neuron_count];
	output = new float[neuron_count];

	cycle = 0;

	// EPOCHS

	for (epoch = 0; epoch < epochs; epoch++) {

		cycle++;

		is_completed = 1;

		// STEPS

		for (step = 0; step < sample_count; step++) {
			sample = &dataset[step * feature_dim];
			desired_output = &d_output[step * neuron_count];

			for (i = 0; i < neuron_count; i++)
				net[i] = 0.0f;

			// NET = W * x

			for (i = 0; i < neuron_count; i++) {
				for (j = 0; j < feature_dim; j++)
					net[i] += sample[j] * weight[(feature_dim + 1) * i + j];
				net[i] += weight[(feature_dim + 1) * i + feature_dim] * BIAS;

				// OUTPUT = f(net)

				output[i] = ACTIVATION(net[i]);

				if (!IS_EQUAL(desired_output[i], output[i]))
					is_completed = 0;

				// Produce the r signal

				switch (rule) {
				case PERCEPTRON: r_signal = desired_output[i] - output[i]; break;
				case DELTA_RULE: r_signal = (desired_output[i] - output[i]) * ACTIVATION_DEV(net[i]); break;
				default: r_signal = 0.0f;
				}

				// W = W + crx
				// c : learning rate
				// r : signal
				// x : sample

				for (j = 0; j < feature_dim; j++)
					weight[(feature_dim + 1) * i + j] += learning_rate * r_signal * sample[j];
				weight[(feature_dim + 1) * i + feature_dim] += learning_rate * r_signal * BIAS;
			}
		}

		// Don't bother to continue if the error is so small

		if (is_completed)
			break;
	}
}

    // Normalize Input Points
void preprocessing::normalize(float *dataset, int len, float *factor) {
	float norm = 0;

	// Calculate the norm of the vector

	for (int i = 0; i < len; i++)
		norm += dataset[i] * dataset[i];

	norm = sqrt(norm);

	// Divide every element to the norm

	for (int i = 0; i < len; i++)
		dataset[i] /= norm;

	*factor = norm;
}

    // Set Weight Coefficient
void preprocessing::randomize(float* arr, int len) {

	// Set random real numbers between 0 and 1
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / (RAND_MAX));
}

    // Return Total Cycle Count
int preprocessing::getCycle() {

	return cycle;
}

