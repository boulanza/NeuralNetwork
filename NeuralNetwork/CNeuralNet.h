#include <vector>
#include "Utils.h"

using namespace std;

// basic neuron structure
struct SNeuron {
	// number of inputs into the neuron
	int numInputs;

	// weights for each input
	vector<double> vecWeight;

	//constructor
	SNeuron(int numIn);
};

// basic neuron layer structure
struct SNeuronLayer {
	// the number of neurons in this layer
	int numNeurons;

	//the layer of neurons
	vector<SNeuron> vecNeurons;

	//constructor
	SNeuronLayer(int numNeurons, int numInputPerNeuron);
};

class CNeuralNet {
private:
	int numInputs;
	int numOutputs;
	int numHiddenLayers;
	int nueronsPerHiddenLayer;
	vector<SNeuronLayer> vecLayers; // storage for each layer including output layer

public:
	CNeuralNet();

	// creates the neural network
	void CreateNet();

	// gets the weights from the NN
	const vector<double> GetWeights();

	// gets the total number of weights in the NN
	const int GetNumberOfWeights();

	// replaces the weights with new ones
	void PutWeights(vector<double> & weights);

	// calculates the outputs from a set of inputs
	vector<double> Update(vector<double> & inputs);

	// sigmoid response curve
	double Sigmoid(double activation, double response);
};