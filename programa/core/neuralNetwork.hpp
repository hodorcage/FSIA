#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <random>
#include <functional>

#define LOG(a, x) std::cout << "[" << a << "] " << x << std::endl
#define LOGE(x) LOG("ERROR", x)
#define LOGD(x) LOG("DEBUG", x)
#define LOGI(x) LOG("INFO", x)
#define LOGW(x) LOG("WARNING", x)

class randDouble
{
public:
	randDouble(double up, double down);
	double generate();
private:
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> dist;
};

using std::vector;
using std::array;

struct neuron;

typedef unsigned int uint;
typedef vector<neuron> layer;

struct connection
{
	double weight;
};

struct neuron
{
	vector<double> weights;
	double value;
};


class neuralNetwork
{
public:
	neuralNetwork(const array<uint, 3> topology);
	~neuralNetwork();

	void backPropagate(vector<double> dInput, vector<double> dOutput);
	vector<double> get(vector<double> dInput);

private:
	layer lHidden;
	layer lInput;
	layer lOutput;
	
	randDouble rand;

	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
};
