#include "CNeuralNet.h"
#include "CParams.h"

///
/// this code is from the tutorial at:
/// http://www.ai-junkie.com/ann/evolved/nnt1.html
///
/// I'm currently on page:
/// http://www.ai-junkie.com/ann/evolved/nnt7.html
///

using namespace std;

//// SNeuron Implementation

SNeuron::SNeuron(int numIn) : numInputs(numIn + 1) {
	// we need an additional weight for the bias,
	// hence the extra +1

	for (int i = 0; i < numIn + 1; i++) {
		// set up the weights with initial random values
		vecWeight.push_back(RandomClamped());
	}
}

//// SNeuronLayer

SNeuronLayer::SNeuronLayer(int neurons, int numIn) : numNeurons(neurons) {
	for (int i = 0; i < neurons; i++) {
		// creates the layer of neurons
		vecNeurons.push_back(SNeuron(numIn));
	}
}

//// CNeuralNet implementation

CNeuralNet::CNeuralNet() {

}

void CNeuralNet::CreateNet() {

}

const vector<double> CNeuralNet::GetWeights() {

}

const int CNeuralNet::GetNumberOfWeights() {

}

void CNeuralNet::PutWeights(vector<double> & weights) {

}

vector<double> CNeuralNet::Update(vector<double> & inputs) {
	// stores the resultant outputs from each layer
	vector<double> outputs;

	int cWeight = 0;

	// first check that we have the correct amount of inputs
	if (inputs.size() != numInputs) {
		// just return an empty vector if incorrect
		return outputs;
	}

	// For each layer...
	for (int i = 0; i < numHiddenLayers + 1; ++i) {
		if (i > 0) {
			inputs = outputs;
		}

		outputs.clear();

		cWeight = 0;

		// for each neuron, sum the (inputs * corresponding weights).
		// Throw the total at our sigmoid function to get the output
		for (int j = 0; j < vecLayers[i].numNeurons; j++) {
			double netInput = 0;
			int numIn = vecLayers[i].vecNeurons[j].numInputs;

			// for each weight
			for (int k = 0; k < numIn - 1; k++) {
				// sum the weights * inputs
				netInput += vecLayers[i].vecNeurons[j].vecWeight[k] * inputs[cWeight++];
			}

			// add in the bias
			netInput += vecLayers[i].vecNeurons[j].vecWeight[numInputs - 1] * CParams::dBias;

			// we can store the outputs from eacah layer as we generate them.
			// the combined activation is first filtered through the sigmoid function.
			outputs.push_back(Sigmoid(netInput, CParams::dActivationResponse));

			cWeight = 0;
		}
	}

	return outputs;
}

double CNeuralNet::Sigmoid(double activation, double response) {

}